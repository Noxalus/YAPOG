#include "Battle/PlayerTrainer.hpp"
//#include "Battle/PokemonFighterTeam.hpp"
#include "Pokemon/PokemonTeam.hpp"
#include "YAPOG/Game/Pokemon/Pokedex.hpp"
#include "YAPOG/System/Error/Exception.hpp"

namespace ycl
{
  PlayerTrainer::PlayerTrainer ()
    : yap::PlayerTrainer ()
    , team_ (nullptr)
    , pokedex_ (nullptr)
  {
  }

  PlayerTrainer::~PlayerTrainer ()
  {
  }

  /// Getters.
  /*
  PokemonFighterTeam& PlayerTrainer::GetTeam ()
  { return *team_; }
  */
  PokemonTeam& PlayerTrainer::GetTeam ()
  { return *team_; }

  /// Setters.
  /*
  void PlayerTrainer::SetTeam (PokemonFighterTeam* value)
  { team_ = value; }
  */

  void PlayerTrainer::SetTeam (PokemonTeam* value)
  { team_ = value; }

  void PlayerTrainer::SetPokedex (yap::Pokedex* value)
  { pokedex_ = value; }

} // namespace yap