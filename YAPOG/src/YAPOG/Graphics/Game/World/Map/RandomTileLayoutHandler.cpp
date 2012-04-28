#include "YAPOG/Graphics/Game/World/Map/RandomTileLayoutHandler.hpp"
#include "YAPOG/Graphics/Game/World/Map/TileLayer.hpp"
#include "YAPOG/Graphics/Game/World/Map/Tile.hpp"
#include "YAPOG/System/RandomHelper.hpp"

namespace yap
{
  RandomTileLayoutHandler::RandomTileLayoutHandler ()
    : TileLayoutHandler ()
    , tiles_ ()
  {
  }

  RandomTileLayoutHandler::~RandomTileLayoutHandler ()
  {
    for (const Tile* tile : tiles_)
      delete tile;
  }

  void RandomTileLayoutHandler::AddTile (Tile* tile)
  {
    tiles_.Add (tile);
  }

  void RandomTileLayoutHandler::HandleExecute (TileLayer& tileLayer)
  {
    if (tiles_.Count () <= 0)
      return;

    for (uint y = 0; y < tileLayer.GetHeight (); y++)
    {
      for (uint x = 0; x < tileLayer.GetWidth (); ++x)
      {
        uint index = RandomHelper::GetNext (0, tiles_.Count () - 1);

        tileLayer.SetTile (x, y, tiles_[index]->Clone ());
      }
    }
  }
} // namespace yap
