#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Game/Pokemon/HitPoint.hpp"
#include "YAPOG/System/StringHelper.hpp"

#include "Battle/PokemonBattleInfoWidget.hpp"

namespace ycl
{
  PokemonBattleInfoWidget::PokemonBattleInfoWidget ()
    : BattleInfoWidget ()
    , hpValue_ ()
    , experienceBar_ ()
    , hpLabelBox_ ()
  {
    this->SetSize (yap::Vector2 (309.f, 108.f));
    nameBox_.SetSize (yap::Vector2 (256.f, 25.f));
    battleInfoBox_.SetSize (yap::Vector2 (309.f, 108.f));

    hpBox_.SetSize (yap::Vector2 (
      hpBarPictureBox_->GetSize ().x, 
      hpBarPictureBox_->GetSize ().y));

    genderBox_.SetSize (yap::Vector2 (
      genderPictureBox_->GetSize ().x, 
      genderPictureBox_->GetSize ().y));

    levelBox_.SetSize (yap::Vector2 (
      256.f - nameLabel_.GetSize ().x - genderPictureBox_->GetSize ().x, 
      25.f));

    yap::WidgetBackground* background = 
      new yap::WidgetBackground (
      "Pictures/Battle/PokemonInfoBackground.png", true);

    battleInfoBox_.SetBackground (*background);

    nameBox_.AddChild (nameLabel_);
    nameBox_.AddChild (genderBox_);
    nameBox_.AddChild (levelBox_);
    levelBox_.AddChild (levelLabel_, yap::LayoutBox::Align::RIGHT);

    hpBox_.AddChild (*hpBarPictureBox_);
    hpBarPictureBox_->AddChild (*hpBarContent_);
    genderBox_.AddChild (*genderPictureBox_);
    hpLabelBox_.AddChild (hpValue_);


    battleInfoBox_.AddChild (nameBox_, yap::LayoutBox::Align::LEFT);
    battleInfoBox_.AddChild (hpBox_, yap::LayoutBox::Align::RIGHT);
    battleInfoBox_.AddChild (hpLabelBox_, yap::LayoutBox::Align::RIGHT);

    hpBarContent_->Move (yap::Vector2 (45.f, 6.f));
  }

  void PokemonBattleInfoWidget::SetHPValue (const yap::HitPoint& hp)
  {
    hpValue_.SetText (
      yap::StringHelper::ToString (hp.GetCurrentValue ()) + 
      " / " +
      yap::StringHelper::ToString (hp.GetValue ()));
  }
}
