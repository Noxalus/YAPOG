#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
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

  UInt32 PokemonExperience::GetValue () const
  {
    return value_;
  }

  UInt32 PokemonExperience::GetExperienceToNextLevel () const
  {
    return totalExperienceToNextLevel_ - value_;
  }

  UInt32 PokemonExperience::GetTotalExperienceToNextLevel () const
  {
    return totalExperienceToNextLevel_;
  }

  UInt32 PokemonExperience::GetCurrentBase (UInt16 level) const
  {
    return ComputeExperienceFromLevel (level);
  }

  float PokemonExperience::GetExperiencePercentage (
    UInt32 value,
    UInt16 level) const
  {
    if (value == INITIAL_EXPERIENCE_VALUE)
      value = value_;
    if (level == INITIAL_LEVEL_VALUE)
      level = GetLevel ();

    UInt32 base = GetCurrentBase (level);

    return MathHelper::Clamp (
      static_cast<float>(value - base) / 
      static_cast<float>(ComputeExperienceFromLevel (level + 1) - base),
      0.f, 1.f);
  }

  UInt16 PokemonExperience::GetLevel () const
  {
    if (previousValue_ != value_)
    {
      previousValue_ = value_;
      currentLevel_ = GetLevelFromExperience (value_, currentLevel_);
    }

    return MathHelper::Clamp(
      currentLevel_, 
      INITIAL_LEVEL_VALUE, 
      MAX_LEVEL_VALUE);
  }

  UInt16 PokemonExperience::GetLevelFromExperience (
    UInt32 experience, 
    UInt16 baseLevel) const
  {
    for (int level = baseLevel + 1; level <= MAX_LEVEL_VALUE; level++)
    {
      if (ComputeExperienceFromLevel (level) > experience)
        return (level - 1);
    }

    return INITIAL_LEVEL_VALUE;
  }

  UInt16 PokemonExperience::ComputeLevelDifference (
    UInt32 oldValue, 
    UInt32 newValue) const
  {
    if (oldValue < newValue)
    {
      UInt16 oldLevel = GetLevelFromExperience (oldValue);
      UInt16 newLevel = GetLevelFromExperience (newValue, oldLevel);

      return (newLevel - oldLevel);
    }
    else
    {
      YAPOG_THROW("WARNING: the old experience value is greater "
        "than or equal to the new value !");
    }
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