#include "YAPOG/Game/World/Map/Physics/BoundingBox.hpp"

namespace yap
{
  BoundingBox::BoundingBox ()
    : spatial3Info_ ()
  {
  }

  BoundingBox::BoundingBox (
    const Vector2& position,
    const Vector2& size,
    int z,
    int h)
    : spatial3Info_ (position, size, z, h)
  {
  }

  BoundingBox::~BoundingBox ()
  {
  }

  BoundingBox::BoundingBox (const BoundingBox& copy)
    : spatial3Info_ (copy.spatial3Info_)
  {
  }

  const Vector2& BoundingBox::GetPosition () const
  {
    return spatial3Info_.GetPosition ();
  }

  const Vector2& BoundingBox::GetSize () const
  {
    return spatial3Info_.GetSize ();
  }

  const Vector2& BoundingBox::GetTopLeft () const
  {
    return spatial3Info_.GetTopLeft ();
  }

  const Vector2& BoundingBox::GetBottomRight () const
  {
    return spatial3Info_.GetBottomRight ();
  }

  const Vector2& BoundingBox::GetCenter () const
  {
    return spatial3Info_.GetCenter ();
  }

  const FloatRect& BoundingBox::GetRectangle () const
  {
    return spatial3Info_.GetRectangle ();
  }

  void BoundingBox::Move (const Vector2& offset)
  {
    spatial3Info_.SetPosition (GetPosition () + offset);
  }

  void BoundingBox::Scale (const Vector2& factor)
  {
    spatial3Info_.SetSize (
      Vector2 (
        GetSize ().x * factor.x,
        GetSize ().y * factor.y));
  }

  void BoundingBox::SetPosition (const Vector2& position)
  {
    Move (position - GetPosition ());
  }

  void BoundingBox::SetSize (const Vector2& size)
  {
    Scale (
      Vector2 (
        size.x / GetSize ().x,
        size.y / GetSize ().y));
  }

  const int& BoundingBox::GetZ () const
  {
    return spatial3Info_.GetZ ();
  }

  void BoundingBox::SetZ (int z)
  {
    spatial3Info_.SetZ (z);
  }

  const int& BoundingBox::GetH () const
  {
    return spatial3Info_.GetH ();
  }

  void BoundingBox::SetH (int h)
  {
    spatial3Info_.SetH (h);
  }
} // namespace yap
