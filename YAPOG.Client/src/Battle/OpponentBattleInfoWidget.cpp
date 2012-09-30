#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/GuiEvent.hpp"

#include "Battle/OpponentBattleInfoWidget.hpp"

namespace ycl
{
  OpponentBattleInfoWidget::OpponentBattleInfoWidget ()
    : BattleInfoWidget (yap::Padding (15, 40, 10, 5))
  {
  }

  void OpponentBattleInfoWidget::Init ()
  {
    // Set the background
    yap::WidgetBackground* background =
      new yap::WidgetBackground (
      "Pictures/Battle/OpponentInfoBackground.png", false);
    background->SetFixed (true);
    battleInfoBox_.SetBackground (*background);

    BattleInfoWidget::Init ();
  }

  void OpponentBattleInfoWidget::UpdateHPBar ()
  {
    BattleInfoWidget::UpdateHPBar ();
  }

  bool OpponentBattleInfoWidget::HandleOnEvent (const yap::GuiEvent& guiEvent)
  {
    return false;
  }
}
