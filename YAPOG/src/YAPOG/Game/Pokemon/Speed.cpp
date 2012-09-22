#include "YAPOG/Game/Pokemon/Speed.hpp"

namespace yap
{
  Speed::Speed ()
  {
  }

  Speed::Speed (const UInt16& ev, const UInt16& iv)
    : BaseStat (ev, iv)
  {
  }

  Speed::Speed (const UInt16& iv)
    : BaseStat (iv)
  {
  }

} // namespace yap
