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
      Speed (const UInt16& ev, const UInt16& iv);
      Speed (const UInt16& iv);
  };
} // namespace yap

#endif // YAPOG_SPEED_HPP
