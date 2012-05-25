#include "YAPOG/Game/World/Map/Physics/BoundingBoxCollection.hpp"
#include "YAPOG/Game/World/Map/Physics/BoundingBox.hpp"
#include "YAPOG/Game/World/Map/Physics/CollidableArea.hpp"

namespace yap
{
  BoundingBoxCollection::BoundingBoxCollection ()
    : spatial3Info_ ()
    , boundingBoxes_ ()
    , collidableArea_ (nullptr)
  {
  }

  BoundingBoxCollection::~BoundingBoxCollection ()
  {
    for (const BoundingBox* boundingBox : boundingBoxes_)
      delete boundingBox;
  }

  BoundingBoxCollection::BoundingBoxCollection (
    const BoundingBoxCollection& copy)
    : spatial3Info_ (copy.spatial3Info_)
    , boundingBoxes_ ()
    , collidableArea_ (nullptr)
  {
    for (BoundingBox* boundingBox : copy.boundingBoxes_)
      AddBoundingBox (new BoundingBox (*boundingBox));
  }

  void BoundingBoxCollection::AddBoundingBox (BoundingBox* boundingBox)
  {
    boundingBoxes_.Add (boundingBox);

    if (collidableArea_ != nullptr)
      collidableArea_->AddCollidable (boundingBox);
  }

  void BoundingBoxCollection::RemoveBoundingBox (BoundingBox* boundingBox)
  {
    boundingBoxes_.Remove (boundingBox);

    if (collidableArea_ != nullptr)
      collidableArea_->RemoveCollidable (boundingBox);
  }

  void BoundingBoxCollection::SetCollidableArea (
    CollidableArea* collidableArea)
  {
    if (collidableArea_ == collidableArea)
      return;

    if (collidableArea_ != nullptr)
      RemoveBoundingBoxesFromCollidableArea ();

    collidableArea_ = collidableArea;

    if (collidableArea_ != nullptr)
      AddBoundingBoxesToCollidableArea ();
  }

  BoundingBoxCollection::ItType BoundingBoxCollection::begin ()
  {
    return boundingBoxes_.begin ();
  }

  BoundingBoxCollection::ConstItType BoundingBoxCollection::begin () const
  {
    return boundingBoxes_.begin ();
  }

  BoundingBoxCollection::ItType BoundingBoxCollection::end ()
  {
    return boundingBoxes_.end ();
  }

  BoundingBoxCollection::ConstItType BoundingBoxCollection::end () const
  {
    return boundingBoxes_.end ();
  }

  const Vector2& BoundingBoxCollection::GetPosition () const
  {
    return spatial3Info_.GetPosition ();
  }

  const Vector2& BoundingBoxCollection::GetSize () const
  {
    return spatial3Info_.GetSize ();
  }

  const Vector2& BoundingBoxCollection::GetTopLeft () const
  {
    return spatial3Info_.GetTopLeft ();
  }

  const Vector2& BoundingBoxCollection::GetBottomRight () const
  {
    return spatial3Info_.GetBottomRight ();
  }

  const Vector2& BoundingBoxCollection::GetCenter () const
  {
    return spatial3Info_.GetCenter ();
  }

  const sf::FloatRect& BoundingBoxCollection::GetRectangle () const
  {
    return spatial3Info_.GetRectangle ();
  }

  void BoundingBoxCollection::Move (const Vector2& offset)
  {
    spatial3Info_.SetPosition (GetPosition () + offset);

    RemoveBoundingBoxesFromCollidableArea ();

    for (BoundingBox* boundingBox : boundingBoxes_)
      boundingBox->Move (offset);

    AddBoundingBoxesToCollidableArea ();
  }

  void BoundingBoxCollection::Scale (const Vector2& factor)
  {
    spatial3Info_.SetSize (
      Vector2 (
        GetSize ().x * factor.x,
        GetSize ().y * factor.y));

    RemoveBoundingBoxesFromCollidableArea ();

    for (BoundingBox* boundingBox : boundingBoxes_)
      boundingBox->Scale (factor);

    AddBoundingBoxesToCollidableArea ();
  }

  void BoundingBoxCollection::SetPosition (const Vector2& position)
  {
    Move (position - GetPosition ());
  }

  void BoundingBoxCollection::SetSize (const Vector2& size)
  {
    Scale (
      Vector2 (
        size.x / GetSize ().x,
        size.y / GetSize ().y));
  }

  const int& BoundingBoxCollection::GetZ () const
  {
    return spatial3Info_.GetZ ();
  }

  void BoundingBoxCollection::SetZ (int z)
  {
    int offset = z - GetZ ();

    spatial3Info_.SetZ (z);

    RemoveBoundingBoxesFromCollidableArea ();

    for (BoundingBox* boundingBox : boundingBoxes_)
      boundingBox->SetZ (boundingBox->GetZ () + offset);

    AddBoundingBoxesToCollidableArea ();
  }

  const int& BoundingBoxCollection::GetH () const
  {
    return spatial3Info_.GetH ();
  }

  void BoundingBoxCollection::SetH (int h)
  {
    int factor = h / GetH ();

    spatial3Info_.SetH (h);

    RemoveBoundingBoxesFromCollidableArea ();

    for (BoundingBox* boundingBox : boundingBoxes_)
      boundingBox->SetH (boundingBox->GetH () * factor);

    AddBoundingBoxesToCollidableArea ();
  }

  bool BoundingBoxCollection::CollidesWith (const ICollidable& other) const
  {
    for (BoundingBox* boundingBox : boundingBoxes_)
      if (boundingBox->CollidesWith (other))
        return true;

    return false;
  }

  void BoundingBoxCollection::AddBoundingBoxesToCollidableArea ()
  {
    if (collidableArea_ == nullptr)
      return;

    for (BoundingBox* boundingBox : boundingBoxes_)
      collidableArea_->AddCollidable (boundingBox);
  }

  void BoundingBoxCollection::RemoveBoundingBoxesFromCollidableArea ()
  {
    if (collidableArea_ == nullptr)
      return;

    for (BoundingBox* boundingBox : boundingBoxes_)
      collidableArea_->RemoveCollidable (boundingBox);
  }
} // namespace yap
