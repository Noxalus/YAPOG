#include "YAPOG/Game/Pokemon/Defense.hpp"

namespace yap
{
  Defense::Defense ()
  {
  }

  Defense::Defense (const UInt16& ev, const UInt16& iv)
    : BaseStat (ev, iv)
  {
  }
} // namespace yap
