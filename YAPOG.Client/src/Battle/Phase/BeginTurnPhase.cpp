#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

#include "Battle/Phase/BeginTurnPhase.hpp"
#include "Battle/Battle.hpp"
#include "Battle/BattleInterface.hpp"

namespace ycl
{
  const bool BeginTurnPhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color BeginTurnPhase::DEFAULT_COLOR = sf::Color ();

  BeginTurnPhase::BeginTurnPhase (
    Battle& battle, 
    BattleInterface& battleInterface)
    : yap::BeginTurnPhase (battle)
    , battle_ (battle)
    , battleInterface_ (battleInterface)
  {
  }

  BeginTurnPhase::~BeginTurnPhase ()
  {
  }

  void BeginTurnPhase::HandleStart (const yap::PhaseArgs& args)
  {
    yap::BeginTurnPhase::HandleStart (args);
  }

  void BeginTurnPhase::HandleUpdate (const yap::Time& dt)
  {
     yap::BeginTurnPhase::HandleUpdate (dt);

     yap::BattlePhase::SwitchPhase (yap::BattlePhaseState::Action, phaseArgs_);
  }

  void BeginTurnPhase::HandleEnd ()
  {
    yap::BeginTurnPhase::HandleEnd ();
  }

  void BeginTurnPhase::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool BeginTurnPhase::IsVisible () const
  {
    return isVisible_;
  }

  void BeginTurnPhase::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void BeginTurnPhase::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  void BeginTurnPhase::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void BeginTurnPhase::HandleShow (bool isVisible)
  {
  }

  void BeginTurnPhase::HandleChangeColor (const sf::Color& color)
  {
  }
}