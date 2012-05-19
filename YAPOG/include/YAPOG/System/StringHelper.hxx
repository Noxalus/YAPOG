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
    String::const_iterator it1 = s1.begin();
    String::const_iterator it2 = s2.begin();

    while ((it1 != s1.end()) && (it2 != s2.end())) { 
      if(::toupper(*it1) != ::toupper(*it2)) 
        return (::toupper(*it1) < ::toupper(*it2)) ? -1 : 1; 
      ++it1;
      ++it2;
    }

    size_t size1 = s1.size();
    size_t size2 = s2.size();

    if (size1 == size2) 
      return 0;
    return (size1 < size2) ? -1 : 1;
  }

  template <typename T>
  inline String& StringHelper::Ltrim(T& s)
  {
    String::iterator it = s.begin();

    while (it != s.end())
    {
      if (!isspace(*it))
        break;
      ++it;
    }

    s.erase(s.begin(), it);
    return s;
  }

  template <typename T>
  inline String& StringHelper::Rtrim(T& s)
  {
    String::reverse_iterator it = s.rbegin();

    while (it != s.rend())
    {
      if (!isspace(*it))
        break;
      ++it;
    }
    String::difference_type diff = s.rend() - it;
    s.erase(s.begin() + diff, s.end());
    return s;
  }

  template <typename T>
  inline String& StringHelper::Trim(T& s)
  {
    return Ltrim(Rtrim(s));
  }

  template <typename T>
  inline String StringHelper::Trim(const T& s)
  {
    String str = s;
    return trim(str);
  }

  template <typename T>
  inline String StringHelper::Rtrim(const T& s)
  {
    String str = s;
    return rtrim(str);
  }

  template <typename T>
  inline String StringHelper::Ltrim(const T& s)
  {
    String str = s;
    return ltrim(str);
  }
} // namespace yap

#endif // YAPOG_STRINGHELPER_HXX
