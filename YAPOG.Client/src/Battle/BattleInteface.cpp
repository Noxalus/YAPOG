#include "YAPOG/Graphics/Gui/DialogBoxWidget.hpp"
#include "YAPOG/Graphics/Gui/BackgroundWidget.hpp"
#include "YAPOG/Graphics/Gui/GuiManager.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"

#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"

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
  {
    battleInfoDialogBox_ = new yap::DialogBoxWidget ();

    // Init Battle Text Dialog
    /*
    battleInfoDialogBox_->SetSize (
    yap::Vector2 (Game::SCREEN_SIZE.x, Game::SCREEN_SIZE.y / 4));
    */

    battleInfoDialogBox_->SetPadding (new yap::Padding (35, 35, 25, 25));

    /*
    battleInfoDialogBox_->SetPosition (
    yap::Vector2 (0, Game::SCREEN_SIZE.y - battleInfoDialogBox_->GetSize ().y));
    */

    battleInfoDialogBox_->SetBackground (
      *(new yap::BackgroundWidget ("WindowSkins/BasicSkin/Global/DialogBoxBackground.png", true)));

    battleInfoDialogBox_->SetBorder (*new yap::WidgetBorder ("red.png"));

    std::cout << "Size: " 
      << battleInfoDialogBox_->GetSize ().x << ", "
      << battleInfoDialogBox_->GetSize ().y
      << std::endl;

    pokemonInfoWidget_ = new PokemonBattleInfoWidget ();
    opponentInfoWidget_ = new OpponentBattleInfoWidget ();

    //this->AddChild (*pokemonInfoWidget_);
    //this->AddChild (*opponentInfoWidget_);

    this->AddChild (*battleInfoDialogBox_);
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
}
