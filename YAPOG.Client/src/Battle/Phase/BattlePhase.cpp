#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

#include "Battle/Phase/BattlePhase.hpp"
#include "Battle/Battle.hpp"

namespace ycl
{
  const bool BattlePhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color BattlePhase::DEFAULT_COLOR = sf::Color ();
  const yap::BattlePhaseState BattlePhase::DEFAULT_BATTLE_PHASE_STATE
    = yap::BattlePhaseState::BeginBattle;

  BattlePhase::BattlePhase (Battle& battle)
    : yap::BattlePhase (battle, DEFAULT_BATTLE_PHASE_STATE)
    , battle_ (battle)
  {
  }

  BattlePhase::BattlePhase (
    Battle& battle, 
    const yap::BattlePhaseState& battlePhaseState)
    : yap::BattlePhase (battle, battlePhaseState)
    , battle_ (battle)
  {
  }

  BattlePhase::~BattlePhase ()
  {
  }

  void BattlePhase::HandleStart (const yap::PhaseArgs& args)
  {
    yap::BattlePhase::HandleStart (args);
  }

  void BattlePhase::HandleUpdate (const yap::Time& dt)
  {
     yap::BattlePhase::HandleUpdate (dt);
  }

  void BattlePhase::HandleEnd ()
  {
    yap::BattlePhase::HandleEnd ();
  }

  void BattlePhase::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool BattlePhase::IsVisible () const
  {
    return isVisible_;
  }

  void BattlePhase::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void BattlePhase::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  void BattlePhase::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void BattlePhase::HandleShow (bool isVisible)
  {
  }

  void BattlePhase::HandleChangeColor (const sf::Color& color)
  {
  }
}