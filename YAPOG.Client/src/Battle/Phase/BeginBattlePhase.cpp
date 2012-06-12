#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"
#include "YAPOG/Graphics/Gui/DialogBoxWidget.hpp"

#include "YAPOG/System/RandomHelper.hpp"

#include "Battle/Phase/BeginBattlePhase.hpp"
#include "Battle/OpponentBattleInfoWidget.hpp"
#include "Battle/PokemonBattleInfoWidget.hpp"
#include "Battle/BattleInterface.hpp"
#include "Battle/Battle.hpp"
#include "Game.hpp"

namespace ycl
{
  const bool BeginBattlePhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color BeginBattlePhase::DEFAULT_COLOR = sf::Color ();
  const float BeginBattlePhase::GROUND_SPEED = 500.f;
  const yap::String BeginBattlePhase::FISRT_STATE = "Init";

  BeginBattlePhase::BeginBattlePhase (Battle& battle, BattleInterface& battleInterface)
    : yap::BeginBattlePhase (battle)
    , battle_ (battle)
    , battleInterface_  (battleInterface)
    , nextState_ (FISRT_STATE)
  {
  }

  BeginBattlePhase::~BeginBattlePhase ()
  {
  }

  void BeginBattlePhase::HandleStart ()
  {
    BattlePhase::HandleStart ();

    // Begin battle little phases booleans init.
    nextState_ = FISRT_STATE;

    // Player's side init
    battle_.GetPlayerGround ().SetPosition (
      yap::Vector2 (
      Game::SCREEN_SIZE.x, battle_.GetPlayerGroundPosition ().y
      ));

    UpdatePlayerTrainerBack ();

    battle_.GetPlayerTeam ().GetBattleSprite ().Show (false);
    battle_.GetPlayerTeam ().GetBattleSprite ().SetPosition (yap::Vector2 (
      battle_.GetPlayerGroundPosition ().x +
      battle_.GetPlayerGround ().GetSize ().x / 2 -
      battle_.GetPlayerTeam ().GetBattleSprite ().GetSize ().x / 2,
      battle_.GetPlayerGroundPosition ().y +
      battle_.GetPlayerGround ().GetSize ().y / 2 -
      battle_.GetPlayerTeam ().GetBattleSprite ().GetSize ().y));

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
    battleInterface_.GetBattleInfoDialogBox ().SetShowText (false);
    battleInterface_.GetBattleInfoDialogBox ().
      AddText ("Un " + opponentName + " sauvage apparait !");

    // Player's side.
    battleInterface_.GetPokemonInfoWidget ().SetPosition (yap::Vector2 (
      Game::SCREEN_SIZE.x, 
      battle_.GetPokemonInfoPosition ().y));
    battleInterface_.GetPokemonInfoWidget ().SetName (
      battle_.GetPlayerTeam ().GetName ());
    battleInterface_.GetPokemonInfoWidget ().SetGender (
      battle_.GetPlayerTeam ().GetGender ());

    // Opponent's side.
    battleInterface_.GetOpponentInfoWidget ().SetName (opponentName);
    battleInterface_.GetOpponentInfoWidget ().SetLevel (
      battle_.GetOpponent ().GetLevel ());
    battleInterface_.GetOpponentInfoWidget ().SetGender (
      battle_.GetOpponent ().GetGender ());
    battleInterface_.GetPokemonInfoWidget ().SetLevel (
      battle_.GetPlayerTeam ().GetLevel ());

    battleInterface_.GetOpponentInfoWidget ().SetPosition (yap::Vector2 (
      -1 * battleInterface_.GetOpponentInfoWidget ().GetSize ().x,
      battle_.GetOpponentInfoPosition ().y));
    /// @}

    battle_.GetOpponent ().OnHPChangedEvent () +=
      [&] (const yap::IBattleEntity& sender, 
      const yap::ChangeEventArgs<const yap::HitPoint&>& args)
    {
      battleInterface_.GetOpponentInfoWidget ().UpdateHPColor (
        battle_.GetOpponent ().GetHPPercentage ());

      battleInterface_.GetOpponentInfoWidget ().UpdateHPSize (
        battle_.GetOpponent ().GetHPPercentage ());
    };

    battle_.GetPlayerTeam ().OnHPChangedEvent () +=
      [&] (const yap::IBattleEntity& sender, 
      const yap::ChangeEventArgs<const yap::HitPoint&>& args)
    {
      battleInterface_.GetPokemonInfoWidget ().UpdateHPColor (
        battle_.GetPlayerTeam ().GetHPPercentage ());

      battleInterface_.GetPokemonInfoWidget ().UpdateHPSize (
        battle_.GetPlayerTeam ().GetHPPercentage ());

      battleInterface_.GetPokemonInfoWidget ().SetHPValue
        (args.Current);
    };

    for (int i = 0; i < battle_.GetPlayerTeam ().GetMoves ().Count (); i++)
    {
      if (battle_.GetPlayerTeam ().GetMoves ()[i] != nullptr)
      {
        battleInterface_.GetBattleMoveMenu ().SetItemContent (
          i, battle_.GetPlayerTeam ().GetMove (i).GetName ());

        battleInterface_.GetBattleMoveMenu ().GetItem (i).OnSelected +=
          [&] (yap::MenuItem& sender, const yap::EmptyEventArgs& args)
        {
          battleInterface_.GetBattleMoveInfoMenu ().SetPP (
            battle_.GetPlayerTeam ().GetMove (
            battleInterface_.GetBattleMoveMenu ().GetIndex (sender)));

          battleInterface_.GetBattleMoveInfoMenu ().SetType (
            battle_.GetPlayerTeam ().GetMoves ()
            [battleInterface_.GetBattleMoveMenu ().
                GetIndex (sender)]->GetType ());
        };
      }
      else
      {
        battleInterface_.GetBattleMoveMenu ().SetItemContent (i, " --- ");

        battleInterface_.GetBattleMoveMenu ().GetItem (i).OnSelected +=
          [&] (yap::MenuItem&, const yap::EmptyEventArgs&)
        {
          battleInterface_.GetBattleMoveInfoMenu ().SetPPLabel (" --- ");
          battleInterface_.GetBattleMoveInfoMenu ().HideType ();
        };
      }
    }
  }

  void BeginBattlePhase::HandleUpdate (const yap::Time& dt)
  {
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

        nextState_ = "PlayerGround";
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

        if (nextState_ == "PlayerGround")
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

        nextState_ = "PlayerBack";
        battleInterface_.GetBattleInfoDialogBox ().
          AddText (battle_.GetPlayerTeam ().GetName () + "! GO !");
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
      {
        nextState_ = "PokemonInfo";
        battleInterface_.GetBattleInfoDialogBox ().SetEnable (true);
        battle_.GetPlayerTeam ().GetBattleSprite ().Show (true);
      }
    }

    if (nextState_ == "PokemonInfo")
    {
      if (battleInterface_.GetPokemonInfoWidget ().GetPosition ().x >
        battle_.GetPokemonInfoPosition ().x)
      {
        battleInterface_.GetPokemonInfoWidget ().Move (
          yap::Vector2 ((-1) * ((GROUND_SPEED * 2) * dt.GetValue ()), 0));
      }
      else
      {
        battleInterface_.GetPokemonInfoWidget ().SetPosition (
          battle_.GetPokemonInfoPosition ());

        nextState_ = "ChangePhase";
      }
    }

    if (nextState_ == "ChangePhase")
      nextPhase_ = yap::BattlePhaseState::Selection;
  }

  void BeginBattlePhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
    std::cout << "FIGHT !" << std::endl;
  }

  void BeginBattlePhase::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool BeginBattlePhase::IsVisible () const
  {
    return isVisible_;
  }

  void BeginBattlePhase::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void BeginBattlePhase::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  void BeginBattlePhase::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void BeginBattlePhase::HandleShow (bool isVisible)
  {
  }

  void BeginBattlePhase::HandleChangeColor (const sf::Color& color)
  {
  }

  void BeginBattlePhase::UpdatePlayerTrainerBack ()
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

  void BeginBattlePhase::UpdateOpponentFront ()
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