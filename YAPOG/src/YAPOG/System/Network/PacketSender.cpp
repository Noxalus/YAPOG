#include "YAPOG/System/Network/PacketSender.hpp"

namespace yap
{
  PacketSender::PacketSender ()
    : parent_ (nullptr)
  {
  }

  PacketSender::~PacketSender ()
  {
  }

  void PacketSender::SetParent (IPacketSender* parent)
  {
    parent_ = parent;
  }

  bool PacketSender::SendPacket (IPacket& packet)
  {
    if (parent_ == nullptr)
      return false;

    return parent_->SendPacket (packet);
  }
} // namespace yap
