#include "YAPOG/System/Network/PacketHandler.hpp"
#include "YAPOG/System/Network/IPacket.hpp"

namespace yap
{
  PacketHandler::PacketHandler ()
    : handlers_ ()
    , relay_ (nullptr)
  {
  }

  PacketHandler::~PacketHandler ()
  {
  }

  void PacketHandler::SetRelay (IPacketHandler* relay)
  {
    relay_ = relay;
  }

  bool PacketHandler::HandlePacket (IPacket& packet)
  {
    if (handlers_.Contains (packet.GetType ()))
    {
      HandlerTargetPairType& action = handlers_[packet.GetType ()];
      (action.second->*action.first) (packet);

      return true;
    }

    if (relay_ != nullptr)
      return relay_->HandlePacket (packet);

    return false;
  }

  void PacketHandler::AddHandler (
    PacketType packetType,
    HandlerType handler,
    IPacketHandler* packetHandler)
  {
    handlers_.Add (packetType, HandlerTargetPairType (handler, packetHandler));
  }
} // namespace yap
