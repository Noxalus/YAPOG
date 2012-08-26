#ifndef YAPOG_CLIENT_POKEMONTEAMWIDGET_HPP
# define YAPOG_CLIENT_POKEMONTEAMWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/Graphics/Gui/PictureBox.hpp"
# include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
# include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
# include "YAPOG/Graphics/Gui/Label.hpp"
# include "YAPOG/System/StringHelper.hpp"
# include "YAPOG/Game/Pokemon/Gender.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/Graphics/Gui/GuiEvent.hpp"
# include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"
# include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
# include "YAPOG/Graphics/Gui/WidgetBackground.hpp"

# include "Pokemon/Pokemon.hpp"

namespace yap
{
  class GridMenu;
}

namespace ycl
{
  class PokemonTeam;
  class PokemonInfoBox;

  class PokemonTeamWidget : public yap::BaseWidget
  {

    DISALLOW_COPY(PokemonTeamWidget);

  public:
    PokemonTeamWidget (const PokemonTeam& team);
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

    virtual bool HandleOnEvent (const yap::GuiEvent& guiEvent);
  private:
    yap::Label* state_;
    Pokemon* current_;
    yap::GridMenu* menu_;
    yap::VerticalLayout* vlayoutMenu_;
    const PokemonTeam& team_;
    yap::collection::Array<PokemonInfoBox*> pokemons;
    PokemonInfoBox* currentBox_;
    yap::WidgetBackground* selecBckgrd_;
    yap::uint ite_;

  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONTEAMWIDGET_HPP