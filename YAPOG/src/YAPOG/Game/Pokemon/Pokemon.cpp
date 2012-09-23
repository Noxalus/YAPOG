#include "YAPOG/Game/Pokemon/Pokemon.hpp"
#include "YAPOG/Game/Factory/XmlObjectIDLoader.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Game/Pokemon/ExperienceErratic.hpp"
#include "YAPOG/Game/Pokemon/ExperienceFluctuating.hpp"
#include "YAPOG/Game/Pokemon/ExperienceFast.hpp"
#include "YAPOG/Game/Pokemon/ExperienceMediumFast.hpp"
#include "YAPOG/Game/Pokemon/ExperienceMediumSlow.hpp"
#include "YAPOG/Game/Pokemon/ExperienceSlow.hpp"
#include "YAPOG/Game/Pokemon/ExperienceType.hpp"
#include "YAPOG/System/RandomHelper.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace yap
{
  const uchar Pokemon::MAX_POKEMON_MOVE_NUMBER = 4;
  const ID Pokemon::DEFAULT_NATURE_ID (2);
  const UInt32 Pokemon::DEFAULT_EXPERIENCE_AMOUNT = 0;

  Pokemon::Pokemon (const ID& staticID)
    : uniqueID_ (ID ())
    , staticID_ (staticID)
    , trainerName_ ()
    , nickname_ ()
    , stats_ ()
    , type_ ()
    , gender_ (Gender::Genderless)
    , status_ (PokemonStatus::Normal)
    , shiny_ (false)
    , loyalty_ (0)
    , moveSet_ ()
    , pokemonInfo_ ()
    , nature_ ()
    , exp_ ()
    , boxNumber_ (0)
    , boxIndex_ (1)
    , catchDate_ ()
  {
    pokemonInfo_ = ObjectFactory::Instance ().
      Create<PokemonInfo> ("PokemonInfo", staticID_);

    nature_ = ObjectFactory::Instance ().
      Create<NatureInfo> ("NatureInfo",  DEFAULT_NATURE_ID);

    SpecifyGender ();

    InitExperience ();
    exp_->Init (DEFAULT_EXPERIENCE_AMOUNT);

    stats_.ComputeStats (*pokemonInfo_, GetLevel (), *nature_);
    stats_.SetCurrentHP (stats_.GetHitPoint ().GetValue ());

    type_.SetType1 (ID (pokemonInfo_->GetType1 ()));
    type_.SetType2 (ID (pokemonInfo_->GetType2 ()));

    InitMoveSet ();
  }

  Pokemon::Pokemon (
    const ID& staticID,
    const UInt16& level,
    const bool& shiny)
    : uniqueID_ (ID ())
    , staticID_ (staticID)
    , trainerName_ ()
    , nickname_ ()
    , stats_ ()
    , type_ ()
    , gender_ (Gender::Genderless)
    , status_ (PokemonStatus::Normal)
    , shiny_ (shiny)
    , loyalty_ (0)
    , moveSet_ ()
    , pokemonInfo_ ()
    , nature_ ()
    , exp_ ()
    , boxNumber_ (0)
    , boxIndex_ (1)
    , catchDate_ ()
  {
    pokemonInfo_ = ObjectFactory::Instance ().
      Create<PokemonInfo> ("PokemonInfo", staticID_);

    nature_ = ObjectFactory::Instance ().
      Create<NatureInfo> ("NatureInfo",  DEFAULT_NATURE_ID);

    SpecifyGender ();

    shiny_ = shiny;

    InitExperience ();
    exp_->InitFromLevel (level);

    stats_.ComputeStats (*pokemonInfo_, level, *nature_);
    stats_.SetCurrentHP (stats_.GetHitPoint ().GetValue ());

    type_.SetType1 (ID (pokemonInfo_->GetType1 ()));
    type_.SetType2 (ID (pokemonInfo_->GetType2 ()));

    InitMoveSet ();
  }

  Pokemon::Pokemon (
    const ID& uniqueID,
    const ID& staticID,
    const String& trainerName,
    const String& nickname,
    const PokemonStat& stats,
    const Gender& gender,
    const PokemonStatus& status,
    const bool shiny,
    const Int16& loyalty,
    const PokemonMoveSet& moveSet,
    const ID& natureID,
    const uint& exp,
    const UInt8& boxNumber,
    const ID& boxIndex,
    const String& catchDate)
    : uniqueID_ (uniqueID)
    , staticID_ (staticID)
    , trainerName_ (trainerName)
    , nickname_ (nickname)
    , stats_ (stats)
    , type_ ()
    , gender_ (gender)
    , status_ (status)
    , shiny_ (shiny)
    , loyalty_ (loyalty)
    , moveSet_ (moveSet)
    , pokemonInfo_ (nullptr)
    , nature_ (nullptr)
    , exp_ (nullptr)
    , boxNumber_ (boxNumber)
    , boxIndex_ (boxIndex)
    , catchDate_ (catchDate)
  {
    pokemonInfo_ = ObjectFactory::Instance ().
      Create<PokemonInfo> ("PokemonInfo", staticID_);

    nature_ = ObjectFactory::Instance ().
      Create<NatureInfo> ("NatureInfo",  ID (natureID));

    InitExperience ();
    exp_->Init (exp);

    UInt16 level = GetLevel ();

    stats_.ComputeStats (*pokemonInfo_, level, *nature_);

    type_.SetType1 (ID (pokemonInfo_->GetType1 ()));
    type_.SetType2 (ID (pokemonInfo_->GetType2 ()));
  }

  Pokemon::Pokemon (
      const ID& staticID,
      const PokemonStat& stats,
      const Gender& gender,
      const bool shiny,
      const PokemonMoveSet& moveSet,
      const ID& natureID,
      const uint& exp)
    : uniqueID_ (ID ())
    , staticID_ (staticID)
    , trainerName_ ()
    , nickname_ ()
    , stats_ (stats)
    , type_ ()
    , gender_ (gender)
    , status_ (PokemonStatus::Normal)
    , shiny_ (shiny)
    , loyalty_ (0)
    , moveSet_ (moveSet)
    , pokemonInfo_ (nullptr)
    , nature_ (nullptr)
    , exp_ (nullptr)
    , boxNumber_ (0)
    , boxIndex_ (1)
    , catchDate_ ()
  {
    pokemonInfo_ = ObjectFactory::Instance ().
      Create<PokemonInfo> ("PokemonInfo", staticID_);

    nature_ = ObjectFactory::Instance ().
      Create<NatureInfo> ("NatureInfo",  ID (natureID));

    InitExperience ();
    exp_->Init (exp);

    UInt16 level = GetLevel ();

    stats_.ComputeStats (*pokemonInfo_, level, *nature_);
    stats_.SetCurrentHP (stats_.GetHitPoint ().GetValue ());

    type_.SetType1 (ID (pokemonInfo_->GetType1 ()));
    type_.SetType2 (ID (pokemonInfo_->GetType2 ()));
  }

  void Pokemon::InitExperience ()
  {
    switch (pokemonInfo_->GetExperienceType ())
    {
    case ExperienceType::Slow:
      exp_ = new ExperienceSlow ();
      break;
    case ExperienceType::MediumSlow:
      exp_ = new ExperienceMediumSlow ();
      break;
    case ExperienceType::MediumFast:
      exp_ = new ExperienceMediumFast ();
      break;
    case ExperienceType::Fast:
      exp_ = new ExperienceFast ();
      break;
    case ExperienceType::Fluctuating:
      exp_ = new ExperienceFluctuating ();
      break;
    case ExperienceType::Erratic:
      exp_ = new ExperienceErratic ();
      break;
    default:
      exp_ = new ExperienceMediumSlow ();
      break;
    }
  }

  void Pokemon::InitMoveSet ()
  {
    pokemonInfo_->InitMoveSet (moveSet_, GetLevel ());
  }

  void Pokemon::SpecifyGender ()
  {
    if (RandomHelper::Percentage (pokemonInfo_->GetGenderProbability ()))
      gender_ = Gender::Female;
    else
      gender_ = Gender::Male;
  }

  const ID& Pokemon::GetUniqueID () const
  {
    return uniqueID_;
  }

  const ID& Pokemon::GetStaticID () const
  {
    return staticID_;
  }

  const String& Pokemon::GetTrainerName () const
  {
    return trainerName_;
  }

  const String& Pokemon::GetName () const
  {
    if (pokemonInfo_ != nullptr)
    {
      if (nickname_ != "")
        return nickname_;
      else
        return pokemonInfo_->GetName ();
    }

    YAPOG_THROW("PokemonInfo is not initialized.");
  }

  const String& Pokemon::GetNickname () const
  {
    return nickname_;
  }

  const TypeInfo& Pokemon::GetType1 () const
  {
    return type_.GetType1 ();
  }

  const TypeInfo& Pokemon::GetType2 () const
  {
    return type_.GetType2 ();
  }

  float Pokemon::GetTypeEffectFactor (const TypeInfo& type) const
  {
    return type.GetTypeEffect (type_.GetType1 ().GetID ()) *
      type.GetTypeEffect (type_.GetType2 ().GetID ());
  }

  const PokemonExperience& Pokemon::GetExperience () const
  {
    return *exp_;
  }

  UInt32 Pokemon::GetTotalExperience () const
  {
    if (exp_ != nullptr)
      return exp_->GetValue ();
    else
    {
      YAPOG_THROW("The Pokémon " + GetName () +
        " doesn't have any experience type !");
    }
  }

  UInt32 Pokemon::GetExperienceToNextLevel () const
  {
    return exp_->GetExperienceToNextLevel ();
  }

  UInt32 Pokemon::GetTotalExperienceToNextLevel () const
  {
    if (exp_ != nullptr)
      return exp_->GetTotalExperienceToNextLevel ();
    else
    {
      YAPOG_THROW("The Pokémon " + GetName () +
        " doesn't have any experience type !");
    }
  }

  float Pokemon::GetExperiencePercentage () const
  {
    return exp_->GetExperiencePercentage ();
  }

  UInt16 Pokemon::GetCurrentHP () const
  {
    return stats_.GetHitPoint ().GetCurrentValue ();
  }

  UInt16 Pokemon::GetMaxHP () const
  {
    return stats_.GetHitPoint ().GetValue ();
  }

  const PokemonStat& Pokemon::GetStats () const
  {
    return stats_;
  }

  const String& Pokemon::GetIconPath () const
  {
    return pokemonInfo_->GetIconPath ();
  }


  UInt16 Pokemon::GetLevel () const
  {
    return exp_->GetLevel ();
  }

  bool Pokemon::GetShiny () const
  {
    return shiny_;
  }

  Int16 Pokemon::GetLoyalty () const
  {
    return loyalty_;
  }

  const yap::NatureInfo& Pokemon::GetNature () const
  {
    if (nature_ == nullptr)
      throw yap::Exception ("The nature of this Pokemon is null !");

    return *nature_;
  }

  const yap::ID& Pokemon::GetNatureID () const
  {
    if (nature_ == nullptr)
      throw yap::Exception ("The nature of this Pokemon is null !");

    return nature_->GetID ();
  }

  const Gender& Pokemon::GetGender () const
  {
    return gender_;
  }

  const PokemonStatus& Pokemon::GetStatus () const
  {
    return status_;
  }

  const yap::UInt8& Pokemon::GetBoxNumber () const
  {
    return boxNumber_;
  }

  const yap::ID& Pokemon::GetBoxIndex () const
  {
    return boxIndex_;
  }

  const yap::String& Pokemon::GetCatchDate () const
  {
    return catchDate_;
  }

  // Setters
  /*
  void Pokemon::SetUniqueID (const ID& value)
  { uniqueID_ = value; }
  void Pokemon::SetExperience (const UInt32& value)
  { 
  exp_->SetValue (value); 

  stats_.ComputeStats (*pokemonInfo_, GetLevel (), *nature_);

  RestoreHP ();
  }
  void Pokemon::SetGender (const UInt8& value)
  { gender_ = (Gender)value; }
  void Pokemon::SetNickname (const String& value)
  { nickname_ = value; }
  void Pokemon::SetLevel (const UInt16& value)
  { level_ = value; }
  void Pokemon::SetShiny (bool value)
  { shiny_ = value; }
  void Pokemon::SetLoyalty (int value)
  { loyalty_ = value; }
  void Pokemon::SetNature (const ID& value)
  {
  if (nature_ != nullptr)
  delete nature_;

  nature_ = ObjectFactory::Instance ().
  Create<NatureInfo> ("NatureInfo",  value);
  }
  */

  void Pokemon::AddExperience (const Int32& value)
  {
    if (exp_ != nullptr)
    {
      int levelEarned = exp_->AddExperience (value);
      if (levelEarned > 0)
      {
        // Level Up
        std::cout << levelEarned << " level(s) earned !" << std::endl;

        while (levelEarned > 0)
        {
          // Skill learning ?
          const collection::List<ID>* newSkills =
            pokemonInfo_->GetNewSkills (GetLevel ());
          if (newSkills != nullptr)
          {
            for (const ID& moveID : *newSkills)
            {
              if (!LearnMove (moveID))
                ReplaceMove (moveID, 0);
            }
          }

          levelEarned--;
        }

        // Evolution ?
        if (pokemonInfo_->CanEvolve ())
        {
          if (GetLevel () > pokemonInfo_->GetEvolutionLevel ())
            Evolve ();
        }

        stats_.ComputeStats (*pokemonInfo_, GetLevel (), *nature_);
      }
    }
    else
    {
      YAPOG_THROW("The Pokémon " + GetName () +
        " doesn't have any experience type !");
    }
  }

  const PokemonMoveSet& Pokemon::GetMoveSet () const
  {
    return moveSet_;
  }

  bool Pokemon::LearnMove (const ID& moveID)
  {
    return moveSet_.AddMove (moveID);
  }

  void Pokemon::ReplaceMove (const ID& moveID, UInt8 index)
  {
    moveSet_.ReplaceMove (moveID, index);
  }

  void Pokemon::Evolve ()
  {
    std::cout << "EVOLUTION !" << std::endl;

    staticID_ = pokemonInfo_->GetPokemonEvolutionID ();
    //Reset ();
  }

  void Pokemon::RestoreHP ()
  {
    stats_.RestoreHP ();
  }

  void Pokemon::SetCurrentHP (int value)
  {
    stats_.SetCurrentHP (value);
  }
}
