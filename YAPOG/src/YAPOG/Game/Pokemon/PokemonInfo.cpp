#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"

namespace yap
{
  PokemonInfo::PokemonInfo (const ID& id)
    : pokedexID_ (id)
  {
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
}