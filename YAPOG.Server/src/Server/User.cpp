#include "Server/User.hpp"
#include "World/Map/Player.hpp"

namespace yse
{
  User::User ()
    : packetHandler_ ()
    , player_ (nullptr)
  {
  }

  User::~User ()
  {
  }

  bool User::HandlePacket (yap::IPacket& packet)
  {
    return packetHandler_.HandlePacket (packet);
  }

  bool User::SendPacket (yap::IPacket& packet)
  {
    return packetHandler_.SendPacket (packet);
  }

  void User::AddRelay (yap::IPacketHandler* relay)
  {
    packetHandler_.AddRelay (relay);
  }

  void User::SetParent (yap::IPacketHandler* parent)
  {
    packetHandler_.SetParent (parent);
  }

  void User::SetPlayer (Player* player)
  {
    player_ = player;
  }
} // namespace yse
