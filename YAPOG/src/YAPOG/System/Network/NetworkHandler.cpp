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
    while (true)
    {
      PacketPtrType packet (new Packet ());

      if (!packet->CreateFromSocket (socket_))
        break;

      packets_.Enqueue (packet);
    }
  }

  bool NetworkHandler::IsEmpty () const
  {
    return packets_.IsEmpty ();
  }

  PacketPtrType NetworkHandler::GetPacket ()
  {
    PacketPtrType packet;

    return packets_.Dequeue (packet);
  }
} // namespace yap
