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
  inline T StringHelper::Parse (const String& str)
  {
    return boost::lexical_cast <T> (str);
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
