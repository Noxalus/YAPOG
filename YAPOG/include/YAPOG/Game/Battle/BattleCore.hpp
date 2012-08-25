#ifndef YAPOG_BATTLECORE_HPP
# define YAPOG_BATTLECORE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/PokemonStat.hpp"
# include "YAPOG/Game/Pokemon/PokemonTeam.hpp"
# include "YAPOG/Game/Battle/PokemonFighter.hpp"

namespace yap
{
  class YAPOG_LIB BattleCore
  {
  public:
    BattleCore ();

    int ComputeDamage (
      const PokemonMove& move, 
      const PokemonFighter& attacker, 
      const PokemonFighter& defender);
  };
} // namespace yap

#endif // YAPOG_BATTLECORE_HPP
