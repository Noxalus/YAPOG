#include "YAPOG/Game/Pokemon/BaseStat.hpp"
#include "YAPOG/System/MathHelper.hpp"
#include "YAPOG/System/RandomHelper.hpp"

namespace yap
{
  const UInt16 BaseStat::INITIAL_STAT_VALUE = 0;
  const UInt16 BaseStat::INITIAL_EFFORT_VALUE = 1;

  BaseStat::BaseStat ()
    : value_ (INITIAL_STAT_VALUE)
    , effortValue_ (INITIAL_EFFORT_VALUE)
  {   
    individualValue_ = RandomHelper::GetNext (0, 32);
  }

  BaseStat::BaseStat (
    const UInt16& ev,
    const UInt16& iv)
    : value_ (INITIAL_STAT_VALUE)
    , individualValue_ (iv)
    , effortValue_ (ev)
  {
  }

  const UInt16& BaseStat::GetValue () const
  {
    return value_;
  }


  const UInt16& BaseStat::GetIndividualValue () const
  {
    return individualValue_;
  }

  const UInt16& BaseStat::GetEffortValue () const
  {
    return effortValue_;
  }

  void BaseStat::SetValue (const UInt16& value)
  {
    value_ = value;
  }

  void BaseStat::SetIndividualValue (const UInt16& iv)
  {
    individualValue_ = iv;
  }

  void BaseStat::SetEffortValue (const UInt16& ev)
  {
    effortValue_ = ev;
  }

  void BaseStat::ComputeValue (const int& base, const UInt16 level)
  {
    UInt16 result = MathHelper::Floor ((((individualValue_ + (2 * base) + 
      MathHelper::Floor (effortValue_ / 4) + 100) * level) / 100)) + 10;

    SetValue (result);
  }

  void BaseStat::AddValue (int value)
  {
    value_ += value;
  }

  void BaseStat::ComputeValue (
    const int& base, 
    const UInt16 level, 
    const float& natureFactor)
  {
    UInt16 result = MathHelper::Floor (((individualValue_ + (2 * base) + 
      MathHelper::Floor (effortValue_ / 4)) * level) / 100) + 5;

    result = MathHelper::Floor (result * natureFactor);

    SetValue (result);
  }

} // namespace yap