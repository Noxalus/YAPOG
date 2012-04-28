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
    PokemonExperience (const UInt16& level);

    void Init ();

    const UInt32& GetValue () const;
    const UInt16& GetLevel () const;
    const UInt32& GetExperienceToNextLevel () const;

    void SetValue (const UInt32& value);
    void AddExperience (const UInt32& value);
    void LevelUp ();

    void ComputeExperienceToNextLevel ();
  protected:
    void SetExperienceToNextLevel (const UInt32& value);

  private:
    virtual UInt32 ComputeExperienceFromLevel (const UInt16& level) = 0;

    UInt32 value_;
    UInt16 level_;
    UInt32 experienceToNextLevel_;
    static const UInt16 INITIAL_LEVEL_VALUE;
    static const UInt16 MAX_LEVEL_VALUE;
    static const UInt32 INITIAL_EXPERIENCE_VALUE;
    static const UInt32 MAX_EXPERIENCE_VALUE;
  };
} // namespace yap

#endif // YAPOG_POKEMONEXPERIENCE_HPP