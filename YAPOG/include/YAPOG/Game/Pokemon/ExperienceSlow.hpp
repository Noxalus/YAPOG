#ifndef YAPOG_EXPERIENCESLOW_HPP
# define YAPOG_EXPERIENCESLOW_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/PokemonExperience.hpp"

namespace yap
{
  class YAPOG_LIB ExperienceSlow : public PokemonExperience
  {
    DISALLOW_COPY (ExperienceSlow);

  public:
    ExperienceSlow ();

  private:
    virtual UInt32 ComputeExperienceFromLevel (const UInt16& level);
  };
} // namespace yap

#endif // YAPOG_EXPERIENCESLOW_HPP
