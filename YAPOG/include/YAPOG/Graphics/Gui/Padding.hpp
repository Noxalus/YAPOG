#ifndef YAPOG_PADDING_HPP
# define YAPOG_PADDING_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"

namespace yap
{
  class YAPOG_LIB Padding
  {
  public:
    Padding (uint l, uint r, uint b, uint t)
      : left (l), right (r), bottom (b), top (t)
    {
    }

    Padding ()
      : left (0), right (0), bottom (0), top (0)
    {
    }

    uint left;
    uint right;
    uint bottom;
    uint top;
  };
} //namespace yap

#endif /* YAPOG_PADDING_HPP! */
