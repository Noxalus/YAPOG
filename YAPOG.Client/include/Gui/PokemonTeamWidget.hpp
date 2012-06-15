#ifndef YAPOG_CLIENT_POKEMONTEAMWIDGET_HPP
# define YAPOG_CLIENT_POKEMONTEAMWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  class Pokedex;
  class PictureBox;
  class PokemonInfo;
  class Menu;
}

namespace ycl
{
  class PokemonTeamWidget : public yap::BaseWidget
  {
    DISALLOW_COPY(PokemonTeamWidget);

  public:
    
    PokemonTeamWidget ();
    void Init ();
    virtual ~PokemonTeamWidget();
    virtual bool IsFocusable () const;

  protected:
    virtual yap::Vector2 HandleGetSize () const;
    virtual void HandleMove (const yap::Vector2& offset);
    virtual void HandleScale (const yap::Vector2& factor);

    virtual void HandleDraw (yap::IDrawingContext& context);

    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    virtual void HandleUpdate (const yap::Time& dt);

  private:

  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONTEAMWIDGET_HPP