#include "World/Map/Character.hpp"

namespace yse
{
  Character::Character (const yap::ID& id)
    : yap::Character (id)
  {
    AddPacketHandlers ();
  }

  Character::~Character ()
  {
  }

  Character::Character (const Character& copy)
    : yap::Character (copy)
    , packetHandler_ ()
    , packetSender_ ()
  {
    AddPacketHandlers ();
  }

  bool Character::HandlePacket (yap::IPacket& packet)
  {
    return packetHandler_.HandlePacket (packet);
  }

  bool Character::SendPacket (yap::IPacket& packet)
  {
    return packetSender_.SendPacket (packet);
  }

  void Character::AddPacketHandlers ()
  {
  }
} // namespace yse
