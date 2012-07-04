#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

#include "Battle/Phase/RunWildBattlePhase.hpp"
#include "Battle/Battle.hpp"
#include "Battle/BattleInterface.hpp"

namespace ycl
{
  const bool RunWildBattlePhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color RunWildBattlePhase::DEFAULT_COLOR = sf::Color ();

  RunWildBattlePhase::RunWildBattlePhase (Battle& battle, BattleInterface& battleInterface)
    : yap::RunWildBattlePhase (battle)
    , battle_ (battle)
    , battleInterface_ (battleInterface)
  {
  }

  RunWildBattlePhase::~RunWildBattlePhase ()
  {
  }

  void RunWildBattlePhase::Init ()
  {
  }

  void RunWildBattlePhase::HandleStart (yap::PhaseArgs* args)
  {
    BattlePhase::HandleStart (args);
  }

  void RunWildBattlePhase::HandleUpdate (const yap::Time& dt)
  {
    BattlePhase::HandleUpdate (dt);
  }

  void RunWildBattlePhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
  }

  void RunWildBattlePhase::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool RunWildBattlePhase::IsVisible () const
  {
    return isVisible_;
  }

  void RunWildBattlePhase::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void RunWildBattlePhase::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  void RunWildBattlePhase::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void RunWildBattlePhase::HandleShow (bool isVisible)
  {
  }

  void RunWildBattlePhase::HandleChangeColor (const sf::Color& color)
  {
  }
}