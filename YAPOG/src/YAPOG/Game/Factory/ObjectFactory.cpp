#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/Game/Factory/IObjectIDLoader.hpp"
#include "YAPOG/Game/Factory/IObjectLoader.hpp"

namespace yap
{
  ObjectFactory::ObjectFactory ()
    : objectIDLoaders_ ()
    , objectLoaders_ ()
  {
  }

  ObjectFactory::~ObjectFactory ()
  {
    for (const auto& it : objectIDLoaders_)
      delete it.second;

    for (const auto& it : objectLoaders_)
      delete it.second;
  }

  ObjectFactory& ObjectFactory::Instance ()
  {
    static ObjectFactory instance;

    return instance;
  }

  void ObjectFactory::RegisterLoader (
    const String& typeName,
    IObjectIDLoader* loader)
  {
    if (objectIDLoaders_.Contains (typeName))
      throw Exception (
        "Loader `" + typeName + "' already added to the factory.");

    objectIDLoaders_.Add (typeName, loader);
  }

  void ObjectFactory::RegisterLoader (
    const String& typeName,
    IObjectLoader* loader)
  {
    if (objectLoaders_.Contains (typeName))
      throw Exception (
        "Loader `" + typeName + "' already added to the factory.");

    objectLoaders_.Add (typeName, loader);
  }
} // namespace yap
