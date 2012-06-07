#ifndef YAPOG_MAP_HPP
# define YAPOG_MAP_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/Game/Factory/IIDLoadable.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Collection/List.hpp"
# include "YAPOG/Game/World/Map/DynamicWorldObjectCollection.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/Game/World/Map/MapEventManager.hpp"

namespace yap
{
  class WorldObject;
  class StaticWorldObject;
  class DynamicWorldObject;
  class CollidableArea;

  /// @brief Base Map class for both client and server.
  class YAPOG_LIB Map : public IUpdateable
                      , public IIDLoadable
  {
      DISALLOW_COPY(Map);

    public:

      virtual ~Map ();

      const ID& GetID () const;
      void SetID (const ID& id);

      const String& GetName () const;
      void SetName (const String& name);

      const ID& GetWorldID () const;
      void SetWorldID (const ID& worldID);

      const uint& GetWidth () const;
      const uint& GetHeight () const;
      void SetSize (uint width, uint height);

      const Vector2& GetSize () const;

      void SetCollidableArea (CollidableArea* collidableArea);

      void AddStaticObject (StaticWorldObject* object);
      void AddDynamicObject (DynamicWorldObject* object);
      void RemoveStaticObject (StaticWorldObject* object);
      void RemoveDynamicObject (DynamicWorldObject* object);

      /// @name IUpdateable members.
      /// @{
      virtual void Update (const Time& dt);
      /// @}

      /// @name ICloneable members.
      /// @{
      virtual Map* Clone () const;
      /// @}

    protected:

      Map (const ID& id);

      DynamicWorldObject& GetObject (const ID& worldID);
      const DynamicWorldObjectCollection& GetDynamicObjects () const;

      void AddObject (WorldObject* object);
      void AddUpdateable (IUpdateable* updateable);

      void RemoveObject (WorldObject* object);
      void RemoveUpdateable (IUpdateable* updateable);

      virtual void HandleSetSize (uint width, uint height);
      virtual void HandleUpdate (const Time& dt);

      virtual void HandleAddObject (WorldObject* object);
      virtual void HandleAddStaticObject (StaticWorldObject* object);
      virtual void HandleAddDynamicObject (DynamicWorldObject* object);
      virtual void HandleAddUpdateable (IUpdateable* updateable);

      virtual void HandleRemoveObject (WorldObject* object);
      virtual void HandleRemoveStaticObject (StaticWorldObject* object);
      virtual void HandleRemoveDynamicObject (DynamicWorldObject* object);
      virtual void HandleRemoveUpdateable (IUpdateable* updateable);

    private:

      virtual bool SupportsEvents () const;

      void UpdateEvents (const Time& dt);
      void UpdateObjectEvents (DynamicWorldObject& object);
      void RemoveObjectEvents (DynamicWorldObject& object);

      void UpdateSize ();

      static const String DEFAULT_NAME;
      static const uint DEFAULT_WIDTH;
      static const uint DEFAULT_HEIGHT;
      static const float DEFAULT_CELL_SIZE;

      static const String MOVED_UPDATE_EVENT_HANDLER_NAME;

      ID id_;
      String name_;

      ID worldID_;

      uint width_;
      uint height_;
      Vector2 size_;

      collection::List<WorldObject*> objects_;
      DynamicWorldObjectCollection dynamicObjects_;

      collection::List<IUpdateable*> updateables_;

      CollidableArea* collidableArea_;

      MapEventManager eventManager_;
  };
} // namespace yap

#endif // YAPOG_MAP_HPP
