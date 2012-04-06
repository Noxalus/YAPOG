#include "YAPOG/Graphics/Game/Sprite/SpriteBase.hpp"

namespace yap
{
  const bool SpriteBase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color SpriteBase::DEFAULT_COLOR = sf::Color ();

  SpriteBase::SpriteBase ()
    : spatialInfo_ ()
    , isVisible_ (DEFAULT_VISIBLE_STATE)
    , color_ (DEFAULT_COLOR)
  {
  }

  SpriteBase::~SpriteBase ()
  {
  }

  const Vector2& SpriteBase::GetPosition () const
  {
    return spatialInfo_.GetPosition ();
  }

  const Vector2& SpriteBase::GetSize () const
  {
    return spatialInfo_.GetSize ();
  }

  const Vector2& SpriteBase::GetTopLeft () const
  {
    return spatialInfo_.GetTopLeft ();
  }

  const Vector2& SpriteBase::GetBottomRight () const
  {
    return spatialInfo_.GetBottomRight ();
  }

  const Vector2& SpriteBase::GetCenter () const
  {
    return spatialInfo_.GetCenter ();
  }

  const sf::FloatRect& SpriteBase::GetRectangle () const
  {
    return spatialInfo_.GetRectangle ();
  }

  void SpriteBase::Move (const Vector2& offset)
  {
    spatialInfo_.SetPosition (GetPosition () + offset);

    HandleMove (offset);
  }

  void SpriteBase::Scale (const Vector2& factor)
  {
    spatialInfo_.SetSize (
      Vector2 (
        GetSize ().x * factor.x,
        GetSize ().y * factor.y));

    HandleScale (factor);
  }

  void SpriteBase::SetPosition (const Vector2& position)
  {
    Move (position - GetPosition ());
  }

  void SpriteBase::SetSize (const Vector2& size)
  {
    Scale (
      Vector2 (
        size.x / GetSize ().x,
        size.y / GetSize ().y));
  }

  void SpriteBase::Draw (IDrawingContext& context)
  {
    if (!isVisible_)
      return;

    HandleDraw (context);
  }

  bool SpriteBase::IsVisible () const
  {
    return isVisible_;
  }

  void SpriteBase::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void SpriteBase::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  void SpriteBase::Update (const Time& dt)
  {
    HandleUpdate (dt);
  }
} // namespace yap
