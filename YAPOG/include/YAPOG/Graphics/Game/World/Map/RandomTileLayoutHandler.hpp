#ifndef YAPOG_RANDOMTILELAYOUTHANDLER_HPP
# define YAPOG_RANDOMTILELAYOUTHANDLER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/World/Map/TileLayoutHandler.hpp"
# include "YAPOG/Collection/Array.hpp"

namespace yap
{
  class Tile;

  class YAPOG_LIB RandomTileLayoutHandler : public TileLayoutHandler
  {
      DISALLOW_COPY(RandomTileLayoutHandler);

    public:

      RandomTileLayoutHandler ();
      virtual ~RandomTileLayoutHandler ();

      void AddTile (Tile* tile);

    private:

      virtual void HandleExecute (TileLayer& tileLayer);

      collection::Array<Tile*> tiles_;
  };
} // namespace yap

#endif // YAPOG_RANDOMTILELAYOUTHANDLER_HPP
