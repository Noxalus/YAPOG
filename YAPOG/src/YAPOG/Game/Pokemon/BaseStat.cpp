#include "YAPOG/Game/Pokemon/BaseStat.hpp"

namespace yap
{
  const UInt16 BaseStat::INITIAL_STAT_VALUE = 50;

  BaseStat::BaseStat ()
  {
    value_ = INITIAL_STAT_VALUE;
  }

  BaseStat::BaseStat (UInt16 value)
    : value_ (value)
  {
  }

  UInt16 BaseStat::GetValue ()
  {
    return value_;
  }
} // namespace yap