#include "World/Map/Player.hpp"

namespace yse
{
  const yap::String Player::OBJECT_FACTORY_TYPE_NAME = "Player";

  Player::Player (const yap::ID& id)
    : Character (id)
    , packetHandler_ ()
  {
  }

  Player::~Player ()
  {
  }

  Player::Player (const Player& copy)
    : Character (copy)
    , packetHandler_ ()
  {
  }

  Player* Player::Clone () const
  {
    return new Player (*this);
  }

  bool Player::HandlePacket (yap::IPacket& packet)
  {
    return packetHandler_.HandlePacket (packet);
  }

  bool Player::SendPacket (yap::IPacket& packet)
  {
    return packetHandler_.SendPacket (packet);
  }

  void Player::AddRelay (yap::IPacketHandler* relay)
  {
    packetHandler_.AddRelay (relay);
  }

  void Player::RemoveRelay (yap::IPacketHandler* relay)
  {
    packetHandler_.RemoveRelay (relay);
  }

  void Player::SetParent (yap::IPacketHandler* parent)
  {
    packetHandler_.SetParent (parent);
  }

  const yap::String& Player::GetObjectFactoryTypeName () const
  {
    return OBJECT_FACTORY_TYPE_NAME;
  }
} // namespace yse
