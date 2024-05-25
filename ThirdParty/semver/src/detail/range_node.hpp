#ifndef SEMVER_DETAIL_RANGE_NODE_HPP
#define SEMVER_DETAIL_RANGE_NODE_HPP

#include <semver/semver.hpp>
#include <algorithm>
#include <limits>
#include <optional>
#include <ostream>
#include <memory>
#include <vector>
#include <cassert>

namespace semver
{
inline namespace v1
{
namespace detail
{
inline semver successor(const semver & v)
{
	if (!v.prerelease().empty())
		return semver(v.major(), v.minor(), v.patch());

	constexpr const auto max = std::numeric_limits<semver::number_type>::max();
	auto major = v.major();
	auto minor = v.minor();
	auto patch = v.patch();

	// bump-up version: version+epsilon
	if (patch == max) {
		patch = 0;
		if (minor == max) {
			minor = 0;
			if (major == max) {
				return {}; // nothing valid possible
			} else {
				++major;
			}
		} else {
			++minor;
		}
	} else {
		++patch;
	}
	return semver(major, minor, patch);
}

inline semver predecessor(const semver & v)
{
	if (v.prerelease().empty())
		return semver(v.major(), v.minor(), v.patch(), "0");

	constexpr const auto max = std::numeric_limits<semver::number_type>::max();
	auto major = v.major();
	auto minor = v.minor();
	auto patch = v.patch();

	// bump-down version: version-epsilon
	if (patch == 0) {
		patch = max;
		if (minor == 0) {
			minor = max;
			if (major == 0) {
				return {}; // nothing valid possible
			} else {
				--major;
			}
		} else {
			--minor;
		}
	} else {
		--patch;
	}
	return semver(major, minor, patch);
}

class node final
{
public:
	enum class type { op_and, op_or, op_eq, op_lt, op_le, op_gt, op_ge };

	~node() = default;

	node(const node &) = delete;
	node & operator=(const node &) = delete;

	node(node &&) = default;
	node & operator=(node &&) = default;

	static node create_and(node && first, node && second)
	{
		return create_and(std::make_unique<node>(std::move(first)),
			std::make_unique<node>(std::move(second)));
	}

	static node create_and(std::unique_ptr<node> first, std::unique_ptr<node> second)
	{
		std::vector<std::unique_ptr<node>> v;
		v.reserve(2);
		v.push_back(std::move(first));
		v.push_back(std::move(second));
		return node(type::op_and, std::move(v));
	}

	static node create_and(std::vector<std::unique_ptr<node>> && v)
	{
		return node(type::op_and, std::move(v));
	}

	static node create_or(node && first, node && second)
	{
		return create_or(std::make_unique<node>(std::move(first)),
			std::make_unique<node>(std::move(second)));
	}

	static node create_or(std::unique_ptr<node> first, std::unique_ptr<node> second)
	{
		std::vector<std::unique_ptr<node>> v;
		v.reserve(2);
		v.push_back(std::move(first));
		v.push_back(std::move(second));
		return node(type::op_or, std::move(v));
	}

	static node create_eq(const semver & s) { return {type::op_eq, s}; }
	static node create_lt(const semver & s) { return {type::op_lt, s}; }
	static node create_le(const semver & s) { return {type::op_le, s}; }
	static node create_gt(const semver & s) { return {type::op_gt, s}; }
	static node create_ge(const semver & s) { return {type::op_ge, s}; }

	bool eval(const semver & v) const noexcept
	{
		switch (type_) {
			case type::op_and:
				// shortcut behavior
				for (const auto & n : nodes_)
					if (!n->eval(v))
						return false;
				return true;

			case type::op_or:
				// shortcut behavior
				for (const auto & n : nodes_)
					if (n->eval(v))
						return true;
				return false;

			case type::op_eq:
				return v == *version_;
			case type::op_lt:
				return v < *version_;
			case type::op_le:
				return v <= *version_;
			case type::op_gt:
				return v > *version_;
			case type::op_ge:
				return v >= *version_;
		}
		return false;
	}

	bool is_leaf() const noexcept { return nodes_.empty(); }
	type get_type() const noexcept { return type_; }
	bool has_version() const noexcept { return version_.has_value(); }
	const semver & get_version() const { return *version_; }

	friend std::vector<std::unique_ptr<node>>::const_iterator begin(const node & n)
	{
		return cbegin(n.nodes_);
	}

	friend std::vector<std::unique_ptr<node>>::const_iterator end(const node & n)
	{
		return cend(n.nodes_);
	}

	template <typename Visitor> void visit_postfix(Visitor v) const
	{
		for (const auto & n : nodes_)
			n->visit_postfix(v);
		v(*this);
	}

	template <typename Visitor> void visit_prefix(Visitor v) const
	{
		v(*this);
		for (const auto & n : nodes_)
			n->visit_prefix(v);
	}

	friend bool operator==(const node & a, const node & b)
	{
		return (a.type_ == b.type_) && (a.version_ == b.version_)
			&& (a.nodes_.size() == b.nodes_.size())
			&& std::equal(begin(a.nodes_), end(a.nodes_), begin(b.nodes_),
				[](const auto & x, const auto & y) { return *x == *y; });
	}

	friend bool operator!=(const node & a, const node & b) { return !(a == b); }

	// This is not an operator, because it has a special semantic in regards
	// of comparing elements of non-leaf nodes. This function is for soring nodes.
	static bool less(const node & a, const node & b)
	{
		if (a.is_leaf() && b.is_leaf())
			return *a.version_ < *b.version_;
		if (a.is_leaf() && !b.is_leaf())
			return true;
		if (!a.is_leaf() && b.is_leaf())
			return false;
		if (!a.is_leaf() && !b.is_leaf()) {
			if (a.nodes_.size() != b.nodes_.size())
				return false;

			// less if one element is less than the corresponding element
			return compare_seq_if(begin(a.nodes_), end(a.nodes_), begin(b.nodes_),
				[](const auto & x, const auto & y) { return node::less(*x, *y); });
		}
		return false;
	}

private:
	type type_;
	std::optional<semver> version_;
	std::vector<std::unique_ptr<node>> nodes_;

	node(type t, const semver & s)
		: type_(t)
		, version_(s)
	{
	}

	node(type t, std::vector<std::unique_ptr<node>> && v)
		: type_(t)
		, nodes_(std::move(v))
	{
		std::sort(begin(nodes_), end(nodes_),
			[](const auto & a, const auto & b) { return node::less(*a, *b); });
	}

	template <typename Iterator, typename Cmp>
	static bool compare_seq_if(Iterator first_1, Iterator last_1, Iterator first_2, Cmp cmp)
	{
		for (; first_1 != last_1; ++first_1, ++first_2)
			if (cmp(*first_1, *first_2))
				return true;
		return false;
	}

	friend void collect_leafs_and_andnodes(std::vector<std::unique_ptr<node>> &, node &);
};

inline std::string to_string(const node::type t)
{
	switch (t) {
		case node::type::op_and:
			return "&&";
		case node::type::op_or:
			return "||";
		case node::type::op_eq:
			return "=";
		case node::type::op_lt:
			return "<";
		case node::type::op_le:
			return "<=";
		case node::type::op_gt:
			return ">";
		case node::type::op_ge:
			return ">=";
	}
	return {};
}

inline std::ostream & operator<<(std::ostream & os, const node::type t)
{
	return os << to_string(t);
}

inline std::string to_string(const node & n)
{
	if (n.is_leaf())
		return to_string(n.get_type()) + to_string(n.get_version());

	std::string s;
	bool first = true;
	for (const auto & c : n) {
		if (first) {
			first = false;
		} else {
			s += ' ';
		}

		s += to_string(*c);
	}
	return s;
}

inline std::ostream & operator<<(std::ostream & os, const node & n)
{
	return os << to_string(n);
}

inline semver lower_bound(const node & n)
{
	switch (n.get_type()) {
		case node::type::op_eq:
			return n.get_version();
		case node::type::op_lt:
			return semver::min();
		case node::type::op_le:
			return semver::min();
		case node::type::op_gt:
			return successor(n.get_version());
		case node::type::op_ge:
			return n.get_version();
		case node::type::op_and:
			break;
		case node::type::op_or:
			break;
	}
	return {};
}

inline semver upper_bound(const node & n)
{
	switch (n.get_type()) {
		case node::type::op_eq:
			return n.get_version();
		case node::type::op_lt:
			return predecessor(n.get_version());
		case node::type::op_le:
			return n.get_version();
		case node::type::op_gt:
			return semver::max();
		case node::type::op_ge:
			return semver::max();
		case node::type::op_and:
			break;
		case node::type::op_or:
			break;
	}
	return {};
}

inline void collect_leafs_and_andnodes(std::vector<std::unique_ptr<node>> & v, node & n)
{
	assert(n.get_type() == node::type::op_or);

	for (auto && p : n.nodes_) {
		if (p->get_type() == node::type::op_or) {
			collect_leafs_and_andnodes(v, *p);
		} else if (p->get_type() == node::type::op_and) {
			v.push_back(std::move(p));
		} else {
			v.push_back(std::move(p));
		}
	}
}
}
}
}

#endif
