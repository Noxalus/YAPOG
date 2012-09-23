#include "YAPOG/Game/Pokemon/ExperienceFluctuating.hpp"
#include "YAPOG/System/MathHelper.hpp"

namespace yap
{
  ExperienceFluctuating::ExperienceFluctuating ()
  {
  }

  UInt32 ExperienceFluctuating::ComputeExperienceFromLevel (
    const UInt16& level) const
  {
    float value = 0;

    if (level <= 15)
    {
      value = MathHelper::Pow (level, 3) * 
        ((MathHelper::Floor ((level + 1) / 3.f) + 24) / 50.f);
    }
    else if (level <= 36)
    {
      value = MathHelper::Pow (level, 3) * 
        ((level + 14) / 50.f);
    }
    else
    {
      value = MathHelper::Pow (level, 3) * 
        ((MathHelper::Floor (level / 2.f) + 32) / 50.f);
    }

    return value;
  }

} // namespace yap
