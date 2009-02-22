#pragma once

#include "StringUtil.h"

namespace DVLib
{
    inline void split_string(
        const stlstring & str,
        char delimitter,
        stlvectorstring & ret,
        int max = 0
        )
    {
        stlstring::size_type delim;
        stlstring::size_type prev_delim = 0;
        ret.clear();

        while ((max == 0 || ret.size() + 1 < max) && (stlstring::npos != (delim = str.find_first_of(delimitter,prev_delim))))
        {
            ret.push_back(str.substr(prev_delim, delim - prev_delim));
            prev_delim = delim + 1;
        }

        // get the tail after the last separator
        ret.push_back(str.substr(prev_delim));
    }
}