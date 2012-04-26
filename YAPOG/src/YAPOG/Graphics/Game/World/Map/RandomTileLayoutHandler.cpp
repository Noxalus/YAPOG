#include "YAPOG/Graphics/Game/World/Map/RandomTileLayoutHandler.hpp"
#include "YAPOG/Graphics/Game/World/Map/TileLayer.hpp"
#include "YAPOG/Graphics/Game/World/Map/Tile.hpp"

namespace yap
{
  RandomTileLayoutHandler::RandomTileLayoutHandler ()
    : TileLayoutHandler ()
    , tiles_ ()
  {
  }

  RandomTileLayoutHandler::~RandomTileLayoutHandler ()
  {
  }

  void RandomTileLayoutHandler::AddTile (Tile* tile)
  {
    tiles_.Add (tile);
  }

  void RandomTileLayoutHandler::HandleExecute (TileLayer& tileLayer)
  {
    for (uint y = 0; y < tileLayer.GetHeight (); y++)
    {
      for (uint x = 0; x < tileLayer.GetWidth (); ++x)
      {
        /// @todo RandomHelper.
        if (tiles_.Count () <= 0)
          return;
        tileLayer.SetTile (x, y, tiles_[0]->Clone ());
      }
    }
  }
} // namespace yap
