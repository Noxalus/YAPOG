#include "YAPOG/Game/World/Map/WorldObject.hpp"
#include "YAPOG/Game/World/Map/Physics/CollidableArea.hpp"
#include "YAPOG/Game/World/Map/Physics/BoundingBox.hpp"

namespace yap
{
  WorldObject::WorldObject (const ID& id)
    : id_ (id)
    , spatial3Info_ ()
    , physicsBoundingBoxes_ ()
  {
  }

  WorldObject::~WorldObject ()
  {
  }

  WorldObject::WorldObject (const WorldObject& copy)
    : id_ (copy.id_)
    , spatial3Info_ (copy.spatial3Info_)
    , physicsBoundingBoxes_ (copy.physicsBoundingBoxes_)
  {
  }

  const ID& WorldObject::GetID () const
  {
    return id_;
  }

  void WorldObject::SetID (const ID& id)
  {
    id_ = id;
  }

  void WorldObject::SetCollidableArea (CollidableArea* collidableArea)
  {
    physicsBoundingBoxes_.SetCollidableArea (*this, collidableArea);

    HandleSetCollidableArea (collidableArea);
  }

  void WorldObject::AddPhysicsBoundingBox (BoundingBox* boundingBox)
  {
    AdjustCollidablePosition (*boundingBox);

    physicsBoundingBoxes_.AddPhysicsBoundingBox (boundingBox);
  }

  void WorldObject::RemovePhysicsBoundingBox (BoundingBox* boundingBox)
  {
    physicsBoundingBoxes_.RemovePhysicsBoundingBox (boundingBox);
  }

  bool WorldObject::CollidesWith (
    const CollidableArea& collidableArea,
    const Vector2& offset) const
  {
    return physicsBoundingBoxes_.CollidesWithArea (collidableArea, offset);
  }

  const Vector2& WorldObject::GetPosition () const
  {
    return spatial3Info_.GetPosition ();
  }

  const Vector2& WorldObject::GetSize () const
  {
    spatial3Info_.SetSize (HandleGetSize ());

    return spatial3Info_.GetSize ();
  }

  const Vector2& WorldObject::GetTopLeft () const
  {
    return spatial3Info_.GetTopLeft ();
  }

  const Vector2& WorldObject::GetBottomRight () const
  {
    /// @warning Temporary.
    GetSize ();

    return spatial3Info_.GetBottomRight ();
  }

  const Vector2& WorldObject::GetCenter () const
  {
    /// @warning Temporary.
    GetSize ();

    return spatial3Info_.GetCenter ();
  }

  const sf::FloatRect& WorldObject::GetRectangle () const
  {
    /// @warning Temporary.
    GetSize ();

    return spatial3Info_.GetRectangle ();
  }

  void WorldObject::Move (const Vector2& offset)
  {
    if (offset == Vector2 ())
      return;

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

    HandleSetZ (z);
  }

  const int& WorldObject::GetH () const
  {
    return spatial3Info_.GetH ();
  }

  void WorldObject::SetH (int h)
  {
    spatial3Info_.SetH (h);

    HandleSetH (h);
  }

  bool WorldObject::CollidesWith (const ICollidable& other) const
  {
    return CollidesWith (other, VECTOR2_ZERO);
  }

  bool WorldObject::CollidesWith (
    const ICollidable& other,
    const Vector2& offset) const
  {
    return physicsBoundingBoxes_.CollidesWith (other, offset);
  }

  const PhysicsBoundingBoxCollection&
  WorldObject::GetPhysicsBoundingBoxes () const
  {
    return physicsBoundingBoxes_;
  }

  void WorldObject::AdjustCollidablePosition (ICollidable& collidable) const
  {
    collidable.Move (GetPosition ());
  }

  void WorldObject::HandleSetCollidableArea (CollidableArea* collidableArea)
  {
  }

  Vector2 WorldObject::HandleGetSize () const
  {
    return spatial3Info_.GetSize ();
  }

  void WorldObject::HandleMove (const Vector2& offset)
  {
    physicsBoundingBoxes_.Move (offset);
  }

  void WorldObject::HandleScale (const Vector2& factor)
  {
    physicsBoundingBoxes_.Scale (factor);
  }

  void WorldObject::HandleSetZ (int z)
  {
    physicsBoundingBoxes_.SetZ (z);
  }

  void WorldObject::HandleSetH (int h)
  {
    physicsBoundingBoxes_.SetH (h);
  }
} // namespace yap
