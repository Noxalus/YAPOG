#ifndef YAPOG_OBJECTFACTORY_HXX
# define YAPOG_OBJECTFACTORY_HXX

# include "YAPOG/Game/Factory/ILoadable.hpp"
# include "YAPOG/Game/Factory/IObjectIDLoader.hpp"
# include "YAPOG/Game/Factory/IObjectLoader.hpp"
# include "YAPOG/System/Error/Exception.hpp"

namespace yap
{
  template <typename T>
  inline T* ObjectFactory::Create (const String& typeName, const ID& id)
  {
    if (!objectIDLoaders_.Contains (typeName))
      throw Exception ("Loader `" + typeName + "' does not exist.");

    IObjectIDLoader* loader = objectIDLoaders_[typeName];

    ILoadable* object = loader->Load (id);
    ICloneable* newObject = object->Clone ();

    return static_cast<T*> (newObject);
  }

  template <typename T>
  inline T* ObjectFactory::Create (
    const String& typeName,
    IReader& reader,
    const String& rootNodeName)
  {
    if (!objectLoaders_.Contains (typeName))
      throw Exception ("Loader `" + typeName + "' does not exist.");

    IObjectLoader* loader = objectLoaders_[typeName];

    ILoadable* object = loader->Load (reader, rootNodeName);
    ICloneable* newObject = object->Clone ();

    return static_cast<T*> (newObject);
  }
} // namespace yap

#endif // YAPOG_OBJECTFACTORY_HXX
