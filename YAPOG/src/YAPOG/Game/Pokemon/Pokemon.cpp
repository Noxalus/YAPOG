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

namespace yap
{
  Pokemon::Pokemon (const ID& staticID)
    : staticID_ (staticID)
    , status_ (Status::Normal)
    , level_ (PokemonExperience::INITIAL_LEVEL_VALUE)
    , shiny_ (false)
  {
    Init ();
  }

  Pokemon::Pokemon (const ID& staticID, const UInt16& level, const bool& shiny)
    : staticID_ (staticID)
    , status_ (Status::Normal)
    , level_ (level)
    , shiny_ (shiny)
  {
    Init ();
  }

  void Pokemon::Init ()
  {
    pokemonInfo_ = ObjectFactory::Instance ().
      Create<PokemonInfo> ("PokemonInfo",  staticID_);

    nature_ = ObjectFactory::Instance ().
      Create<NatureInfo> ("NatureInfo",  ID (2));

    InitExperience ();

    stats_.ComputeStats (*pokemonInfo_, GetLevel (), *nature_);
    type_.SetType1 (ID (pokemonInfo_->GetType1 ()));
    type_.SetType2 (ID (pokemonInfo_->GetType2 ()));

    InitMoveSet ();
  }

  void Pokemon::InitExperience ()
  {
    switch (pokemonInfo_->GetExperienceType ())
    {
    case ExperienceType::Slow:
      exp_ = new ExperienceSlow (level_);
      break;
    case ExperienceType::MediumSlow:
      exp_ = new ExperienceMediumSlow (level_);
      break;
    case ExperienceType::MediumFast:
      exp_ = new ExperienceMediumFast (level_);
      break;
    case ExperienceType::Fast:
      exp_ = new ExperienceFast (level_);
      break;
    case ExperienceType::Fluctuating:
      exp_ = new ExperienceFluctuating (level_);
      break;
    case ExperienceType::Erratic:
      exp_ = new ExperienceErratic (level_);
      break;
    default:
      exp_ = new ExperienceMediumSlow (level_);
      break;
    }

    exp_->Init (level_);
  }

  void Pokemon::InitMoveSet ()
  {
    for (int i = 0; i < PokemonInfo::MAX_MOVE_NUMBER; i++)
      moveSet[i] = nullptr;

    pokemonInfo_->InitMoveSet (moveSet, level_);
  }

  const String& Pokemon::GetName () const
  {
    return pokemonInfo_->GetName ();
  }

  float Pokemon::GetTypeEffectFactor (const TypeInfo& type) const
  {
    return type.GetTypeEffect (type_.GetType1 ().GetID ()) *
      type.GetTypeEffect (type_.GetType2 ().GetID ());
  }

  const UInt32& Pokemon::GetTotalExperience () const
  {
    if (exp_ != nullptr)
      return exp_->GetValue ();
    else
    {
      throw Exception ("The Pokémon " + GetName () +
        " doesn't have any experience type !");
    }
  }

  const UInt32& Pokemon::GetExperienceToNextLevel () const
  {
    if (exp_ != nullptr)
      return exp_->GetExperienceToNextLevel ();
    else
    {
      throw Exception ("The Pokémon " + GetName () +
        " doesn't have any experience type !");
    }
  }

  const UInt16& Pokemon::GetLevel () const
  {
    return level_;
  }

  void Pokemon::AddExperience (const Int32& value)
  {
    if (exp_ != nullptr)
    {
      int levelEarned = exp_->AddExperience (value, level_); 
      if (levelEarned > 0)
      {
        // Level Up
        std::cout << levelEarned << " level(s) earned !" << std::endl;

        while (levelEarned > 0)
        {
          level_++;
          // Skill learning ?
          const collection::List<ID>* newSkills = 
            pokemonInfo_->GetNewSkills (level_);
          if (newSkills != nullptr)
          {
            for (const ID& skillID : *newSkills)
            {
              if (!Learn (skillID))
                Replace (skillID, 0);
            }
          }

          levelEarned--;
        }

        // Evolution ?

      }
    }
    else
    {
      throw Exception ("The Pokémon " + GetName () +
        " doesn't have any experience type !");
    }
  }

  bool Pokemon::Learn (const ID& skillID)
  {
    for (int i = 0; i < 4; i++)
    {
      if (moveSet[i] == nullptr)
      {
        moveSet[i] = new PokemonSkill (skillID);
        return true;
      }
    }

    return false;
  }

  void Pokemon::Replace (const ID& skillID, int index)
  {
    moveSet[index] = new PokemonSkill (skillID);
  }

  static String GetStringFromExperienceType (const ExperienceType& experienceType)
  {
    switch (experienceType)
    {
    case ExperienceType::Slow:
      return "Slow";
    case ExperienceType::MediumSlow:
      return "MediumSlow";
    case ExperienceType::MediumFast:
      return "MediumFast";
    case ExperienceType::Fast:
      return "Fast";
    case ExperienceType::Fluctuating:
      return "Fluctuating";
    case ExperienceType::Erratic:
      return "Erratic";
    default:
      return "Error";
    }
  }

  void Pokemon::PrintStats ()
  {
    //pokemonInfo_->PrintBaseStats ();

    std::cout
      << "---------------------------------------------" << std::endl
      << "              Current Statistics" << std::endl
      << "---------------------------------------------" << std::endl
      << "Level: " << GetLevel () << std::endl
      << "Total experience: " << GetTotalExperience () << std::endl
      << "Experience to the next level: " << GetExperienceToNextLevel ()
      << " (" << GetExperienceToNextLevel () - GetTotalExperience () << ")" << std::endl
      << "Experience type: " 
      << GetStringFromExperienceType (pokemonInfo_->GetExperienceType ()) << std::endl
      << "Nature: " << nature_->GetName () << std::endl
      << "Type1: " << type_.GetType1 ().GetName () << std::endl
      << "Type2: " << type_.GetType2 ().GetName () << std::endl
      << "Current HP: " << stats_.GetHitPoint ().GetCurrentValue () << std::endl
      << "Max HP: " << stats_.GetHitPoint ().GetValue ()
      << " (IV: " << stats_.GetHitPoint ().GetIndividualValue () << ")" << std::endl
      << "Attack: " << stats_.GetAttack ().GetValue ()
      << " (IV: " << stats_.GetAttack ().GetIndividualValue () << ")" << std::endl
      << "Defense: " << stats_.GetDefense ().GetValue ()
      << " (IV: " << stats_.GetDefense ().GetIndividualValue () << ")" << std::endl
      << "Special Attack: " << stats_.GetSpecialAttack ().GetValue ()
      << " (IV: " << stats_.GetSpecialAttack ().GetIndividualValue () << ")" << std::endl
      << "Special Defense: " << stats_.GetSpecialDefense ().GetValue ()
      << " (IV: " << stats_.GetSpecialDefense ().GetIndividualValue () << ")" << std::endl
      << "Speed: " << stats_.GetSpeed ().GetValue ()
      << " (IV: " << stats_.GetSpeed ().GetIndividualValue () << ")" << std::endl;

    std::cout << "Move set:" << std::endl;

    for (int i = 0; i < 4; i++)
    {
      if (moveSet[i] != nullptr)
      {
        std::cout << moveSet[i]->GetName ()
          << " (" << moveSet[i]->GetCurrentPP () << "/" 
          << moveSet[i]->GetMaxPP () << ")" << std::endl;
      }
      else
        std::cout << " - " << std::endl;
    }

    pokemonInfo_->PrintBaseSkills ();
  }
}
