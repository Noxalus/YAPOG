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

namespace yap
{
  class WorldObject;
  class DynamicWorldObject;

  /// @brief Base Map class for both client and server.
  class YAPOG_LIB Map : public IUpdateable
                      , public IIDLoadable
  {
      DISALLOW_ASSIGN(Map);

    public:

      virtual ~Map ();

      const ID& GetID () const;
      void SetID (const ID& id);

      const String& GetName () const;
      void SetName (const String& name);

      const uint& GetWidth () const;
      const uint& GetHeight () const;
      void SetSize (uint width, uint height);

      /// @name IUpdateable members.
      /// @{
      virtual void Update (const Time& dt);
      /// @}

    protected:

      Map (const ID& id);
      Map (const Map& copy);

      virtual void AddObject (WorldObject* object);
      virtual void AddDynamicObject (DynamicWorldObject* object);
      virtual void AddUpdateable (IUpdateable* updateable);

    private:

      virtual void HandleSetSize (uint width, uint height);
      virtual void HandleUpdate (const Time& dt) = 0;

      static const String DEFAULT_NAME;
      static const uint DEFAULT_WIDTH;
      static const uint DEFAULT_HEIGHT;

      ID id_;
      String name_;

      uint width_;
      uint height_;

      collection::List<WorldObject*> objects_;
      DynamicWorldObjectCollection dynamicObjects_;

      collection::List<IUpdateable*> updateables_;
  };
} // namespace yap

#endif // YAPOG_MAP_HPP
