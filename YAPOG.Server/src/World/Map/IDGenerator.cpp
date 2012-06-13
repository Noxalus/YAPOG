#include "World/Map/IDGenerator.hpp"

namespace yse
{
  IDGenerator::IDGenerator ()
    : currentID_ ()
  {
  }

  IDGenerator::~IDGenerator ()
  {
  }

  IDGenerator& IDGenerator::Instance ()
  {
    static IDGenerator instance;

    return instance;
  }

  yap::ID IDGenerator::GetID ()
  {
    return yap::ID (currentID_++);
  }
} // namespace yse
