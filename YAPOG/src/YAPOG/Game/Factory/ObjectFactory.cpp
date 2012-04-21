#include "YAPOG/Game/Factory/ObjectFactory.hpp"

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
    loaders_.Add (typeName, loader);
  }
} // namespace yap
