#include "YAPOG/System/Network/PacketHandler.hpp"
#include "YAPOG/System/Network/IPacket.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace yap
{
  PacketHandler::PacketHandler ()
    : handlers_ ()
    , relays_ ()
    , parent_ (nullptr)
  {
  }

  PacketHandler::~PacketHandler ()
  {
  }

  void PacketHandler::AddHandler (
    PacketType packetType,
    HandlerType handler,
    IPacketHandler* packetHandler)
  {
    handlers_.Add (packetType, HandlerTargetPairType (handler, packetHandler));
  }

  bool PacketHandler::HandlePacket (IPacket& packet)
  {
    if (handlers_.Contains (packet.GetType ()))
    {
      HandlerTargetPairType& action = handlers_[packet.GetType ()];
      (action.second->*action.first) (packet);

      return true;
    }

    for (IPacketHandler* relay : relays_)
      if (relay->HandlePacket (packet))
        return true;

    return false;
  }

  bool PacketHandler::SendPacket (IPacket& packet)
  {
    if (parent_ == nullptr)
      return false;

    return parent_->SendPacket (packet);
  }

  void PacketHandler::AddRelay (IPacketHandler* relay)
  {
    relays_.Add (relay);

    relay->SetParent (this);
  }

  void PacketHandler::SetParent (IPacketHandler* parent)
  {
    if (parent_ != nullptr)
      YAPOG_THROW("Parent already exists.");

    parent_ = parent;
  }
} // namespace yap
