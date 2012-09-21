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
    , battleParameters_ (nullptr)
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

  yap::UInt32 PlayerTrainer::GetPokemonCaughtCount () const
  {
    return pokedex_->GetPokemonCaughtCount ();
  }

  BattleParameters& 
    PlayerTrainer::GetBattleParameters () const
  { return *battleParameters_; }

  /// Setters.
  /*
  void PlayerTrainer::SetTeam (PokemonFighterTeam* value)
  { team_ = value; }
  */

  void PlayerTrainer::SetTeam (PokemonTeam* value)
  { team_ = value; }

  void PlayerTrainer::SetPokedex (yap::Pokedex* value)
  { pokedex_ = value; }

  void PlayerTrainer::SetBattleParameters (BattleParameters* value)
  { battleParameters_ = value; }

} // namespace yap