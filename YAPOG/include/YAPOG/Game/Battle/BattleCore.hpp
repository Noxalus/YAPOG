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
      const IBattleEntity& attacker, 
      const IBattleEntity& defender) const;

    UInt32 ComputeExperienceGain () const;
  };
} // namespace yap

#endif // YAPOG_BATTLECORE_HPP
