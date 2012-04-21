#include "YAPOG/Graphics/Game/World/Map/TileLayer.hpp"
#include "YAPOG/Graphics/Game/World/Map/Tile.hpp"
#include "YAPOG/Graphics/Game/World/Map/TileLayoutHandler.hpp"

namespace yap
{
  const bool TileLayer::DEFAULT_VISIBLE_STATE = true;
  const sf::Color TileLayer::DEFAULT_COLOR = sf::Color ();

  TileLayer::TileLayer (UInt32 width, UInt32 height)
    : width_ (width)
    , height_ (height)
    , tiles_ ()
    , layoutHandler_ (nullptr)
    , isVisible_ (DEFAULT_VISIBLE_STATE)
    , color_ (DEFAULT_COLOR)
  {
  }

  TileLayer::~TileLayer ()
  {
    for (const Tile* tile : tiles_)
      delete tile;
  }

  const Tile& TileLayer::GetTile (UInt32 x, UInt32 y) const
  {
    collection::Array<Tile*>::SizeType index = y * width_ + x;

    return *tiles_[index];
  }

  Tile& TileLayer::GetTile (UInt32 x, UInt32 y)
  {
    collection::Array<Tile*>::SizeType index = y * width_ + x;

    return *tiles_[index];
  }

  void TileLayer::SetTile (UInt32 x, UInt32 y, Tile* tile)
  {
    collection::Array<Tile*>::SizeType index = y * width_ + x;

    tiles_[index] = tile;
  }

  void TileLayer::SetLayoutHandler (TileLayoutHandler* layoutHandler)
  {
    layoutHandler_ = layoutHandler;
  }

  void TileLayer::PerformLayout ()
  {
    layoutHandler_->Execute ();
  }

  void TileLayer::Draw (IDrawingContext& context)
  {
    if (!isVisible_)
      return;

    for (Tile* tile : tiles_)
      tile->Draw (context);
  }

  bool TileLayer::IsVisible () const
  {
    return isVisible_;
  }

  void TileLayer::Show (bool isVisible)
  {
    isVisible_ = isVisible;
  }

  void TileLayer::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    for (Tile* tile : tiles_)
      tile->ChangeColor (color);
  }

  void TileLayer::Update (const Time& dt)
  {
    for (Tile* tile : tiles_)
      tile->Update (dt);
  }
} // namespace yap
