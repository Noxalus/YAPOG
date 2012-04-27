#ifndef YAPOG_SPECIALATTACK_HPP
# define YAPOG_SPECIALATTACK_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/BaseStat.hpp"

namespace yap
{
  class YAPOG_LIB SpecialAttack : public BaseStat
  {
    DISALLOW_COPY (SpecialAttack);

    public:
      SpecialAttack ();
      SpecialAttack (UInt16 value);
  };
} // namespace yap

#endif // YAPOG_SPECIALATTACK_HPP
