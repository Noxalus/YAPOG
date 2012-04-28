#include "YAPOG/Game/Pokemon/PokemonExperience.hpp"

namespace yap
{
  const UInt32 PokemonExperience::INITIAL_EXPERIENCE_VALUE = 0;
  const UInt16 PokemonExperience::INITIAL_LEVEL_VALUE = 1;
  const UInt32 PokemonExperience::MAX_EXPERIENCE_VALUE = 2000000;
  const UInt16 PokemonExperience::MAX_LEVEL_VALUE = 100;

  PokemonExperience::PokemonExperience ()
    : value_ (INITIAL_EXPERIENCE_VALUE)
    , level_ (INITIAL_LEVEL_VALUE)
    , experienceToNextLevel_ (INITIAL_EXPERIENCE_VALUE)

  {
  }

  PokemonExperience::PokemonExperience (const UInt16& level)
    : value_ (INITIAL_EXPERIENCE_VALUE)
    , level_ (level)
    , experienceToNextLevel_ (INITIAL_EXPERIENCE_VALUE)
  {
  }

  void PokemonExperience::Init ()
  {
    if (level_ == INITIAL_LEVEL_VALUE)
      value_ = INITIAL_EXPERIENCE_VALUE;
    else
      value_ = ComputeExperienceFromLevel (level_);

    ComputeExperienceToNextLevel ();
  }

  void PokemonExperience::ComputeExperienceToNextLevel ()
  {
    experienceToNextLevel_ = ComputeExperienceFromLevel (level_ + 1);
  }

  /// Getters

  const UInt32& PokemonExperience::GetValue () const
  {
    return value_;
  }

  const UInt16& PokemonExperience::GetLevel () const
  {
    return level_;
  }

  const UInt32& PokemonExperience::GetExperienceToNextLevel () const
  {
    return experienceToNextLevel_;
  }

  /// Setters
  void PokemonExperience::SetValue (const UInt32& value)
  {
    value_ = value;
  }

  void PokemonExperience::SetExperienceToNextLevel (const UInt32& value)
  {
    experienceToNextLevel_ = value;
  }

  void PokemonExperience::AddExperience (const UInt32& value)
  {
    if ((value_ + value) <= MAX_EXPERIENCE_VALUE)
      value_ += value;

    if (value_ >= experienceToNextLevel_)
      LevelUp ();
  }

  void PokemonExperience::LevelUp ()
  {
    if (level_ < MAX_LEVEL_VALUE)
    {
      level_++;
      ComputeExperienceToNextLevel ();
    }
  }

} // namespace yap