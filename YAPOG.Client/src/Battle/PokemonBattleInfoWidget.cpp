#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"

#include "Battle/PokemonBattleInfoWidget.hpp"

namespace ycl
{
  PokemonBattleInfoWidget::PokemonBattleInfoWidget ()
    : BattleInfoWidget ()
  {
    this->SetSize (yap::Vector2 (309.f, 108.f));
    nameBox_.SetSize (yap::Vector2 (256.f, 25.f));
    battleInfoBox_.SetSize (yap::Vector2 (309.f, 108.f));

    hpBarPictureBox_->SetPicture ("Pictures/Battle/HPBattleBar.png");

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
      new yap::WidgetBackground ("Pictures/Battle/PokemonInfoBackground.png", false);
      
    battleInfoBox_.SetBackground (*background);

    nameBox_.AddChild (nameLabel_);
    nameBox_.AddChild (genderBox_);
    nameBox_.AddChild (levelBox_);
    levelBox_.AddChild (levelLabel_, yap::LayoutBox::Align::RIGHT);
    battleInfoBox_.AddChild (nameBox_, yap::LayoutBox::Align::LEFT);
    hpBox_.AddChild (*hpBarPictureBox_);
    genderBox_.AddChild (*genderPictureBox_);
    battleInfoBox_.AddChild (hpBox_, yap::LayoutBox::Align::RIGHT);
  }
}
