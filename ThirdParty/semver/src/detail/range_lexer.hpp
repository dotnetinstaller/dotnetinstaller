#ifndef SEMVER_DETAIL_RANGE_LEXER_HPP
#define SEMVER_DETAIL_RANGE_LEXER_HPP

#include "semver_parser.hpp"
#include <semver/semver.hpp>
#include <algorithm>
#include <string>
#include <cassert>

namespace semver
{
inline namespace v1
{
namespace detail
{
class range_lexer final
{
public:
	using string_type = std::string;

	enum class token {
		partial,
		caret_partial,
		tilde_partial,
		op_partial,
		dash,
		logical_or,
		error,
		eof
	};

	// structure to hold scanned parts, not all are strictly necessary but
	// caching them makes it easier to process the result.
	struct parts {
		string_type token = {}; // full token

		string_type version = {}; // version without op/tilde/caret
		bool full_version = false; // all three parts, major.minor.patch, were parsed

		// indivisual parts
		string_type op = {};
		string_type major = {};
		string_type minor = {};
		string_type patch = {};
		string_type prerelease = {};
		string_type build = {};
	};

	range_lexer(const std::string & s)
		: data_(s)
	{
		cursor_ = data_.data();
		last_ = data_.data() + data_.size();
	}

	token scan() noexcept
	{
		clear();
		while (!eof()) {
			start_ = cursor_;

			if (is_space()) {
				advance(1);
				continue;
			}

			if (is_dash()) {
				advance(1);
				store();
				return token::dash;
			}

			if (is_logical_or()) {
				advance(2);
				store();
				return token::logical_or;
			}

			if (is_caret())
				return lex_caret_partial();

			if (is_tilde())
				return lex_tilde_partial();

			if (is_op())
				return lex_op_partial();

			if (is_x() || is_star() || is_digit())
				return lex_partial();

			return token::error;
		}
		return token::eof;
	}

	const string_type & data() const noexcept { return data_; }

	const parts & text() noexcept { return parts_; }

private:
	using char_type = string_type::value_type;

	const char_type * cursor_ = nullptr;
	const char_type * last_ = nullptr;
	const char_type * start_ = nullptr;
	const char_type * error_ = nullptr;

	parts parts_;
	std::string data_;

	void patch(char c) noexcept
	{
		assert(cursor_ >= data_.data());
		assert(cursor_ < data_.data() + data_.size());
		char_type * p = const_cast<char_type *>(cursor_); // we know what we are doing
		*p = c;
	}

	void clear() noexcept { parts_ = {}; }

	void store()
	{
		store(parts_.token, start_);
		store(parts_.version, start_ + parts_.op.size());
	}

	void store(string_type & s, const char_type * start)
	{
		const auto d = std::distance(start, cursor_);
		assert(d >= 0);
		s = string_type(start, static_cast<std::size_t>(d));
	}

	bool is_numerical(const string_type & s) const
	{
		return std::find_if_not(begin(s), end(s), [](const auto c) { return isdigit(c); })
			== end(s);
	}

	void error() noexcept { error_ = cursor_; }
	void advance(int n) noexcept { cursor_ += std::min(n, static_cast<int>(last_ - cursor_)); }

	bool eof() const noexcept { return (cursor_ == last_) || (*cursor_ == '\x00'); }
	bool eof(const char_type * p) const noexcept { return (p == last_) || (*p == '\x00'); }
	bool is_space() const noexcept { return ::isspace(*cursor_); }
	bool is_digit() const noexcept { return ::isdigit(*cursor_); }
	bool is_caret() const noexcept { return *cursor_ == '^'; }
	bool is_tilde() const noexcept { return *cursor_ == '~'; }
	bool is_star() const noexcept { return *cursor_ == '*'; }
	bool is_dash() const noexcept { return *cursor_ == '-'; }
	bool is_dot() const noexcept { return *cursor_ == '.'; }
	bool is_plus() const noexcept { return *cursor_ == '+'; }
	bool is_x() const noexcept { return *cursor_ == 'x' || *cursor_ == 'X'; }
	bool is_zero() const noexcept { return *cursor_ == '0'; }

	bool is_positive_digit() const noexcept
	{
		return !eof() && ((*cursor_ >= '1') && (*cursor_ <= '9'));
	}

	bool is_letter() const noexcept
	{
		return !eof()
			&& (((*cursor_ >= 'A') && (*cursor_ <= 'Z'))
				|| ((*cursor_ >= 'a') && (*cursor_ <= 'z')));
	}

	char_type peek(int n = 1) const noexcept
	{
		const char_type * p = cursor_ + n;
		return eof(p) ? '\0' : *p;
	}

	bool is_lt() const noexcept { return *cursor_ == '<' && peek() != '='; }
	bool is_le() const noexcept { return *cursor_ == '<' && peek() == '='; }
	bool is_gt() const noexcept { return *cursor_ == '>' && peek() != '='; }
	bool is_ge() const noexcept { return *cursor_ == '>' && peek() == '='; }
	bool is_eq() const noexcept { return *cursor_ == '='; }
	bool is_op() const noexcept { return is_lt() || is_le() || is_gt() || is_ge() || is_eq(); }
	bool is_logical_or() const noexcept { return (*cursor_ == '|') && (peek() == '|'); }

	token lex_caret_partial()
	{
		scan_op();
		scan_partial();
		store();
		return (!error_) ? token::caret_partial : token::error;
	}

	token lex_tilde_partial()
	{
		scan_op();
		scan_partial();
		store();
		return (!error_) ? token::tilde_partial : token::error;
	}

	token lex_op_partial()
	{
		scan_op();
		scan_partial();
		store();
		return (!error_) ? token::op_partial : token::error;
	}

	token lex_partial()
	{
		scan_partial();
		store();
		return (!error_) ? token::partial : token::error;
	}

	void scan_op()
	{
		const char_type * p = cursor_;
		if (is_eq() || is_lt() || is_gt() || is_tilde() || is_caret())
			advance(1);
		else
			advance(2);
		store(parts_.op, p);
	}

	void scan_major()
	{
		const char_type * p = cursor_;
		scan_partial_version();
		store(parts_.major, p);
	}

	void scan_minor()
	{
		const char_type * p = cursor_;
		scan_partial_version();
		store(parts_.minor, p);
	}

	void scan_patch()
	{
		const char_type * p = cursor_;
		scan_partial_version();
		store(parts_.patch, p);
	}

	void scan_prerelease()
	{
		const char_type * p = cursor_;
		scan_dot_separated_identifier();
		store(parts_.prerelease, p);
	}

	void scan_build()
	{
		const char_type * p = cursor_;
		scan_dot_separated_identifier();
		store(parts_.build, p);
	}

	void scan_partial()
	{
		parts_.full_version = false;

		scan_major();

		if (!is_dot())
			return;
		advance(1);

		scan_minor();

		if (!is_dot())
			return;
		advance(1);

		scan_patch();

		parts_.full_version = is_numerical(parts_.major) && is_numerical(parts_.minor)
			&& is_numerical(parts_.patch);

		if (is_dash()) {
			advance(1);
			scan_prerelease();
			if (is_plus()) {
				advance(1);
				scan_build();
			}
			return;
		}
		if (is_plus()) {
			advance(1);
			scan_build();
			return;
		}
	}

	void scan_dot_separated_identifier() noexcept
	{
		scan_identifier();
		while (is_dot()) {
			advance(1);
			scan_identifier();
		}
	}

	void scan_identifier() noexcept
	{
		if (!(is_letter() || is_digit() || is_dash())) {
			error();
			return;
		}
		while (is_letter() || is_digit() || is_dash())
			advance(1);
	}

	void scan_partial_version() noexcept
	{
		if (is_x()) {
			patch('*'); // normalize wildcards to '*'
			advance(1);
			return;
		}
		if (is_star()) {
			advance(1);
			return;
		}
		if (is_zero()) {
			advance(1);
			return;
		}
		if (is_positive_digit()) {
			advance(1);
			while (is_digit())
				advance(1);
			return;
		}
		error();
	}
};

inline semver lower_bound(const range_lexer::parts & p)
{
	if (p.major.empty() || p.major == "*")
		return semver::min();

	const auto major = semver_parser::ston(p.major);

	if (p.minor.empty() || p.minor == "*")
		return semver(major, 0, 0);

	const auto minor = semver_parser::ston(p.minor);

	if (p.patch.empty() || p.patch == "*")
		return semver(major, minor, 0);

	return semver(p.token.substr(
		p.op.size(), p.token.size() - p.op.size() - p.build.size() + 1)); // cut op and build
}

inline semver upper_bound(const range_lexer::parts & p)
{
	if (p.major.empty() || p.major == "*")
		return semver::max();

	const auto major = semver_parser::ston(p.major);

	if (p.op == "^" && p.major != "0")
		return semver(major + 1u, 0, 0, "0");

	if (p.minor.empty() || p.minor == "*")
		return semver(major + 1u, 0, 0, "0");

	const auto minor = semver_parser::ston(p.minor);

	if (p.op == "^" && p.minor != "0")
		return semver(major, minor + 1u, 0, "0");

	if (p.patch.empty() || p.patch == "*" || p.op == "~")
		return semver(major, minor + 1u, 0, "0");

	const auto patch = semver_parser::ston(p.patch);

	if (p.op == "^" && p.patch != "0")
		return semver(major, minor, patch + 1u, "0");

	return semver(p.token.substr(
		p.op.size(), p.token.size() - p.op.size() - p.build.size() + 1)); // cut op and build
}
}
}
}

#endif

