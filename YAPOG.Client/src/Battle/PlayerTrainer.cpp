#include "Battle/PlayerTrainer.hpp"
#include "Battle/PokemonFighterTeam.hpp"
#include "YAPOG/Game/Pokemon/Pokedex.hpp"

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

  void PlayerTrainer::SetTeam (PokemonFighterTeam* value)
  {
    team_ = value;
  }

  void PlayerTrainer::SetPokedex (yap::Pokedex* value)
  {
    pokedex_ = value;
  }

} // namespace yap