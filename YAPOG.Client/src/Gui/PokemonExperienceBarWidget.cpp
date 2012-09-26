#include "YAPOG/System/MathHelper.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
#include "YAPOG/Game/Pokemon/PokemonExperience.hpp"

#include "Gui/PokemonExperienceBarWidget.hpp"

namespace ycl
{
  const float PokemonExperienceBarWidget::
    MAX_BATTLE_EXP_BAR_SIZE = 192.f;
  const float PokemonExperienceBarWidget::
    MAX_TEAM_MANAGER_EXP_BAR_SIZE = 187.f;

  PokemonExperienceBarWidget::PokemonExperienceBarWidget (bool inBattle_)
    : yap::ProgressBarWidget ()
    , experience_ (nullptr)
    , inBattle_ (inBattle_)
    , levelEarned_ (0)
  {
    if (!inBattle_)
    {
      mainLayout_ = new yap::HorizontalLayout (
        yap::Padding (60, 0, 0, 11), yap::Padding (), false);
    }
    else
    {
      mainLayout_ = new yap::HorizontalLayout (
        yap::Padding (), yap::Padding (), false);
    }

    barContent_ = new yap::PictureBox ();
  }

  void PokemonExperienceBarWidget::Init ()
  {
    barContent_->SetPicture (new yap::Sprite (
      "Pictures/TeamManager/ExperienceBarContent.png"));

    if (!inBattle_)
    {
      SetSize (yap::Vector2 (258, 26));

      SetBackground (*new yap::WidgetBackground (
        "Pictures/TeamManager/ExperienceBarContainer.png", true));

      barContent_->SetSize (yap::Vector2 (1, 8)); 

      mainLayout_->SetSize (GetSize ());
      mainLayout_->AddChild (*barContent_, yap::LayoutBox::Align::TOP);
    }
    else
    {
      SetSize (yap::Vector2 (192, 19));
      barContent_->SetSize (yap::Vector2 (1, 6)); 

      mainLayout_->SetSize (GetSize ());
      mainLayout_->AddChild (*barContent_, yap::LayoutBox::Align::BOTTOM);
    }

    AddChild (*mainLayout_);

    //mainLayout_->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
  }

  void PokemonExperienceBarWidget::SetExperience (
    const yap::PokemonExperience& experience)
  {
    experience_ = &experience;
    previousValue_ = experience_->GetValue ();

    RefreshWidget ();
  }

  void PokemonExperienceBarWidget::UpdateExperienceBar (
    yap::UInt16 levelEarned)
  {
    variance_ = experience_->GetValue () - previousValue_;
    levelEarned_ = levelEarned;
    previousValue_ = experience_->GetValue ();
    timer_.Reset ();
  }

  void PokemonExperienceBarWidget::RefreshWidget ()
  {
    /// @todo Fix the bug when a Pokemon level up
    float size = 0;
    float percentage = experience_->GetExperiencePercentage (
      experience_->GetValue () - variance_, 
      experience_->GetLevel () - levelEarned_);

    if (levelEarned_ > 0 && percentage == 1)
      levelEarned_--;

    if (inBattle_)
      size = MAX_BATTLE_EXP_BAR_SIZE * percentage;
    else
      size = MAX_TEAM_MANAGER_EXP_BAR_SIZE * percentage;

    // Update the size
    barContent_->SetSize (yap::Vector2 (
      size + 1,
      barContent_->GetSize ().y));
  }

  void PokemonExperienceBarWidget::HandleUpdate (const yap::Time& dt)
  {
    ProgressBarWidget::HandleUpdate (dt);
  }

  bool PokemonExperienceBarWidget::IsFocusable () const
  {
    return false;
  }

} // namespace ycl
