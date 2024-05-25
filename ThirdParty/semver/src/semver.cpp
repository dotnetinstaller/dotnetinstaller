#include <semver/semver.hpp>
#include "detail/semver_parser.hpp"
#include <functional>
#include <limits>
#include <ostream>

namespace semver
{
inline namespace v1
{
semver::semver(const std::string & s, bool loose)
{
	const auto p = detail::semver_parser(s, loose);
	good_ = p.ok();
	if (good_) {
		major_ = p.major();
		minor_ = p.minor();
		patch_ = p.patch();
		build_ = p.build();
		prerelease_ = p.prerelease();
	}
}

semver::semver(number_type major, number_type minor, number_type patch)
	: major_(major)
	, minor_(minor)
	, patch_(patch)
	, good_(true)
{
}

semver::semver(
	number_type major, number_type minor, number_type patch, const std::string & prerelease)
	: major_(major)
	, minor_(minor)
	, patch_(patch)
	, prerelease_(prerelease)
	, good_(prerelease_.empty())
{
	if (!good_)
		good_ = detail::semver_parser(major_, minor_, patch_, prerelease_).ok();
}

semver::semver(number_type major, number_type minor, number_type patch,
	const std::string & prerelease, const std::string & build)
	: major_(major)
	, minor_(minor)
	, patch_(patch)
	, prerelease_(prerelease)
	, build_(build)
	, good_(prerelease_.empty() && build_.empty())
{
	if (!good_)
		good_ = detail::semver_parser(major_, minor_, patch_, prerelease_, build_).ok();
}

std::string semver::str() const
{
	return (!ok()) ? "<invalid>" : render();
}

semver semver::invalid() noexcept
{
	return semver();
}

semver semver::min() noexcept
{
	return semver(0u, 0u, 0u);
}

semver semver::max() noexcept
{
	return semver(std::numeric_limits<number_type>::max(),
		std::numeric_limits<number_type>::max(), std::numeric_limits<number_type>::max());
}

std::string semver::render() const
{
	using std::to_string;
	auto s = to_string(major()) + '.' + to_string(minor()) + '.' + to_string(patch());
	const auto pr = prerelease();
	const auto b = build();
	if (!pr.empty() || !b.empty()) {
		s.reserve(s.size() + pr.size() + (!!pr.size()) + b.size() + (!!b.size()));
		if (!pr.empty()) {
			s += '-';
			s.append(pr.data(), pr.size());
		}
		if (!b.empty()) {
			s += '+';
			s.append(b.data(), b.size());
		}
	}
	return s;
}

std::string to_string(const semver & v)
{
	return v.str();
}

std::ostream & operator<<(std::ostream & os, const semver & v)
{
	return os << to_string(v);
}

bool operator==(const semver & v1, const semver & v2) noexcept
{
	return (v1.major() == v2.major()) && (v1.minor() == v2.minor())
		&& (v1.patch() == v2.patch()) && (v1.prerelease() == v2.prerelease());
}

bool operator!=(const semver & v1, const semver & v2) noexcept
{
	return !(v1 == v2);
}

bool operator<(const semver & v1, const semver & v2) noexcept
{
	// major, minor and patch are first priority to compare in descending order. if one
	// of them is different, it is already decided.
	if (v1.major() < v2.major())
		return true;
	if (v1.major() > v2.major())
		return false;

	if (v1.minor() < v2.minor())
		return true;
	if (v1.minor() > v2.minor())
		return false;

	if (v1.patch() < v2.patch())
		return true;
	if (v1.patch() > v2.patch())
		return false;

	const auto p1 = v1.prerelease();
	const auto p2 = v2.prerelease();

	// if one has a prerelease the other not, the one with is smaller
	if (!p1.empty() && p2.empty())
		return true;
	if (p1.empty() && !p2.empty())
		return false;

	// compare fields of prerelease individually, separated by '.'
	// rules from semver.org, literally or shortened:
	//
	//   - pure numerically are compared numerically
	//   - alphanumeric are compared lexically
	//   - pure numerically has always lower precedence than alphanumerically
	//   - larger set of fields has a higher precedence than the smaller set, if all of
	//     preceeding identifiers are equal, example:
	//     1.0.0-alpha < 1.0.0-alpha.1 < 1.0.0-alpha.beta < 1.0.0-beta < 1.0.0-beta.2
	//     < 1.0.0-beta.11 < 1.0.0-rc.1 < 1.0.0
	//
	std::string::size_type c1 = 0u;
	std::string::size_type c2 = 0u;
	for (;;) {

		const auto c1e = p1.find('.', c1);
		const auto c2e = p2.find('.', c2);

		// numerical vs alphanumerical fields? alphanumerical alwasys wins
		auto find_alpha_in_substr = [](const std::string & s, auto start_pos, auto end_pos) {
			const auto sub = s.substr(start_pos, end_pos);
			return std::find_if(begin(sub), end(sub), std::not_fn(::isdigit)) == end(sub);
		};

		const bool c1num = find_alpha_in_substr(p1, c1, c1e);
		const bool c2num = find_alpha_in_substr(p2, c2, c2e);
		if (c1num && !c2num)
			return true;
		if (!c1num && c2num)
			return false;

		if (c1num && c2num) {
			// pure numerical comparison

			semver::number_type p1n = 0u;
			semver::number_type p2n = 0u;

			// we ignore the return value because it was already tested to be numerical only
			std::from_chars(p1.data() + c1, p1.data() + std::min(c1e, p1.size()), p1n);
			std::from_chars(p2.data() + c2, p2.data() + std::min(c2e, p2.size()), p2n);

			if (p1n < p2n)
				return true;
			if (p1n > p2n)
				return false;
		} else {
			// alphanumerical comparison

			const auto rc = p1.compare(c1, c1e - c1, p2, c2, c2e - c2);
			if (rc < 0)
				return true;
			if (rc > 0)
				return false;
		}

		// compare number of fields, unil now all fields were the same, the one with
		// more fields is the higher version
		if ((c1e != std::string::npos) && (c2e == std::string::npos))
			return false; // p1 has more fields
		if ((c1e == std::string::npos) && (c2e != std::string::npos))
			return true; // p2 has more fields
		if ((c1e == std::string::npos) && (c2e == std::string::npos))
			return false; // both exhausted

		// all were the same until now, on to the next field
		c1 = c1e + 1u;
		c2 = c2e + 1u;
	}
}

bool operator<=(const semver & v1, const semver & v2) noexcept
{
	return (v1 == v2) || (v1 < v2);
}

bool operator>(const semver & v1, const semver & v2) noexcept
{
	return !(v1 <= v2);
}

bool operator>=(const semver & v1, const semver & v2) noexcept
{
	return !(v1 < v2);
}

int compare(const semver & v1, const semver & v2) noexcept
{
	return (v1 == v2) ? 0 : (v1 < v2) ? -1 : +1;
}
}
}

