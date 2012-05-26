#include "YAPOG/Game/World/Map/Map.hpp"
#include "YAPOG/Game/World/Map/WorldObject.hpp"
#include "YAPOG/Game/World/Map/StaticWorldObject.hpp"
#include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Game/World/Map/Physics/CollidableArea.hpp"

namespace yap
{
  const String Map::DEFAULT_NAME = "<ANONYMOUS_MAP>";
  const uint Map::DEFAULT_WIDTH = 0;
  const uint Map::DEFAULT_HEIGHT = 0;
  const float Map::DEFAULT_CELL_SIZE = 32.0f;

  Map::Map (const ID& id)
    : id_ (id)
    , name_ (DEFAULT_NAME)
    , worldID_ ()
    , width_ (DEFAULT_WIDTH)
    , height_ (DEFAULT_HEIGHT)
    , size_ ()
    , objects_ ()
    , dynamicObjects_ ()
    , updateables_ ()
    , collidableArea_ (nullptr)
  {
  }

  Map::~Map ()
  {
    delete collidableArea_;
    collidableArea_ = nullptr;
  }

  Map* Map::Clone () const
  {
    YAPOG_THROW("Invalid method call: `Map::Clone () const'.");
  }

  const ID& Map::GetID () const
  {
    return id_;
  }

  void Map::SetID (const ID& id)
  {
    id_ = id;
  }

  const String& Map::GetName () const
  {
    return name_;
  }

  void Map::SetName (const String& name)
  {
    name_ = name;
  }

  const ID& Map::GetWorldID () const
  {
    return worldID_;
  }

  void Map::SetWorldID (const ID& worldID)
  {
    worldID_ = worldID;
  }

  const uint& Map::GetWidth () const
  {
    return width_;
  }

  const uint& Map::GetHeight () const
  {
    return height_;
  }

  void Map::SetSize (uint width, uint height)
  {
    width_ = width;
    height_ = height;

    HandleSetSize (width, height);
  }

  const Vector2& Map::GetSize () const
  {
    return size_;
  }

  void Map::SetCollidableArea (CollidableArea* collidableArea)
  {
    collidableArea_ = collidableArea;
  }

  void Map::HandleSetSize (uint width, uint height)
  {
    UpdateSize ();

    collidableArea_->SetSize (GetSize ());
  }

  void Map::Update (const Time& dt)
  {
    for (IUpdateable* updateable : updateables_)
      updateable->Update (dt);

    for (auto& it : dynamicObjects_)
      if (it.second->IsMoving ())
      {
        /// @todo Move decomposition: dedicated classes.

        /// @todo Replace CollidesWith by GetDistance (implement it).
        /// + debug

        /// @todo Travers bounding boxes, else CollidesWith is performed
        /// directly on the world object (does not work).

        /// @todo Erase.
//        if (it.second->CanMove (it.second->GetMove ()))
        if (!collidableArea_->CollidesWithObject (
              *it.second,
              it.second->GetMove ()))
          it.second->Move (it.second->GetMove ());
      }

    HandleUpdate (dt);
  }

  void Map::HandleUpdate (const Time& dt)
  {
  }

  void Map::AddObject (WorldObject* object)
  {
    objects_.Add (object);

    HandleAddObject (object);
  }

  void Map::AddStaticObject (StaticWorldObject* object)
  {
    AddObject (object);
    AddUpdateable (object);

    HandleAddStaticObject (object);
  }

  void Map::AddDynamicObject (DynamicWorldObject* object)
  {
    AddObject (object);
    dynamicObjects_.AddObject (object);
    AddUpdateable (object);

    HandleAddDynamicObject (object);
  }

  void Map::AddUpdateable (IUpdateable* updateable)
  {
    updateables_.Add (updateable);

    HandleAddUpdateable (updateable);
  }

  void Map::RemoveObject (WorldObject* object)
  {
    objects_.Remove (object);

    HandleRemoveObject (object);
  }

  void Map::RemoveStaticObject (StaticWorldObject* object)
  {
    RemoveObject (object);
    RemoveUpdateable (object);

    HandleRemoveStaticObject (object);
  }

  void Map::RemoveDynamicObject (DynamicWorldObject* object)
  {
    RemoveObject (object);
    dynamicObjects_.RemoveObject (object->GetWorldID ());
    RemoveUpdateable (object);

    HandleRemoveDynamicObject (object);
  }

  void Map::RemoveUpdateable (IUpdateable* updateable)
  {
    updateables_.Remove (updateable);

    HandleRemoveUpdateable (updateable);
  }

  void Map::HandleAddObject (WorldObject* object)
  {
    object->SetCollidableArea (collidableArea_);
  }

  void Map::HandleAddStaticObject (StaticWorldObject* object)
  {
  }

  void Map::HandleAddDynamicObject (DynamicWorldObject* object)
  {
  }

  void Map::HandleAddUpdateable (IUpdateable* updateable)
  {
  }

  void Map::HandleRemoveObject (WorldObject* object)
  {
    object->SetCollidableArea (nullptr);
  }

  void Map::HandleRemoveStaticObject (StaticWorldObject* object)
  {
  }

  void Map::HandleRemoveDynamicObject (DynamicWorldObject* object)
  {
  }

  void Map::HandleRemoveUpdateable (IUpdateable* updateable)
  {
  }

  void Map::UpdateSize ()
  {
    size_ = Vector2 (width_, height_) * DEFAULT_CELL_SIZE;
  }
} // namespace yap
