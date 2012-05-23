#include "YAPOG/Graphics/Gui/WidgetDialogBox.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/GuiManager.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"

#include "Battle/BattleInterface.hpp"
#include "Battle/BattleBackgroundWidget.hpp"
#include "TestGame.hpp"

namespace ycl
{
  const yap::Vector2 BattleInterface::DEFAULT_OPPONENT_GROUND_SPRITES_SCALE
    = yap::Vector2 (0.75f, 0.75f);

  BattleInterface::BattleInterface ()
  {
    background_ = new yap::Sprite (yap::ObjectFactory::Instance ().
      Create<yap::Texture> ("Texture", yap::ID (42)));

    opponentGround_ = new yap::Sprite (yap::ObjectFactory::Instance ().
      Create<yap::Texture> ("Texture", yap::ID (43)));
    playerGround_ = new yap::Sprite (yap::ObjectFactory::Instance ().
      Create<yap::Texture> ("Texture", yap::ID (43)));

    background_->SetSize (TestGame::SCREEN_SIZE);

    playerGround_->SetPosition (
      yap::Vector2 (0, 
      TestGame::SCREEN_SIZE.y - (TestGame::SCREEN_SIZE.y / 4) -
      ((playerGround_->GetSize ().y) / 2)));

    opponentGround_->Scale (DEFAULT_OPPONENT_GROUND_SPRITES_SCALE);
    opponentGround_->SetPosition (
      yap::Vector2 (
      TestGame::SCREEN_SIZE.x - 2 *
      ((playerGround_->GetSize ().x * 
      DEFAULT_OPPONENT_GROUND_SPRITES_SCALE.x) / 2), 
      TestGame::SCREEN_SIZE.y / 3 - 
      ((playerGround_->GetSize ().y * 
      DEFAULT_OPPONENT_GROUND_SPRITES_SCALE.y) / 2)));

    battleTextDialogBox_ = new yap::WidgetDialogBox ();
    yap::WidgetBackground* battleTextDialogBoxBackground_ = 
      new yap::WidgetBackground ("WindowSkins/dummy1.png", true);

    // Init Battle Text Dialog
    battleTextDialogBox_->SetSize (
      yap::Vector2 (TestGame::SCREEN_SIZE.x, TestGame::SCREEN_SIZE.y / 4));
    battleTextDialogBox_->SetPosition (
      yap::Vector2 (0, TestGame::SCREEN_SIZE.y));
    battleTextDialogBox_->SetPadding (new yap::Padding (35, 35, 25, 25));
    battleTextDialogBox_->AddText ("COUCOU !!");
    battleTextDialogBox_->SetBackground (*battleTextDialogBoxBackground_);

    //this->AddChild (*battleTextDialogBox_);
  }
}