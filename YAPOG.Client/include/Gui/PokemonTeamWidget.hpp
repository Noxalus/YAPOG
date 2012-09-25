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
# include "Gui/PokemonInfoWidget.hpp"

namespace yap
{
  class GridMenu;
}

namespace ycl
{
  class PokemonTeam;
  class PokemonInfoBox;
  class PokemonInfoWidget;

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
    virtual bool HandleOnEvent (const yap::GuiEvent& guiEvent);
    virtual void HandleOpen ();

  private:
    void RefreshWidget ();

    yap::Label* state_;
    yap::GridMenu* menu_;
    const PokemonTeam& team_;
    yap::collection::Array<PokemonInfoBox*> pokemonInfoBoxes_;
    yap::uint index_;
    PokemonInfoWidget pokemonInfoWidget_;

  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONTEAMWIDGET_HPP