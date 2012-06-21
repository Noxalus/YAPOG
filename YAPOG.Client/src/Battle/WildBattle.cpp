#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"

#include "Battle/WildBattle.hpp"
#include "Battle/Phase/BeginWildBattlePhase.hpp"
#include "Battle/Phase/SelectionPhase.hpp"
#include "Battle/Phase/EndPokemonSwitchPhase.hpp"
#include "Battle/Battle.hpp"
#include "Battle/BattleInterface.hpp"

namespace ycl
{
  WildBattle::WildBattle (BattleInterface& battleInterface)
    : Battle (battleInterface)
  {
    // DO NOT INIT BATTLE PHASE HERE !
  }

  WildBattle::~WildBattle ()
  {
  }

  void WildBattle::HandleInit ()
  {
    Battle::HandleInit ();

    /*
    BeginWildBattlePhase* beginWildBattlePhase = 
      new BeginWildBattlePhase (*this, battleInterface_);
    EndPokemonSwitchPhase* switchPhase = new EndPokemonSwitchPhase (*this, battleInterface_);
    SelectionPhase* selectionPhase = new SelectionPhase (*this, battleInterface_);

    AddPhase (yap::BattlePhaseState::BeginBattle, beginWildBattlePhase);
    AddPhase (yap::BattlePhaseState::Switch, switchPhase);
    AddPhase (yap::BattlePhaseState::Selection, selectionPhase);
    */
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