#include "YAPOG/Game/Battle/PokemonFighterTeam.hpp"
#include "YAPOG/System/Error/Exception.hpp"

namespace yap
{
  PokemonFighterTeam::PokemonFighterTeam ()
    : pokemons_ (PokemonTeam::MAX_POKEMON_TEAM_NUMBER, nullptr)
  {
  }

  PokemonFighterTeam::PokemonFighterTeam (const PokemonTeam& pokemonTeam)
    : pokemons_ (PokemonTeam::MAX_POKEMON_TEAM_NUMBER, nullptr)
  {
    int i = 0;
    for (Pokemon* p : pokemonTeam.GetTeam ())
    {
      if (p == nullptr)
        break;

      pokemons_[i] = new PokemonFighter (p);
      i++;
    }
  }

  PokemonFighter* PokemonFighterTeam::GetPokemon (int index) const
  {
    /*
    if (index >= PokemonTeam::MAX_POKEMON_TEAM_NUMBER)
    {
    YAPOG_THROW("Pokemon Team: index out of bound (" + 
    StringHelper::ToString (index) + ")");
    }

    if (pokemons_[index] == nullptr)
    {
    YAPOG_THROW("Pokemon Team: no Pokemon at this index (" + 
    StringHelper::ToString (index) + ")");
    }
    */

    return pokemons_[index];
  }

  bool PokemonFighterTeam::AddPokemon (PokemonFighter* pokemonFighter)
  {
    for (int i = 0; i < PokemonTeam::MAX_POKEMON_TEAM_NUMBER; i++)
    {
      if (pokemons_[i] == nullptr)
      {
        pokemons_[i] = pokemonFighter;
        return true;
      }
    }

    return false;
  }

  const collection::Array<PokemonFighter*>& PokemonFighterTeam::GetTeam () const
  {
    return pokemons_;
  }

  /// Debug
  void PokemonFighterTeam::PrintTeam ()
  {
    for (int i = 0; i < PokemonTeam::MAX_POKEMON_TEAM_NUMBER; i++)
    {
      if (pokemons_[i] != nullptr)
      {
        std::cout << pokemons_[i]->GetName () 
          << " (lvl. " << pokemons_[i]->GetLevel () << ")"
          << std::endl;

        pokemons_[i]->PrintStats ();
      }
      else
        std::cout << "[NO POKEMON] " << std::endl;
    }
  }
}