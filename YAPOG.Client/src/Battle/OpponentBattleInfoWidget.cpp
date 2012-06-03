#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"

#include "Battle/OpponentBattleInfoWidget.hpp"

namespace ycl
{
  OpponentBattleInfoWidget::OpponentBattleInfoWidget ()
    : BattleInfoWidget ()
  {
    nameBox_.SetSize (yap::Vector2 (256.f, 25.f));
    battleInfoBox_.SetSize (yap::Vector2 (300.f, 84.f));

    hpBarPictureBox_->SetPicture ("Pictures/HPBattleBar.png");

    hpBox_.SetSize (yap::Vector2 (
      hpBarPictureBox_->GetSize ().x, 
      hpBarPictureBox_->GetSize ().y));

    genderPictureBox_->SetPicture ("Pictures/Femaleb.png");

    genderBox_.SetSize (yap::Vector2 (
      genderPictureBox_->GetSize ().x, 
      genderPictureBox_->GetSize ().y));

    levelBox_.SetSize (yap::Vector2 (
      256.f - nameLabel_.GetSize ().x - genderPictureBox_->GetSize ().x, 
      25.f));

    yap::WidgetBackground* background = 
      new yap::WidgetBackground ("Pictures/opponent_battle_info.png", false);
      
    battleInfoBox_.SetBackground (*background);

    nameBox_.AddChild (nameLabel_);
    nameBox_.AddChild (genderBox_);
    nameBox_.AddChild (levelBox_);
    levelBox_.AddChild (levelLabel_, yap::LayoutBox::Align::RIGHT);
    battleInfoBox_.AddChild (nameBox_, yap::LayoutBox::Align::LEFT);
    hpBox_.AddChild (*hpBarPictureBox_);
    genderBox_.AddChild (*genderPictureBox_);
    battleInfoBox_.AddChild (hpBox_, yap::LayoutBox::Align::RIGHT);

    Init ();
  }
}
