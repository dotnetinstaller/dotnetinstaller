#include "stdafx.h"
#include "VersionUtil.h"
#include "ExceptionMacros.h"
#include "StringUtil.h"
#include "FormatUtil.h"
#include "LoggerManager.h"
#include "semver200.h"

DVLib::Version DVLib::wstring2version(std::wstring version)
{
    Version result = { 0, 0, 0, 0 };

    if (!version.empty() && (version[0] == 'v' || version[0] == 'V'))
        version.erase(0, 1);

    for (size_t i = 0; i < version.length(); i++)
    {
        CHECK_BOOL(version[i] == '.' || isdigit(version[i]),
            L"Invalid version format: '" << version << L"'");
    }

    if (!version.empty())
    {
        std::vector<std::wstring> parts_l = DVLib::split(version, L".", 4);
        result.major = ((parts_l.size() >= 1) ? DVLib::wstring2long(parts_l[0]) : 0);
        result.minor = ((parts_l.size() >= 2) ? DVLib::wstring2long(parts_l[1]) : 0);
        result.build = ((parts_l.size() >= 3) ? DVLib::wstring2long(parts_l[2]) : 0);
        result.rev = ((parts_l.size() == 4) ? DVLib::wstring2long(parts_l[3]) : 0);
    }
    return result;
}

std::wstring DVLib::version2wstring(const Version& version)
{
    return DVLib::FormatMessageW(L"%d.%d.%d.%d",
        version.major, version.minor, version.build, version.rev);
}

int DVLib::CompareVersion(const std::wstring& l, const std::wstring& r)
{
    Version l_v = wstring2version(l);
    Version r_v = wstring2version(r);

    if (l_v.major < r_v.major)
        return -1;
    else if (l_v.major > r_v.major)
        return 1;

    if (l_v.minor < r_v.minor)
        return -1;
    else if (l_v.minor > r_v.minor)
        return 1;

    if (l_v.build < r_v.build)
        return -1;
    else if (l_v.build > r_v.build)
        return 1;

    if (l_v.rev < r_v.rev)
        return -1;
    else if (l_v.rev > r_v.rev)
        return 1;

    return 0;
}

int DVLib::CompareSemanticVersion(const std::wstring& l, const std::wstring& r)
{
    version::Semver200_version l_v(DVLib::wstring2string(l));
    version::Semver200_version r_v(DVLib::wstring2string(r));

    if (l_v < r_v)
        return -1;
    else if (l_v > r_v)
        return 1;

    return 0;
}

bool DVLib::CompareVersion(const std::wstring& comparison, const std::list<std::wstring>& valuesToCompare, const std::wstring& checkValue)
{
    if ((comparison == L"version")
        || (comparison == L"semver"))
    {
        for each (const std::wstring & valueToCompare in valuesToCompare)
        {
            int result = comparison == L"version" ? DVLib::CompareVersion(valueToCompare, checkValue)
                : DVLib::CompareSemanticVersion(valueToCompare, checkValue);
            if (result >= 0)
            {
                LoggerManager::Log(L"Check value '" + checkValue + L"' version matches '" + valueToCompare + L"'");
                return true;
            }
            else
            {
                LoggerManager::Log(L"Check value '" + checkValue + L"' version doesn't match '" + valueToCompare + L"'");
            }
        }

        return false;
    }
    else if ((comparison == L"version_eq")
        || (comparison == L"semver_eq"))
    {
        for each (const std::wstring & valueToCompare in valuesToCompare)
        {
            int result = comparison == L"version_eq" ? DVLib::CompareVersion(valueToCompare, checkValue)
                : DVLib::CompareSemanticVersion(valueToCompare, checkValue);
            if (result == 0)
            {
                LoggerManager::Log(L"Check value '" + checkValue + L"' version is equal to '" + valueToCompare + L"'");
                return true;
            }
            else
            {
                LoggerManager::Log(L"Check value '" + checkValue + L"' version is not equal to '" + valueToCompare + L"'");
            }
        }

        return false;
    }
    else if ((comparison == L"version_lt")
        || (comparison == L"semver_lt"))
    {
        for each (const std::wstring & valueToCompare in valuesToCompare)
        {
            int result = comparison == L"version_lt" ? DVLib::CompareVersion(valueToCompare, checkValue)
                : DVLib::CompareSemanticVersion(valueToCompare, checkValue);
            if (result < 0)
            {
                LoggerManager::Log(L"Check value '" + checkValue + L"' version lesser match with '" + valueToCompare + L"'");
                return true;
            }
            else
            {
                LoggerManager::Log(L"Check value '" + checkValue + L"' version no lesser match to '" + valueToCompare + L"'");
            }
        }

        return false;
    }
    else if ((comparison == L"version_le")
        || (comparison == L"semver_le"))
    {
        for each (const std::wstring & valueToCompare in valuesToCompare)
        {
            int result = comparison == L"version_le" ? DVLib::CompareVersion(valueToCompare, checkValue)
                : DVLib::CompareSemanticVersion(valueToCompare, checkValue);
            if (result <= 0)
            {
                LoggerManager::Log(L"Check value '" + checkValue + L"' version lesser or equal than '" + valueToCompare + L"'");
                return true;
            }
            else
            {
                LoggerManager::Log(L"Check value '" + checkValue + L"' version no lesser or equal match to '" + valueToCompare + L"'");
            }
        }

        return false;
    }
    else if ((comparison == L"version_gt")
        || (comparison == L"semver_gt"))
    {
        for each (const std::wstring & valueToCompare in valuesToCompare)
        {
            int result = comparison == L"version_gt" ? DVLib::CompareVersion(valueToCompare, checkValue)
                : DVLib::CompareSemanticVersion(valueToCompare, checkValue);
            if (result > 0)
            {
                LoggerManager::Log(L"Check value '" + checkValue + L"' version greater match to '" + valueToCompare + L"'");
                return true;
            }
            else
            {
                LoggerManager::Log(L"Check value '" + checkValue + L"' version no greater match to '" + valueToCompare + L"'");
            }
        }

        return false;
    }
    else if ((comparison == L"version_ge")
        || (comparison == L"semver_ge"))
    {
        for each (const std::wstring & valueToCompare in valuesToCompare)
        {
            int result = comparison == L"version_ge" ? DVLib::CompareVersion(valueToCompare, checkValue)
                : DVLib::CompareSemanticVersion(valueToCompare, checkValue);
            if (result >= 0)
            {
                LoggerManager::Log(L"Check value '" + checkValue + L"' version greater or equal match to '" + valueToCompare + L"'");
                return true;
            }
            else
            {
                LoggerManager::Log(L"Check value '" + checkValue + L"' version no greater or equal match to '" + valueToCompare + L"'");
            }
        }

        return false;
    }
    else
    {
        THROW_EX(L"Invalid comparison: " + comparison);
    }
}