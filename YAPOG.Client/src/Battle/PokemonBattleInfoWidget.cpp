#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Game/Pokemon/HitPoint.hpp"
#include "YAPOG/System/StringHelper.hpp"

#include "Battle/PokemonBattleInfoWidget.hpp"

namespace ycl
{
  PokemonBattleInfoWidget::PokemonBattleInfoWidget ()
    : BattleInfoWidget (yap::Padding (40, 30, 0, 0))
    , hp_ (nullptr)
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

  void PokemonBattleInfoWidget::SetHitPoint (const yap::HitPoint& hp)
  {
    BattleInfoWidget::SetHitPoint (hp);

    hp_ = &hp;

    UpdateHPBar ();
  }

  void PokemonBattleInfoWidget::UpdateHPBar ()
  {
    BattleInfoWidget::UpdateHPBar ();

    hpValue_.SetText (
      yap::StringHelper::ToString (hp_->GetCurrentValue ()) + 
      " / " +
      yap::StringHelper::ToString (hp_->GetValue ()));

    battleInfoBox_.Refresh ();
  }
}
