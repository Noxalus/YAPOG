#ifndef YAPOG_ATTACK_HPP
# define YAPOG_ATTACK_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/BaseStat.hpp"

namespace yap
{
  class YAPOG_LIB Attack : public BaseStat
  {
  public:
    Attack ();
    Attack (const UInt16& ev, const UInt16& iv);
    Attack (const UInt16& iv);
  };
} // namespace yap

#endif // YAPOG_ATTACK_HPP
