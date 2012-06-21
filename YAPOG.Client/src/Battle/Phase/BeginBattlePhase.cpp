#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"
#include "YAPOG/Graphics/Gui/DialogBoxWidget.hpp"
#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

#include "Battle/Phase/BeginBattlePhase.hpp"
#include "Battle/OpponentBattleInfoWidget.hpp"
#include "Battle/BattleInterface.hpp"
#include "Battle/Battle.hpp"
#include "Game.hpp"

namespace ycl
{
  const bool BeginBattlePhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color BeginBattlePhase::DEFAULT_COLOR = sf::Color ();

  BeginBattlePhase::BeginBattlePhase (Battle& battle, BattleInterface& battleInterface)
    : yap::BeginBattlePhase (battle)
    , battle_ (battle)
    , battleInterface_  (battleInterface)
  {
  }

  BeginBattlePhase::~BeginBattlePhase ()
  {
  }

  void BeginBattlePhase::HandleStart (yap::PhaseArgs* args)
  {
    yap::BeginBattlePhase::HandleStart (args);
  }

  void BeginBattlePhase::HandleUpdate (const yap::Time& dt)
  {
    yap::BeginBattlePhase::HandleUpdate (dt);
  }

  void BeginBattlePhase::HandleEnd ()
  {
    yap::BeginBattlePhase::HandleEnd ();
  }

  void BeginBattlePhase::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool BeginBattlePhase::IsVisible () const
  {
    return isVisible_;
  }

  void BeginBattlePhase::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void BeginBattlePhase::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  void BeginBattlePhase::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void BeginBattlePhase::HandleShow (bool isVisible)
  {
  }

  void BeginBattlePhase::HandleChangeColor (const sf::Color& color)
  {
  }
}