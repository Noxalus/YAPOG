#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"
#include "YAPOG/Graphics/Gui/DialogBoxWidget.hpp"

#include "Battle/Phase/BeginBattlePhase.hpp"
#include "Battle/OpponentBattleInfoWidget.hpp"
#include "Battle/BattleInterface.hpp"
#include "Battle/Battle.hpp"
#include "Game.hpp"

namespace ycl
{
  const bool BeginBattlePhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color BeginBattlePhase::DEFAULT_COLOR = sf::Color ();
  const float BeginBattlePhase::GROUND_SPEED = 1000.f;

  BeginBattlePhase::BeginBattlePhase (Battle& battle, BattleInterface& battleInterface)
    : yap::BeginBattlePhase (battle)
    , battle_ (battle)
    , battleInterface_  (battleInterface)
  {
  }

  BeginBattlePhase::~BeginBattlePhase ()
  {
  }

  void BeginBattlePhase::HandleStart ()
  {
    BattlePhase::HandleStart ();

    battle_.GetPlayerGround ().SetPosition (
      yap::Vector2 (
      Game::SCREEN_SIZE.x, battle_.GetPlayerGroundPosition ().y
      ));

    UpdatePlayerTrainerBack ();

    battle_.GetOpponentGround ().SetPosition (
      yap::Vector2 (
      (-1) * battle_.GetOpponentGround ().GetSize ().x,
      battle_.GetOpponentGroundPosition ().y));

    yap::String opponentName = battle_.GetOpponent ().GetName ();

    battleInterface_.GetOpponentInfoWidget ().SetName (opponentName);
    battleInterface_.GetOpponentInfoWidget ().SetLevel (battle_.GetOpponent ().GetLevel ());

    battleInterface_.GetBattleInfoDialogBox ().SetEnable (false);
    battleInterface_.GetBattleInfoDialogBox ().
      AddText ("Un " + opponentName + 
      " sauvage apparait !");

    battleInterface_.GetOpponentInfoWidget ().SetPosition (yap::Vector2 (
      -1 * battleInterface_.GetOpponentInfoWidget ().GetSize ().x,
      battle_.GetOpponentInfoPosition ().y));

    UpdateOpponentFront ();

    /*
    battle_.GetOpponent ().GetBattleSprite ().SetPosition (
    yap::Vector2 (
    Game::SCREEN_SIZE.x -
    (battle_.GetOpponentGround ().GetSize ().x) / 2 -
    battle_.GetOpponent ().GetBattleSprite ().GetSize ().x / 2,
    Game::SCREEN_SIZE.y / 3 -
    (battle_.GetOpponentGround ().GetSize ().y) / 2 -
    battle_.GetOpponent ().GetBattleSprite ().GetSize ().y / 2));
    */
  }

  void BeginBattlePhase::HandleUpdate (const yap::Time& dt)
  {
    if (battle_.GetPlayerGround ().GetPosition ().x >
      battle_.GetPlayerGroundPosition ().x)
    {
      battle_.GetPlayerGround ().SetPosition (
        yap::Vector2 (
        battle_.GetPlayerGround ().GetPosition ().x - (GROUND_SPEED * dt.GetValue ()),
        battle_.GetPlayerGround ().GetPosition ().y));

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
      battle_.GetOpponentGround ().SetPosition (
        yap::Vector2 (
        battle_.GetOpponentGround ().GetPosition ().x + (GROUND_SPEED * dt.GetValue ()),
        battle_.GetOpponentGround ().GetPosition ().y));

      UpdateOpponentFront ();
    }
    else
    {
      battle_.GetOpponentGround ().SetPosition (
        battle_.GetOpponentGroundPosition ());

      UpdateOpponentFront ();
    }

    if (battle_.GetPlayerGround ().GetPosition () ==
      battle_.GetPlayerGroundPosition () &&
      battle_.GetOpponentGround ().GetPosition () ==
      battle_.GetOpponentGroundPosition ())
    {
      if (battleInterface_.GetOpponentInfoWidget ().GetPosition ().x <
        battle_.GetOpponentInfoPosition ().x)
      {
        battleInterface_.GetOpponentInfoWidget ().SetPosition (yap::Vector2 (
          battleInterface_.GetOpponentInfoWidget ().GetPosition ().x + 
          (GROUND_SPEED * dt.GetValue ()),
          battleInterface_.GetOpponentInfoWidget ().GetPosition ().y));
      }
      else
      {
        battleInterface_.GetOpponentInfoWidget ().SetPosition (
          battle_.GetOpponentInfoPosition ());
      }

      if (battleInterface_.GetOpponentInfoWidget ().GetPosition () ==
        battle_.GetOpponentInfoPosition ())
      {

        battleInterface_.GetBattleInfoDialogBox ().SetEnable (true);

        nextPhase_ = yap::BattlePhaseState::Selection;
      }
    }
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
      battle_.GetOpponent ().GetBattleSprite ().GetSize ().x / 2,
      battle_.GetOpponentGround ().GetPosition ().y - 
      battle_.GetOpponent ().GetBattleSprite ().GetSize ().y / 2));
  }
}