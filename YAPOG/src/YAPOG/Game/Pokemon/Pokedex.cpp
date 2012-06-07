#include "YAPOG/Game/Pokemon/Pokedex.hpp"

namespace yap
{
  Pokedex::Pokedex ()
    : pokCaught_ ()
    , pokList_ ()
    , pokSeen_ ()
  {

  }

  Pokedex::~Pokedex ()
  {

  }

  uint Pokedex::GetPokemonSeenCount () const
  {
    return pokSeen_.Count ();
  }
  uint Pokedex::GetPokemonCaughtCount () const
  {
    return pokCaught_.Count ();
  }
  uint Pokedex::GetPokemonCount () const
  {
    return pokList_.Count ();
  }

  uint Pokedex::GetMaxIDSeen () const
  {
    ID maxID (0);
    for (PokemonInfo* pok : pokSeen_)
    {
      if (pok->GetID () > maxID)
        maxID = pok->GetID ();
    }

    return maxID.GetValue ();
  }
  const PokemonInfo& Pokedex::GetPokemonSeen (uint index) const
  {
    return *pokSeen_[index];
  }

  PokemonInfo* Pokedex::GetPokemon (uint index) const
  {
    if (index < pokList_.Count ())
      return pokList_[index];
    else
    {
      return nullptr;
    }
  }
  const PokemonInfo* Pokedex::GetPokemonSeenID (uint ID) const
  {
    for (PokemonInfo* pok : pokSeen_)
    {
      if (pok->GetID ().GetValue () == ID)
        return pok;
    }
    return nullptr;
  }

  void Pokedex::AddPokemon (PokemonInfo* pok)
  {
    pokList_.Add (pok);
  }

  void Pokedex::AddPokemonSeen (PokemonInfo* pokSeen)
  {
    pokSeen_.Add (pokSeen);
  }

  void Pokedex::AddPokemonCaught (PokemonInfo* pokCaught)
  {
    pokCaught_.Add (pokCaught);
  }

  void Pokedex::SetPokemonSeenInfoList (const collection::Array<PokemonInfo*>& pokSeen)
  {
    pokSeen_ = pokSeen;
  }

  void Pokedex::SetPokemonCaughtInfoList (const collection::Array<PokemonInfo*>& pokCaught)
  {
    pokCaught_ = pokCaught;
  }

  void Pokedex::SetPokemonList (const collection::Array<PokemonInfo*>& pokList)
  {
    pokList_ = pokList;
  }

  void Pokedex::Init ()
  {

  }
}