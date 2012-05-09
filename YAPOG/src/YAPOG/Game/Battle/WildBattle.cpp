#include "YAPOG/Game/Battle/WildBattle.hpp"
#include "YAPOG/Game/Pokemon/PokemonSkill.hpp"

using namespace std;

namespace yap
{
  WildBattle::WildBattle (
    PokemonTeam& playerTeam, 
    Pokemon* wildPokemon)
    : Battle (playerTeam)
    , wildPokemon_ (wildPokemon)
  {
    currentOpponent_ = PokemonFighter (wildPokemon);
  }

  void WildBattle::DisplayBeginMessage ()
  {
    cout 
      << "Un " << wildPokemon_->GetName () 
      << " sauvage apparait !" 
      << endl;
  }

} // namespace yap