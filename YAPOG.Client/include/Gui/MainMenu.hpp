#ifndef YAPOG_CLIENT_MAINMENU_HPP
# define YAPOG_CLIENT_MAINMENU_hpp

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/Menu.hpp"

namespace ycl
{
  class MainMenu : public yap::Menu
  {
      DISALLOW_COPY(MainMenu);

    public:
      MainMenu();
      virtual ~MainMenu ();

      void Init ();
      
  };
} // namespace ycl

#endif // YAPOG_CLIENT_MAINMENU_HPP
