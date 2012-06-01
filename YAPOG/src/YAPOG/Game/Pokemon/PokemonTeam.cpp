#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Game/Pokemon/PokemonTeam.hpp"

namespace yap
{
  const int PokemonTeam::MAX_POKEMON_TEAM_NUMBER = 6;

  PokemonTeam::PokemonTeam ()
    : pokemonTeam_ (MAX_POKEMON_TEAM_NUMBER, nullptr)
  {
  }

  Pokemon* PokemonTeam::GetPokemon (int index) const
  {
    if (index >= MAX_POKEMON_TEAM_NUMBER)
      YAPOG_THROW("Pokemon Team: index out of bound (" + StringHelper::ToString (index) + ")");

    if (pokemonTeam_[index] == nullptr)
      YAPOG_THROW("Pokemon Team: no Pokemon at this index (" + StringHelper::ToString (index) + ")");

    return pokemonTeam_[index];
  }

  bool PokemonTeam::AddPokemon (Pokemon* pokemon)
  {
    for (int i = 0; i < MAX_POKEMON_TEAM_NUMBER; i++)
    {
      if (pokemonTeam_[i] == nullptr)
      {
        pokemonTeam_[i] = pokemon;
        return true;
      }
    }

    return false;
  }

  /// Debug
  void PokemonTeam::PrintTeam ()
  {
    for (int i = 0; i < MAX_POKEMON_TEAM_NUMBER; i++)
    {
      if (pokemonTeam_[i] != nullptr)
      {
        std::cout << pokemonTeam_[i]->GetName () 
          << " (lvl. " << pokemonTeam_[i]->GetLevel () << ")"
          << std::endl;

        pokemonTeam_[i]->PrintStats ();
      }
      else
        std::cout << "[NO POKEMON] " << std::endl;
    }
  }
}