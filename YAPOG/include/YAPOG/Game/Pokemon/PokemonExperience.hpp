#ifndef YAPOG_POKEMONEXPERIENCE_HPP
# define YAPOG_POKEMONEXPERIENCE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"

namespace yap
{
  class YAPOG_LIB PokemonExperience
  {
    DISALLOW_COPY (PokemonExperience);

  public:
    PokemonExperience ();

    void Init (UInt32 experience);
    void InitFromLevel (UInt16 level);

    UInt32 GetValue () const;
    UInt32 GetExperienceToNextLevel () const;
    UInt32 GetTotalExperienceToNextLevel () const;
    float GetExperiencePercentage ();

    int AddExperience (const UInt32& value);

    void ComputeTotalExperienceToNextLevel (UInt16 level);
    UInt16 GetLevel ();

    static const UInt16 INITIAL_LEVEL_VALUE;
    static const UInt16 MAX_LEVEL_VALUE;

  private:
    virtual UInt32 ComputeExperienceFromLevel (const UInt16& level) = 0;

    UInt32 value_;
    UInt32 totalExperienceToNextLevel_;
    UInt32 previousValue_;
    UInt16 currentLevel_;
    static const UInt32 INITIAL_EXPERIENCE_VALUE;
    static const UInt32 MAX_EXPERIENCE_VALUE;
  };
} // namespace yap

#endif // YAPOG_POKEMONEXPERIENCE_HPP