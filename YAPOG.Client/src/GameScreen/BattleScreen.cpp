#include "YAPOG/System/RandomHelper.hpp"
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

  Pokemon* GeneratePokemon ()
  {
    yap::ID staticID = yap::ID (yap::RandomHelper::GetNext (1, 4));

    if (staticID == yap::ID (4))
      staticID = yap::ID (16);

    int level = yap::RandomHelper::GetNext (1, 100);

    Pokemon* p = new Pokemon (staticID, level, false);

    return p;
  }

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

    PokemonTeam* team = new PokemonTeam ();
    team->AddPokemon (new Pokemon (yap::ID (2), 100, false));
    team->AddPokemon (new Pokemon (yap::ID (16), 32, true));

    PokemonFighterTeam* playerFighterTeam = new PokemonFighterTeam ();
    playerFighterTeam->AddPokemon (
      new PokemonFighter (team->GetPokemon (0), false));
    playerFighterTeam->AddPokemon (
      new PokemonFighter (team->GetPokemon (1), false));

    PokemonFighter* wildPokemon =
      new PokemonFighter (GeneratePokemon (), true);

    battle_ = new WildBattle (*battleInterface_);

    battle_->SetPlayerTeam (playerFighterTeam);
    battle_->SetOpponent (wildPokemon);
    battle_->Init ();

    battle_->OnBattleEnd +=
      [&] (const yap::Battle& sender, const yap::EmptyEventArgs& args)
    {
      nextScreen_ = "Gameplay";
    };
  }

  void BattleScreen::HandleDeactivate ()
  {
    battleInterface_->Reset ();
  }

} // namespace ycl
