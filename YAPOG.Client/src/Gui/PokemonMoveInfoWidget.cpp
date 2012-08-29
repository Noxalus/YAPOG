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
  PokemonMoveInfoWidget::PokemonMoveInfoWidget (const Pokemon& pokemon)
    : pokemon_ (pokemon)
    , mainLayout_ (nullptr)
    , firstLine_ (nullptr)
    , firstLinePartRight_ (nullptr)
    , pokemonFrontInfoWidget_ (pokemon)
    , pokemonSingleMoveInfoWidgets_ (4, nullptr)
  {
  }

  void PokemonMoveInfoWidget::Init ()
  {
    SetBackground (*new yap::WidgetBackground (
      "Pictures/TeamManager/PokemonMoveInfoBackground.png", true));

    pokemonFrontInfoWidget_.Init ();

    // Layouts
    mainLayout_ = new yap::VerticalLayout (
      yap::Padding (), yap::Padding (), false);

    firstLine_ = new yap::HorizontalLayout (
      yap::Padding (), yap::Padding (), false);

    firstLinePartRight_ = new yap::VerticalLayout (
      yap::Padding (5, 0, 0, 15), yap::Padding (0, 0, 11, 0), false);

    // Set layouts size
    mainLayout_->SetSize (GetSize ());
    firstLine_->SetSize (yap::Vector2 (800, 328));
    firstLinePartRight_->SetSize (yap::Vector2 (408, 410));

    for (int i = 0; i < 4; i++)
    {
      if (pokemon_.GetMoveSet ().GetMove (i) != nullptr)
      {
        PokemonSingleMoveInfoWidget* pokemonSingleMoveInfoWidget = 
          new PokemonSingleMoveInfoWidget (*pokemon_.GetMoveSet ().GetMove (i));

        pokemonSingleMoveInfoWidget->Init ();

        pokemonSingleMoveInfoWidgets_[i] = pokemonSingleMoveInfoWidget;

        firstLinePartRight_->AddChild (*pokemonSingleMoveInfoWidget);
      }
    }

    firstLine_->AddChild (pokemonFrontInfoWidget_, yap::LayoutBox::Align::TOP);
    firstLine_->AddChild (*firstLinePartRight_, yap::LayoutBox::Align::TOP);

    mainLayout_->AddChild (*firstLine_, yap::LayoutBox::Align::LEFT);

    AddChild (*mainLayout_);

    mainLayout_->SetPosition (yap::Vector2 (1, 60));
  }

  bool PokemonMoveInfoWidget::IsFocusable () const
  {
    return false;
  }

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
