#include "Battle/Phase/BeginTurnPhase.hpp"
#include "Battle/Battle.hpp"

namespace ycl
{
  const bool BeginTurnPhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color BeginTurnPhase::DEFAULT_COLOR = sf::Color ();

  BeginTurnPhase::BeginTurnPhase (Battle& battle)
    : yap::BeginTurnPhase (battle)
    , battle_ (battle)
  {
  }

  BeginTurnPhase::~BeginTurnPhase ()
  {
  }

  void BeginTurnPhase::HandleStart ()
  {
    BattlePhase::HandleStart ();
  }

  void BeginTurnPhase::HandleUpdate (const yap::Time& dt)
  {
  }

  void BeginTurnPhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
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