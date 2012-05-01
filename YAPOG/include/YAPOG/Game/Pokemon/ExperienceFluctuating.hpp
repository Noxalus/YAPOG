#ifndef YAPOG_EXPERIENCEFLUCTUATING_HPP
# define YAPOG_EXPERIENCEFLUCTUATING_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/PokemonExperience.hpp"

namespace yap
{
  class YAPOG_LIB ExperienceFluctuating : public PokemonExperience
  {
    DISALLOW_COPY (ExperienceFluctuating);

  public:
    ExperienceFluctuating ();
    ExperienceFluctuating (const UInt16& level);

  private:
    virtual UInt32 ComputeExperienceFromLevel (const UInt16& level);
  };
} // namespace yap

#endif // YAPOG_EXPERIENCEFLUCTUATING_HPP
