#include "YAPOG/Game/Pokemon/ExperienceMediumSlow.hpp"
#include "YAPOG/System/MathHelper.hpp"

namespace yap
{
  ExperienceMediumSlow::ExperienceMediumSlow ()
  {
  }

  UInt32 ExperienceMediumSlow::ComputeExperienceFromLevel (const UInt16& level)
  {
    float value = (6.f/5.f) * MathHelper::Pow (level, 3);
    value -= 15 * MathHelper::Pow (level, 2);
    value += 100 * level;
    value -= 140;

    return value;
  }

} // namespace yap
