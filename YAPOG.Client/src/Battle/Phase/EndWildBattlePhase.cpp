#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

#include "Battle/Phase/EndWildBattlePhase.hpp"
#include "Battle/Battle.hpp"
#include "Battle/BattleInterface.hpp"

namespace ycl
{
  const bool EndWildBattlePhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color EndWildBattlePhase::DEFAULT_COLOR = sf::Color ();

  EndWildBattlePhase::EndWildBattlePhase (
    Battle& battle, 
    BattleInterface& battleInterface)
    : EndBattlePhase (battle, battleInterface)
  {
  }

  EndWildBattlePhase::~EndWildBattlePhase ()
  {
  }

  void EndWildBattlePhase::HandleStart (const yap::PhaseArgs& args)
  {
     ycl::EndBattlePhase::HandleStart (args);
  }

  void EndWildBattlePhase::HandleUpdate (const yap::Time& dt)
  {
    ycl::EndBattlePhase::HandleUpdate (dt);
  }

  void EndWildBattlePhase::HandleEnd ()
  {
    ycl::EndBattlePhase::HandleEnd ();
  }

  void EndWildBattlePhase::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void EndWildBattlePhase::HandleShow (bool isVisible)
  {
  }

  void EndWildBattlePhase::HandleChangeColor (const sf::Color& color)
  {
  }
}