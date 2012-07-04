#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"
#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"
#include "YAPOG/Game/Battle/Phase/ActionPhaseArgs.hpp"
#include "YAPOG/Graphics/Gui/DialogBoxWidget.hpp"

#include "Game.hpp"

#include "Battle/Phase/EndPokemonSwitchPhase.hpp"
#include "Battle/Battle.hpp"
#include "Battle/BattleInterface.hpp"
#include "Battle/PokemonBattleInfoWidget.hpp"
#include "Battle/Battle.hpp"

namespace ycl
{
  const bool EndPokemonSwitchPhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color EndPokemonSwitchPhase::DEFAULT_COLOR = sf::Color ();
  const float EndPokemonSwitchPhase::BATTLE_INFO_SPEED = 500.f;

  EndPokemonSwitchPhase::EndPokemonSwitchPhase (Battle& battle, BattleInterface& battleInterface)
    : yap::EndPokemonSwitchPhase (battle)
    , battle_ (battle)
    , battleInterface_ (battleInterface)
    , nextPhase_ (yap::BattlePhaseState::Switch)
  {
  }

  EndPokemonSwitchPhase::~EndPokemonSwitchPhase ()
  {
  }

  void EndPokemonSwitchPhase::HandleStart (yap::PhaseArgs* args)
  {
    yap::EndPokemonSwitchPhase::HandleStart (args);

    /* Battle interface */

    battleInterface_.GetBattleInfoDialogBox ().SetEnable (false);

    // Battle info widget initial position
    battleInterface_.GetPokemonInfoWidget ().SetPosition (yap::Vector2 (
      Game::SCREEN_SIZE.x, 
      battle_.GetPokemonInfoPosition ().y));

    battleInterface_.GetPokemonInfoWidget ().Show (true);

    // Pokemon name
    battleInterface_.GetPokemonInfoWidget ().SetName (
      battle_.GetPlayerTeam ().GetName ());

    // Pokemon gender
    battleInterface_.GetPokemonInfoWidget ().SetGender (
      battle_.GetPlayerTeam ().GetGender ());

    // Pokemon level
    battleInterface_.GetPokemonInfoWidget ().SetLevel (
      battle_.GetPlayerTeam ().GetLevel ());

    // Pokemon HP
    battleInterface_.GetPokemonInfoWidget ().SetHPValue (
      battle_.GetPlayerTeam ().GetStats ().GetHitPoint ());

    /* Pokemon sprite */

    // Visibility
    battle_.GetPlayerTeam ().GetBattleSprite ().Show (true);

    // Position
    battle_.GetPlayerTeam ().GetBattleSprite ().SetPosition (
      yap::Vector2 (
      battle_.GetPlayerGroundPosition ().x +
      battle_.GetPlayerGround ().GetSize ().x / 2 -
      battle_.GetPlayerTeam ().GetBattleSprite ().GetSize ().x / 2,
      battle_.GetPlayerGroundPosition ().y +
      battle_.GetPlayerGround ().GetSize ().y / 2 -
      battle_.GetPlayerTeam ().GetBattleSprite ().GetSize ().y));

    /* Events */

    // Pokemon hit points
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

    // Pokemon moves
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

        battleInterface_.GetBattleMoveMenu ().GetItem (i).OnActivated +=
          [&] (yap::MenuItem& sender, const yap::EmptyEventArgs& args)
        {
          yap::BattlePhase::SwitchPhase (yap::BattlePhaseState::BeginBattle);
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

    battleInterface_.GetBattleInfoDialogBox ().OnTextChanged.AddHandler (
      "SKIP_TEXT_EVENT_HANDLER",
      [&] (const yap::BaseWidget& sender, const yap::EmptyEventArgs& args)
    {
      if (previousPhase_ == yap::BattlePhaseState::BeginBattle)
        nextPhase_ = yap::BattlePhaseState::Selection;
      else
        nextPhase_ = yap::BattlePhaseState::Action;
    });
  }

  void EndPokemonSwitchPhase::HandleUpdate (const yap::Time& dt)
  {
    yap::EndPokemonSwitchPhase::HandleUpdate (dt);

    if (battleInterface_.GetPokemonInfoWidget ().GetPosition ().x >
      battle_.GetPokemonInfoPosition ().x)
    {
      battleInterface_.GetPokemonInfoWidget ().Move (
        yap::Vector2 ((-1) * ((BATTLE_INFO_SPEED * 2) * dt.GetValue ()), 0));
    }
    else
    {
      battleInterface_.GetPokemonInfoWidget ().SetPosition (
        battle_.GetPokemonInfoPosition ());

      battleInterface_.GetBattleInfoDialogBox ().SetEnable (true);
    }

    if (battleInterface_.GetPokemonInfoWidget ().GetPosition () ==
      battle_.GetPokemonInfoPosition ())
    {
      if (nextPhase_ != yap::BattlePhaseState::Switch)
        yap::BattlePhase::SwitchPhase (nextPhase_);
    }
  }

  void EndPokemonSwitchPhase::HandleEnd ()
  {
    yap::EndPokemonSwitchPhase::HandleEnd ();

    battleInterface_.GetBattleInfoDialogBox ().
      OnTextChanged.RemoveHandler ("SKIP_TEXT_EVENT_HANDLER");
  }

  void EndPokemonSwitchPhase::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool EndPokemonSwitchPhase::IsVisible () const
  {
    return isVisible_;
  }

  void EndPokemonSwitchPhase::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void EndPokemonSwitchPhase::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  void EndPokemonSwitchPhase::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void EndPokemonSwitchPhase::HandleShow (bool isVisible)
  {
  }

  void EndPokemonSwitchPhase::HandleChangeColor (const sf::Color& color)
  {
  }
}