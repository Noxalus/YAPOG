#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/GuiEvent.hpp"

#include "Battle/OpponentBattleInfoWidget.hpp"

namespace ycl
{
  OpponentBattleInfoWidget::OpponentBattleInfoWidget ()
    : BattleInfoWidget ()
  {
    this->SetSize (yap::Vector2 (300.f, 84.f));
    battleInfoBox_.SetSize (yap::Vector2 (300.f, 84.f));
    nameBox_.SetSize (yap::Vector2 (256.f, 30.f));
    genderBox_.SetSize (yap::Vector2 (12.f, 22.f));
    levelBox_.SetSize (yap::Vector2 (100.f, 50.f));

    hpBox_.SetSize (yap::Vector2 (
      hpBarPictureBox_->GetSize ().x,
      hpBarPictureBox_->GetSize ().y));

    genderBox_.SetSize (yap::Vector2 (
      genderPictureBox_->GetSize ().x,
      genderPictureBox_->GetSize ().y));

    yap::WidgetBackground* background =
      new yap::WidgetBackground (
      "Pictures/Battle/OpponentInfoBackground.png", true);

    battleInfoBox_.SetBackground (*background);

    /*
    nameBox_.AddChild (nameLabel_);
    nameBox_.AddChild (genderBox_);
    nameBox_.AddChild (levelBox_);
    levelBox_.AddChild (levelLabel_, yap::LayoutBox::Align::RIGHT);
    hpBox_.AddChild (*hpBarPictureBox_);
    hpBarPictureBox_->AddChild (*hpBarContent_);
    genderBox_.AddChild (*genderPictureBox_);
    battleInfoBox_.AddChild (hpBox_, yap::LayoutBox::Align::RIGHT);

    */
    nameBox_.AddChild (nameLabel_);
    nameBox_.AddChild (*genderPictureBox_);
    /*
    nameBox_.AddChild (levelBox_, yap::LayoutBox::Align::RIGHT);
    levelBox_.AddChild (levelLabel_);
    */
    battleInfoBox_.AddChild (nameBox_, yap::LayoutBox::Align::LEFT);
    
    hpBarContent_->Move (yap::Vector2 (45.f, 6.f));    
  }

  bool OpponentBattleInfoWidget::HandleOnEvent (const yap::GuiEvent& guiEvent)
  {
    return false;
  }
}
