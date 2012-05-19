#include "World/Map/NPC.hpp"

namespace ycl
{
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
} // namespace ycl
