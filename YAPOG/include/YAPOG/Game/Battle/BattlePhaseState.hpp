#ifndef YAPOG_BATTLEPHASESTATE_HPP
# define YAPOG_BATTLEPHASESTATE_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  enum class BattlePhaseState : int
  {
    BeginBattle,
    BeginTurn,
    Selection,
    Action,
    EndTurn,
    EndBattle
  };
} // namespace yap

#endif // YAPOG_BATTLEPHASESTATE_HPP
