#include "YAPOG/Game/Pokemon/Pokedex.hpp"

namespace yap
{
  Pokedex::Pokedex ()  
  {

  }
  Pokedex::~Pokedex ()  
  {

  }

  void Pokedex::SetPokemonSeenInfoList (const collection::Map<ID, Pokedex*>& pokSeen)
  {
    pokSeen_ = pokSeen;
  }

  void Pokedex::SetPokemonCaughtInfoList (const collection::Map<ID, Pokedex*>& pokCaught)
  {
    pokCaught_ = pokCaught;
  }

  void Pokedex::SetPokemonList (const collection::Array<Pokedex*>& pokList)
  {
    pokList_ = pokList;
  }

  void Pokedex::Init ()
  {

  }
}