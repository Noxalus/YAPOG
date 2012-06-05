#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/System/StringHelper.hpp"

#include "Battle/BattleInfoWidget.hpp"

namespace ycl
{
  BattleInfoWidget::BattleInfoWidget ()
    : nameLabel_ ("Bulbizarre")
    , levelLabel_ ("N.100")
    , nameBox_ (
    yap::Padding (5, 0, 0, 0), 
    yap::Padding (0, 0, 0, 0),
    false)
    , genderBox_ ()
    , levelBox_ (
    yap::Padding (0, 5, 0, 0),
    yap::Padding (0, 0, 0, 0),
    false)
    , hpBox_ ()
    , battleInfoBox_ (
    yap::Padding (10, 35, 0, 12), 
    yap::Padding (0, 0, 7, 0), 
    false)
    , hpBarPictureBox_ (new yap::PictureBox ())
    , genderPictureBox_ (new yap::PictureBox ())
  {
    nameLabel_.ChangeColor (sf::Color::Black);
    levelLabel_.ChangeColor (sf::Color::Black);

    /*
    battleInfoBox_.SetBorder (*new yap::WidgetBorder ("Test/black.png"));
    nameBox_.SetBorder (*new yap::WidgetBorder ("Test/red.png"));
    hpBox_.SetBorder (*new yap::WidgetBorder ("Test/orange.png"));
    genderBox_.SetBorder (*new yap::WidgetBorder ("Test/green.png"));
    levelBox_.SetBorder (*new yap::WidgetBorder ("Test/yellow.png"));
    */

    this->AddChild (battleInfoBox_);
  }

  void BattleInfoWidget::SetName (const yap::String& value)
  {
    nameLabel_.SetText (value);
  }

  void BattleInfoWidget::SetLevel (int value)
  {
    levelLabel_.SetText ("N." + yap::StringHelper::ToString (value));
  }
}