#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/System/MathHelper.hpp"
#include "YAPOG/Graphics/Gui/Label.hpp"

#include "YAPOG/Game/Pokemon/HitPoint.hpp"

#include "Battle/BattleInfoWidget.hpp"

namespace ycl
{
  BattleInfoWidget::BattleInfoWidget (const yap::Padding& widgetPadding)
    : nameLabel_ ()
    , levelLabel_ ()
    , battleInfoBox_ (
    widgetPadding,
    yap::Padding (),
    false)
    , firstLine_ (yap::Padding (0, 0, 0, 2), yap::Padding (), false)
    , nameBox_ (
    yap::Padding (0, 0, 7, 0),
    yap::Padding (),
    false)
    , levelAndGenderBox_ (yap::Padding (), yap::Padding (0, 10, 0, 0), false)
    , levelBox_ (yap::Padding (), yap::Padding (), false)
    , genderBox_ (yap::Padding (0, 0, 4, 0), yap::Padding (), false)
    , genderPictureBox_ (new yap::PictureBox ())
    , hpBar_ ()
  {
  }

  void BattleInfoWidget::Init ()
  {
    nameLabel_.ChangeColor (sf::Color::Black);
    levelLabel_.ChangeColor (sf::Color::Black);

    hpBar_.Init ();

    SetGender (yap::Gender::Genderless);

    // Sizes
    firstLine_.SetSize (yap::Vector2 (253, 35));
    nameBox_.SetSize (yap::Vector2 (175, 35));
    nameLabel_.SetSize (nameBox_.GetSize ());
    levelAndGenderBox_.SetSize (yap::Vector2 (65, 35));
    levelBox_.SetSize (yap::Vector2 (53, 35));
    levelLabel_.SetSize (levelBox_.GetSize ());
    genderBox_.SetSize (yap::Vector2 (12, 35));

    // First line
    nameBox_.AddChild (nameLabel_);
    levelBox_.AddChild (levelLabel_, yap::LayoutBox::Align::RIGHT);
    genderBox_.AddChild (*genderPictureBox_, yap::LayoutBox::Align::BOTTOM);

    levelAndGenderBox_.AddChild (genderBox_);
    levelAndGenderBox_.AddChild (levelBox_);

    firstLine_.AddChild (nameBox_);
    firstLine_.AddChild (levelAndGenderBox_);

    // Add to the global box
    battleInfoBox_.AddChild (firstLine_, yap::LayoutBox::Align::LEFT);
    battleInfoBox_.AddChild (hpBar_, yap::LayoutBox::Align::RIGHT); 

    /// @debug Borders.
    /// @{
    /*
    nameBox_.SetBorder (*new yap::WidgetBorder ("Test/red.png"));
    nameLabel_.SetBorder (*new yap::WidgetBorder ("Test/blue.png"));
    levelLabel_.SetBorder (*new yap::WidgetBorder ("Test/yellow.png"));
    hpBar_.SetBorder (*new yap::WidgetBorder ("Test/green.png"));
    battleInfoBox_.SetBorder (*new yap::WidgetBorder ("Test/black.png"));
    levelAndGenderBox_.SetBorder (*new yap::WidgetBorder ("Test/grey.png"));
    */
    /// @}

    this->AddChild (battleInfoBox_);
  }

 void BattleInfoWidget::SetHitPoint (const yap::HitPoint& hp)
  {
    hpBar_.SetHitPoint (hp);
  }

  void BattleInfoWidget::UpdateHPBar ()
  {
    hpBar_.UpdateProgressBar ();
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
      genderPictureBox_->SetPicture (new yap::Sprite ("Pictures/Battle/FemaleIcon.png"));
      break;
    case yap::Gender::Male:
      genderPictureBox_->SetPicture (new yap::Sprite ("Pictures/Battle/MaleIcon.png"));
      break;
    default:
      genderPictureBox_->SetPicture (new yap::Sprite ("Pictures/Battle/MaleIcon.png"));
      break;
    }
  }

  void BattleInfoWidget::HandleDraw (yap::IDrawingContext& context)
  {
  }

  yap::Vector2 BattleInfoWidget::HandleGetSize () const
  {
    return battleInfoBox_.GetSize ();
  }
}
