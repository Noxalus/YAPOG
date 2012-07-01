#ifndef YAPOG_CLIENT_GAMEMAINMENU_HPP
# define YAPOG_CLIENT_GAMEMAINMENU_hpp

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/Menu.hpp"

namespace ycl
{
  class GameMainMenu : public yap::Menu
  {
      DISALLOW_COPY(GameMainMenu);

    public:

      GameMainMenu();
      virtual ~GameMainMenu ();

      void Init (const yap::String& playerName);

      yap::Event<
        GameMainMenu&,
        const yap::EmptyEventArgs&> OnPokedexItemActivated;
      yap::Event<
        GameMainMenu&,
        const yap::EmptyEventArgs&> OnPokemonItemActivated;

    private:

      yap::MenuItem& AddItem (const yap::String& itemName);

      static const yap::Menu::Type DEFAULT_ALIGNMENT;
      static const yap::Padding DEFAULT_PADDING;

      static const sf::Color DEFAULT_ITEM_COLOR;
      static const yap::LayoutBox::Align DEFAULT_ITEM_ALIGNMENT;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_GAMEMAINMENU_HPP
