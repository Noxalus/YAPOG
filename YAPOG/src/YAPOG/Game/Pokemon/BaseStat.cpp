#include "YAPOG/Game/Pokemon/BaseStat.hpp"

namespace yap
{
  const UInt16 BaseStat::INITIAL_STAT_VALUE = 0;
  const UInt16 BaseStat::INITIAL_INDIVIDUAL_VALUE = 0;
  const UInt16 BaseStat::INITIAL_EFFORT_VALUE = 1;

  BaseStat::BaseStat ()
  {
    value_ = INITIAL_STAT_VALUE;
    individualValue_ = INITIAL_INDIVIDUAL_VALUE;
    effortValue_ = INITIAL_EFFORT_VALUE;
  }

  BaseStat::BaseStat (const UInt16& value)
    : value_ (value)
  {
    individualValue_ = INITIAL_INDIVIDUAL_VALUE;
    effortValue_ = INITIAL_EFFORT_VALUE;
  }

  BaseStat::BaseStat (const UInt16& value, const UInt16& iv, const UInt16& ev)
    : value_ (value)
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

} // namespace yap