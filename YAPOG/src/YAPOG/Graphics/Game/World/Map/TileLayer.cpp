#include "YAPOG/Graphics/Game/World/Map/TileLayer.hpp"
#include "YAPOG/Graphics/Game/World/Map/Tile.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"
#include "YAPOG/Graphics/ICamera.hpp"
#include "YAPOG/System/MathHelper.hpp"

namespace yap
{
  const bool TileLayer::DEFAULT_VISIBLE_STATE = true;
  const sf::Color TileLayer::DEFAULT_COLOR = sf::Color ();
  const uint TileLayer::DEFAULT_DRAW_MARGIN = 4;

  TileLayer::TileLayer (uint width, uint height)
    : width_ (width)
    , height_ (height)
    , tiles_ (width_ * height_, nullptr)
    , isVisible_ (DEFAULT_VISIBLE_STATE)
    , color_ (DEFAULT_COLOR)
  {
  }

  TileLayer::~TileLayer ()
  {
    for (const Tile* tile : tiles_)
      delete tile;
  }

  TileLayer::TileLayer (const TileLayer& copy)
    : width_ (copy.width_)
    , height_ (copy.height_)
    , tiles_ (width_ * height_, nullptr)
    , isVisible_ (copy.isVisible_)
    , color_ (copy.color_)
  {
    for (collection::Array<Tile*>::SizeType count = 0;
         count < width_ * height_;
         ++count)
      tiles_[count] = copy.tiles_[count]->Clone ();
  }

  TileLayer* TileLayer::Clone () const
  {
    return new TileLayer (*this);
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

    tile->SetPosition (
      Vector2 (
        x * Tile::DEFAULT_SIZE,
        y * Tile::DEFAULT_SIZE));
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
    if (!IsVisible ())
      return;

    int left =
      context.GetCamera ().GetTopLeft ().x / Tile::DEFAULT_SIZE -
      DEFAULT_DRAW_MARGIN;
    int top =
      context.GetCamera ().GetTopLeft ().y / Tile::DEFAULT_SIZE -
      DEFAULT_DRAW_MARGIN;
    int right =
      context.GetCamera ().GetBottomRight ().x / Tile::DEFAULT_SIZE +
      DEFAULT_DRAW_MARGIN;
    int bottom =
      context.GetCamera ().GetBottomRight ().y / Tile::DEFAULT_SIZE +
      DEFAULT_DRAW_MARGIN;

    int maxX = width_ - 1;
    int maxY = height_ - 1;

    uint clampedLeft = MathHelper::Clamp (left, 0, maxX);
    uint clampedTop = MathHelper::Clamp (top, 0, maxY);
    uint clampedRight = MathHelper::Clamp (right, 0, maxX);
    uint clampedBottom = MathHelper::Clamp (bottom, 0, maxY);

    for (uint y = clampedTop; y <= clampedBottom; ++y)
      for (uint x = clampedLeft; x <= clampedRight; ++x)
        tiles_[y * width_ + x]->Draw (context);
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
