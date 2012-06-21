#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

#include "Battle/Phase/EndWildBattlePhase.hpp"
#include "Battle/Battle.hpp"

namespace ycl
{
  const bool EndWildBattlePhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color EndWildBattlePhase::DEFAULT_COLOR = sf::Color ();

  EndWildBattlePhase::EndWildBattlePhase (Battle& battle)
    : yap::EndWildBattlePhase (battle)
    , battle_ (battle)
  {
  }

  EndWildBattlePhase::~EndWildBattlePhase ()
  {
  }

  void EndWildBattlePhase::HandleStart (yap::PhaseArgs* args)
  {
    BattlePhase::HandleStart (args);
  }

  void EndWildBattlePhase::HandleUpdate (const yap::Time& dt)
  {
  }

  void EndWildBattlePhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
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