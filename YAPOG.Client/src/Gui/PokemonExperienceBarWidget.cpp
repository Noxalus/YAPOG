#include "YAPOG/System/MathHelper.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
#include "YAPOG/Game/Pokemon/PokemonExperience.hpp"

#include "Gui/PokemonExperienceBarWidget.hpp"

namespace ycl
{
  const float PokemonExperienceBarWidget::MAX_EXP_BAR_SIZE = 137.f;

  PokemonExperienceBarWidget::PokemonExperienceBarWidget (bool inBattle_)
    : yap::ProgressBarWidget ()
    , experience_ (nullptr)
    , inBattle_ (inBattle_)
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
    if (!inBattle_)
    {
      SetSize (yap::Vector2 (258, 26));

      SetBackground (*new yap::WidgetBackground (
        "Pictures/TeamManager/ExperienceBarContainer.png", true));
    }
    else
      SetSize (yap::Vector2 (192, 6));

    barContent_->SetPicture (new yap::Sprite (
      "Pictures/TeamManager/ExperienceBarContent.png"));

    barContent_->SetSize (yap::Vector2 (1, 6)); 

    mainLayout_->SetSize (GetSize ());

    mainLayout_->AddChild (*barContent_, yap::LayoutBox::Align::TOP);

    mainLayout_->Move (yap::Vector2 (5, 10));

    AddChild (*mainLayout_);
  }

  void PokemonExperienceBarWidget::SetExperience (
    const yap::PokemonExperience& experience)
  {
    experience_ = &experience;
    previousValue_ = experience_->GetValue ();

    RealUpdate ();
  }

  void PokemonExperienceBarWidget::UpdateProgressBar ()
  {
    variance_ = previousValue_ - experience_->GetValue ();
    previousValue_ = experience_->GetValue ();
    timer_.Reset ();
  }

  void PokemonExperienceBarWidget::RealUpdate ()
  {
    /// @todo Fix the bug when a Pokemon level up
    float size = MAX_EXP_BAR_SIZE * 
      experience_->GetExperiencePercentage (variance_);

    // Update the size
    barContent_->SetSize (yap::Vector2 (
      size,
      barContent_->GetSize ().y));
  }

  bool PokemonExperienceBarWidget::IsFocusable () const
  {
    return false;
  }

  void PokemonExperienceBarWidget::HandleMove (const yap::Vector2& offset)
  {
  }

  void PokemonExperienceBarWidget::HandleScale (const yap::Vector2& factor)
  {
  }

  void PokemonExperienceBarWidget::HandleDraw (yap::IDrawingContext& offset)
  {
  }

  void PokemonExperienceBarWidget::HandleShow (bool isVisible)
  {
  }

  void PokemonExperienceBarWidget::HandleChangeColor (const sf::Color& color)
  {
  }

} // namespace ycl
