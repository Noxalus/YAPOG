#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
#include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/Gui/MultiLabelWidget.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"

#include "Gui/PokemonMoveInfoWidget.hpp"
#include "Pokemon/Pokemon.hpp"

namespace ycl
{
  PokemonMoveInfoWidget::PokemonMoveInfoWidget ()
    : mainLayout_ (nullptr)
    , firstLine_ (nullptr)
    , firstLinePartRight_ (nullptr)
    , pokemonFrontInfoWidget_ ()
    , pokemonSingleMoveInfoWidgets_ (4, nullptr)
  {
    // Layouts
    mainLayout_ = new yap::VerticalLayout (
      yap::Padding (), yap::Padding (), false);

    firstLine_ = new yap::HorizontalLayout (
      yap::Padding (), yap::Padding (), false);

    firstLinePartRight_ = new yap::VerticalLayout (
      yap::Padding (5, 0, 0, 15), yap::Padding (0, 0, 11, 0), false);
  }

  void PokemonMoveInfoWidget::Init ()
  {
    SetBackground (*new yap::WidgetBackground (
      "Pictures/TeamManager/PokemonMoveInfoBackground.png", true));

    pokemonFrontInfoWidget_.Init ();

    // Set layouts size
    mainLayout_->SetSize (GetSize ());
    firstLine_->SetSize (yap::Vector2 (800, 328));
    firstLinePartRight_->SetSize (yap::Vector2 (408, 410));

    // Hierarchy construction
    firstLine_->AddChild (pokemonFrontInfoWidget_, yap::LayoutBox::Align::TOP);
    firstLine_->AddChild (*firstLinePartRight_, yap::LayoutBox::Align::TOP);

    mainLayout_->AddChild (*firstLine_, yap::LayoutBox::Align::LEFT);

    AddChild (*mainLayout_);

    mainLayout_->SetPosition (yap::Vector2 (1, 60));
  }

  void PokemonMoveInfoWidget::SetPokemon (const Pokemon& pokemon)
  {
    pokemonFrontInfoWidget_.SetPokemon (pokemon);

    firstLinePartRight_->Clear ();

    for (int i = 0; i < 4; i++)
    {
      if (pokemon.GetMoveSet ().GetMove (i) != nullptr)
      {
        PokemonSingleMoveInfoWidget* pokemonSingleMoveInfoWidget = 
          new PokemonSingleMoveInfoWidget (*pokemon.GetMoveSet ().GetMove (i));

        pokemonSingleMoveInfoWidget->Init ();

        pokemonSingleMoveInfoWidgets_[i] = pokemonSingleMoveInfoWidget;

        firstLinePartRight_->AddChild (*pokemonSingleMoveInfoWidget);
      }
    }
  }

  /// @name IWidget members.
  /// {
  /*
  void PokemonMoveInfoWidget::SetDefaultColor (const sf::Color& color)
  {}
  void PokemonMoveInfoWidget::AddDrawable (yap::IDrawable& drawable)
  {}
  void PokemonMoveInfoWidget::AddChild (yap::IWidget& child)
  {}
  yap::IWidget& PokemonMoveInfoWidget::GetRoot () const
  { return GetRoot (); }
  yap::WidgetBorder* PokemonMoveInfoWidget::GetBorder () const
  { return GetBorder (); }
  void PokemonMoveInfoWidget::SetParent (yap::IWidget& parent)
  {}
  void PokemonMoveInfoWidget::SetPadding (const yap::Padding& padding)
  {}
  void PokemonMoveInfoWidget::SetBackground (yap::WidgetBackground& background)
  {}
  void PokemonMoveInfoWidget::SetBorder  (yap::WidgetBorder& border, yap::uint width)
  {}
  void PokemonMoveInfoWidget::Refresh ()
  {}
  */
  bool PokemonMoveInfoWidget::IsFocusable () const
  {
    return false;
  }
  /*
  void PokemonMoveInfoWidget::SetFocused (bool state)
  {}
  void PokemonMoveInfoWidget::SetEnable (bool enable)
  {}
  void PokemonMoveInfoWidget::Open ()
  {}
  void PokemonMoveInfoWidget::Close ()
  {}
  */
  /// }

  void PokemonMoveInfoWidget::HandleMove (const yap::Vector2& offset)
  {

  }
  void PokemonMoveInfoWidget::HandleScale (const yap::Vector2& factor)
  {

  }
  void PokemonMoveInfoWidget::HandleDraw (yap::IDrawingContext& offset)
  {

  }
  void PokemonMoveInfoWidget::HandleShow (bool isVisible)
  {
  }
  void PokemonMoveInfoWidget::HandleChangeColor (const sf::Color& color)
  {
  }
  void PokemonMoveInfoWidget::HandleUpdate (const yap::Time& dt)
  {
  }

} // namespace ycl
