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
  const UInt16 Pokemon::POKEMON_INITIAL_LEVEL = 1;

  Pokemon::Pokemon (const ID& staticID)
    : staticID_ (staticID)
  {
    pokemonInfo_ = ObjectFactory::Instance ().
      Create<PokemonInfo> ("PokemonInfo",  staticID);

    nature_ = ObjectFactory::Instance ().
      Create<NatureInfo> ("NatureInfo",  ID (2));

    exp_ = new ExperienceErratic ();
    exp_->Init ();

    stats_.ComputeStats (*pokemonInfo_, GetLevel (), *nature_);
    type_.SetType1 (ID (pokemonInfo_->GetType1 ()));
    type_.SetType2 (ID (pokemonInfo_->GetType2 ()));

  }

  Pokemon::Pokemon (const ID& staticID, const UInt16& level, const bool& shiny)
    : staticID_ (staticID_)
    , shiny_ (shiny)
  {
    pokemonInfo_ = ObjectFactory::Instance ().
      Create<yap::PokemonInfo> ("PokemonInfo",  staticID);

    nature_ = ObjectFactory::Instance ().
      Create<NatureInfo> ("NatureInfo",  ID (1));

    exp_ = new ExperienceErratic (level);
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
