#pragma once

#include "StringUtil.h"

namespace DVLib
{
	inline void split_string(
							const stlstring & str,
							char delimitter,
							stlvectorstring & ret
							)
	{
		stlstring::size_type delim;
		stlstring::size_type prev_delim = 0;

		while (stlstring::npos != (delim = str.find_first_of(delimitter,prev_delim)))
		{
			ret.push_back(str.substr(prev_delim,delim-prev_delim));
			prev_delim = delim+1;
		}

		// Get the tail after the last separator
		ret.push_back(str.substr(prev_delim));
	}

}