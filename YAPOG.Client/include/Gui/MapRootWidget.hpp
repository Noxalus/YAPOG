#ifndef YAPOG_CLIENT_MAPROOTWIDGET_HPP
# define YAPOG_CLIENT_MAPROOTWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/Game/World/GameWorldWidget.hpp"
# include "YAPOG/Collection/Map.hpp"

namespace ycl
{
  class Map;
  class Player;
  class MapPlayerInfoPanel;

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

      void AddPlayerInfoPanel (Player* player);
      void RemovePlayerInfoPanel (Player* player);

      void Clear ();

      void HandleSetCurrentMap (Map* oldMap, Map* map);

      Map* currentMap_;

      yap::collection::Map<Player*, MapPlayerInfoPanel*> playerInfoPanels_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_MAPROOTWIDGET_HPP
