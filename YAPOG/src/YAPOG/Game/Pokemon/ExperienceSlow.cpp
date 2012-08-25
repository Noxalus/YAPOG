#include "YAPOG/Game/Pokemon/ExperienceSlow.hpp"
#include "YAPOG/System/MathHelper.hpp"

namespace yap
{
  ExperienceSlow::ExperienceSlow ()
  {
  }

  UInt32 ExperienceSlow::ComputeExperienceFromLevel (const UInt16& level)
  {
    return (5 * MathHelper::Pow (level, 3)) / 4;
  }

  UInt16 ExperienceSlow::ComputeLevel ()
  {
    return 1;
  }

} // namespace yap
