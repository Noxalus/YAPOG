#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"
#include "YAPOG/Game/Battle/Phase/BattlePhase.hpp"

namespace yap
{
  PhaseArgs::PhaseArgs ()
    : choice_ (BattleChoice::None)
    , index_ (0)
  {
  }
}