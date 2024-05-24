#ifndef SEMVER_DETAIL_SEMVER_PARSER_HPP
#define SEMVER_DETAIL_SEMVER_PARSER_HPP

#include <algorithm>
#include <charconv>
#include <string>

#include <semver/glibc-bugfix.hpp> // must be included last


namespace semver
{
inline namespace v1
{
class semver; // forward

namespace detail
{
class semver_parser final
{
	friend class ::semver::v1::semver;
public:
	using number_type = unsigned long;

	static number_type ston(const std::string & s) { return std::stoul(s); }

	semver_parser(const std::string & s, bool loose = false)
		: data_(s)
	{
		if (loose) {
			data_.erase(std::remove_if(begin(data_), end(data_), ::isspace), end(data_));
			data_.erase(begin(data_), std::find_if(begin(data_), end(data_), ::isdigit));
		}

		last_ = data_.data() + data_.size();
		cursor_ = data_.data();

		if (!data_.empty()) {
			parse_valid_semver();
			good_ = (cursor_ == last_) && !error_;
		}
	}

	semver_parser(
		number_type major, number_type minor, number_type patch, const std::string & prerelease)
		: major_(major)
		, minor_(minor)
		, patch_(patch)
		, prerelease_(prerelease)
		, good_(prerelease_.empty())
	{
		if (!good_)
			good_ = only_parse_prerelease();
	}

	semver_parser(number_type major, number_type minor, number_type patch,
		const std::string & prerelease, const std::string & build)
		: major_(major)
		, minor_(minor)
		, patch_(patch)
		, prerelease_(prerelease)
		, build_(build)
		, good_(prerelease_.empty() && build_.empty())
	{
		if (!good_) {
			good_ = true;
			if (!prerelease_.empty())
				good_ &= only_parse_prerelease();
			if (!build_.empty())
				good_ &= only_parse_build();
		}
	}

	bool ok() const noexcept { return good_; }
	number_type major() const noexcept { return major_; }
	number_type minor() const noexcept { return minor_; }
	number_type patch() const noexcept { return patch_; }
	const std::string & build() const noexcept { return build_; }
	const std::string & prerelease() const noexcept { return prerelease_; }

private:
	using char_type = std::string::value_type;

	const char_type * last_ = {};
	const char_type * start_ = {};
	const char_type * cursor_ = {};
	const char_type * error_ = nullptr;

	number_type major_ = {};
	number_type minor_ = {};
	number_type patch_ = {};
	std::string prerelease_ = {};
	std::string build_ = {};

	std::string data_;
	bool good_ = false;

	bool only_parse_prerelease()
	{
		last_ = prerelease_.data() + prerelease_.size();
		cursor_ = prerelease_.data();
		parse_pre_release();
		return (cursor_ == last_) && !error_;
	}

	bool only_parse_build()
	{
		last_ = build_.data() + build_.size();
		cursor_ = build_.data();
		parse_build();
		return (cursor_ == last_) && !error_;
	}

	static std::string token(const char_type * start, const char_type * end) noexcept
	{
		return std::string(start, end);
	}

	void parse_valid_semver() noexcept
	{
		parse_version_core();
		if (is_dash(cursor_)) {
			advance(1);
			parse_pre_release();
			if (is_plus(cursor_)) {
				advance(1);
				parse_build();
			}
			return;
		}
		if (is_plus(cursor_)) {
			advance(1);
			parse_build();
			return;
		}
	}

	void advance(int n) noexcept { cursor_ += std::min(n, static_cast<int>(last_ - cursor_)); }

	void error() noexcept { error_ = cursor_; }

	void parse_version_core() noexcept
	{
		parse_major();
		parse_dot();
		parse_minor();
		parse_dot();
		parse_patch();
	}

	void parse_major() noexcept
	{
		start_ = cursor_;
		parse_numeric_identifier();
		std::from_chars(start_, cursor_, major_);
	}

	void parse_minor() noexcept
	{
		start_ = cursor_;
		parse_numeric_identifier();
		std::from_chars(start_, cursor_, minor_);
	}

	void parse_patch() noexcept
	{
		start_ = cursor_;
		parse_numeric_identifier();
		std::from_chars(start_, cursor_, patch_);
	}

	void parse_dot() noexcept
	{
		if (is_dot(cursor_)) {
			advance(1);
			return;
		}
		error();
	}

	void parse_build() noexcept
	{
		start_ = cursor_;
		parse_dot_separated_identifier();
		build_ = token(start_, cursor_);
	}

	void parse_pre_release() noexcept
	{
		start_ = cursor_;
		parse_dot_separated_identifier();
		prerelease_ = token(start_, cursor_);
	}

	void parse_dot_separated_identifier() noexcept
	{
		parse_identifier();
		while (is_dot(cursor_)) {
			parse_dot();
			parse_identifier();
		}
	}

	void parse_identifier() noexcept
	{
		if (!(is_letter(cursor_) || is_digit(cursor_) || is_dash(cursor_))) {
			error();
			return;
		}
		while (is_letter(cursor_) || is_digit(cursor_) || is_dash(cursor_))
			advance(1);
	}

	void parse_numeric_identifier() noexcept
	{
		if (is_zero(cursor_)) {
			advance(1);
			return;
		}
		if (is_positive_digit(cursor_)) {
			parse_positive_digit();
			if (is_digit(cursor_))
				parse_digits();
			return;
		}
		error();
	}

	void parse_positive_digit() noexcept
	{
		if (is_positive_digit(cursor_)) {
			advance(1);
			return;
		}
		error();
	}

	void parse_digits() noexcept
	{
		if (!is_digit(cursor_)) {
			error();
			return;
		}
		while (is_digit(cursor_))
			advance(1);
	}

	// low level primitives, must check for eof

	bool peek(char_type c, const char_type * p) const noexcept
	{
		return !is_eof(p) && (*p == c);
	}

	bool is_eof(const char_type * p) const noexcept { return (p >= last_) || (*p == '\x00'); }
	bool is_dot(const char_type * p) const noexcept { return peek('.', p); }
	bool is_plus(const char_type * p) const noexcept { return peek('+', p); }
	bool is_dash(const char_type * p) const noexcept { return peek('-', p); }
	bool is_zero(const char_type * p) const noexcept { return peek('0', p); }

	bool is_positive_digit(const char_type * p) const noexcept
	{
		return !is_eof(p) && ((*p >= '1') && (*p <= '9'));
	}

	bool is_digit(const char_type * p) const noexcept
	{
		return !is_eof(p) && ((*p >= '0') && (*p <= '9'));
	}

	bool is_letter(const char_type * p) const noexcept
	{
		return !is_eof(p) && (((*p >= 'A') && (*p <= 'Z')) || ((*p >= 'a') && (*p <= 'z')));
	}
};
}
}
}

#endif
