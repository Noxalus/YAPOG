#ifndef YAPOG_SERVER_DYNAMICOBJECTFACTORY_HXX
# define YAPOG_SERVER_DYNAMICOBJECTFACTORY_HXX

# include "YAPOG/Game/Factory/ObjectFactory.hpp"

# include "World/Map/IDGenerator.hpp"

namespace yse
{
  template <typename T>
  inline T* DynamicObjectFactory::Create (
    const yap::String& typeName,
    const yap::ID& id,
    const yap::ICloner<T>& cloner) const
  {
    T* object = yap::ObjectFactory::Instance ().Create<T> (
      typeName,
      id,
      cloner);

    object->SetWorldID (IDGenerator::Instance ().GetID ());

    return object;
  }

  template <typename T>
  inline T* DynamicObjectFactory::Create (
    const yap::String& typeName,
    const yap::ID& id) const
  {
    T* object = yap::ObjectFactory::Instance ().Create<T> (typeName, id);

    object->SetWorldID (IDGenerator::Instance ().GetID ());

    return object;
  }
} // namespace yse

#endif // YAPOG_SERVER_DYNAMICOBJECTFACTORY_HXX
