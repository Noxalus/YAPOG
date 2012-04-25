#ifndef YAPOG_RANDOMTILELAYOUTHANDLER_HPP
# define YAPOG_RANDOMTILELAYOUTHANDLER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/World/Map/TileLayoutHandler.hpp"
# include "YAPOG/Collection/Array.hpp"

namespace yap
{
  class Tile;

  class RandomTileLayoutHandler : public TileLayoutHandler
  {
      DISALLOW_COPY(RandomTileLayoutHandler);

    public:

      RandomTileLayoutHandler ();
      virtual ~RandomTileLayoutHandler ();

    private:

      virtual void HandleExecute (TileLayer& tileLayer);

      collection::Array<Tile*> tiles_;
  };
} // namespace yap

#endif // YAPOG_RANDOMTILELAYOUTHANDLER_HPP
