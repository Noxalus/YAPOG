#ifndef YAPOG_EXPERIENCEFAST_HPP
# define YAPOG_EXPERIENCEFAST_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/PokemonExperience.hpp"

namespace yap
{
  class YAPOG_LIB ExperienceFast : public PokemonExperience
  {
    DISALLOW_COPY (ExperienceFast);

  public:
    ExperienceFast ();
    ExperienceFast (const UInt16& level);

  private:
    virtual UInt32 ComputeExperienceFromLevel (const UInt16& level);
  };
} // namespace yap

#endif // YAPOG_EXPERIENCEFAST_HPP
