#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"

namespace yap
{
  const int PokemonInfo::INITIAL_BASE_STATS_VALUE = 0;
  
  PokemonInfo::PokemonInfo (const ID& id)
    : pokedexID_ (id)
  {
    name_ = "";
    description_ = "";
    species_ = "";
    height_ = 0.f;
    weight_ = 0.f;
    experience_ = 0;
    rarity_ = 255;
    baseHitPoint_ = PokemonInfo::INITIAL_BASE_STATS_VALUE;
    baseAttack_ = PokemonInfo::INITIAL_BASE_STATS_VALUE;
    baseDefense_ = PokemonInfo::INITIAL_BASE_STATS_VALUE;
    baseSpecialAttack_ = PokemonInfo::INITIAL_BASE_STATS_VALUE;
    baseSpecialDefense_ = PokemonInfo::INITIAL_BASE_STATS_VALUE;
    baseSpeed_ = PokemonInfo::INITIAL_BASE_STATS_VALUE;
    type1_ = 0;
    type2_ = 0;
  }

  PokemonInfo::PokemonInfo (const PokemonInfo& copy)
    : pokedexID_ (copy.pokedexID_),
    name_ (copy.name_),
    description_ (copy.description_),
    species_ (copy.species_),
    height_ (copy.height_),
    weight_ (copy.weight_),
    experience_ (copy.experience_),
    rarity_ (copy.rarity_),
    baseHitPoint_ (copy.baseHitPoint_),
    baseAttack_ (copy.baseAttack_),
    baseDefense_ (copy.baseDefense_),
    baseSpecialAttack_ (copy.baseSpecialAttack_),
    baseSpecialDefense_ (copy.baseSpecialDefense_),
    baseSpeed_ (copy.baseSpeed_),
    type1_ (copy.type1_),
    type2_ (copy.type2_)
  {
  }

  PokemonInfo* PokemonInfo::Clone () const
  {
    return new PokemonInfo (*this);
  }

  void PokemonInfo::SetID (const ID& id)
  {
    pokedexID_ = id;
  }

  void PokemonInfo::SetName (const String& name)
  {
    name_ = name;
  }

  void PokemonInfo::SetDescription (const String& description)
  {
    description_ = description;
  }

  void PokemonInfo::SetSpecies (const String& species) 
  {
    species_ = species;
  }

  void PokemonInfo::SetHeight (const float& value)
  {
    height_ = value;
  }

  void PokemonInfo::SetWeight (const float& value)
  {
    weight_ = value;
  }

  void PokemonInfo::SetExperience (const int& value)
  {
    experience_ = value;
  }

  void PokemonInfo::SetRarity (const int& value)
  {
    rarity_ = value;
  }

  void PokemonInfo::SetHitPoint (const int& value)
  {
    baseHitPoint_ = value;
  }

  void PokemonInfo::SetAttack (const int& value)
  {
    baseAttack_ = value;
  }

  void PokemonInfo::SetDefense (const int& value)
  {
    baseDefense_ = value;
  }

  void PokemonInfo::SetSpecialAttack (const int& value)
  {
    baseSpecialAttack_ = value;
  }

  void PokemonInfo::SetSpecialDefense (const int& value)
  {
    baseSpecialDefense_ = value;
  }

  void PokemonInfo::SetSpeed (const int& value)
  {
    baseSpeed_ = value;
  }

  ID& PokemonInfo::GetID ()
  {
    return pokedexID_;
  }

  String& PokemonInfo::GetName ()
  {
    return name_;
  }

  String& PokemonInfo::GetDescription ()
  {
    return description_;
  }

  String& PokemonInfo::GetSpecies ()
  {
    return species_;
  }

  float& PokemonInfo::GetHeight ()
  {
    return height_;
  }

  float& PokemonInfo::GetWeight ()
  {
    return weight_;
  }

  int& PokemonInfo::GetExperience ()
  {
    return experience_;
  }

  int& PokemonInfo::GetRarity ()
  {
    return rarity_;
  }

  int& PokemonInfo::GetHitPoint ()
  {
    return baseHitPoint_;
  }

  int& PokemonInfo::GetAttack ()
  {
    return baseAttack_;
  }

  int& PokemonInfo::GetDefense ()
  {
    return baseDefense_;
  }

  int& PokemonInfo::GetSpecialAttack ()
  {
    return baseSpecialAttack_;
  }

  int& PokemonInfo::GetSpecialDefense ()
  {
    return baseSpecialDefense_;
  }

  int& PokemonInfo::GetSpeed ()
  {
    return baseSpeed_;
  }

  void PokemonInfo::PrintBaseStats ()
  {
    std::cout << "PokemonInfo Data: " << std::endl
      << "ID: " << pokedexID_.GetValue () << std::endl
      << "Name: " << name_ << std::endl
      << "Description: " << description_ << std::endl
      << "Species: " << species_ << std::endl
      << "Height: " << height_ << std::endl
      << "Weight: " << weight_ << std::endl
      << "Rarity: " << rarity_ << std::endl
      << "Experience: " << experience_ << std::endl
      << "---------------------------------------------" << std::endl
      << "              Base stats" << std::endl
      << "---------------------------------------------" << std::endl
      <<  "HP: " << baseHitPoint_ << std::endl
      <<  "Attack: " << baseAttack_ << std::endl
      <<  "Defense: " << baseDefense_ << std::endl
      <<  "Special Attack: " << baseSpecialAttack_ << std::endl
      <<  "Special Defense: " << baseSpecialDefense_ << std::endl
      <<  "Speed: " << baseSpeed_ << std::endl
      << "---------------------------------------------" << std::endl;
  }
}