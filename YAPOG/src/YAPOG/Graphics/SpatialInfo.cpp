#include "YAPOG/Graphics/SpatialInfo.hpp"

namespace yap
{
  SpatialInfo::SpatialInfo ()
  {
    Init (DEFAULT_POSITION, DEFAULT_SIZE);
  }

  SpatialInfo::SpatialInfo (const Vector2& position, const Vector2& size)
  {
    Init (position, size);
  }

  SpatialInfo::SpatialInfo (const SpatialInfo& copy)
  {
    Init (copy.position_, copy.size_);
  }

  SpatialInfo& SpatialInfo::operator= (const SpatialInfo& copy)
  {
    if (this == &copy)
      return *this;

    Init (copy.position_, copy.size_);

    return *this;
  }

  const Vector2& SpatialInfo::GetPosition () const
  {
    return position_;
  }

  const Vector2& SpatialInfo::GetSize () const
  {
    return size_;
  }

  const Vector2& SpatialInfo::GetTopLeft () const
  {
    return topLeft_;
  }

  const Vector2& SpatialInfo::GetBottomRight () const
  {
    return bottomRight_;
  }

  const Vector2& SpatialInfo::GetCenter () const
  {
    return center_;
  }

  const sf::FloatRect& SpatialInfo::GetRectangle () const
  {
    return rectangle_;
  }

  void SpatialInfo::SetPosition (const Vector2& position)
  {
    position_ = position;

    Update ();
  }

  void SpatialInfo::SetSize (const Vector2& size)
  {
    size_ = size;

    Update ();
  }

  void SpatialInfo::Init (const Vector2& position, const Vector2& size)
  {
    position_ = position;
    size_ = size;

    Update ();
  }

  void SpatialInfo::Update ()
  {
    center_ = position_ + size_ / 2.0f;
    topLeft_ = position_;
    bottomRight_ = position_ + size_;

    rectangle_ = sf::FloatRect (position_, size_);
  }
} // namespace yap