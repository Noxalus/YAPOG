#include "YAPOG/System/Network/NetworkHandler.hpp"
#include "YAPOG/System/Network/Packet.hpp"
#include "YAPOG/System/Network/ClientSocket.hpp"

namespace yap
{
  NetworkHandler::NetworkHandler (ClientSocket& socket)
    : socket_ (socket)
    , packets_ ()
  {
  }

  void NetworkHandler::Refresh ()
  {
    IPacketPtrType packet (new Packet ());

    while (socket_.Receive (*packet))
      packets_.Enqueue (packet);
  }

  bool NetworkHandler::IsEmpty () const
  {
    return packets_.IsEmpty ();
  }

  IPacketPtrType NetworkHandler::GetPacket ()
  {
    IPacketPtrType packet;

    return packets_.Dequeue (packet);
  }
} // namespace yap
