#include <semver/range.hpp>
#include "detail/range_node.hpp"
#include "detail/range_parser.hpp"
#include <cassert>

namespace semver
{
inline namespace v1
{
namespace detail
{
template <typename Iterator, typename Predicate>
typename Iterator::value_type satisfies_if(
	const range & r,
	Iterator first, Iterator last, Predicate pred) noexcept
{
	if (first == last)
		return {};
	bool never_checked = true;
	typename Iterator::value_type result = {};
	for (; first != last; ++first) {
		if (r.satisfies(*first)) {
			if (never_checked) {
				never_checked = false;
				result = *first;
			} else if (pred(*first, result)) {
				result = *first;
			}
		}
	}
	return result;
}
}

range::~range() { }

range::range(const std::string & s)
{
	auto p = detail::range_parser(s);
	good_ = p.ok();
	if (good_)
		nodes_ = p.ast();
}

semver range::max() const noexcept
{
	// Algorithm:
	//
	//   1. collect all min/max of 'or' nodes -> v_min, v_max
	//
	//   2. collect min/max from all 'and' nodes using (min|max)_satisfying, for all 'and':
	//      - min = min_satisfying({local min})
	//      - max = max_satisfying({local max})
	//
	//   3. determine min/max using (min|max)_satisfying from v_min/v_max and min/max from step
	//   2
	//

	std::vector<semver> v;
	for (const auto & n : nodes_) {
		if (n->is_leaf()) {
			v.emplace_back(upper_bound(*n));
		} else {
			std::vector<semver> local;
			for (const auto & m : *n)
				local.emplace_back(upper_bound(*m));
			v.push_back(max_satisfying(local));
		}
	}

	return max_satisfying(v);
}

semver range::min() const noexcept
{
	std::vector<semver> v;
	for (const auto & n : nodes_) {
		if (n->is_leaf()) {
			v.emplace_back(lower_bound(*n));
		} else {
			std::vector<semver> local;
			for (const auto & m : *n)
				local.emplace_back(lower_bound(*m));
			v.push_back(min_satisfying(local));
		}
	}

	return min_satisfying(v);
}

bool range::satisfies(const semver & v) const noexcept
{
	if (nodes_.empty())
		return false;

	// all nodes in AST are implicit `or`
	for (const auto & n : nodes_)
		if (n->eval(v))
			return true;

	return false;
}

semver range::max_satisfying(const std::vector<semver> & versions) const noexcept
{
	return detail::satisfies_if(*this, begin(versions), end(versions), std::greater<> {});
}

semver range::min_satisfying(const std::vector<semver> & versions) const noexcept
{
	return detail::satisfies_if(*this, begin(versions), end(versions), std::less<> {});
}

std::string to_string(const range & r)
{
	std::string s;
	bool first = true;
	for (const auto & n : r.nodes_) {
		if (first) {
			first = false;
		} else {
			s += " || ";
		}

		s += to_string(*n);
	}

	return s;
}

std::ostream & operator<<(std::ostream & os, const range & r)
{
	return os << to_string(r);
}

bool operator==(const range & r1, const range & r2) noexcept
{
	return std::equal(begin(r1.nodes_), end(r1.nodes_), begin(r2.nodes_), end(r2.nodes_),
		[](const auto & a, const auto & b) { return *a == *b; });
}

bool operator!=(const range & r1, const range & r2) noexcept
{
	return !(r1 == r2);
}
}
}

