#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"

#include "Battle/OpponentBattleInfoWidget.hpp"

namespace ycl
{
  OpponentBattleInfoWidget::OpponentBattleInfoWidget ()
    : BattleInfoWidget ()
  {
    this->SetSize (yap::Vector2 (300.f, 84.f));
    battleInfoBox_.SetSize (yap::Vector2 (300.f, 84.f));
    nameBox_.SetSize (yap::Vector2 (256.f, 25.f));

    hpBarPictureBox_->SetPicture ("Pictures/Battle/HPBattleBar.png");
    hpBarContent_->SetPicture ("Pictures/Battle/HPBarContent.png");

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
      "Pictures/Battle/OpponentInfoBackground.png", true);

    battleInfoBox_.SetBackground (*background);

    nameBox_.AddChild (nameLabel_);
    nameBox_.AddChild (genderBox_);
    nameBox_.AddChild (levelBox_);
    levelBox_.AddChild (levelLabel_, yap::LayoutBox::Align::RIGHT);
    battleInfoBox_.AddChild (nameBox_, yap::LayoutBox::Align::LEFT);
    hpBox_.AddChild (*hpBarPictureBox_);
    hpBarPictureBox_->AddChild (*hpBarContent_);
    genderBox_.AddChild (*genderPictureBox_);
    battleInfoBox_.AddChild (hpBox_, yap::LayoutBox::Align::RIGHT);

    hpBox_.Move (yap::Vector2 (20.f, 10.f));
    hpBarContent_->Move (yap::Vector2 (45.f, 6.f));
    nameBox_.Move (yap::Vector2 (20.f, 10.f));
  }
}
