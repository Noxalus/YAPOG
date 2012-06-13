#include "YAPOG/Game/World/Map/IDynamicWorldObjectVisitor.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectConstVisitor.hpp"

#include "World/Map/Player.hpp"
#include "Server/User.hpp"
#include "World/World.hpp"
#include "World/Map/Map.hpp"

namespace yse
{
  const yap::String Player::OBJECT_FACTORY_TYPE_NAME = "Player";

  Player::Player (const yap::ID& id)
    : Character (id)
    , parentUser_ (nullptr)
    , packetHandler_ ()
  {
  }

  Player::~Player ()
  {
  }

  Player::Player (const Player& copy)
    : Character (copy)
    , parentUser_ (nullptr)
    , packetHandler_ ()
  {
  }

  Player* Player::Clone () const
  {
    return new Player (*this);
  }

  void Player::SetParentUser (User* parentUser)
  {
    parentUser_ = parentUser;
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

  void Player::Accept (yap::IDynamicWorldObjectVisitor& visitor)
  {
    visitor.VisitPlayer (*this);
    visitor.VisitCharacter (*this);
  }

  void Player::Accept (
    yap::IDynamicWorldObjectConstVisitor& visitor) const
  {
    visitor.VisitPlayer (*this);
    visitor.VisitCharacter (*this);
  }

  void Player::Warp (const yap::ID& mapWorldID, const yap::Vector2& point)
  {
    GetParent ().GetMap ().RemovePlayer (this);
    GetParent ().GetWorld ().GetMap (mapWorldID).AddPlayer (this);

    SetPosition (point);
  }

  const yap::String& Player::GetObjectFactoryTypeName () const
  {
    return OBJECT_FACTORY_TYPE_NAME;
  }

  User& Player::GetParent ()
  {
    return *parentUser_;
  }
} // namespace yse
