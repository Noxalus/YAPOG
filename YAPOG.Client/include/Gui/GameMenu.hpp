#ifndef YAPOG_CLIENT_GAMEMENU_hpp
# define YAPOG_CLIENT_GAMEMENU_hpp

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/Menu.hpp"

namespace ycl
{
  class GameMenu : public yap::Menu
  {
      DISALLOW_COPY(GameMenu);

    public:

      GameMenu(
        yap::Menu::Type menuType,
        const yap::Padding& ext,
        const yap::Padding& in,
        bool fixed);
      virtual ~GameMenu ();

  protected:

      virtual bool HandleOnEvent (const yap::GuiEvent& guiEvent);

    virtual void HandleItemActivated ();
    virtual void HandleItemSelected ();
  };
} // namespace ycl

#endif // YAPOG_CLIENT_GAMEMENU_hpp
