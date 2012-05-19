#include "YAPOG/Game/Pokemon/HitPoint.hpp"

namespace yap
{
  const UInt16 HitPoint::INITIAL_CURRENT_VALUE = 0;

  HitPoint::HitPoint ()
  {
    currentValue_ = INITIAL_CURRENT_VALUE;
  }

  HitPoint::HitPoint (UInt16 value)
    : BaseStat (value)
  {
    currentValue_ = INITIAL_CURRENT_VALUE;
  }

  const UInt16& HitPoint::GetCurrentValue () const
  {
    return currentValue_;
  }

  void HitPoint::SetCurrentValue (const UInt16& value)
  {
    currentValue_ = value;
  }

  void HitPoint::SetValue (const UInt16& value)
  {
    value_ = value;

    if (currentValue_ == INITIAL_CURRENT_VALUE)
      currentValue_ = value;
  }

} // namespace yap
