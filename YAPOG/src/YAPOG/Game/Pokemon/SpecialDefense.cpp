#include "YAPOG/Game/Pokemon/SpecialDefense.hpp"

namespace yap
{
  SpecialDefense::SpecialDefense ()
  {
  }

  SpecialDefense::SpecialDefense (const UInt16& ev, const UInt16& iv)
    : BaseStat (ev, iv)
  {
  }
} // namespace yap