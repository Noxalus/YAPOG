#ifndef YAPOG_DIRECTION_HPP
# define YAPOG_DIRECTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"

namespace yap
{
  enum class YAPOG_LIB Direction : uchar
  {
      North = 0,
      NorthEast = 1,
      East = 2,
      SouthEast = 3,
      South = 4,
      SouthWest = 5,
      West = 6,
      NorthWest = 7
  };
} // namespace yap

#endif // YAPOG_DIRECTION_HPP
