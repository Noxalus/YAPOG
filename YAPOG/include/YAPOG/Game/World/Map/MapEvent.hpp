#ifndef YAPOG_MAPEVENT_HPP
# define YAPOG_MAPEVENT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Factory/ICloneable.hpp"
# include "YAPOG/Collection/List.hpp"
# include "YAPOG/Game/World/Map/MapEventActionType.hpp"

namespace yap
{
  struct IMapEventCondition;
  struct IMapEventAction;
  struct ICollidable;

  class BoundingBox;
  class MapEventArgs;
  class EventBoundingBoxCollection;
  class DynamicWorldObject;

  class YAPOG_LIB MapEvent : ICloneable
  {
      DISALLOW_ASSIGN(MapEvent);

    public:

      MapEvent ();
      virtual ~MapEvent ();

      bool Call (MapEventActionType actionType, MapEventArgs& args);

      void AddBoundingBox (BoundingBox* boundingBox);
      void RemoveBoundingBox (BoundingBox* boundingBox);

      void AddCondition (IMapEventCondition* condition);
      void RemoveCondition (IMapEventCondition* condition);
      void AddAction (IMapEventAction* action);
      void RemoveAction (IMapEventAction* action);

      void AddToEventBoundingBoxCollection (
        EventBoundingBoxCollection& eventBoundingBoxCollection,
        const DynamicWorldObject& parent);
      void RemoveFromEventBoundingBoxCollection (
        EventBoundingBoxCollection& eventBoundingBoxCollection);

      bool CollidesWith (const ICollidable& collidable) const;

      /// @name ICloneable members.
      /// @{
      virtual MapEvent* Clone () const;
      /// @}

    protected:

      MapEvent (const MapEvent& copy);

      virtual bool HandleCall (
        MapEventActionType actionType,
        MapEventArgs& args);

    private:

      collection::List<BoundingBox*> boundingBoxes_;

      collection::List<IMapEventCondition*> conditions_;
      collection::List<IMapEventAction*> actions_;
  };
} // namespace yap

#endif // YAPOG_MAPEVENT_HPP
