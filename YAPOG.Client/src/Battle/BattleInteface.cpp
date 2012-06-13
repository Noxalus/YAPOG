#include "YAPOG/Graphics/Gui/DialogBoxWidget.hpp"

#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/GuiManager.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Graphics/Gui/GridMenu.hpp"

#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"

#include "Game.hpp"

#include "Battle/BattleInterface.hpp"
#include "Battle/PokemonBattleInfoWidget.hpp"
#include "Battle/OpponentBattleInfoWidget.hpp"

#include "Game.hpp"

namespace ycl
{
  BattleInterface::BattleInterface ()
    : battleInfoDialogBox_ (nullptr)
    , pokemonInfoWidget_ (nullptr)
    , opponentInfoWidget_ (nullptr)
    , battleMenu_ ()
    , battleMoveMenu_ ()
  {
    battleInfoDialogBox_ = new yap::DialogBoxWidget ();

    // Init Battle Text Dialog
    battleInfoDialogBox_->SetSize (
      yap::Vector2 (Game::SCREEN_SIZE.x, Game::SCREEN_SIZE.y / 4));

    battleInfoDialogBox_->SetPosition (
      yap::Vector2 (0, Game::SCREEN_SIZE.y - battleInfoDialogBox_->GetSize ().y));

    battleInfoDialogBox_->SetPadding (yap::Padding (35, 35, 25, 25));
    battleInfoDialogBox_->SetBackground (
      *(new yap::WidgetBackground (
      "WindowSkins/BasicSkin/Global/DialogBoxBackground.png", true)));

    battleInfoDialogBox_->ChangeColor (sf::Color::White);

    pokemonInfoWidget_ = new PokemonBattleInfoWidget ();
    opponentInfoWidget_ = new OpponentBattleInfoWidget ();

    pokemonInfoWidget_->Show (false);

    battleMenu_.SetPosition (yap::Vector2 (
      Game::SCREEN_SIZE.x - battleMenu_.GetSize ().x , 
      Game::SCREEN_SIZE.y - battleMenu_.GetSize ().y ));

    battleMoveMenu_.SetPosition (yap::Vector2 (
      0 , 
      Game::SCREEN_SIZE.y - battleMenu_.GetSize ().y ));

    battleMoveInfoMenu_.SetPosition (yap::Vector2 (
      Game::SCREEN_SIZE.x - battleMoveInfoMenu_.GetSize ().x - 20,
      Game::SCREEN_SIZE.y - battleMoveInfoMenu_.GetSize ().y - 20));

    battleMenu_.Close ();
    battleMoveMenu_.Close ();
    battleMoveInfoMenu_.Close ();

    // Affect events
    battleMenu_.GetItem (0).OnActivated += 
      [&] (const yap::MenuItem& sender, const yap::EmptyEventArgs& args)
    {
      battleMenu_.Close ();
      OpenBattleMoveMenu ();
    };

    battleMoveMenu_.OnDesactivated +=
      [&] (const yap::GridMenu& sender, const yap::EmptyEventArgs& args)
    {
      battleMoveMenu_.Close ();
      battleMoveInfoMenu_.Close ();
      battleMenu_.Open ();
    };

    this->AddChild (*pokemonInfoWidget_);
    this->AddChild (*opponentInfoWidget_);
    this->AddChild (*battleInfoDialogBox_);
    this->AddChild (battleMenu_);
    this->AddChild (battleMoveMenu_);
    this->AddChild (battleMoveInfoMenu_);
  }

  /// Getters
  yap::DialogBoxWidget& BattleInterface::GetBattleInfoDialogBox ()
  {
    return *battleInfoDialogBox_;
  }

  PokemonBattleInfoWidget& BattleInterface::GetPokemonInfoWidget ()
  {
    return *pokemonInfoWidget_;
  }

  OpponentBattleInfoWidget& BattleInterface::GetOpponentInfoWidget ()
  {
    return *opponentInfoWidget_;
  }

  BattleMenu& BattleInterface::GetBattleMenu ()
  {
    return battleMenu_;
  }

  BattleMoveMenu& BattleInterface::GetBattleMoveMenu ()
  {
    return battleMoveMenu_;
  }

  BattleMoveInfoMenu& BattleInterface::GetBattleMoveInfoMenu ()
  {
    return battleMoveInfoMenu_;
  }

  void BattleInterface::OpenBattleMoveMenu ()
  {
    battleMoveMenu_.Open ();
    battleMoveInfoMenu_.Open ();
  }
}
