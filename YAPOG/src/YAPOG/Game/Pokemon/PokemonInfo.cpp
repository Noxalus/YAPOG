#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"

namespace yap
{
  PokemonInfo::PokemonInfo (const ID& id)
    : pokedexID_ (id)
  {
  }

  PokemonInfo::PokemonInfo (const PokemonInfo& copy)
    : pokedexID_ (copy.pokedexID_),
    name_ (copy.name_)

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

  void PokemonInfo::SetHitPoint (int value)
  {
    baseHitPoint_ = value;
  }

  void PokemonInfo::SetAttack (int value)
  {
    baseAttack_ = value;
  }

  ID& PokemonInfo::GetID ()
  {
    return pokedexID_;
  }

  String& PokemonInfo::GetName ()
  {
    return name_;
  }
}