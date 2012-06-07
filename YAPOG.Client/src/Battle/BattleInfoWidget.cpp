#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/System/MathHelper.hpp"

#include "Battle/BattleInfoWidget.hpp"

namespace ycl
{
  const sf::Color BattleInfoWidget::
    DEFAULT_HP_COLOR_GOOD = sf::Color (110, 250, 170);
  const sf::Color BattleInfoWidget::
    DEFAULT_HP_COLOR_MEDIUM = sf::Color (250, 225, 50);
  const sf::Color BattleInfoWidget::
    DEFAULT_HP_COLOR_BAD = sf::Color (250, 90, 60);

  const float BattleInfoWidget::MAX_HP_BAR_SIZE = 145.f;

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
      MAX_HP_BAR_SIZE,
      hpBarContent_->GetSize ().y));

    hpBarContent_->ChangeColor (DEFAULT_HP_COLOR_GOOD);

    //nameBox_.SetBorder (*new yap::WidgetBorder ("Test/red.png"));
    //nameLabel_.SetBorder (*new yap::WidgetBorder ("Test/blue.png"));
    //genderBox_.SetBorder (*new yap::WidgetBorder ("Test/green.png"));
    levelBox_.SetBorder (*new yap::WidgetBorder ("Test/yellow.png"));
    hpBox_.SetBorder (*new yap::WidgetBorder ("Test/orange.png"));

    /*
    battleInfoBox_.SetBorder (*new yap::WidgetBorder ("Test/black.png"));
    levelBox_.SetBorder (*new yap::WidgetBorder ("Test/yellow.png"));
    */

    this->AddChild (battleInfoBox_);
  }

  void BattleInfoWidget::ComputeLevelBoxSize ()
  {
    levelBox_.SetSize (
      yap::Vector2 (
      nameBox_.GetSize ().x - 
      nameLabel_.GetSize ().x - 
      genderPictureBox_->GetSize ().x, 
      25.f));
  }

  void BattleInfoWidget::UpdateHPColor (int value)
  {
    /*
    /// Red: -1.4x + 250
    int red = (-1.4f) * value + 250;
    /// Green: 2x + 50
    int green = 2 * value + 50;
    /// Blue: 1.2x + 50
    int blue = 1.2f * value + 50;

    hpBarContent_->ChangeColor (sf::Color (
    yap::MathHelper::Clamp (red, 0, 255),
    yap::MathHelper::Clamp (green, 0, 255),
    yap::MathHelper::Clamp (blue, 0, 255)));
    */

    if (value <= 25)
      hpBarContent_->ChangeColor (DEFAULT_HP_COLOR_BAD);
    else if (value <= 50)
      hpBarContent_->ChangeColor (DEFAULT_HP_COLOR_MEDIUM);
    else
      hpBarContent_->ChangeColor (DEFAULT_HP_COLOR_GOOD);
  }

  void BattleInfoWidget::UpdateHPSize (int value)
  {
    float size =  MAX_HP_BAR_SIZE * ((float)value / 100);

    hpBarContent_->SetSize (yap::Vector2 (
      size,
      hpBarContent_->GetSize ().y));
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
