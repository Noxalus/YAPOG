#include "Battle/Phase/EndTurnPhase.hpp"
#include "Battle/Battle.hpp"
#include "Battle/BattleInterface.hpp"

namespace ycl
{
  const bool EndTurnPhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color EndTurnPhase::DEFAULT_COLOR = sf::Color ();

  EndTurnPhase::EndTurnPhase (
    Battle& battle, 
    BattleInterface& battleInterface)
    : yap::EndTurnPhase (battle)
    , battle_ (battle)
    , battleInterface_  (battleInterface)
  {
  }

  EndTurnPhase::~EndTurnPhase ()
  {
  }

  void EndTurnPhase::HandleStart (const yap::PhaseArgs& args)
  {
    yap::EndTurnPhase::HandleStart (args);
  }

  void EndTurnPhase::HandleUpdate (const yap::Time& dt)
  {
     yap::EndTurnPhase::HandleUpdate (dt);

     if (battle_.GetPlayerTeam ().GetCurrentHP () == 0 ||
       battle_.GetOpponent ().GetCurrentHP () == 0)
      BattlePhase::SwitchPhase (yap::BattlePhaseState::EndBattle);
     else
      yap::BattlePhase::SwitchPhase (yap::BattlePhaseState::Selection);
  }

  void EndTurnPhase::HandleEnd ()
  {
    yap::EndTurnPhase::HandleEnd ();
  }

  void EndTurnPhase::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool EndTurnPhase::IsVisible () const
  {
    return isVisible_;
  }

  void EndTurnPhase::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void EndTurnPhase::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  void EndTurnPhase::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void EndTurnPhase::HandleShow (bool isVisible)
  {
  }

  void EndTurnPhase::HandleChangeColor (const sf::Color& color)
  {
  }
}