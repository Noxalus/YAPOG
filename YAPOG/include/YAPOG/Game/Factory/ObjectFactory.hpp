#ifndef YAPOG_OBJECTFACTORY_HPP
# define YAPOG_OBJECTFACTORY_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/Game/ID.hpp"

namespace yap
{
  struct IObjectIDLoader;
  struct IObjectLoader;
  struct IReader;

  class YAPOG_LIB ObjectFactory
  {
      DISALLOW_COPY(ObjectFactory);

    public:

      static ObjectFactory& Instance ();

      template <typename T>
      T* Get (const String& typeName, const ID& id);

      template <typename T>
      T* Create (const String& typeName, const ID& id);

      template <typename T>
      T* Create (const ID& typeID, const ID& id);

      /// @brief Creates an object from a partial input file.
      /// Does not store it.
      /// @param typeName Name of the registered type to load.
      /// @param reader IReader from which to load the entity.
      /// @param rootNodeName Name of the root node which contains
      /// the definition of the entity to create.
      /// @return The entity with the type @a typeName created from the
      /// node @a rootNodeName in the file @a file.
      template <typename T>
      T* Create (
        const String& typeName,
        IReader& reader,
        const String& rootNodeName);

      void RegisterLoader (const String& typeName, IObjectIDLoader* loader);
      void RegisterLoader (const String& typeName, IObjectLoader* loader);

      void AddType (const ID& id, const String& type);
      const String& GetType (const ID& id) const;
      const ID& GetID (const String& type) const;

      const collection::Map<ID, String>& GetTypes () const;

    private:

      ObjectFactory ();
      ~ObjectFactory ();

      bool ContainsLoader (const String& typeName) const;

      static const UInt64 INITIAL_ID;
      static UInt64 currentID_;

      collection::Map<String, IObjectIDLoader*> objectIDLoaders_;
      collection::Map<String, IObjectLoader*> objectLoaders_;

      collection::Map<ID, String> types_;
      collection::Map<String, ID> ids_;
  };
} // namespace yap

# include "YAPOG/Game/Factory/ObjectFactory.hxx"

#endif // YAPOG_OBJECTFACTORY_HPP
