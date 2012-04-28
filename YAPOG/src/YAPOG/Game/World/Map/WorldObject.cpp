#include "YAPOG/Game/World/Map/WorldObject.hpp"

namespace yap
{
  WorldObject::WorldObject ()
    : spatial3Info_ ()
  {
  }

  WorldObject::~WorldObject ()
  {
  }

  WorldObject::WorldObject (const WorldObject& copy)
    : spatial3Info_ (copy.spatial3Info_)
  {
  }

  const Vector2& WorldObject::GetPosition () const
  {
    return spatial3Info_.GetPosition ();
  }

  const Vector2& WorldObject::GetSize () const
  {
    return spatial3Info_.GetSize ();
  }

  const Vector2& WorldObject::GetTopLeft () const
  {
    return spatial3Info_.GetTopLeft ();
  }

  const Vector2& WorldObject::GetBottomRight () const
  {
    return spatial3Info_.GetBottomRight ();
  }

  const Vector2& WorldObject::GetCenter () const
  {
    return spatial3Info_.GetCenter ();
  }

  const sf::FloatRect& WorldObject::GetRectangle () const
  {
    return spatial3Info_.GetRectangle ();
  }

  void WorldObject::Move (const Vector2& offset)
  {
    spatial3Info_.SetPosition (GetPosition () + offset);

    HandleMove (offset);
  }

  void WorldObject::Scale (const Vector2& factor)
  {
    spatial3Info_.SetSize (
      Vector2 (
        GetSize ().x * factor.x,
        GetSize ().y * factor.y));

    HandleScale (factor);
  }

  void WorldObject::SetPosition (const Vector2& position)
  {
    Move (position - GetPosition ());
  }

  void WorldObject::SetSize (const Vector2& size)
  {
    Scale (
      Vector2 (
        size.x / GetSize ().x,
        size.y / GetSize ().y));
  }

  const int& WorldObject::GetZ () const
  {
    return spatial3Info_.GetZ ();
  }

  void WorldObject::SetZ (int z)
  {
    spatial3Info_.SetZ (z);
  }

  const int& WorldObject::GetH () const
  {
    return spatial3Info_.GetH ();
  }

  void WorldObject::SetH (int h)
  {
    spatial3Info_.SetH (h);
  }

  void WorldObject::HandleMove (const Vector2& offset)
  {
  }

  void WorldObject::HandleScale (const Vector2& factor)
  {
  }

  void WorldObject::HandleSetZ (int z)
  {
  }

  void WorldObject::HandleSetH (int h)
  {
  }
} // namespace yap
