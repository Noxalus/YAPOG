#include "YAPOG/Game/Pokemon/ExperienceSlow.hpp"
#include "YAPOG/System/MathHelper.hpp"

namespace yap
{
  ExperienceSlow::ExperienceSlow ()
  {
  }

  UInt32 ExperienceSlow::ComputeExperienceFromLevel (const UInt16& level) const
  {
    return (5 * MathHelper::Pow (level, 3)) / 4;
  }

} // namespace yap
