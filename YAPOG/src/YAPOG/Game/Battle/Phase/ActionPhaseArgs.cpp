#include "YAPOG/Game/Battle/Phase/ActionPhaseArgs.hpp"
#include "YAPOG/Game/Battle/Phase/BattlePhase.hpp"

namespace yap
{
  ActionPhaseArgs::ActionPhaseArgs ()
  {
  }

  void ActionPhaseArgs::Accept (BattlePhase& visitor)
  {
    visitor.Visit (*this);
  }
}