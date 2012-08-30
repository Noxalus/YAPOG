#include "Gui/PokemonInfoWidget.hpp"
#include "Gui/PokemonBasicInfoWidget.hpp"
#include "Gui/PokemonStatsInfoWidget.hpp"
#include "Gui/PokemonMoveInfoWidget.hpp"
#include "Pokemon/Pokemon.hpp"

namespace ycl
{
  PokemonInfoWidget::PokemonInfoWidget ()
    : pokemon_ (nullptr)
    , pageNumber_ (0)
    , pokemonInfoPages_ ()
  {
    SetSize (yap::Vector2 (800, 600));

    PokemonBasicInfoWidget* pokemonBasicInfoWidget =
      new PokemonBasicInfoWidget ();

    PokemonStatsInfoWidget* pokemonStatsInfoWidget =
      new PokemonStatsInfoWidget ();

    PokemonMoveInfoWidget* pokemonMoveInfoWidget =
      new PokemonMoveInfoWidget ();

    pokemonInfoPages_.Add (pokemonBasicInfoWidget);
    pokemonInfoPages_.Add (pokemonStatsInfoWidget);
    pokemonInfoPages_.Add (pokemonMoveInfoWidget);

    for (yap::BaseWidget* widget : pokemonInfoPages_)
    {
      widget->SetSize (GetSize ());
      widget->Close ();
      AddChild (*widget);
    }
  }

  PokemonInfoWidget::~PokemonInfoWidget ()
  {
    for (yap::BaseWidget* widget : pokemonInfoPages_)
      delete widget;
  }

  void PokemonInfoWidget::Init (Pokemon* pokemon)
  {
    pokemon_ = pokemon;
    pokemonInfoPages_[pageNumber_]->Init (*pokemon_);
    pokemonInfoPages_[pageNumber_]->Open ();
  }

  bool PokemonInfoWidget::IsFocusable () const
  {
    return false;
  }

  bool PokemonInfoWidget::HandleOnEvent (const yap::GuiEvent& guiEvent)
  {
    if (guiEvent.type == sf::Event::KeyPressed)
    {
      if (guiEvent.key.code == sf::Keyboard::Left)
      {
        pokemonInfoPages_[pageNumber_]->Close ();

        if (pageNumber_ == 0)
          pageNumber_ = pokemonInfoPages_.Count () - 1;
        else
          pageNumber_--;

        pokemonInfoPages_[pageNumber_]->Open ();

        return true;
      }

      if (guiEvent.key.code == sf::Keyboard::Right)
      {
        pokemonInfoPages_[pageNumber_]->Close ();

        pageNumber_ = (pageNumber_ + 1) % pokemonInfoPages_.Count ();

        pokemonInfoPages_[pageNumber_]->Init (*pokemon_);
        pokemonInfoPages_[pageNumber_]->Open ();

        return true;
      }

      if (guiEvent.key.code == sf::Keyboard::Return)
      {
        return true;
      }

      if (guiEvent.key.code == sf::Keyboard::Escape)
      {
        Close ();

        return true;
      }
    }

    return yap::BaseWidget::HandleOnEvent (guiEvent);
  }

  void PokemonInfoWidget::HandleMove (const yap::Vector2& offset)
  {

  }

  void PokemonInfoWidget::HandleScale (const yap::Vector2& factor)
  {

  }

  void PokemonInfoWidget::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void PokemonInfoWidget::HandleShow (bool isVisible)
  {
  }

  void PokemonInfoWidget::HandleChangeColor (const sf::Color& color)
  {
  }

  void PokemonInfoWidget::HandleUpdate (const yap::Time& dt)
  {
  }

} // namespace ycl
