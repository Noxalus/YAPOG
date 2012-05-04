#include "YAPOG/Game/Pokemon/ExperienceMediumFast.hpp"
#include "YAPOG/System/MathHelper.hpp"

namespace yap
{
  ExperienceMediumFast::ExperienceMediumFast ()
  {
  }

  UInt32 ExperienceMediumFast::ComputeExperienceFromLevel (const UInt16& level)
  {
    return MathHelper::Pow (level, 3);
  }
} // namespace yap
