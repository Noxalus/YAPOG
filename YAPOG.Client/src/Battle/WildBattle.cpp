#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"

#include "Battle/WildBattle.hpp"
#include "Battle/Phase/BeginBattlePhase.hpp"
#include "Battle/Battle.hpp"
#include "Battle/BattleInterface.hpp"

namespace ycl
{
  WildBattle::WildBattle (BattleInterface& battleInterface)
    : Battle ()
    , battleInterface_ (battleInterface)
  {
    // DO NOT INIT BATTLE PHASE HERE !
  }

  WildBattle::~WildBattle ()
  {
  }

  void WildBattle::HandleInit ()
  {
    Battle::HandleInit ();

    BeginBattlePhase* beginBattlePhase = new BeginBattlePhase (*this, battleInterface_);

    AddPhase (yap::BattlePhaseState::BeginBattle, beginBattlePhase);
  }

  void WildBattle::HandleUpdate (const yap::Time& dt)
  {
    Battle::HandleUpdate (dt);
  }

  void WildBattle::HandleDraw (yap::IDrawingContext& context)
  {
    Battle::HandleDraw (context);
  }

  void WildBattle::HandleShow (bool isVisible)
  {
  }

  void WildBattle::HandleChangeColor (const sf::Color& color)
  {
  }

} // namespace yap