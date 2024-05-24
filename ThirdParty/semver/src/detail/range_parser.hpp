#ifndef SEMVER_DETAIL_RANGE_PARSER_HPP
#define SEMVER_DETAIL_RANGE_PARSER_HPP

#include "range_lexer.hpp"
#include "range_node.hpp"
#include <semver/semver.hpp>
#include <memory>
#include <vector>

namespace semver
{
inline namespace v1
{
namespace detail
{
inline std::string trim(std::string s)
{
	const auto b = s.find_first_not_of(" ");
	const auto e = s.find_last_not_of(" ");

	return (b != std::string::npos) ? s.substr(b, e - b + 1) : "";
}

class range_parser final
{
private:
	using char_type = std::string::value_type;

public:
	range_parser(const std::string & s)
		: lex_(trim(s))
	{
		parse_range_set();

		assert(ast_.size() <= 1);
		if (!ast_.empty())
			flatten_ast();
	}

	bool ok() const noexcept { return good_; }

	std::vector<std::unique_ptr<node>> && ast()
	{
		good_ = false;
		return std::move(ast_);
	}

private:
	using token = ::semver::v1::detail::range_lexer::token;

	detail::range_lexer lex_;
	detail::range_lexer::token token_ = detail::range_lexer::token::eof;
	detail::range_lexer::token next_ = detail::range_lexer::token::eof;
	detail::range_lexer::parts token_text_ = {};
	detail::range_lexer::parts next_text_ = {};

	bool good_ = false;
	std::vector<std::unique_ptr<node>> ast_;

	void flatten_ast()
	{
		if (ast_back()->is_leaf())
			return;

		if (ast_back()->get_type() == node::type::op_and)
			return;

		assert(ast_back()->get_type() == node::type::op_or);

		// transform AST into a list of `or` connected nodes, simple ones frist.
		// this makes the structure of the AST more approachable for other algorithms
		// like comparing ranges.

		std::vector<std::unique_ptr<node>> v;
		collect_leafs_and_andnodes(v, *ast_back());
		std::sort(begin(v), end(v),
			[](const auto & a, const auto & b) { return node::less(*a, *b); });
		ast_ = std::move(v);
	}

	void start() noexcept
	{
		token_ = lex_.scan();
		token_text_ = lex_.text();
		next_ = lex_.scan();
		next_text_ = lex_.text();
	}

	void advance() noexcept
	{
		token_ = next_;
		token_text_ = next_text_;
		next_ = lex_.scan();
		next_text_ = lex_.text();
	}

	void error() noexcept { good_ = false; }

	bool is_eof(token t) const noexcept { return t == token::eof; }
	bool is_error(token t) const noexcept { return t == token::error; }
	bool is_caret(token t) const noexcept { return t == token::caret_partial; }
	bool is_tilde(token t) const noexcept { return t == token::tilde_partial; }
	bool is_op(token t) const noexcept { return t == token::op_partial; }
	bool is_logical_or(token t) const noexcept { return t == token::logical_or; }
	bool is_partial(token t) const noexcept { return t == token::partial; }
	bool is_dash(token t) const noexcept { return t == token::dash; }

	std::unique_ptr<node> & ast_back() { return ast_.back(); }
	const std::unique_ptr<node> & ast_back() const { return ast_.back(); }

	void ast_push(node && n) { ast_push(std::make_unique<node>(std::move(n))); }
	void ast_push(std::unique_ptr<node> n) { ast_.push_back(std::move(n)); }

	std::unique_ptr<node> ast_pop()
	{
		auto n = std::move(ast_back());
		ast_.erase(prev(end(ast_)));
		return n;
	}

	void parse_range_set() noexcept
	{
		start();

		if (is_eof(token_)) {
			ast_push(node::create_ge(lower_bound(token_text_)));
			good_ = true;
			return;
		}

		parse_range();
		while (is_logical_or(token_)) {
			advance(); // logial-or
			parse_range();

			assert(ast_.size() > 1);
			auto b = ast_pop();
			auto a = ast_pop();
			ast_push(node::create_or(std::move(a), std::move(b)));
		}

		good_ = !is_error(token_);
	}

	void parse_range() noexcept
	{
		if (is_partial(token_) && is_dash(next_)) {
			const auto first = token_text_;
			advance(); // partial
			advance(); // dash
			if (is_partial(token_)) {
				auto l = lower_bound(first);

				// according to the examples provided here: https://github.com/npm/node-semver#versions,
				// use lower_bound/le if it was a complete partial, upper_bound/lt otherwise
				auto u = token_text_.full_version ? lower_bound(token_text_)
												  : upper_bound(token_text_);

				if (l == u) {
					ast_push(node::create_eq(l));
				} else {
					if (l > u)
						std::swap(l, u);
					if (token_text_.full_version) {
						ast_push(node::create_and(node::create_ge(l), node::create_le(u)));
					} else {
						ast_push(node::create_and(node::create_ge(l), node::create_lt(u)));
					}
				}
				advance();
				return;
			}
			error();
			return;
		}

		int partial_count = 0; // how may partials are participating in implicit and
		while (!is_eof(token_) && !is_logical_or(token_)) {
			++partial_count;

			if (is_caret(token_) || is_tilde(token_)) {
				auto l = lower_bound(token_text_);
				auto u = upper_bound(token_text_);
				if (l == u) {
					ast_push(node::create_eq(l));
				} else if (u == semver::max()) {
					ast_push(node::create_ge(l));
				} else {
					ast_push(node::create_and(node::create_ge(l), node::create_lt(u)));
				}
				advance();
				continue;
			}
			if (is_op(token_)) {
				if (token_text_.op == "<")
					ast_push(node::create_lt(lower_bound(token_text_)));
				if (token_text_.op == "<=")
					ast_push(node::create_le(lower_bound(token_text_)));
				if (token_text_.op == ">")
					ast_push(node::create_gt(lower_bound(token_text_)));
				if (token_text_.op == ">=")
					ast_push(node::create_ge(lower_bound(token_text_)));
				if (token_text_.op == "=")
					ast_push(node::create_eq(lower_bound(token_text_)));
				advance();
				continue;
			}
			if (is_partial(token_)) {
				// if the version contains wildcards, handle it as range
				if (token_text_.full_version) {
					ast_push(node::create_eq(lower_bound(token_text_)));
				} else {
					auto l = lower_bound(token_text_);
					auto u = upper_bound(token_text_);
					if (l == u) {
						ast_push(node::create_eq(l));
					} else if (u == semver::max()) {
						ast_push(node::create_ge(l));
					} else {
						ast_push(node::create_and(node::create_ge(l), node::create_lt(u)));
					}
				}
				advance();
				continue;
			}

			error();
			return;
		}

		// are there multiple leafs and therefore an implicit 'and'?
		if (partial_count > 1) {
			std::vector<std::unique_ptr<node>> v;
			for (; partial_count > 0 && ast_back()->is_leaf(); --partial_count)
				v.push_back(ast_pop());
			ast_push(node::create_and(std::move(v)));
		}
	}
};
}
}
}

#endif
