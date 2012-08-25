#include "YAPOG/Game/Pokemon/PokemonExperience.hpp"

namespace yap
{
  const uint PokemonExperience::INITIAL_EXPERIENCE_VALUE = 0;
  const UInt16 PokemonExperience::INITIAL_LEVEL_VALUE = 1;
  const uint PokemonExperience::MAX_EXPERIENCE_VALUE = 2000000;
  const UInt16 PokemonExperience::MAX_LEVEL_VALUE = 100;

  PokemonExperience::PokemonExperience ()
    : value_ (INITIAL_EXPERIENCE_VALUE)
    , experienceToNextLevel_ (INITIAL_EXPERIENCE_VALUE)
    , previousValue_ (INITIAL_EXPERIENCE_VALUE + 1)
    , currentLevel_ (INITIAL_LEVEL_VALUE)
  {
  }

  void PokemonExperience::Init (UInt32 experience)
  {
    value_ = experience;

    ComputeExperienceToNextLevel (GetLevel ());
  }

  void PokemonExperience::InitFromLevel (UInt16 level)
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

  UInt16 PokemonExperience::GetLevel ()
  {
    if (previousValue_ != value_)
    {
      previousValue_ = value_;

      for (int level = currentLevel_ + 1; level <= MAX_LEVEL_VALUE; level++)
      {
        if (ComputeExperienceFromLevel (level) > value_)
        {
          currentLevel_ = level - 1;
          break;
        }
      }
    }

    return currentLevel_;
  }

  int PokemonExperience::AddExperience (const UInt32& value)
  {
    int levelEarned = 0;
    UInt16 level = GetLevel ();

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