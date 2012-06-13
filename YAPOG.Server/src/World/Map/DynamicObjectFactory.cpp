#include "World/Map/DynamicObjectFactory.hpp"

namespace yse
{
  DynamicObjectFactory::DynamicObjectFactory ()
  {
  }

  DynamicObjectFactory::~DynamicObjectFactory ()
  {
  }

  DynamicObjectFactory& DynamicObjectFactory::Instance ()
  {
    static DynamicObjectFactory instance;

    return instance;
  }
} // namespace yse
