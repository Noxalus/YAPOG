#ifndef YAPOG_CLIENT_MAPROOTWIDGET_HPP
# define YAPOG_CLIENT_MAPROOTWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/Game/World/GameWorldWidget.hpp"

namespace ycl
{
  class Map;

  class MapRootWidget : public yap::GameWorldWidget
  {
      DISALLOW_COPY(MapRootWidget);

    public:

      MapRootWidget ();

      virtual ~MapRootWidget ();

      void SetCurrentMap (Map* map);

    protected:

      Map& GetCurrentMap ();

    private:

      Map* currentMap_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_MAPROOTWIDGET_HPP
