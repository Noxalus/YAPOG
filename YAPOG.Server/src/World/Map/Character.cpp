#include "World/Map/Character.hpp"

namespace yse
{
  Character::Character (const yap::ID& id)
    : yap::Character (id)
    , packetHandler_ ()
  {
  }

  Character::~Character ()
  {
  }

  Character::Character (const Character& copy)
    : yap::Character (copy)
    , packetHandler_ ()
  {
  }

  bool Character::HandlePacket (yap::IPacket& packet)
  {
    return packetHandler_.HandlePacket (packet);
  }

  bool Character::SendPacket (yap::IPacket& packet)
  {
    return packetHandler_.SendPacket (packet);
  }

  void Character::AddRelay (yap::IPacketHandler* relay)
  {
    packetHandler_.AddRelay (relay);
  }

  void Character::RemoveRelay (yap::IPacketHandler* relay)
  {
    packetHandler_.RemoveRelay (relay);
  }

  void Character::SetParent (yap::IPacketHandler* parent)
  {
    packetHandler_.SetParent (parent);
  }
} // namespace yse
