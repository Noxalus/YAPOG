#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"

#include "Game.hpp"

#include "Battle/Phase/SwitchPhase.hpp"
#include "Battle/Battle.hpp"
#include "Battle/BattleInterface.hpp"
#include "Battle/PokemonBattleInfoWidget.hpp"
#include "Battle/Battle.hpp"

namespace ycl
{
  const bool SwitchPhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color SwitchPhase::DEFAULT_COLOR = sf::Color ();
  const float SwitchPhase::BATTLE_INFO_SPEED = 500.f;

  SwitchPhase::SwitchPhase (Battle& battle, BattleInterface& battleInterface)
    : yap::SwitchPhase (battle)
    , battle_ (battle)
    , battleInterface_ (battleInterface)
  {
  }

  SwitchPhase::~SwitchPhase ()
  {
  }

  void SwitchPhase::HandleStart ()
  {
    yap::SwitchPhase::HandleStart ();

    /* Battle interface */

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

  void SwitchPhase::HandleUpdate (const yap::Time& dt)
  {
    yap::SwitchPhase::HandleUpdate (dt);

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
    }

    if (battleInterface_.GetPokemonInfoWidget ().GetPosition () ==
      battle_.GetPokemonInfoPosition ())
    {
      if (previousPhase_ == yap::BattlePhaseState::BeginBattle)
        nextPhase_ = yap::BattlePhaseState::Selection;
      else
        nextPhase_ = yap::BattlePhaseState::Action;
    }
  }

  void SwitchPhase::HandleEnd ()
  {
    yap::SwitchPhase::HandleEnd ();
  }

  void SwitchPhase::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool SwitchPhase::IsVisible () const
  {
    return isVisible_;
  }

  void SwitchPhase::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void SwitchPhase::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  void SwitchPhase::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void SwitchPhase::HandleShow (bool isVisible)
  {
  }

  void SwitchPhase::HandleChangeColor (const sf::Color& color)
  {
  }
}