#pragma once

namespace DVLib
{
	// convert UTF8 to UNICODE
	std::wstring UTF8string2wstring(const char * s);
	std::wstring UTF8string2wstring(const std::string& s);
	// convert ASCII to UNICODE
	std::wstring string2wstring(const std::string& s);
	std::wstring string2wstring(const char * s);
	// convert UNICODE to ASCII (CP_ACP)
	std::string wstring2string(const wchar_t * s);
	std::string wstring2string(const std::wstring& s);
	// convert UTF8 to ASCII
	std::string UTF8string2string(const char * s);
	std::string UTF8string2string(const std::string& s);

	// convert a string representation of boolean
	bool string2bool(const char *, bool defaultvalue = false);
	bool string2bool(const std::string&, bool defaultvalue = false);
	bool wstring2bool(const wchar_t *, bool defaultvalue = false);
	bool wstring2bool(const std::wstring&, bool defaultvalue = false);

	// convert a string representation of long
    long string2long(const std::string& ss, int base = 10);
    long wstring2long(const std::wstring& ss, int base = 10);

    // perform a string replace on every instance
	std::string replace(const std::string& s, const std::string& from, const std::string& to);
	std::wstring replace(const std::wstring& s, const std::wstring& from, const std::wstring& to);

    // tokenize a given string using a multi-byte delimiter
    std::vector<std::string> split(const std::string& ss, const std::string& delims, int max = -1);
    std::vector<std::wstring> split(const std::wstring& ss, const std::wstring& delims, int max = -1);

    // join a vector using a multi-byte delimiter
    std::string join(const std::vector<std::string>& tokens, const std::string& delims);
    std::wstring join(const std::vector<std::wstring>& tokens, const std::wstring& delims);
    std::string join(const std::list<std::string>& tokens, const std::string& delims);
    std::wstring join(const std::list<std::wstring>& tokens, const std::wstring& delims);

    // left trim
	std::string trimleft(const std::string& s, const std::string& whitespaces = " \t\n\r");
	std::wstring trimleft(const std::wstring& s, const std::wstring& whitespaces = L" \t\n\r");

    // right trim
	std::string trimright(const std::string& s, const std::string& whitespaces = " \t\n\r");
	std::wstring trimright(const std::wstring& s, const std::wstring& whitespaces = L" \t\n\r");

    // left and right trim
	std::string trim(const std::string& s, const std::string& whitespaces = " \t\n\r");
	std::wstring trim(const std::wstring& s, const std::wstring& whitespaces = L" \t\n\r");

    // returns true if a string starts with (case-sensitive) another string
    bool startswith(const std::string& ss, const std::string& what);
    bool startswith(const std::wstring& ss, const std::wstring& what);

    // returns true if a string ends with (case-sensitive) another string
    bool endswith(const std::string& ss, const std::string& what);
    bool endswith(const std::wstring& ss, const std::wstring& what);

    // convert any streamable data into a UNICODE string
    template<class T>
    std::wstring towstring(const T& t)
    {
	    std::wstringstream ss;
	    ss << t;
	    return ss.str();
    }

    // convert any streamable data into an ANSI string
    template<class T>
    std::string tostring(const T& t)
    {
	    std::stringstream ss;
	    ss << t;
	    return ss.str();
    }
}