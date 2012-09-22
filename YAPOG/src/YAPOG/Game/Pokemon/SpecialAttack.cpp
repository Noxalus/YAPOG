#include "YAPOG/Game/Pokemon/SpecialAttack.hpp"

namespace yap
{
  SpecialAttack::SpecialAttack ()
  {
  }

  SpecialAttack::SpecialAttack (const UInt16& ev, const UInt16& iv)
    : BaseStat (ev, iv)
  {
  }

  SpecialAttack::SpecialAttack (const UInt16& iv)
    : BaseStat (iv)
  {
  }

} // namespace yap
