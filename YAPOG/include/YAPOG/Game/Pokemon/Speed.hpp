#ifndef YAPOG_SPEED_HPP
# define YAPOG_SPEED_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/BaseStat.hpp"

namespace yap
{
  class YAPOG_LIB Speed : public BaseStat
  {
    public:
      Speed ();
      Speed (UInt16 value);
  };
} // namespace yap

#endif // YAPOG_SPEED_HPP
