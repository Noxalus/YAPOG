#include "YAPOG/Game/Pokemon/PokemonExperience.hpp"

namespace yap
{
  const uint PokemonExperience::INITIAL_EXPERIENCE_VALUE = 0;
  const UInt16 PokemonExperience::INITIAL_LEVEL_VALUE = 1;
  const uint PokemonExperience::MAX_EXPERIENCE_VALUE = 2000000;
  const UInt16 PokemonExperience::MAX_LEVEL_VALUE = 100;

  PokemonExperience::PokemonExperience (const UInt16& level)
    : value_ (INITIAL_EXPERIENCE_VALUE)
    , experienceToNextLevel_ (INITIAL_EXPERIENCE_VALUE)
  {
  }

  void PokemonExperience::Init (UInt16 level)
  {
    if (level == INITIAL_LEVEL_VALUE)
      value_ = INITIAL_EXPERIENCE_VALUE;
    else
    {
      if (level > MAX_LEVEL_VALUE)
        level = MAX_LEVEL_VALUE;

      value_ = ComputeExperienceFromLevel (level);
    }

    ComputeExperienceToNextLevel (level);
  }

  void PokemonExperience::ComputeExperienceToNextLevel (UInt16 level)
  {
    experienceToNextLevel_ = ComputeExperienceFromLevel (level + 1);
  }

  /// Getters

  const UInt32& PokemonExperience::GetValue () const
  {
    return value_;
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

  int PokemonExperience::AddExperience (const UInt32& value, UInt16 level)
  {
    int levelEarned = 0;
    
    if ((value_ + value) <= MAX_EXPERIENCE_VALUE)
      value_ += value;

    if (value_ >= experienceToNextLevel_)
    {
      while (value_ >= experienceToNextLevel_)
      {
        levelEarned++;
        level++;
        ComputeExperienceToNextLevel (level);
      }

      return levelEarned;
    }

    return levelEarned;
  }

  /*
  void PokemonExperience::LevelUp ()
  {
    if (level_ < MAX_LEVEL_VALUE)
    {
      level_++;
      ComputeExperienceToNextLevel ();
    }
  }
  */
   
} // namespace yap