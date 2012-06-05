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
    : nameLabel_ ("")
    , levelLabel_ ("")
    , nameBox_ ()
    , genderBox_ ()
    , levelBox_ ()
    , hpBox_ ()
    , battleInfoBox_ ()
    , hpBarPictureBox_ (new yap::PictureBox ())
    , hpBarContent_ (new yap::PictureBox ())
    , genderPictureBox_ (new yap::PictureBox ())
  {
    nameLabel_.ChangeColor (sf::Color::Black);
    levelLabel_.ChangeColor (sf::Color::Black);

    hpBarContent_->SetSize (yap::Vector2 (
      145.f,
      hpBarContent_->GetSize ().y));

    hpBarContent_->ChangeColor (sf::Color (110, 250, 170));

    nameBox_.SetBorder (*new yap::WidgetBorder ("Test/red.png"));
    genderBox_.SetBorder (*new yap::WidgetBorder ("Test/green.png"));
    /*
    battleInfoBox_.SetBorder (*new yap::WidgetBorder ("Test/black.png"));

    levelBox_.SetBorder (*new yap::WidgetBorder ("Test/grey.png"));
    hpBox_.SetBorder (*new yap::WidgetBorder ("Test/orange.png"));

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

  void BattleInfoWidget::SetGender (const yap::Gender& value)
  {
    switch (value)
    {
    case yap::Gender::Female:
      genderPictureBox_->SetPicture ("Pictures/Battle/FemaleIcon.png");
      break;
    case yap::Gender::Male:
      genderPictureBox_->SetPicture ("Pictures/Battle/MaleIcon.png");
      break;
    default:
      genderPictureBox_->SetPicture ("Pictures/Battle/MaleIcon.png");
      break;
    }
  }

  void BattleInfoWidget::HandleDraw (yap::IDrawingContext& context)
  {
  }
}