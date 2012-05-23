#include "Battle/Phase/EndBattlePhase.hpp"

namespace ycl
{
  const bool EndBattlePhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color EndBattlePhase::DEFAULT_COLOR = sf::Color ();

  EndBattlePhase::EndBattlePhase ()
    : yap::EndBattlePhase ()
  {
  }

  EndBattlePhase::~EndBattlePhase ()
  {
  }

  void EndBattlePhase::HandleStart ()
  {
    BattlePhase::HandleStart ();
  }

  void EndBattlePhase::HandleUpdate (const yap::Time& dt)
  {
  }

  void EndBattlePhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
  }

  void EndBattlePhase::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool EndBattlePhase::IsVisible () const
  {
    return isVisible_;
  }

  void EndBattlePhase::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void EndBattlePhase::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  void EndBattlePhase::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void EndBattlePhase::HandleShow (bool isVisible)
  {
  }

  void EndBattlePhase::HandleChangeColor (const sf::Color& color)
  {
  }
}