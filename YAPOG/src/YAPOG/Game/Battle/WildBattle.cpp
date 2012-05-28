#include "YAPOG/Game/Battle/WildBattle.hpp"

namespace yap
{
  WildBattle::WildBattle ()
    : Battle ()
  {
  }

  WildBattle::~WildBattle ()
  {
  }

  void WildBattle::HandleInit ()
  {
    Battle::HandleInit ();
  }

  void WildBattle::HandleUpdate (const Time& dt)
  {
    Battle::HandleUpdate (dt);
  }

} // namespace yap