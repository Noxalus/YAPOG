#ifndef YAPOG_EXPERIENCEMEDIUMFAST_HPP
# define YAPOG_EXPERIENCEMEDIUMFAST_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/PokemonExperience.hpp"

namespace yap
{
  class YAPOG_LIB ExperienceMediumFast : public PokemonExperience
  {
    DISALLOW_COPY (ExperienceMediumFast);

  public:
    ExperienceMediumFast (const UInt16& level);

  private:
    virtual UInt32 ComputeExperienceFromLevel (const UInt16& level);
  };
} // namespace yap

#endif // YAPOG_EXPERIENCEMEDIUMFAST_HPP
