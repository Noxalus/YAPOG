#ifndef YAPOG_STRINGHELPER_HXX
# define YAPOG_STRINGHELPER_HXX

# include <sstream>

# include <boost/lexical_cast.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Direction.hpp"
# include "YAPOG/System/Error/Exception.hpp"
# include "YAPOG/Game/World/Map/Direction.hpp"
# include "YAPOG/Game/Pokemon/ExperienceType.hpp"

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
    return Trim(str);
  }

  template <typename T>
  inline String StringHelper::Rtrim(const T& s)
  {
    String str = s;
    return Rtrim(str);
  }

  template <typename T>
  inline String StringHelper::Ltrim(const T& s)
  {
    String str = s;
    return Ltrim(str);
  }
  
  template <typename T>
  inline T StringHelper::Parse (const String& str)
  {
    return boost::lexical_cast <T> (str);
  }

  template <>
  inline String StringHelper::ToString<Direction> (const Direction& value)
  {
    switch (value)
    {
    case Direction::North: return "North";
    case Direction::NorthEast: return "NorthEast";
    case Direction::East: return "East";
    case Direction::SouthEast: return "SouthEast";
    case Direction::South: return "South";
    case Direction::SouthWest: return "SouthWest";
    case Direction::West: return "West";
    case Direction::NorthWest: return "NorthWest";
    default: YAPOG_THROW("Not a valid direction.");
    }
  }

  template <>
  inline Direction StringHelper::Parse<Direction> (const String& str)
  {
    if (str == "North") return Direction::North;
    if (str == "NorthEast") return Direction::NorthEast;
    if (str == "East") return Direction::East;
    if (str == "SouthEast") return Direction::SouthEast;
    if (str == "South") return Direction::South;
    if (str == "SouthWest") return Direction::SouthWest;
    if (str == "West") return Direction::West;
    if (str == "NorthWest") return Direction::NorthWest;
    YAPOG_THROW("Not a valid direction: " + str);
  }

  template <>
  inline ExperienceType StringHelper::Parse<ExperienceType> (const String& str)
  {
    if (str == "Slow") return ExperienceType::Slow;
    if (str == "MediumSlow") return ExperienceType::MediumSlow;
    if (str == "MediumFast") return ExperienceType::MediumFast;
    if (str == "Fast") return ExperienceType::Fast;
    if (str == "Fluctuating") return ExperienceType::Fluctuating;
    if (str == "Erratic") return ExperienceType::Erratic;
    YAPOG_THROW("Not a valid experience type: " + str);
  }
} // namespace yap

#endif // YAPOG_STRINGHELPER_HXX
