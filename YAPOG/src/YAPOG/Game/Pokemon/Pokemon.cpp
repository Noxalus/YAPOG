#include "YAPOG/Game/Pokemon/Pokemon.hpp"
#include "YAPOG/Game/Factory/XmlObjectIDLoader.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Game/Pokemon/ExperienceErratic.hpp"
#include "YAPOG/Game/Pokemon/ExperienceFluctuating.hpp"
#include "YAPOG/Game/Pokemon/ExperienceFast.hpp"
#include "YAPOG/Game/Pokemon/ExperienceMediumFast.hpp"
#include "YAPOG/Game/Pokemon/ExperienceMediumSlow.hpp"
#include "YAPOG/Game/Pokemon/ExperienceSlow.hpp"

namespace yap
{
  Pokemon::Pokemon (const ID& staticID)
    : staticID_ (staticID)
  {
    pokemonInfo_ = ObjectFactory::Instance ().
      Create<PokemonInfo> ("PokemonInfo",  staticID_);

    nature_ = ObjectFactory::Instance ().
      Create<NatureInfo> ("NatureInfo",  ID (2));

    switch (pokemonInfo_->GetExperienceType ())
    {
    case 1:
      exp_ = new ExperienceSlow ();
      break;
    case 2:
      exp_ = new ExperienceMediumSlow ();
      break;
    case 3:
      exp_ = new ExperienceMediumFast ();
      break;
    case 4:
      exp_ = new ExperienceFast ();
      break;
    case 5:
      exp_ = new ExperienceFluctuating ();
      break;
    case 6:
      exp_ = new ExperienceErratic ();
      break;
    default:
      exp_ = new ExperienceMediumSlow ();
      break;
    }

    exp_->Init ();

    stats_.ComputeStats (*pokemonInfo_, GetLevel (), *nature_);
    type_.SetType1 (ID (pokemonInfo_->GetType1 ()));
    type_.SetType2 (ID (pokemonInfo_->GetType2 ()));
  }

  Pokemon::Pokemon (const ID& staticID, const UInt16& level, const bool& shiny)
    : staticID_ (staticID)
    , shiny_ (shiny)
  {
    pokemonInfo_ = ObjectFactory::Instance ().
      Create<PokemonInfo> ("PokemonInfo",  staticID_);

    nature_ = ObjectFactory::Instance ().
      Create<NatureInfo> ("NatureInfo",  ID (2));

    switch (pokemonInfo_->GetExperienceType ())
    {
    case 1:
      exp_ = new ExperienceSlow (level);
      break;
    case 2:
      exp_ = new ExperienceMediumSlow (level);
      break;
    case 3:
      exp_ = new ExperienceMediumFast (level);
      break;
    case 4:
      exp_ = new ExperienceFast (level);
      break;
    case 5:
      exp_ = new ExperienceFluctuating (level);
      break;
    case 6:
      exp_ = new ExperienceErratic (level);
      break;
    default:
      exp_ = new ExperienceMediumSlow (level);
      break;
    }

    exp_->Init ();

    stats_.ComputeStats (*pokemonInfo_, GetLevel (), *nature_);
    type_.SetType1 (ID (pokemonInfo_->GetType1 ()));
    type_.SetType2 (ID (pokemonInfo_->GetType2 ()));
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
    if (exp_ != nullptr)
      return exp_->GetLevel ();
    else
    {
      throw Exception ("The Pokémon " + GetName () + 
        " doesn't have any experience type !");
    }
  }

  void Pokemon::AddExperience (const Int32& value)
  {
    if (exp_ != nullptr)
      exp_->AddExperience (value);
    else
    {
      throw Exception ("The Pokémon " + GetName () + 
        " doesn't have any experience type !");
    }
  }

  void Pokemon::PrintStats ()
  {
    //pokeInfo_->PrintBaseStats ();

    std::cout
      << "---------------------------------------------" << std::endl
      << "              Current Statistics" << std::endl
      << "---------------------------------------------" << std::endl
      << "Level: " << GetLevel () << std::endl
      << "Total experience: " << GetTotalExperience () << std::endl
      << "Experience to the next level: " << GetExperienceToNextLevel ()
      << " (" << GetExperienceToNextLevel () - GetTotalExperience () << ")" << std::endl
      << "Experience type: " << pokemonInfo_->GetExperienceType () << std::endl
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
  }
}
