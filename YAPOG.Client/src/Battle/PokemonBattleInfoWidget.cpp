#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Game/Pokemon/HitPoint.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Game/Pokemon/PokemonExperience.hpp"

#include "Battle/PokemonBattleInfoWidget.hpp"

namespace ycl
{
  PokemonBattleInfoWidget::PokemonBattleInfoWidget ()
    : BattleInfoWidget (yap::Padding (40, 24, 0, 0))
    , hp_ (nullptr)
    , hpValue_ ()
    , experienceBar_ (true)
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
    experienceBar_.Init ();

    experienceBar_.OnExperienceBarLevelUp += 
      [&] (const yap::ProgressBarWidget&, const yap::EmptyEventArgs&) 
    {
      UpdateHPBar ();
    };

    hpValue_.ChangeColor (sf::Color::Black);
    battleInfoBox_.AddChild (hpValue_, yap::LayoutBox::Align::RIGHT);
    battleInfoBox_.AddChild (experienceBar_, yap::LayoutBox::Align::RIGHT);

    // Debug borders
    /*
    hpValue_.SetBorder (*new yap::WidgetBorder ("Test/black.png"));
    */
  }

  void PokemonBattleInfoWidget::SetHitPoint (const yap::HitPoint& hp)
  {
    hp_ = &hp;

    UpdateHPBar ();
  }

  void PokemonBattleInfoWidget::SetExperience (
    const yap::PokemonExperience& experience)
  {
    experienceBar_.SetExperience (experience);

    UpdateExperienceBar (0);
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

  void PokemonBattleInfoWidget::UpdateExperienceBar (yap::UInt16 levelEarned)
  {
    experienceBar_.UpdateExperienceBar (levelEarned);
  }
}
