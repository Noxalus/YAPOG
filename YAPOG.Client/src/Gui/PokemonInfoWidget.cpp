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
  }

  PokemonInfoWidget::~PokemonInfoWidget ()
  {
    for (yap::BaseWidget* widget : pokemonInfoPages_)
      delete widget;
  }

  void PokemonInfoWidget::Init ()
  {
    SetSize (yap::Vector2 (800, 600));

    PokemonBasicInfoWidget* pokemonBasicInfoWidget = 
      new PokemonBasicInfoWidget (*pokemon_);

    PokemonStatsInfoWidget* pokemonStatsInfoWidget = 
      new PokemonStatsInfoWidget (*pokemon_);

    PokemonMoveInfoWidget* pokemonMoveInfoWidget = 
      new PokemonMoveInfoWidget (*pokemon_);

    //pokemonInfoPages_.Add (pokemonBasicInfoWidget);
    //pokemonInfoPages_.Add (pokemonStatsInfoWidget);
    pokemonInfoPages_.Add (pokemonMoveInfoWidget);

    for (yap::BaseWidget* widget : pokemonInfoPages_)
    {
      widget->SetSize (GetSize ());
      AddChild (*widget);
    }

    //pokemonBasicInfoWidget->Init ();
    //pokemonStatsInfoWidget->Init ();
    pokemonMoveInfoWidget->Init ();
  }

  void PokemonInfoWidget::SetPokemon (Pokemon* pokemon)
  {
    pokemon_ = pokemon;

    Init ();
  }

  bool PokemonInfoWidget::IsFocusable () const
  {
    return false;
  }

  bool PokemonInfoWidget::HandleOnEvent (const yap::GuiEvent& guiEvent)
  {
    if (guiEvent.type == sf::Event::KeyPressed)
    {
      if (guiEvent.key.code == sf::Keyboard::Up)
      {
        return true;
      }
      if (guiEvent.key.code == sf::Keyboard::Down)
      {
        return true;
      }

      if (guiEvent.key.code == sf::Keyboard::Left)
      {
        if (pageNumber_ == 0)
          pageNumber_ = pokemonInfoPages_.Count () - 1;
        else
          pageNumber_--;

        return true;
      }

      if (guiEvent.key.code == sf::Keyboard::Right)
      {
        pageNumber_ = (pageNumber_ + 1) % pokemonInfoPages_.Count ();

        return true;
      }

      if (guiEvent.key.code == sf::Keyboard::Return)
      {
        return true;
      }
      if (guiEvent.key.code == sf::Keyboard::Escape)
      {
        return true;
      }
    }

    return false;
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
