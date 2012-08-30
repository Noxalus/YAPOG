#ifndef YAPOG_CLIENT_POKEMONINFOWIDGET_HPP
# define YAPOG_CLIENT_POKEMONINFOWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"

# include "Gui/IPokemonSummaryWidget.hpp"

namespace ycl
{
  class Pokemon;

  class PokemonInfoWidget : public yap::BaseWidget
  {
     DISALLOW_COPY(PokemonInfoWidget);
  public:
    PokemonInfoWidget ();
    ~PokemonInfoWidget ();
    
    void Init (Pokemon* pokemon);

    virtual bool IsFocusable () const;

  private:
    Pokemon* pokemon_;
    yap::UInt8 pageNumber_;
    yap::collection::Array<IPokemonSummaryWidget*> pokemonInfoPages_;

  protected:
    virtual void HandleMove (const yap::Vector2& offset);
    virtual void HandleScale (const yap::Vector2& factor);
    virtual void HandleDraw (yap::IDrawingContext& context);
    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);
    virtual void HandleUpdate (const yap::Time& dt);
    virtual bool HandleOnEvent (const yap::GuiEvent& guiEvent);

  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONINFOWIDGET_HPP
