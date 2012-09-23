#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"

#include "Battle/WildBattle.hpp"
#include "Battle/Phase/BeginWildBattlePhase.hpp"
#include "Battle/Phase/SelectionPhase.hpp"
#include "Battle/Phase/BeginTurnPhase.hpp"
#include "Battle/Phase/ActionPhase.hpp"
#include "Battle/Phase/EndTurnPhase.hpp"
#include "Battle/Phase/EndPokemonSwitchPhase.hpp"
#include "Battle/Phase/RunWildBattlePhase.hpp"
#include "Battle/Phase/EndWildBattlePhase.hpp"
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

    BeginWildBattlePhase* beginWildBattlePhase = 
      new BeginWildBattlePhase (*this, battleInterface_);
    EndPokemonSwitchPhase* switchPhase = 
      new EndPokemonSwitchPhase (*this, battleInterface_);
    SelectionPhase* selectionPhase = 
      new SelectionPhase (*this, battleInterface_);
    BeginTurnPhase* beginTurnPhase = 
      new BeginTurnPhase (*this, battleInterface_);
    ActionPhase* actionPhase = new ActionPhase (*this, battleInterface_);
    EndTurnPhase* endTurnPhase = new EndTurnPhase (*this, battleInterface_);
    RunWildBattlePhase* runPhase = new RunWildBattlePhase (*this, battleInterface_);
    EndWildBattlePhase* endBattlePhase = 
      new EndWildBattlePhase (*this, battleInterface_);

    beginWildBattlePhase->Init ();
    selectionPhase->Init ();

    AddPhase (yap::BattlePhaseState::BeginBattle, beginWildBattlePhase);
    AddPhase (yap::BattlePhaseState::Switch, switchPhase);
    AddPhase (yap::BattlePhaseState::Selection, selectionPhase);
    AddPhase (yap::BattlePhaseState::BeginTurn, beginTurnPhase);
    AddPhase (yap::BattlePhaseState::Action, actionPhase);
    AddPhase (yap::BattlePhaseState::EndTurn, endTurnPhase);
    AddPhase (yap::BattlePhaseState::Run, runPhase);
    AddPhase (yap::BattlePhaseState::EndBattle, endBattlePhase);
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