#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "Pokemon/PokemonTeam.hpp"

namespace yse
{
  PokemonTeam::PokemonTeam ()
    : yap::PokemonTeam ()
    , pokemonTeam_ (MAX_POKEMON_TEAM_NUMBER, nullptr)
    , pokemonNumber_ (0)
  {
  }

  PokemonTeam::~PokemonTeam ()
  {
  }

  Pokemon* PokemonTeam::GetPokemon (int index) const
  {
    if (index >= MAX_POKEMON_TEAM_NUMBER)
      YAPOG_THROW("Pokemon Team: index out of bound (" + yap::StringHelper::ToString (index) + ")");

    if (pokemonTeam_[index] == nullptr)
      YAPOG_THROW("Pokemon Team: no Pokemon at this index (" + yap::StringHelper::ToString (index) + ")");

    return pokemonTeam_[index];
  }

  int PokemonTeam::GetPokemonCount () const
  {
    return pokemonNumber_;
  }


  bool PokemonTeam::AddPokemon (Pokemon* pokemon)
  {
    for (int i = 0; i < MAX_POKEMON_TEAM_NUMBER; i++)
    {
      if (pokemonTeam_[i] == nullptr)
      {
        pokemonTeam_[i] = pokemon;
        pokemonNumber_++;

        return true;
      }
    }

    return false;
  }
} // namespace yse