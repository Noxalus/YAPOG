#include "YAPOG/System/Network/PacketHandler.hpp"
#include "YAPOG/System/Network/IPacket.hpp"

namespace yap
{
  PacketHandler::PacketHandler ()
    : actions_ ()
    , relay_ (nullptr)
  {
  }

  PacketHandler::~PacketHandler ()
  {
  }

  void PacketHandler::SetRelay (PacketHandler* relay)
  {
    relay_ = relay;
  }

  bool PacketHandler::HandlePacket (IPacket& packet)
  {
    if (actions_.Contains (packet.GetType ()))
    {
      (this->*actions_[packet.GetType ()]) (packet);
      return true;
    }

    if (relay_ != nullptr)
      return relay_->HandlePacket (packet);

    return false;
  }

  void PacketHandler::AddAction (PacketType packetType, Action action)
  {
    actions_.Add (packetType, action);
  }
} // namespace yap
