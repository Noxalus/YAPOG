#ifndef YAPOG_MAPROOTWIDGET_HPP
# define YAPOG_MAPROOTWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/Game/World/GameWorldWidget.hpp"

namespace yap
{
  class Map;

  class MapRootWidget : public GameWorldWidget
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
} // namespace yap

#endif // YAPOG_MAPROOTWIDGET_HPP
