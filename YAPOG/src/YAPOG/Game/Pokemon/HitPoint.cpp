#include "YAPOG/Game/Pokemon/HitPoint.hpp"
#include "YAPOG/System/MathHelper.hpp"

namespace yap
{
  const UInt16 HitPoint::INITIAL_CURRENT_VALUE = 0;

  HitPoint::HitPoint ()
    : currentValue_ (INITIAL_CURRENT_VALUE)
  {
  }

  HitPoint::HitPoint (
    const UInt16& currentValue, 
    const UInt16& ev, 
    const UInt16& iv)
    : BaseStat (ev, iv)
    , currentValue_ (currentValue)
  {
  }

  HitPoint::HitPoint (const UInt16& iv)
    : BaseStat (iv)
    , currentValue_ (INITIAL_CURRENT_VALUE)
  {
  }

  UInt16 HitPoint::GetCurrentValue () const
  { return currentValue_; }

  float HitPoint::GetHPPercentage () const
  {
    return (static_cast<float>(currentValue_) / static_cast<float>(value_));
  }

  void HitPoint::SetCurrentValue (const UInt16& value)
  {
    currentValue_ = MathHelper::Clamp 
      (value, INITIAL_CURRENT_VALUE, value_);
  }

  void HitPoint::Restore ()
  {
    currentValue_ = value_;
  }

} // namespace yap
