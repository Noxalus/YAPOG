#include "YAPOG/Graphics/Game/World/Map/TileLayer.hpp"
#include "YAPOG/Graphics/Game/World/Map/Tile.hpp"
#include "YAPOG/Graphics/Game/World/Map/TileLayoutHandler.hpp"

namespace yap
{
  const bool TileLayer::DEFAULT_VISIBLE_STATE = true;
  const sf::Color TileLayer::DEFAULT_COLOR = sf::Color ();

  TileLayer::TileLayer (uint width, uint height)
    : width_ (width)
    , height_ (height)
    , tiles_ (width_ * height_, nullptr)
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

  const Tile& TileLayer::GetTile (uint x, uint y) const
  {
    collection::Array<Tile*>::SizeType index = y * width_ + x;

    return *tiles_[index];
  }

  Tile& TileLayer::GetTile (uint x, uint y)
  {
    collection::Array<Tile*>::SizeType index = y * width_ + x;

    return *tiles_[index];
  }

  void TileLayer::SetTile (uint x, uint y, Tile* tile)
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
    layoutHandler_->Execute (*this);
  }

  const uint& TileLayer::GetWidth () const
  {
    return width_;
  }

  const uint& TileLayer::GetHeight () const
  {
    return height_;
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
