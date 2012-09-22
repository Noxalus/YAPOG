#include "YAPOG/Game/Pokemon/Attack.hpp"

namespace yap
{
  Attack::Attack ()
  {
  }

  Attack::Attack (const UInt16& ev, const UInt16& iv)
    : BaseStat (ev, iv)
  {
  }

  Attack::Attack (const UInt16& iv)
    : BaseStat (iv)
  {
  }

} // namespace yap
