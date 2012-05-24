#include "YAPOG/Game/Pokemon/Pokedex.hpp"

namespace yap
{
  Pokedex::Pokedex ()
  {

  }

  Pokedex::~Pokedex ()
  {

  }


  void Pokedex::AddPokemon (PokemonInfo* pok)
  {
    pokList_.Add (pok);
  }

  void Pokedex::AddPokemonSeen (PokemonInfo* pokSeen)
  {
    pokSeen_.Add (pokSeen->GetID (), pokSeen);
  }

  void Pokedex::AddPokemonCaught (PokemonInfo* pokCaught)
  {
    pokCaught_.Add (pokCaught->GetID (), pokCaught);
  }

  void Pokedex::SetPokemonSeenInfoList (const collection::Map<ID, PokemonInfo*>& pokSeen)
  {
    pokSeen_ = pokSeen;
  }

  void Pokedex::SetPokemonCaughtInfoList (const collection::Map<ID, PokemonInfo*>& pokCaught)
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