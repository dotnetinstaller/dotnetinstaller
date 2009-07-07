#pragma once

template<class T>
class StringUtilImpl
{
public:

	static std::basic_string<T> replace(const std::basic_string<T>& s_in, const std::basic_string<T>& from, const std::basic_string<T>& to) 
	{
		std::basic_string<T> s(s_in);
		int ii = 0;
		int result = 0; // \todo: return number of replacements
		
		if (s.length() != 0 && from.length() != 0)
		{
			while ((ii = s.find(from, ii)) != s.npos) 
			{
				s.replace(ii, from.length(), to);
				ii += (abs((int)(to.length() - from.length())) + 1);
				result ++;
			}
		}
		return s;
	}

	static std::vector<std::basic_string<T>> split(const std::basic_string<T>& ss, const std::basic_string<T>& delim, int max) 
	{
		std::vector<std::basic_string<T>> tokens;
		int begin = 0, end = 0;
		std::basic_string<T> temp;

		if (max == 1 || delim.empty()) 
		{
			throw std::exception("Invalid parameter");
		}

		temp = ss;

		while ( (end = temp.find(delim)) != std::basic_string<T>::npos )
		{			
			tokens.push_back( temp.substr(0, end) );
			begin = end + delim.length();
			temp = temp.substr(begin, temp.length() - begin);

			if (tokens.size() + 1 == max) 
				break;
		}

		tokens.push_back(temp);
		return tokens;
	}

	static std::basic_string<T> join(const std::vector<std::basic_string<T>>& tokens, const std::basic_string<T>& delim) 
	{
        std::basic_string<T> ss;
				
		for (unsigned int i = 0; i < tokens.size(); i++)
		{
			if (i > 0) ss.append(delim);
			ss.append(tokens[i]);
		}

        return ss;
	}

	static std::basic_string<T> join(const std::list<std::basic_string<T>>& tokens, const std::basic_string<T>& delim) 
	{
        std::basic_string<T> ss;
        
        int i = 0;
		for each (const std::basic_string<T>& token in tokens)
		{
			if (i > 0) ss.append(delim);
			ss.append(token);
            i++;
		}

        return ss;
	}

	static std::basic_string<T> trimleft(const std::basic_string<T>& ss_in, const std::basic_string<T>& whitespaces) 
	{
		std::basic_string<T> ss(ss_in);
		ss.erase(0, ss.find_first_not_of(whitespaces));
		return ss;
	}

	static std::basic_string<T> trimright(const std::basic_string<T>& ss_in, const std::basic_string<T>& whitespaces) 
	{
		std::basic_string<T> ss(ss_in);
		ss.erase(ss.find_last_not_of(whitespaces) + 1);
		return ss;
	}

	static std::basic_string<T> trim(const std::basic_string<T>& ss, const std::basic_string<T>& whitespaces) 
	{
		return trimleft(trimright(ss, whitespaces), whitespaces);
	}

	static bool startswith(const std::basic_string<T>& what, const std::basic_string<T>& with) 
	{
		if (what.length() < with.length())
			return false;
		if (what.substr(0, with.length()) == with)
			return true;
		return false;
	}
   
	static bool endswith(const std::basic_string<T>& what, const std::basic_string<T>& with) 
	{
		if (what.length() < with.length())
			return false;
		if (what.substr(what.length() - with.length(), what.length()) == with)
			return true;
		return false;
	}
};
