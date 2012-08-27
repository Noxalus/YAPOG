#include "YAPOG/Game/Pokemon/PokemonExperience.hpp"
#include "YAPOG/System/MathHelper.hpp"

namespace yap
{
  const uint PokemonExperience::INITIAL_EXPERIENCE_VALUE = 0;
  const UInt16 PokemonExperience::INITIAL_LEVEL_VALUE = 1;
  const uint PokemonExperience::MAX_EXPERIENCE_VALUE = 2000000;
  const UInt16 PokemonExperience::MAX_LEVEL_VALUE = 100;

  PokemonExperience::PokemonExperience ()
    : value_ (INITIAL_EXPERIENCE_VALUE)
    , totalExperienceToNextLevel_ (INITIAL_EXPERIENCE_VALUE)
    , previousValue_ (INITIAL_EXPERIENCE_VALUE + 1)
    , currentLevel_ (INITIAL_LEVEL_VALUE)
  {
  }

  void PokemonExperience::Init (UInt32 experience)
  {
    value_ = experience;

    ComputeTotalExperienceToNextLevel (GetLevel ());
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

    ComputeTotalExperienceToNextLevel (level);
  }

  void PokemonExperience::ComputeTotalExperienceToNextLevel (UInt16 level)
  {
    totalExperienceToNextLevel_ = ComputeExperienceFromLevel (level + 1);
  }

  /// Getters

  const UInt32& PokemonExperience::GetValue () const
  {
    return value_;
  }

  const UInt32& PokemonExperience::GetExperienceToNextLevel () const
  {
    return totalExperienceToNextLevel_ - value_;
  }

  const UInt32& PokemonExperience::GetTotalExperienceToNextLevel () const
  {
    return totalExperienceToNextLevel_;
  }

  float PokemonExperience::GetExperiencePercentage ()
  {
    return static_cast<float>(value_) / 
      static_cast<float>(totalExperienceToNextLevel_);
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

    return MathHelper::Clamp(
      currentLevel_, 
      INITIAL_LEVEL_VALUE, 
      MAX_LEVEL_VALUE);
  }

  int PokemonExperience::AddExperience (const UInt32& value)
  {
    int levelEarned = 0;
    UInt16 level = GetLevel ();

    if ((value_ + value) <= MAX_EXPERIENCE_VALUE)
      value_ += value;

    if (value_ >= totalExperienceToNextLevel_)
    {
      while (value_ >= totalExperienceToNextLevel_)
      {
        levelEarned++;
        level++;
        ComputeTotalExperienceToNextLevel (level);
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