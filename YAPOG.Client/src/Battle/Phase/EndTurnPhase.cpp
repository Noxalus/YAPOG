#include "Battle/Phase/EndTurnPhase.hpp"
#include "Battle/Battle.hpp"

namespace ycl
{
  const bool EndTurnPhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color EndTurnPhase::DEFAULT_COLOR = sf::Color ();

  EndTurnPhase::EndTurnPhase (Battle& battle)
    : yap::EndTurnPhase (battle)
    , battle_ (battle)
  {
  }

  EndTurnPhase::~EndTurnPhase ()
  {
  }

  void EndTurnPhase::HandleStart (yap::PhaseArgs* args)
  {
    BattlePhase::HandleStart (args);
  }

  void EndTurnPhase::HandleUpdate (const yap::Time& dt)
  {
  }

  void EndTurnPhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
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