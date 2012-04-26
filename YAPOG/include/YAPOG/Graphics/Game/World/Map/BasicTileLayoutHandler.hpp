#ifndef YAPOG_BASICTILELAYOUTHANDLER_HPP
# define YAPOG_BASICTILELAYOUTHANDLER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/World/Map/TileLayoutHandler.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/System/IntTypes.hpp"

namespace yap
{
  class Tile;

  class YAPOG_LIB BasicTileLayoutHandler : public TileLayoutHandler
  {
      DISALLOW_COPY(BasicTileLayoutHandler);

    public:

      BasicTileLayoutHandler (uint width, uint height);
      virtual ~BasicTileLayoutHandler ();

      void SetTile (uint x, uint y, Tile* tile);

    private:

      virtual void HandleExecute (TileLayer& tileLayer);

      uint width_;
      uint height_;
      collection::Array<Tile*> tiles_;
  };
} // namespace yap

#endif // YAPOG_BASICTILELAYOUTHANDLER_HPP
