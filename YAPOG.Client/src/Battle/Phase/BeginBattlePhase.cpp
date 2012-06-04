#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"
#include "YAPOG/Graphics/Gui/DialogBoxWidget.hpp"

#include "Battle/Phase/BeginBattlePhase.hpp"
#include "Battle/BattleInterface.hpp"
#include "Battle/Battle.hpp"
#include "Game.hpp"

namespace ycl
{
  const bool BeginBattlePhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color BeginBattlePhase::DEFAULT_COLOR = sf::Color ();
  const float BeginBattlePhase::GROUND_SPEED = 500.f;

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

    //battleInterface_.GetPokemonName ().SetText (opponentName);
    //battleInterface_.GetPokemonName ().ChangeColor (sf::Color::Black);

    battleInterface_.GetBattleInfoDialogBox ().SetEnable (false);
    battleInterface_.GetBattleInfoDialogBox ().
      AddText ("Un " + opponentName + 
      " sauvage apparait !");


    battle_.GetDrawableOpponent ().GetBattleSprite ().SetPosition (
      yap::Vector2 (
      Game::SCREEN_SIZE.x -
      (battle_.GetOpponentGround ().GetSize ().x),
      Game::SCREEN_SIZE.y / 3 -
      (battle_.GetOpponentGround ().GetSize ().y) / 2));
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
    }
    else
    {
      battle_.GetOpponentGround ().SetPosition (
        battle_.GetOpponentGroundPosition ());
    }

    if (battle_.GetPlayerGround ().GetPosition () ==
      battle_.GetPlayerGroundPosition () &&
      battle_.GetOpponentGround ().GetPosition () ==
      battle_.GetOpponentGroundPosition ())
    {
      battleInterface_.GetBattleInfoDialogBox ().SetEnable (true);

      nextPhase_ = yap::BattlePhaseState::BeginBattle;
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
}