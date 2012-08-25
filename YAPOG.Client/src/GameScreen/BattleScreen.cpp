#include "YAPOG/Audio/AudioManager.hpp"
#include "YAPOG/Graphics/Gui/GuiManager.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"

#include "GameScreen/BattleScreen.hpp"
#include "Game.hpp"
#include "Battle/WildBattle.hpp"
#include "Battle/BattleInterface.hpp"
#include "Pokemon/Pokemon.hpp"
#include "Pokemon/PokemonTeam.hpp"
#include "Battle/PokemonFighter.hpp"
#include "Battle/PokemonFighterTeam.hpp"
#include "Client/Session.hpp"
#include "Battle/PlayerTrainer.hpp"

namespace ycl
{
  const yap::ScreenType BattleScreen::DEFAULT_NAME = "Battle";

  BattleScreen::BattleScreen (yap::IDrawingContext& context)
    : BaseScreen (DEFAULT_NAME, context)
    , battleInterface_ (nullptr)
  {
  }

  BattleScreen::~BattleScreen ()
  {
  }

  void BattleScreen::HandleInit ()
  {
    BaseScreen::HandleInit ();

    battleInterface_ = new BattleInterface ();

    guiManager_->AddChild (*battleInterface_);
  }

  void BattleScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    context.SetMode ("Battle");

    battle_->Update (dt);
    battle_->Draw (context);

    context.SetDefaultCamera ();

    BaseScreen::HandleRun (dt, context);
  }

  void BattleScreen::HandleActivate ()
  {
    yap::AudioManager::Instance ().PlayMusic ("BGM/WildPokemonBattleShort.ogg");
  }

  void BattleScreen::HandleDeactivate ()
  {
    battleInterface_->Reset ();
  }

  void BattleScreen::SetBattle (Battle* value)
  {
    battle_ = value;
  }
} // namespace ycl
