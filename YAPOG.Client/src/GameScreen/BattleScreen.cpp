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

namespace ycl
{
  const yap::ScreenType BattleScreen::DEFAULT_NAME = "Battle";

  BattleScreen::BattleScreen (yap::IDrawingContext& context)
    : BaseScreen (DEFAULT_NAME, context)
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

  bool BattleScreen::HandleOnEvent (const yap::GuiEvent& guiEvent)
  {
    switch (guiEvent.type)
    {
    case sf::Event::KeyPressed:

      switch (guiEvent.key.code)
      {
      case sf::Keyboard::PageDown:
        battle_->GetPlayerTeam ().TakeDamage (5);
        return true;
      case sf::Keyboard::PageUp:
        battle_->GetPlayerTeam ().TakeDamage (-5);
        return true;

      case sf::Keyboard::W:
        battle_->GetPlayerTeam ().AddExperience (1);
        return true;
      case sf::Keyboard::A:
        battle_->GetPlayerTeam ().AddExperience (-1);
        return true;
      default: break;
      }

      break;

    default: break;
    }

    return false;
  }

  void BattleScreen::HandleActivate ()
  {
    BattleParameters& parameters = 
      session_.GetUser ().GetBattleParameters ();

    // Create a PokemonTeamFighter from the player's PokemonTeam
    PokemonTeam& playerTeam = session_.GetUser ().GetTrainer ().GetTeam ();

    PokemonFighterTeam* playerFighterTeam = new PokemonFighterTeam ();
    playerFighterTeam->LoadFromPokemonTeam (playerTeam, false);

    switch (parameters.GetBattleType ())
    {
    case yap::BattleType::SingleWild:
      battle_ = new WildBattle (*battleInterface_);

      battle_->SetPlayerTeam (playerFighterTeam);
      battle_->SetOpponent (&parameters.GetOpponent ());
      battle_->Init ();

      battle_->OnBattleEnd +=
        [&] (const yap::Battle& sender, const yap::EmptyEventArgs& args)
      {
        yap::AudioManager::Instance ().ResumePreviousMusic ();
        nextScreen_ = "Gameplay";
      };

      yap::AudioManager::Instance ().PlayMusic ("BGM/WildPokemonBattleShort.ogg");
      break;
    case yap::BattleType::DoubleWild:
      break;
    case yap::BattleType::SingleTrainer:
      break;
    case yap::BattleType::DoubleTrainer:
      break;
    default:
      break;
    }

    // Team Manager Widget
    PokemonTeamWidget* pokemonTeamWidget = new PokemonTeamWidget (
      session_.GetUser ().GetTrainer ().GetTeam ());
    battleInterface_->AddBattleWidget ("PokemonTeam", pokemonTeamWidget);
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
