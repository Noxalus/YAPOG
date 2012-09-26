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
    float GetExperiencePercentage (
      UInt32 value = INITIAL_EXPERIENCE_VALUE, 
      UInt16 level = INITIAL_LEVEL_VALUE) const;

    int AddExperience (const UInt32& value);

    void ComputeTotalExperienceToNextLevel (UInt16 level);
    UInt16 GetLevel () const;

    UInt16 ComputeLevelDifference (UInt32 oldValue, UInt32 newValue) const;

    static const UInt16 INITIAL_LEVEL_VALUE;
    static const UInt16 MAX_LEVEL_VALUE;

  private:
    UInt32 GetCurrentBase (UInt16 level) const;
    virtual UInt32 ComputeExperienceFromLevel (const UInt16& level) const = 0;
    UInt16 GetLevelFromExperience (
      UInt32 experience, 
      UInt16 baseLevel = INITIAL_LEVEL_VALUE) const;

    UInt32 value_;
    UInt32 totalExperienceToNextLevel_;
    mutable UInt32 previousValue_;
    mutable UInt16 currentLevel_;
    static const UInt32 INITIAL_EXPERIENCE_VALUE;
    static const UInt32 MAX_EXPERIENCE_VALUE;
  };
} // namespace yap

#endif // YAPOG_POKEMONEXPERIENCE_HPP