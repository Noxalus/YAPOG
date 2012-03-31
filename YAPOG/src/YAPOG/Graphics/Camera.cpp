#include "YAPOG/Graphics/Camera.hpp"

namespace yap
{
  Camera::Camera (const Vector2& position, const Vector2& size)
    : spatialInfo_ (position, size)
    , view_ (spatialInfo_.GetRectangle ())
  {
  }

  Camera::~Camera ()
  {
  }

  const Vector2& Camera::GetPosition () const
  {
    return spatialInfo_.GetPosition ();
  }

  const Vector2& Camera::GetSize () const
  {
    return spatialInfo_.GetSize ();
  }

  const Vector2& Camera::GetTopLeft () const
  {
    return spatialInfo_.GetTopLeft ();
  }

  const Vector2& Camera::GetBottomRight () const
  {
    return spatialInfo_.GetBottomRight ();
  }

  const Vector2& Camera::GetCenter () const
  {
    return spatialInfo_.GetCenter ();
  }

  const sf::FloatRect& Camera::GetRectangle () const
  {
    return spatialInfo_.GetRectangle ();
  }

  void Camera::Move (const Vector2& offset)
  {
    spatialInfo_.SetPosition (GetPosition () + offset);

    view_.Move (offset);
  }

  void Camera::Scale (const Vector2& factor)
  {
    spatialInfo_.SetSize (
      Vector2 (
        GetSize ().x * factor.x,
        GetSize ().y * factor.y));

    view_.SetSize (spatialInfo_.GetSize ());
  }

  bool Camera::IsInView (const Vector2& point) const
  {
    return IsInView (point, DEFAULT_SIZE);
  }

  bool Camera::IsInView (const Vector2& point, const Vector2& size) const
  {
    return GetRectangle ().Intersects (sf::FloatRect (point, size));
  }

  Vector2 Camera::ToLocal (const Vector2& globalPoint) const
  {
    return globalPoint - GetPosition ();
  }

  Vector2 Camera::ToGlobal (const Vector2& localPoint) const
  {
    return localPoint + GetPosition ();
  }

  const sf::View& Camera::GetInnerView () const
  {
    return view_;
  }
} // namespace yap
