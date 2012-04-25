#include "YAPOG/Graphics/Game/World/Map/BasicTileLayoutHandler.hpp"
#include "YAPOG/Graphics/Game/World/Map/TileLayer.hpp"

namespace yap
{
  BasicTileLayoutHandler::BasicTileLayoutHandler (uint width, uint height)
    : TileLayoutHandler ()
    , width_ (width)
    , height_ (height)
    , tiles_ (width_ * height_, nullptr)
  {
  }

  BasicTileLayoutHandler::~BasicTileLayoutHandler ()
  {
  }

  void BasicTileLayoutHandler::SetTile (uint x, uint y, Tile* tile)
  {
    tiles_[y * width_ + x] = tile;
  }

  void BasicTileLayoutHandler::HandleExecute (TileLayer& tileLayer)
  {
    for (uint y = 0; y < height_; ++y)
      for (uint x = 0; x < width_; ++x)
        tileLayer.SetTile (x, y, tiles_[y * width_ + x]);
  }
} // namespace yap
