#include "YAPOG/Graphics/Game/World/Map/Tile.hpp"
#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"

namespace yap
{
  const UInt32 Tile::DEFAULT_SIZE = 32;
  const bool Tile::DEFAULT_VISIBLE_STATE = true;
  const sf::Color Tile::DEFAULT_COLOR = sf::Color ();

  Tile::Tile (const ID& id)
    : id_ (id)
    , sprite_ (nullptr)
    , family_ (nullptr)
    , spatialInfo_ (DEFAULT_POSITION, Vector2 (DEFAULT_SIZE, DEFAULT_SIZE))
    , isVisible_ (DEFAULT_VISIBLE_STATE)
    , color_ (DEFAULT_COLOR)
  {
  }

  Tile::~Tile ()
  {
    delete sprite_;
    sprite_ = nullptr;
  }

  const Vector2& Tile::GetPosition () const
  {
    return spatialInfo_.GetPosition ();
  }

  const Vector2& Tile::GetSize () const
  {
    return spatialInfo_.GetSize ();
  }

  const Vector2& Tile::GetTopLeft () const
  {
    return spatialInfo_.GetTopLeft ();
  }

  const Vector2& Tile::GetBottomRight () const
  {
    return spatialInfo_.GetBottomRight ();
  }

  const Vector2& Tile::GetCenter () const
  {
    return spatialInfo_.GetCenter ();
  }

  const sf::FloatRect& Tile::GetRectangle () const
  {
    return spatialInfo_.GetRectangle ();
  }

  void Tile::Move (const Vector2& offset)
  {
    spatialInfo_.SetPosition (GetPosition () + offset);

    sprite_->Move (offset);
  }

  void Tile::Scale (const Vector2& factor)
  {
    spatialInfo_.SetSize (
      Vector2 (
        GetSize ().x * factor.x,
        GetSize ().y * factor.y));

    sprite_->Scale (factor);
  }

  void Tile::SetPosition (const Vector2& position)
  {
    Move (position - GetPosition ());
  }

  void Tile::SetSize (const Vector2& size)
  {
    Scale (
      Vector2 (
        size.x / GetSize ().x,
        size.y / GetSize ().y));
  }

  void Tile::Draw (IDrawingContext& context)
  {
    if (!isVisible_)
      return;

    sprite_->Draw (context);
  }

  bool Tile::IsVisible () const
  {
    return isVisible_;
  }

  void Tile::Show (bool isVisible)
  {
    isVisible_ = isVisible;
  }

  void Tile::ChangeColor (const sf::Color& color)
  {
    color_ = color;
  }

  void Tile::Update (const Time& dt)
  {
    sprite_->Update (dt);
  }
} // namespace yap
