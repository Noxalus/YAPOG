#include "World/Map/NPC.hpp"

namespace ycl
{
  const yap::String NPC::OBJECT_FACTORY_TYPE_NAME = "NPC";

  NPC::NPC (const yap::ID& id)
    : Character (id)
  {
  }

  NPC::~NPC ()
  {
  }

  NPC::NPC (const NPC& copy)
    : Character (copy)
  {
  }

  NPC* NPC::Clone () const
  {
    return new NPC (*this);
  }

  const yap::String& NPC::GetObjectFactoryTypeName () const
  {
    return OBJECT_FACTORY_TYPE_NAME;
  }
} // namespace ycl
