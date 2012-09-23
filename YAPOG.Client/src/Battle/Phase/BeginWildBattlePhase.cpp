#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"
#include "YAPOG/Graphics/Gui/DialogBoxWidget.hpp"
#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

#include "Battle/Phase/BeginWildBattlePhase.hpp"
#include "Battle/OpponentBattleInfoWidget.hpp"
#include "Battle/BattleInterface.hpp"
#include "Battle/Battle.hpp"
#include "Game.hpp"

namespace ycl
{
  const bool BeginWildBattlePhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color BeginWildBattlePhase::DEFAULT_COLOR = sf::Color ();
  const float BeginWildBattlePhase::GROUND_SPEED = 500.f;
  const yap::String BeginWildBattlePhase::FISRT_STATE = "Init";

  BeginWildBattlePhase::BeginWildBattlePhase 
    (Battle& battle, BattleInterface& battleInterface)
    : BeginBattlePhase (battle, battleInterface)
    , nextState_ (FISRT_STATE)
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
        battleInterface_.GetBattleInfoDialogBox ().
          AddText (battle_.GetPlayerTeam ().GetName () + "! GO !");

        nextState_ = "PlayerBack";
        battleInterface_.GetBattleInfoDialogBox ().SetEnable (false);
      }
    };
  }

  void BeginWildBattlePhase::HandleStart (const yap::PhaseArgs& args)
  {
    BeginBattlePhase::HandleStart (args);

    // Begin battle little phases booleans init.
    nextState_ = FISRT_STATE;

    // Player's side init
    battle_.GetPlayerGround ().SetPosition (
      yap::Vector2 (
      Game::SCREEN_SIZE.x, battle_.GetPlayerGroundPosition ().y
      ));

    UpdatePlayerTrainerBack ();

    // Opponent's side init.
    battle_.GetOpponentGround ().SetPosition (
      yap::Vector2 (
      (-1) * battle_.GetOpponentGround ().GetSize ().x,
      battle_.GetOpponentGroundPosition ().y));

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
    battleInterface_.GetOpponentInfoWidget ().SetName (opponentName);
    battleInterface_.GetOpponentInfoWidget ().SetLevel (
      battle_.GetOpponent ().GetLevel ());
    battleInterface_.GetOpponentInfoWidget ().SetGender (
      battle_.GetOpponent ().GetGender ());

    battleInterface_.GetOpponentInfoWidget ().SetPosition (yap::Vector2 (
      -1 * battleInterface_.GetOpponentInfoWidget ().GetSize ().x,
      battle_.GetOpponentInfoPosition ().y));
    battleInterface_.GetOpponentInfoWidget ().SetHitPoint (
      battle_.GetOpponent ().GetStats ().GetHitPoint ());
    /// @}

    battleInterface_.GetBattleInfoDialogBox ().SetEnable (false);
  }

  void BeginWildBattlePhase::HandleUpdate (const yap::Time& dt)
  {
    BeginBattlePhase::HandleUpdate (dt);

    if (nextState_ == FISRT_STATE)
    {
      if (battle_.GetPlayerGround ().GetPosition ().x >
        battle_.GetPlayerGroundPosition ().x)
      {
        battle_.GetPlayerGround ().Move (
          yap::Vector2 (
          (-1) * (GROUND_SPEED * dt.GetValue ()),
          0));

        UpdatePlayerTrainerBack ();
      }
      else
      {
        battle_.GetPlayerGround ().SetPosition (
          battle_.GetPlayerGroundPosition ());

        UpdatePlayerTrainerBack ();
      }

      if (battle_.GetOpponentGround ().GetPosition ().x <
        battle_.GetOpponentGroundPosition ().x)
      {
        battle_.GetOpponentGround ().Move (
          yap::Vector2 (
          (GROUND_SPEED * dt.GetValue ()),
          0));

        UpdateOpponentFront ();
      }
      else
      {
        battle_.GetOpponentGround ().SetPosition (
          battle_.GetOpponentGroundPosition ());

        UpdateOpponentFront ();
      }

      if (battle_.GetOpponentGround ().GetPosition () ==
        battle_.GetOpponentGroundPosition () &&
        battle_.GetPlayerGround ().GetPosition () ==
        battle_.GetPlayerGroundPosition ())
      {
        nextState_ = "OpponentInfo";
      }
    }

    if (nextState_ == "OpponentInfo")
    {
      battleInterface_.GetBattleInfoDialogBox ().SetShowText (true);

      if (battleInterface_.GetOpponentInfoWidget ().GetPosition ().x <
        battle_.GetOpponentInfoPosition ().x)
      {
        battleInterface_.GetOpponentInfoWidget ().Move (yap::Vector2 (
          ((GROUND_SPEED * 2) * dt.GetValue ()),
          0));
      }
      else
      {
        battleInterface_.GetOpponentInfoWidget ().SetPosition (
          battle_.GetOpponentInfoPosition ());

        battleInterface_.GetBattleInfoDialogBox ().SetEnable (true);
        nextState_ = "WaitUser";
      }
    }

    if (nextState_ == "PlayerBack")
    {
      if (battle_.GetPlayerTrainerBack ().GetPosition ().x >
        (-1) * battle_.GetPlayerTrainerBack ().GetSize ().x)
      {
        battle_.GetPlayerTrainerBack ().Move (
          yap::Vector2 ((-1) * ((GROUND_SPEED * 2) * dt.GetValue ()), 0));
      }
      else
        nextState_ = "SwitchPhase";
    }

    if (nextState_ == "SwitchPhase")
      yap::BattlePhase::SwitchPhase (yap::BattlePhaseState::Switch);
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
    battle_.GetOpponent ().GetBattleSprite ().SetPosition (
      yap::Vector2 (
      battle_.GetOpponentGround ().GetPosition ().x + 
      battle_.GetOpponentGround ().GetSize ().x / 2 - 
      battle_.GetOpponent ().GetBattleSprite ().GetSize ().x / 2,
      battle_.GetOpponentGround ().GetPosition ().y - 
      battle_.GetOpponent ().GetBattleSprite ().GetSize ().y / 2));
  }
}