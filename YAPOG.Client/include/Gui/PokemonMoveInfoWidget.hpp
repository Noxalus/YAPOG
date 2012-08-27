#ifndef YAPOG_CLIENT_POKEMONMOVEINFOWIDGET_HPP
# define YAPOG_CLIENT_POKEMONMOVEINFOWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"

namespace yap
{
  class PictureBox;
  class Label;
  class VerticalLayout;
}

namespace ycl
{
  class Pokemon;

  class PokemonMoveInfoWidget : public yap::BaseWidget
  {
  public:
    PokemonMoveInfoWidget (const Pokemon& pokemon);

    virtual bool IsFocusable () const;

  private:
    const Pokemon& pokemon_;

  protected:
    virtual void HandleMove (const yap::Vector2& offset);
    virtual void HandleScale (const yap::Vector2& factor);
    virtual void HandleDraw (yap::IDrawingContext& offset);
    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);
    virtual void HandleUpdate (const yap::Time& dt);

  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONMOVEINFOWIDGET_HPP
