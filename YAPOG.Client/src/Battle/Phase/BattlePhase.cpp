#include "Battle/Phase/BattlePhase.hpp"

namespace ycl
{
  const bool BattlePhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color BattlePhase::DEFAULT_COLOR = sf::Color ();
  const yap::BattlePhaseState BattlePhase::DEFAULT_BATTLE_PHASE_STATE
    = yap::BattlePhaseState::BeginBattle;

  BattlePhase::BattlePhase ()
    : yap::BattlePhase (DEFAULT_BATTLE_PHASE_STATE)
  {
  }

  BattlePhase::BattlePhase (
    const yap::BattlePhaseState& battlePhaseState)
    : yap::BattlePhase (battlePhaseState)
  {
  }

  BattlePhase::~BattlePhase ()
  {
  }

  void BattlePhase::HandleStart ()
  {
    BattlePhase::HandleStart ();
  }

  void BattlePhase::HandleUpdate (const yap::Time& dt)
  {
  }

  void BattlePhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
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