#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

#include "Battle/Phase/EndTrainerBattlePhase.hpp"
#include "Battle/Battle.hpp"

namespace ycl
{
  const bool EndTrainerBattlePhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color EndTrainerBattlePhase::DEFAULT_COLOR = sf::Color ();

  EndTrainerBattlePhase::EndTrainerBattlePhase (Battle& battle)
    : yap::EndTrainerBattlePhase (battle)
    , battle_ (battle)
  {
  }

  EndTrainerBattlePhase::~EndTrainerBattlePhase ()
  {
  }

  void EndTrainerBattlePhase::HandleStart (yap::PhaseArgs* args)
  {
    BattlePhase::HandleStart (args);
  }

  void EndTrainerBattlePhase::HandleUpdate (const yap::Time& dt)
  {
  }

  void EndTrainerBattlePhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
  }

  void EndTrainerBattlePhase::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void EndTrainerBattlePhase::HandleShow (bool isVisible)
  {
  }

  void EndTrainerBattlePhase::HandleChangeColor (const sf::Color& color)
  {
  }
}