#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Game/Pokemon/HitPoint.hpp"
#include "YAPOG/System/StringHelper.hpp"

#include "Battle/PokemonBattleInfoWidget.hpp"

namespace ycl
{
  PokemonBattleInfoWidget::PokemonBattleInfoWidget ()
    : BattleInfoWidget (yap::Padding (40, 30, 0, 0))
    , hpValue_ ()
    , experienceBar_ ()
  {
  }

  void PokemonBattleInfoWidget::Init ()
  {
    // Set background
    yap::WidgetBackground* background = 
      new yap::WidgetBackground (
      "Pictures/Battle/PokemonInfoBackground.png", true);
    background->SetFixed (true);
    battleInfoBox_.SetBackground (*background);

    BattleInfoWidget::Init ();

    hpValue_.ChangeColor (sf::Color::Black);
    battleInfoBox_.AddChild (hpValue_, yap::LayoutBox::Align::RIGHT);
  }

  void PokemonBattleInfoWidget::SetHPValue (const yap::HitPoint& hp)
  {
    hpValue_.SetText (
      yap::StringHelper::ToString (hp.GetCurrentValue ()) + 
      " / " +
      yap::StringHelper::ToString (hp.GetValue ()));

    battleInfoBox_.Refresh ();
  }
}
