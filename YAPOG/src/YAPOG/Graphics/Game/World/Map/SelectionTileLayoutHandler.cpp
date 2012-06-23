#include "YAPOG/Graphics/Game/World/Map/SelectionTileLayoutHandler.hpp"
#include "YAPOG/Graphics/Game/World/Map/Tile.hpp"
#include "YAPOG/Graphics/Game/World/Map/TileLayer.hpp"

namespace yap
{
  const uint SelectionTileLayoutHandler::DEFAULT_WIDTH = 0;
  const uint SelectionTileLayoutHandler::DEFAULT_HEIGHT = 0;

  SelectionTileLayoutHandler::SelectionTileLayoutHandler ()
    : TileLayoutHandler ()
    , width_ (DEFAULT_WIDTH)
    , height_ (DEFAULT_HEIGHT)
    , defaultTile_ (nullptr)
    , tiles_ (width_, height_, nullptr)
  {
  }

  SelectionTileLayoutHandler::~SelectionTileLayoutHandler ()
  {
    for (uint y = 0; y < height_; ++y)
      for (uint x = 0; x < width_; ++x)
        if (tiles_ (x, y) != defaultTile_)
        {
          delete tiles_ (x, y);
          tiles_ (x, y) = nullptr;
        }

    delete defaultTile_;
    defaultTile_ = nullptr;
  }

  void SelectionTileLayoutHandler::SetSize (uint width, uint height)
  {
    width_ = width;
    height_ = height;

    tiles_.Resize (width_, height_, nullptr);
  }

  void SelectionTileLayoutHandler::SetDefaultTile (Tile* defaultTile)
  {
    defaultTile_ = defaultTile;

    for (uint y = 0; y < height_; ++y)
      for (uint x = 0; x < width_; ++x)
        tiles_ (x, y) = defaultTile_;
  }

  void SelectionTileLayoutHandler::SetTile (uint x, uint y, Tile* tile)
  {
    tiles_ (x, y) = tile;
  }

  void SelectionTileLayoutHandler::HandleExecute (TileLayer& tileLayer)
  {
    for (uint y = 0; y < height_; ++y)
      for (uint x = 0; x < width_; ++x)
        tileLayer.SetTile (x, y, tiles_ (x, y)->Clone ());
  }
} // namespace yap
