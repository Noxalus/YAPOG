#include "YAPOG/Game/Battle/WildBattle.hpp"
#include "YAPOG/Game/Pokemon/PokemonSkill.hpp"

using namespace std;

namespace yap
{
  WildBattle::WildBattle (
      IBattleEntity& playerTeam, 
      IBattleEntity& wildPokemon)
      : Battle (playerTeam, wildPokemon)
  {
  }

} // namespace yap