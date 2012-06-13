#ifndef YAPOG_CLIENT_WIDGETPOKEDEX_HPP
# define YAPOG_CLIENT_WIDGETPOKEDEX_HPP

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
  class PokedexCompositeWidget;
  class PokedexWidget : public yap::BaseWidget
  {
    DISALLOW_COPY(PokedexWidget);

  public:
    
    PokedexWidget (yap::Pokedex* pokedex);
    void Init ();
    virtual ~PokedexWidget();
    virtual bool IsFocusable () const;
    yap::PokemonInfo* GetActivatedPokemon () const;

  protected:
    virtual yap::Vector2 HandleGetSize () const;
    virtual void HandleMove (const yap::Vector2& offset);
    virtual void HandleScale (const yap::Vector2& factor);

    virtual void HandleDraw (yap::IDrawingContext& context);

    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    virtual void HandleUpdate (const yap::Time& dt);

  private:
    void Refresh ();
    yap::Pokedex* pokedex_;
    yap::PictureBox* boxInfoContent_;
    yap::Menu* menu_;
    yap::PokemonInfo* validatedPokemon_;
    yap::HorizontalLayout* firstHLayout_;
    yap::VerticalLayout* firstVLayout_;
    PokedexCompositeWidget* pokedexInfo_;
    yap::Label* pokSeen_;
    yap::Label* pokCaught_;

  };
} // namespace ycl

#endif // YAPOG_CLIENT_WIDGETPOKEDEX_HPP