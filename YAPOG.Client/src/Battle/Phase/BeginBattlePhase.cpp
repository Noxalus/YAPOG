#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"
#include "YAPOG/Graphics/Gui/WidgetDialogBox.hpp"

#include "Battle/Phase/BeginBattlePhase.hpp"
#include "Battle/BattleInterface.hpp"
#include "Battle/Battle.hpp"
#include "Game.hpp"

namespace ycl
{
  const bool BeginBattlePhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color BeginBattlePhase::DEFAULT_COLOR = sf::Color ();

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

    battle_.SetPlayerGroundPosition (
      yap::Vector2 (0,
      Game::SCREEN_SIZE.y - (Game::SCREEN_SIZE.y / 4) -
      ((battle_.GetPlayerGround ()->GetSize ().y) / 2)));

    battle_.SetOpponentGroundPosition (
      yap::Vector2 (
      Game::SCREEN_SIZE.x -
      (battle_.GetOpponentGround ()->GetSize ().x),
      Game::SCREEN_SIZE.y / 3 -
      (battle_.GetOpponentGround ()->GetSize ().y) / 2));

    battle_.GetPlayerGround ()->SetPosition (
      yap::Vector2 (
      Game::SCREEN_SIZE.x, battle_.GetPlayerGroundPosition ().y
      ));

    battle_.GetOpponentGround ()->SetPosition (
      yap::Vector2 (
      (-1) * battle_.GetOpponentGround ()->GetSize ().x,
      battle_.GetOpponentGroundPosition ().y));

    yap::String pokemonName = battle_.GetOpponent ().GetName ();
    battleInterface_.GetBattleInfoDialogBox ()->SetEnable (false);
    battleInterface_.GetBattleInfoDialogBox ()->
      AddText ("Un " + pokemonName + " sauvage\napparaît !");

    //battle_.GetOpponent ().SetPosition ();
  }

  void BeginBattlePhase::HandleUpdate (const yap::Time& dt)
  {
    if (battle_.GetPlayerGround ()->GetPosition ().x >
      battle_.GetPlayerGroundPosition ().x)
    {
      battle_.GetPlayerGround ()->SetPosition (
        yap::Vector2 (
        battle_.GetPlayerGround ()->GetPosition ().x - 1.f,
        battle_.GetPlayerGround ()->GetPosition ().y));
    }
    else
    {
      battle_.GetPlayerGround ()->SetPosition (
        yap::Vector2 ( battle_.GetPlayerGroundPosition ()));
    }

    if (battle_.GetOpponentGround ()->GetPosition ().x <
      battle_.GetOpponentGroundPosition ().x)
    {
      battle_.GetOpponentGround ()->SetPosition (
        yap::Vector2 (
        battle_.GetOpponentGround ()->GetPosition ().x + 1.f,
        battle_.GetOpponentGround ()->GetPosition ().y));
    }
    else
    {
      battle_.GetOpponentGround ()->SetPosition (
        yap::Vector2 (battle_.GetOpponentGround ()->GetPosition ()));
    }

    if (battle_.GetPlayerGround ()->GetPosition () ==
      battle_.GetPlayerGroundPosition () &&
      battle_.GetOpponentGround ()->GetPosition () ==
      battle_.GetOpponentGroundPosition ())
    {
      battleInterface_.GetBattleInfoDialogBox ()->SetEnable (true);
    }

    //nextPhase_ = yap::BattlePhaseState::BeginBattle;
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
}
