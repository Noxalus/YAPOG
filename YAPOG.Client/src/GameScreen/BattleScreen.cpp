#include "YAPOG/Audio/AudioManager.hpp"
#include "YAPOG/Graphics/Gui/GuiManager.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"
#include "YAPOG/System/RandomHelper.hpp"

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
#include "Gui/PokemonTeamWidget.hpp"

namespace debug
{
  ycl::Pokemon* GenerateRandomPokemon ()
  {
    yap::ID staticID = yap::ID (yap::RandomHelper::GetNext (1, 5));

    if (staticID == yap::ID (5))
      staticID = yap::ID (16);

    int level = yap::RandomHelper::GetNext (1, 100);

    ycl::Pokemon* p = new ycl::Pokemon (staticID, level, false);

    return p;
  }
}

namespace ycl
{
  const yap::ScreenType BattleScreen::DEFAULT_NAME = "Battle";

  BattleScreen::BattleScreen ()
    : BaseScreen (DEFAULT_NAME)
    , battle_ (nullptr)
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
    /*
    PokemonTeam* team = new PokemonTeam ();
    team->AddPokemon (new Pokemon (yap::ID (2), 100, false));
    team->AddPokemon (new Pokemon (yap::ID (16), 32, true));
    */

    PokemonTeam& playerTeam = session_.GetUser ().GetTrainer ().GetTeam ();

    PokemonFighterTeam* playerFighterTeam = new PokemonFighterTeam ();
    playerFighterTeam->LoadFromPokemonTeam (playerTeam, false);

    PokemonFighter* wildPokemon =
      new PokemonFighter (debug::GenerateRandomPokemon (), true);

    battle_ = new WildBattle (*battleInterface_);

    battle_->SetPlayerTeam (playerFighterTeam);
    battle_->SetOpponent (wildPokemon);
    battle_->Init ();

    battle_->OnBattleEnd +=
      [&] (const yap::Battle& sender, const yap::EmptyEventArgs& args)
    {
      yap::AudioManager::Instance ().ResumePreviousMusic ();
      nextScreen_ = "Gameplay";
    };

    // Team Manager Widget
    PokemonTeamWidget* pokemonTeamWidget = new PokemonTeamWidget (
      session_.GetUser ().GetTrainer ().GetTeam ());
    battleInterface_->AddBattleWidget ("PokemonTeam", pokemonTeamWidget);

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
