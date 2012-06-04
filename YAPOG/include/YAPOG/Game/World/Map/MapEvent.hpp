#ifndef YAPOG_MAPEVENT_HPP
# define YAPOG_MAPEVENT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Factory/ICloneable.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Collection/List.hpp"

namespace yap
{
  struct IMapEventCondition;
  struct IMapEventAction;

  class BoundingBox;
  class MapEventArgs;
  class EventBoundingBoxCollection;

  class MapEvent : ICloneable
  {
      DISALLOW_ASSIGN(MapEvent);

    public:

      enum class Type : UInt8
      {
        In,
        Normal,
        Out
      };

      MapEvent ();
      explicit MapEvent (Type type);
      virtual ~MapEvent ();

      bool Call (MapEventArgs& args);

      void AddBoundingBox (BoundingBox* boundingBox);
      void RemoveBoundingBox (BoundingBox* boundingBox);

      void AddCondition (IMapEventCondition* condition);
      void RemoveCondition (IMapEventCondition* condition);
      void AddAction (IMapEventAction* action);
      void RemoveAction (IMapEventAction* action);

      void AddToEventBoundingBoxCollection (
        EventBoundingBoxCollection& eventBoundingBoxCollection);
      void RemoveFromEventBoundingBoxCollection (
        EventBoundingBoxCollection& eventBoundingBoxCollection);

      /// @name ICloneable members.
      /// @{
      virtual MapEvent* Clone () const;
      /// @}

    protected:

      MapEvent (const MapEvent& copy);

      virtual bool HandleCall (MapEventArgs& args);

    private:

      static const Type DEFAULT_TYPE;

      Type type_;

      collection::List<BoundingBox*> boundingBoxes_;

      collection::List<IMapEventCondition*> conditions_;
      collection::List<IMapEventAction*> actions_;
  };
} // namespace yap

#endif // YAPOG_MAPEVENT_HPP
