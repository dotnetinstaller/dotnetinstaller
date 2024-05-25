#ifndef SEMVER_RANGE_HPP
#define SEMVER_RANGE_HPP

#include <semver/semver.hpp>
#include <memory>
#include <vector>

namespace semver
{
inline namespace v1
{
namespace detail
{
class node; // forward
}

class range final
{
public:
	~range();

	range(const range &) = default;
	range & operator=(const range &) = default;

	range(range &&) = default;
	range & operator=(range &&) = default;

	range(const std::string & s);

	bool ok() const noexcept { return good_; }
	explicit operator bool() const noexcept { return ok(); }

	semver max() const noexcept;
	semver min() const noexcept;

	bool satisfies(const semver & v) const noexcept;
	bool outside(const semver & v) const noexcept { return !satisfies(v); }

	semver max_satisfying(const std::vector<semver> & versions) const noexcept;
	semver min_satisfying(const std::vector<semver> & versions) const noexcept;

	friend bool operator==(const range & r1, const range & r2) noexcept;
	friend std::string to_string(const range &);

private:
	bool good_ = false;
	std::vector<std::unique_ptr<detail::node>> nodes_;
};

std::string to_string(const range & r);
std::ostream & operator<<(std::ostream & os, const range & r);

bool operator!=(const range & r1, const range & r2) noexcept;

bool intersect(const range &, const range &) noexcept;
}
}

#endif

