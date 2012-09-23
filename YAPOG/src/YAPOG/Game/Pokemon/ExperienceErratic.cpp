#include "YAPOG/Game/Pokemon/ExperienceErratic.hpp"
#include "YAPOG/System/MathHelper.hpp"

namespace yap
{
  ExperienceErratic::ExperienceErratic ()
  {
  }

  UInt32 ExperienceErratic::ComputeExperienceFromLevel (
    const UInt16& level) const
  {
    float value = 0;

    if (level <= 50)
    {
      value = (MathHelper::Pow (level, 3) * 
        (100 - level)) / 50.f;
    }
    else if (level <= 68)
    {
      value = (MathHelper::Pow (level, 3) * 
        (150 - level)) / 100.f;
    }
    else if (level <= 98)
    {
      value = (MathHelper::Pow (level, 3) * 
        MathHelper::Floor ((1911 - (10 * level)) / 3.f)) / 500.f;
    }
    else
    {
      value = (MathHelper::Pow (level, 3) * 
      (160 - level)) / 100.f;
    }

    return value;
  }

} // namespace yap
