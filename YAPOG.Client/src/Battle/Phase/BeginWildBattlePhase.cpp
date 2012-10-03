#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"
#include "YAPOG/Graphics/Gui/DialogBoxWidget.hpp"
#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"
#include "YAPOG/Graphics/Game/MoveController.hpp"

#include "Battle/Phase/BeginWildBattlePhase.hpp"
#include "Battle/OpponentBattleInfoWidget.hpp"
#include "Battle/BattleInterface.hpp"
#include "Battle/Battle.hpp"
#include "Game.hpp"

namespace ycl
{
  const bool BeginWildBattlePhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color BeginWildBattlePhase::DEFAULT_COLOR = sf::Color ();
  const yap::String BeginWildBattlePhase::FISRT_STATE = "Init";

  BeginWildBattlePhase::BeginWildBattlePhase 
    (Battle& battle, BattleInterface& battleInterface)
    : BeginBattlePhase (battle, battleInterface)
    , nextState_ (FISRT_STATE)
    , opponentMoveController_ (nullptr)
    , opponentInfoMoveController_ (nullptr)
    , opponentGroundMoveController_ (nullptr)
    , playerMoveController_ (nullptr)
    , pokemonGroundMoveController_ (nullptr)
  {
  }

  BeginWildBattlePhase::~BeginWildBattlePhase ()
  {
  }

  void BeginWildBattlePhase::Init ()
  {
    battle_.GetOpponent ().OnHPChangedEvent () +=
      [&] (const yap::IBattleEntity& sender, 
      const yap::ChangeEventArgs<const yap::HitPoint&>& args)
    {
      battleInterface_.GetOpponentInfoWidget ().UpdateHPBar ();
    };

    battleInterface_.GetBattleInfoDialogBox ().OnTextChanged +=
      [&] (const yap::BaseWidget& sender, const yap::EmptyEventArgs& args)
    {
      if (nextState_ == "WaitUser")
      {
        playerMoveController_->SetEndPosition (yap::Vector2 (
          (-1) * playerMoveController_->GetElement ().GetSize ().x,
          playerMoveController_->GetElement ().GetPosition ().y
          ));
        playerMoveController_->SetTime (yap::Time (0.5f));

        battleInterface_.GetBattleInfoDialogBox ().SetEnable (false);

        nextState_ = "SwitchPhase";
      }
    };
  }

  void BeginWildBattlePhase::HandleStart (const yap::PhaseArgs& args)
  {
    BeginBattlePhase::HandleStart (args);

    // Begin battle little phases booleans init.
    nextState_ = FISRT_STATE;

    // Player's side init
    pokemonGroundMoveController_ = new yap::MoveController (
      battle_.GetPlayerGround (),
      yap::Vector2 (Game::SCREEN_SIZE.x,  Battle::POKEMON_GROUND_POSITION.y),
      Battle::POKEMON_GROUND_POSITION,
      yap::Time (1.f)
      );

    playerMoveController_ = new yap::MoveController (
      battle_.GetPlayerTrainerBack (),
      yap::Vector2 (
      Game::SCREEN_SIZE.x + battle_.GetPlayerGround ().GetSize ().x / 2
      - battle_.GetPlayerTrainerBack ().GetSize ().x / 2,  
      Battle::PLAYER_POSITION.y),
      Battle::PLAYER_POSITION,
      yap::Time (1.f));

    UpdatePlayerTrainerBack ();

    // Opponent's side init.
    opponentGroundMoveController_ = new yap::MoveController (
      battle_.GetOpponentGround (),
      yap::Vector2 (
      (-1) * battle_.GetOpponentGround ().GetSize ().x, 
      Battle::OPPONENT_GROUND_POSITION.y),
      Battle::OPPONENT_GROUND_POSITION,
      yap::Time (1.f));

    opponentMoveController_ = new yap::MoveController (
      battle_.GetOpponentSprite (),
      yap::Vector2 (
      (-1) * (battle_.GetOpponentSprite ().GetSize ().x + 
      (battle_.GetOpponentGround ().GetSize ().x / 4)), 
      Battle::OPPONENT_POSITION.y),
      Battle::OPPONENT_POSITION,
      yap::Time (1.f));

    UpdateOpponentFront ();

    /// @name Battle interface init.
    /// @{
    const yap::String& opponentName = battle_.GetOpponent ().GetName ();

    // Battle dialog box init.
    battleInterface_.GetBattleInfoDialogBox ().SetEnable (false);
    battleInterface_.GetBattleInfoDialogBox ().Show (true);
    battleInterface_.GetBattleInfoDialogBox ().SetShowText (false);
    battleInterface_.GetBattleInfoDialogBox ().
      AddText ("Un " + opponentName + " sauvage apparait !");

    // Opponent's side.
    battleInterface_.GetOpponentInfoWidget ().Show (true);
    battleInterface_.GetOpponentInfoWidget ().SetPokemon (
      battle_.GetOpponent ());

    opponentInfoMoveController_ = new yap::MoveController (
      battleInterface_.GetOpponentInfoWidget (),
      yap::Vector2 (
      (-1) * battleInterface_.GetOpponentInfoWidget ().GetSize ().x,
      battle_.GetOpponentInfoPosition ().y),
      Battle::OPPONENT_INFO_POSITION,
      yap::Time (0.5f)
      );
    /// @}

    battleInterface_.GetBattleInfoDialogBox ().SetEnable (false);
  }

  void BeginWildBattlePhase::HandleUpdate (const yap::Time& dt)
  {
    BeginBattlePhase::HandleUpdate (dt);

    if (opponentMoveController_->Update (dt) & 
      opponentGroundMoveController_->Update (dt) &
      pokemonGroundMoveController_->Update (dt) &
      playerMoveController_->Update (dt))
    {
      if (nextState_ == "Init")
      {
        battle_.GetOpponent ().PlayCry ();
        battleInterface_.GetBattleInfoDialogBox ().SetShowText (true);
        nextState_ = "EnableDialogBox";
      }

      if (opponentInfoMoveController_->Update (dt))
      {
        if (nextState_ == "EnableDialogBox")
        {
          battleInterface_.GetBattleInfoDialogBox ().SetEnable (true);

          battleInterface_.GetBattleInfoDialogBox ().
            AddText (battle_.GetPlayerTeam ().GetName () + "! GO !");

          nextState_ = "WaitUser";
        }
        else if (nextState_ == "SwitchPhase")
          yap::BattlePhase::SwitchPhase (yap::BattlePhaseState::Switch);
      }
    }
  }

  void BeginWildBattlePhase::HandleEnd ()
  {
    BeginBattlePhase::HandleEnd ();
  }

  void BeginWildBattlePhase::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void BeginWildBattlePhase::HandleShow (bool isVisible)
  {
  }

  void BeginWildBattlePhase::HandleChangeColor (const sf::Color& color)
  {
  }

  void BeginWildBattlePhase::UpdatePlayerTrainerBack ()
  {
    battle_.GetPlayerTrainerBack ().SetPosition (
      yap::Vector2 (
      battle_.GetPlayerGround ().GetPosition ().x +
      battle_.GetPlayerGround ().GetSize ().x / 2 -
      battle_.GetPlayerTrainerBack ().GetSize ().x / 2
      , battle_.GetPlayerGroundPosition ().y + 
      battle_.GetPlayerGround ().GetSize ().y / 2 -
      battle_.GetPlayerTrainerBack ().GetSize ().y
      ));
  }

  void BeginWildBattlePhase::UpdateOpponentFront ()
  {
    battle_.GetOpponent ().SetPosition (
      yap::Vector2 (
      battle_.GetOpponentGround ().GetPosition ().x + 
      battle_.GetOpponentGround ().GetSize ().x / 2 - 
      battle_.GetOpponent ().GetBattleSprite ().GetSize ().x / 2,
      battle_.GetOpponentGround ().GetPosition ().y - 
      battle_.GetOpponent ().GetBattleSprite ().GetSize ().y / 2));
  }
}