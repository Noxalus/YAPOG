#include "YAPOG/Game/Pokemon/HitPoint.hpp"

namespace yap
{
  HitPoint::HitPoint ()
  {
    currentValue_ = value_;
  }

  HitPoint::HitPoint (UInt16 value)
    : BaseStat (value)
  {
  }

  UInt16& HitPoint::GetCurrentValue ()
  {
    return currentValue_;
  }

} // namespace yap
