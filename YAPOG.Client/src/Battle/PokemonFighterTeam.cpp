#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"
#include "YAPOG/Collection/Array.hpp"

#include "Pokemon/Pokemon.hpp"
#include "Pokemon/PokemonTeam.hpp"
#include "Battle/PokemonFighter.hpp"
#include "Battle/PokemonFighterTeam.hpp"

namespace ycl
{
  PokemonFighterTeam::PokemonFighterTeam ()
    : yap::PokemonFighterTeam ()
    , fighters_ (PokemonTeam::MAX_POKEMON_TEAM_NUMBER, nullptr)
  {
  }

  PokemonFighterTeam::~PokemonFighterTeam ()
  {
  }

  PokemonFighter* PokemonFighterTeam::GetPokemon (int index) const
  {
    return fighters_[index];
  }

  bool PokemonFighterTeam::AddPokemon (PokemonFighter* pokemonFighter)
  {
    for (int i = 0; i < PokemonTeam::MAX_POKEMON_TEAM_NUMBER; i++)
    {
      if (fighters_[i] == nullptr)
      {
        fighters_[i] = pokemonFighter;
        return true;
      }
    }

    return false;
  }

  PokemonFighter* PokemonFighterTeam::GetCurrentFighter () const
  {
    return fighters_[currentFighterIndex_];
  }

  yap::ISprite& PokemonFighterTeam::GetFrontSprite ()
  {
    return GetCurrentFighter ()->GetFrontSprite ();
  }

  yap::ISprite& PokemonFighterTeam::GetBackSprite ()
  {
    return GetCurrentFighter ()->GetBackSprite ();
  }

} // namespace yap