#ifndef YAPOG_OBJECTFACTORY_HPP
# define YAPOG_OBJECTFACTORY_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Collection/Map.hpp"

namespace yap
{
  struct IObjectIDLoader;
  struct IObjectLoader;
  struct IReader;

  class ID;

  class YAPOG_LIB ObjectFactory
  {
      DISALLOW_COPY(ObjectFactory);

    public:

      static ObjectFactory& Instance ();

      template <typename T>
      T* Get (const String& typeName, const ID& id);

      template <typename T>
      T* Create (const String& typeName, const ID& id);

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

    private:

      ObjectFactory ();
      ~ObjectFactory ();

      collection::Map<String, IObjectIDLoader*> objectIDLoaders_;
      collection::Map<String, IObjectLoader*> objectLoaders_;
  };
} // namespace yap

# include "YAPOG/Game/Factory/ObjectFactory.hxx"

#endif // YAPOG_OBJECTFACTORY_HPP
