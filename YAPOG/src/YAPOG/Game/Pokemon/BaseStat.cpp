#include "YAPOG/Game/Pokemon/BaseStat.hpp"

namespace yap
{
  const UInt16 BaseStat::INITIAL_STAT_VALUE = 0;
  const UInt16 BaseStat::INITIAL_INDIVIDUAL_VALUE = 0;
  const UInt16 BaseStat::INITIAL_EFFORT_VALUE = 0;

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

  UInt16 BaseStat::GetValue ()
  {
    return value_;
  }
} // namespace yap