#include "YAPOG/System/MathHelper.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Game/Pokemon/HitPoint.hpp"
#include "YAPOG/System/Time/Time.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"

#include "Gui/PokemonHPBarWidget.hpp"
#include "Pokemon/Pokemon.hpp"

namespace ycl
{
  const sf::Color PokemonHPBarWidget::
    DEFAULT_HP_COLOR_GOOD = sf::Color (110, 250, 170);
  const sf::Color PokemonHPBarWidget::
    DEFAULT_HP_COLOR_MEDIUM = sf::Color (250, 225, 50);
  const sf::Color PokemonHPBarWidget::
    DEFAULT_HP_COLOR_BAD = sf::Color (250, 90, 60);

  const float PokemonHPBarWidget::MAX_HP_BAR_SIZE = 144.f;

  PokemonHPBarWidget::PokemonHPBarWidget ()
    : yap::ProgressBarWidget ()
    , hp_ (nullptr)
  {
    mainLayout_ = new yap::HorizontalLayout (
      yap::Padding (45, 0, 0, 6), yap::Padding (), false);
    barContent_ = new yap::PictureBox ();
  }

  void PokemonHPBarWidget::Init ()
  {
    SetSize (yap::Vector2 (195, 21));

    SetBackground (*new yap::WidgetBackground (
      "Pictures/Battle/HPBattleBar.png", true));

    barContent_->SetPicture (new yap::Sprite (
      "Pictures/Battle/HPBarContent.png"));

    mainLayout_->SetSize (GetSize ());

    mainLayout_->AddChild (*barContent_, yap::LayoutBox::Align::TOP);

    AddChild (*mainLayout_);
  }

  void PokemonHPBarWidget::SetHitPoint (const yap::HitPoint& hp)
  {
    hp_ = &hp;
    previousValue_ = hp_->GetCurrentValue ();

    RealUpdate ();
  }

  void PokemonHPBarWidget::UpdateProgressBar ()
  {
    variance_ = previousValue_ - hp_->GetCurrentValue ();
    previousValue_ = hp_->GetCurrentValue ();
    timer_.Reset ();
  }

  void PokemonHPBarWidget::RealUpdate ()
  {
    // Update the color
    /*
    /// Red: -1.4x + 250
    int red = (-1.4f) * value + 250;
    /// Green: 2x + 50
    int green = 2 * value + 50;
    /// Blue: 1.2x + 50
    int blue = 1.2f * value + 50;

    hpBarContent_->ChangeColor (sf::Color (
    yap::MathHelper::Clamp (red, 0, 255),
    yap::MathHelper::Clamp (green, 0, 255),
    yap::MathHelper::Clamp (blue, 0, 255)));
    */

    float hpPercentage = 
      yap::MathHelper::Clamp (
      static_cast<float>(hp_->GetCurrentValue () + variance_) / 
      static_cast<float>(hp_->GetValue ()), 0.f, 1.f);

    float size = MAX_HP_BAR_SIZE * hpPercentage;

    // Update the size
    barContent_->SetSize (yap::Vector2 (
      size,
      barContent_->GetSize ().y));

    if (hpPercentage * 100 <= 25)
      barContent_->ChangeColor (DEFAULT_HP_COLOR_BAD);
    else if (hpPercentage * 100 <= 50)
      barContent_->ChangeColor (DEFAULT_HP_COLOR_MEDIUM);
    else
      barContent_->ChangeColor (DEFAULT_HP_COLOR_GOOD);
  }

  bool PokemonHPBarWidget::IsFocusable () const
  {
    return false;
  }

  void PokemonHPBarWidget::HandleMove (const yap::Vector2& offset)
  {
  }

  void PokemonHPBarWidget::HandleScale (const yap::Vector2& factor)
  {
  }
  void PokemonHPBarWidget::HandleDraw (yap::IDrawingContext& offset)
  {
  }

  void PokemonHPBarWidget::HandleShow (bool isVisible)
  {
  }

  void PokemonHPBarWidget::HandleChangeColor (const sf::Color& color)
  {
  }

} // namespace ycl
