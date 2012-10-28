#ifndef YAPOG_OBJECTFACTORY_HXX
# define YAPOG_OBJECTFACTORY_HXX

# include "YAPOG/Game/Factory/ILoadable.hpp"
# include "YAPOG/Game/Factory/IIDLoadable.hpp"
# include "YAPOG/Game/Factory/IObjectIDLoader.hpp"
# include "YAPOG/Game/Factory/IObjectLoader.hpp"
# include "YAPOG/Game/Factory/DefaultCloner.hpp"
# include "YAPOG/System/Error/Exception.hpp"
# include "YAPOG/System/StringHelper.hpp"

namespace yap
{
  template <typename T>
  T* ObjectFactory::Get (const String& typeName, const ID& id)
  {
    IObjectIDLoader** loaderPtr = objectIDLoaders_.TryGetValue (typeName);

    if (loaderPtr == nullptr)
      YAPOG_THROW("Loader `" + typeName + "' does not exist.");

    IObjectIDLoader* loader = *loaderPtr;

    return static_cast<T*> (loader->Load (id));
  }

  template <typename T>
  inline T* ObjectFactory::Create (
    const String& typeName,
    const ID& id,
    const ICloner<T>& cloner)
  {
    IObjectIDLoader** loaderPtr = objectIDLoaders_.TryGetValue (typeName);

    if (loaderPtr == nullptr)
      YAPOG_THROW("Loader `" + typeName + "' does not exist.");

    IObjectIDLoader* loader = *loaderPtr;

    T* object = static_cast<T*> (loader->Load (id));

    return cloner.Clone (*object);
  }

  template <typename T>
  inline T* ObjectFactory::Create (const String& typeName, const ID& id)
  {
    return Create<T> (typeName, id, DefaultCloner<T> ());
  }

  template <typename T>
  inline T* ObjectFactory::Create (const ID& typeID, const ID& id)
  {
    return Create<T> (GetType (typeID), id);
  }

  template <typename T>
  inline T* ObjectFactory::Create (
    const String& typeName,
    IReader& reader,
    const String& rootNodeName)
  {
    IObjectLoader** loaderPtr = objectLoaders_.TryGetValue (typeName);

    if (loaderPtr == nullptr)
      YAPOG_THROW("Loader `" + typeName + "' does not exist.");

    IObjectLoader* loader = *loaderPtr;

    ILoadable* object = loader->Load (reader, rootNodeName);

    return static_cast<T*> (object);
  }
} // namespace yap

#endif // YAPOG_OBJECTFACTORY_HXX
