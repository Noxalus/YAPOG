#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"

#include "Gui/PokemonHPBarWidget.hpp"
#include "Pokemon/Pokemon.hpp"

namespace ycl
{
  PokemonHPBarWidget::PokemonHPBarWidget ()
    : experienceBarContent_ (nullptr)
    , mainLayout_ (nullptr)
  {
    mainLayout_ = new yap::HorizontalLayout (
      yap::Padding (60, 0, 0, 11), yap::Padding (), false);
    experienceBarContent_ = new yap::PictureBox ();
  }

  void PokemonHPBarWidget::Init ()
  {
    SetSize (yap::Vector2 (258, 26));

    SetBackground (*new yap::WidgetBackground (
      "Pictures/TeamManager/ExperienceBarContainer.png", true));

    experienceBarContent_->SetPicture (new yap::Sprite (
      "Pictures/TeamManager/ExperienceBarContent.png"));

    mainLayout_->SetSize (GetSize ());

    mainLayout_->AddChild (*experienceBarContent_, yap::LayoutBox::Align::TOP);

    AddChild (*mainLayout_);
  }

  void PokemonHPBarWidget::SetPokemon (const Pokemon& pokemon)
  {
    experienceBarContent_->SetSize (yap::Vector2 (
      137 * pokemon.GetExperiencePercentage (), 8));
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

  void PokemonHPBarWidget::HandleUpdate (const yap::Time& dt)
  {
  }

} // namespace ycl
