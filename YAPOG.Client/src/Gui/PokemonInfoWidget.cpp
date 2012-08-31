#include "YAPOG/Audio/AudioManager.hpp"

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

    IPokemonSummaryWidget* pokemonBasicInfoWidget = 
      new PokemonBasicInfoWidget ();

    IPokemonSummaryWidget* pokemonStatsInfoWidget = 
      new PokemonStatsInfoWidget ();

    IPokemonSummaryWidget* pokemonMoveInfoWidget = 
      new PokemonMoveInfoWidget ();

    pokemonInfoPages_.Add (pokemonBasicInfoWidget);
    pokemonInfoPages_.Add (pokemonStatsInfoWidget);
    pokemonInfoPages_.Add (pokemonMoveInfoWidget);
  }

  PokemonInfoWidget::~PokemonInfoWidget ()
  {
    for (yap::BaseWidget* widget : pokemonInfoPages_)
      delete widget;
  }

  void PokemonInfoWidget::Init ()
  {
    for (IPokemonSummaryWidget* widget : pokemonInfoPages_)
    {
      widget->SetSize (GetSize ());
      widget->Init ();
      widget->Close ();

      AddChild (*widget);
    }
  }

  void PokemonInfoWidget::SetPokemon (Pokemon* pokemon)
  {
    pokemon_ = pokemon;

    pokemonInfoPages_[pageNumber_]->SetPokemon (*pokemon_);
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
        // Play a sound
        yap::AudioManager::Instance ().PlaySound ("SE/Select.wav");

        pokemonInfoPages_[pageNumber_]->Close ();

        if (pageNumber_ == 0)
          pageNumber_ = pokemonInfoPages_.Count () - 1;
        else
          pageNumber_--;

        pokemonInfoPages_[pageNumber_]->SetPokemon (*pokemon_);
        pokemonInfoPages_[pageNumber_]->Open ();

        return true;
      }

      if (guiEvent.key.code == sf::Keyboard::Right)
      {
        // Play a sound
        yap::AudioManager::Instance ().PlaySound ("SE/Select.wav");

        pokemonInfoPages_[pageNumber_]->Close ();

        pageNumber_ = (pageNumber_ + 1) % pokemonInfoPages_.Count ();

        pokemonInfoPages_[pageNumber_]->SetPokemon (*pokemon_);
        pokemonInfoPages_[pageNumber_]->Open ();

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
