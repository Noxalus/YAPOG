#ifndef YAPOG_MAPEVENTMANAGER_HPP
# define YAPOG_MAPEVENTMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/Collection/Set.hpp"

namespace yap
{
  class DynamicWorldObject;
  class MapEventContext;
  class BoundingBox;
  class CollidableArea;

  class MapEventManager : public IUpdateable
  {
      DISALLOW_COPY(MapEventManager);

    public:

      MapEventManager ();
      ~MapEventManager ();

      void SetCollidableArea (CollidableArea* collidableArea);

      /// @name IUpdateable members.
      /// @{
      virtual void Update (const Time& dt);
      /// @}

    private:

      void AddEvent (const DynamicWorldObject* object, MapEventContext* args);

      void UpdateObject (const Time& dt, const DynamicWorldObject& object);

      void UpdateObjectOut (const Time& dt, const DynamicWorldObject& object);
      void UpdateObjectIn (const Time& dt, const DynamicWorldObject& object);

      /// Map<Object, Map<Source bounding box, Set<Event context>>>
      collection::Map<
        const DynamicWorldObject*,
        collection::Map<
          BoundingBox*,
          collection::Set<MapEventContext*>>> events_;

      CollidableArea* collidableArea_;
  };
} // namespace yap

#endif // YAPOG_MAPEVENTMANAGER_HPP
