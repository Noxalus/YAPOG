#include "YAPOG/Game/Pokemon/ExperienceFast.hpp"
#include "YAPOG/System/MathHelper.hpp"

namespace yap
{
  ExperienceFast::ExperienceFast ()
  {
  }

  UInt32 ExperienceFast::ComputeExperienceFromLevel (const UInt16& level)
  {
    return ((4.f / 5.f) * MathHelper::Pow (level, 3));
  }
} // namespace yap
