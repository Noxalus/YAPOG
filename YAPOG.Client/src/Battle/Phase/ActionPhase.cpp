#include "Battle/Phase/ActionPhase.hpp"

namespace ycl
{
  const bool ActionPhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color ActionPhase::DEFAULT_COLOR = sf::Color ();

  ActionPhase::ActionPhase ()
    : yap::ActionPhase ()
  {
  }

  ActionPhase::~ActionPhase ()
  {
  }

  void ActionPhase::HandleStart ()
  {
    BattlePhase::HandleStart ();
  }

  void ActionPhase::HandleUpdate (const yap::Time& dt)
  {
  }

  void ActionPhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
  }

  void ActionPhase::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool ActionPhase::IsVisible () const
  {
    return isVisible_;
  }

  void ActionPhase::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void ActionPhase::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  void ActionPhase::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void ActionPhase::HandleShow (bool isVisible)
  {
  }

  void ActionPhase::HandleChangeColor (const sf::Color& color)
  {
  }
}