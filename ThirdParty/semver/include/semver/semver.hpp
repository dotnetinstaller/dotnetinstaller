#ifndef SERMVER_SEMVER_HPP
#define SERMVER_SEMVER_HPP

#include <iosfwd>
#include <string>

#include <semver/glibc-bugfix.hpp> // must be included last


namespace semver
{
inline namespace v1
{
// Implementation of semver 2.0.0
//
class semver final
{
public:
	using number_type = unsigned long;

	~semver() = default;

	semver(const semver &) = default;
	semver & operator=(const semver &) = default;

	semver(semver &&) = default;
	semver & operator=(semver &&) = default;

	semver() = default;

	semver(const std::string & s, bool loose = false);

	semver(number_type major, number_type minor, number_type patch);
	semver(number_type major, number_type minor, number_type patch,
		const std::string & prerelease);
	semver(number_type major, number_type minor, number_type patch,
		const std::string & prerelease, const std::string & build);

	number_type major() const noexcept { return major_; }
	number_type minor() const noexcept { return minor_; }
	number_type patch() const noexcept { return patch_; }
	const std::string & build() const noexcept { return build_; }
	const std::string & prerelease() const noexcept { return prerelease_; }

	bool ok() const noexcept { return good_; }
	explicit operator bool() const noexcept { return ok(); }

	std::string str() const;

	static semver invalid() noexcept;
	static semver min() noexcept;
	static semver max() noexcept;

private:
	number_type major_ = {};
	number_type minor_ = {};
	number_type patch_ = {};
	std::string prerelease_ = {};
	std::string build_ = {};

	bool good_ = false;

	std::string render() const;
};

std::string to_string(const semver & v);
std::ostream & operator<<(std::ostream & os, const semver & v);

bool operator==(const semver & v1, const semver & v2) noexcept;
bool operator!=(const semver & v1, const semver & v2) noexcept;
bool operator<(const semver & v1, const semver & v2) noexcept;
bool operator<=(const semver & v1, const semver & v2) noexcept;
bool operator>(const semver & v1, const semver & v2) noexcept;
bool operator>=(const semver & v1, const semver & v2) noexcept;
int compare(const semver & v1, const semver & v2) noexcept;
}
}

#endif
