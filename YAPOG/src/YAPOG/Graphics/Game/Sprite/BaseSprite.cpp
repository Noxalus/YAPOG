#include "YAPOG/Graphics/Game/Sprite/BaseSprite.hpp"

namespace yap
{
  const bool BaseSprite::DEFAULT_VISIBLE_STATE = true;
  const sf::Color BaseSprite::DEFAULT_COLOR = sf::Color ();

  BaseSprite::BaseSprite ()
    : spatialInfo_ ()
    , isVisible_ (DEFAULT_VISIBLE_STATE)
    , color_ (DEFAULT_COLOR)
  {
  }

  BaseSprite::~BaseSprite ()
  {
  }

  const Vector2& BaseSprite::GetPosition () const
  {
    return spatialInfo_.GetPosition ();
  }

  const Vector2& BaseSprite::GetSize () const
  {
    spatialInfo_.SetSize (HandleGetSize ());

    return spatialInfo_.GetSize ();
  }

  const Vector2& BaseSprite::GetTopLeft () const
  {
    return spatialInfo_.GetTopLeft ();
  }

  const Vector2& BaseSprite::GetBottomRight () const
  {
    return spatialInfo_.GetBottomRight ();
  }

  const Vector2& BaseSprite::GetCenter () const
  {
    return spatialInfo_.GetCenter ();
  }

  const sf::FloatRect& BaseSprite::GetRectangle () const
  {
    return spatialInfo_.GetRectangle ();
  }

  void BaseSprite::Move (const Vector2& offset)
  {
    spatialInfo_.SetPosition (GetPosition () + offset);

    HandleMove (offset);
  }

  void BaseSprite::Scale (const Vector2& factor)
  {
    spatialInfo_.SetSize (
      Vector2 (
        GetSize ().x * factor.x,
        GetSize ().y * factor.y));

    HandleScale (factor);
  }

  void BaseSprite::SetPosition (const Vector2& position)
  {
    Move (position - GetPosition ());
  }

  void BaseSprite::SetSize (const Vector2& size)
  {
    Scale (
      Vector2 (
        size.x / GetSize ().x,
        size.y / GetSize ().y));
  }

  void BaseSprite::Draw (IDrawingContext& context)
  {
    if (!isVisible_)
      return;

    HandleDraw (context);
  }

  bool BaseSprite::IsVisible () const
  {
    return isVisible_;
  }

  void BaseSprite::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void BaseSprite::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  void BaseSprite::Update (const Time& dt)
  {
    HandleUpdate (dt);
  }

  BaseSprite::BaseSprite (const BaseSprite& copy)
    : spatialInfo_ (copy.spatialInfo_)
    , isVisible_ (copy.isVisible_)
    , color_ (copy.color_)
  {
  }

  Vector2 BaseSprite::HandleGetSize () const
  {
    return spatialInfo_.GetSize ();
  }
} // namespace yap
