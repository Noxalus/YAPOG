#include "YAPOG/Game/World/Map/MapEvent.hpp"
#include "YAPOG/Game/World/Map/Physics/BoundingBox.hpp"
#include "YAPOG/Game/World/Map/IMapEventCondition.hpp"
#include "YAPOG/Game/World/Map/IMapEventAction.hpp"
#include "YAPOG/Game/World/Map/Physics/EventBoundingBoxCollection.hpp"

namespace yap
{
  const MapEvent::Type MapEvent::DEFAULT_TYPE = Type::Normal;

  MapEvent::MapEvent ()
    : type_ (DEFAULT_TYPE)
    , boundingBoxes_ ()
    , conditions_ ()
    , actions_ ()
  {
  }

  MapEvent::MapEvent (Type type)
    : type_ (type)
    , boundingBoxes_ ()
    , conditions_ ()
    , actions_ ()
  {
  }

  MapEvent::~MapEvent ()
  {
    for (BoundingBox* boundingBox : boundingBoxes_)
      delete boundingBox;

    for (IMapEventCondition* condition : conditions_)
      delete condition;

    for (IMapEventAction* action : actions_)
      delete action;
  }

  MapEvent::MapEvent (const MapEvent& copy)
    : type_ (copy.type_)
    , boundingBoxes_ ()
    , conditions_ ()
    , actions_ ()
  {
    for (BoundingBox* boundingBox : boundingBoxes_)
      AddBoundingBox (new BoundingBox (*boundingBox));

    for (IMapEventCondition* condition : conditions_)
      AddCondition (condition->Clone ());

    for (IMapEventAction* action : actions_)
      AddAction (action->Clone ());
  }

  MapEvent* MapEvent::Clone () const
  {
    return new MapEvent (*this);
  }

  bool MapEvent::Call (MapEventArgs& args)
  {
    for (IMapEventCondition* condition : conditions_)
      if (!condition->IsValid (args))
        return false;

    return HandleCall (args);
  }

  void MapEvent::AddBoundingBox (BoundingBox* boundingBox)
  {
    boundingBoxes_.Add (boundingBox);
  }

  void MapEvent::RemoveBoundingBox (BoundingBox* boundingBox)
  {
    boundingBoxes_.Remove (boundingBox);
  }

  void MapEvent::AddCondition (IMapEventCondition* condition)
  {
    conditions_.Add (condition);
  }

  void MapEvent::RemoveCondition (IMapEventCondition* condition)
  {
    conditions_.Remove (condition);
  }

  void MapEvent::AddAction (IMapEventAction* action)
  {
    actions_.Add (action);
  }

  void MapEvent::RemoveAction (IMapEventAction* action)
  {
    actions_.Remove (action);
  }

  void MapEvent::AddToEventBoundingBoxCollection (
    EventBoundingBoxCollection& eventBoundingBoxCollection)
  {
    for (BoundingBox* boundingBox : boundingBoxes_)
      eventBoundingBoxCollection.AddEventBoundingBox (boundingBox, this);
  }

  void MapEvent::RemoveFromEventBoundingBoxCollection (
    EventBoundingBoxCollection& eventBoundingBoxCollection)
  {
    for (BoundingBox* boundingBox : boundingBoxes_)
      eventBoundingBoxCollection.RemoveEventBoundingBox (boundingBox);
  }

  bool MapEvent::HandleCall (MapEventArgs& args)
  {
    bool successful = true;

    for (IMapEventAction* action : actions_)
      if (!action->Execute (args))
        successful = false;

    return successful;
  }
} // namespace yap
