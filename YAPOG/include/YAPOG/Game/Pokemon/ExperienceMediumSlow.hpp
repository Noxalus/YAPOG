#ifndef YAPOG_EXPERIENCEMEDIUMSLOW_HPP
# define YAPOG_EXPERIENCEMEDIUMSLOW_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/PokemonExperience.hpp"

namespace yap
{
  class YAPOG_LIB ExperienceMediumSlow : public PokemonExperience
  {
    DISALLOW_COPY (ExperienceMediumSlow);

  public:
    ExperienceMediumSlow ();
    ExperienceMediumSlow (const UInt16& level);

  private:
    virtual UInt32 ComputeExperienceFromLevel (const UInt16& level);
  };
} // namespace yap

#endif // YAPOG_EXPERIENCEMEDIUMSLOW_HPP
