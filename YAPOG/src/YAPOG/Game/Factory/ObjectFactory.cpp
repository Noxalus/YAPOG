#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/System/Error/Exception.hpp"

namespace yap
{
  ObjectFactory::ObjectFactory ()
    : loaders_ ()
  {
  }

  ObjectFactory::~ObjectFactory ()
  {
    for (const auto& it : loaders_)
      delete it.second;
  }

  ObjectFactory& ObjectFactory::Instance ()
  {
    static ObjectFactory instance;

    return instance;
  }

  void ObjectFactory::RegisterLoader (const String& typeName, ILoader* loader)
  {
    if (loaders_.Contains (typeName))
      throw Exception (
        "Loader `" + typeName + "' already added to the factory.");

    loaders_.Add (typeName, loader);
  }
} // namespace yap
