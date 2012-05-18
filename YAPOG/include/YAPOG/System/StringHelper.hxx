#ifndef YAPOG_STRINGHELPER_HXX
# define YAPOG_STRINGHELPER_HXX

# include <sstream>

# include "YAPOG/Macros.hpp"

namespace yap
{
	template <typename T>
	inline String StringHelper::ToString (const T& value)
	{
		std::ostringstream oss;

		oss << value;

		return oss.str ();
	}

	template <typename T>
	inline int StringHelper::CompareString(const T& s1, const T& s2)
	{
		std::string::const_iterator it1=s1.begin();
		std::string::const_iterator it2=s2.begin();

		while ((it1!=s1.end()) && (it2!=s2.end())) { 
			if(::toupper(*it1) != ::toupper(*it2)) 
					return (::toupper(*it1) < ::toupper(*it2)) ? -1 : 1; 
			++it1;
			++it2;
		}

		size_t size1=s1.size(), size2=s2.size();

		if (size1 == size2) 
			return 0;
		return (size1<size2) ? -1 : 1;
	}
} // namespace yap

#endif // YAPOG_STRINGHELPER_HXX
