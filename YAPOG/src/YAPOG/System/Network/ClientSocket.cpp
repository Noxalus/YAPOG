#include <SFML/Network/IpAddress.hpp>

#include "YAPOG/System/Network/ClientSocket.hpp"
#include "YAPOG/System/Network/IPacket.hpp"

namespace yap
{
  ClientSocket::ClientSocket ()
    : Socket ()
    , socket_ ()
  {
  }

  ClientSocket::~ClientSocket ()
  {
  }

  bool ClientSocket::Connect (const String& ipAddress, Int16 port)
  {
    return socket_.connect (sf::IpAddress (ipAddress), port) == VALID_STATUS;
  }

  void ClientSocket::Disconnect ()
  {
    socket_.disconnect ();
  }

  bool ClientSocket::Send (IPacket& packet)
  {
    return socket_.send (packet.GetInnerPacket ()) == VALID_STATUS;
  }

  bool ClientSocket::Receive (IPacket& packet)
  {
    return socket_.receive (packet.GetInnerPacket ()) == VALID_STATUS;
  }

  sf::TcpSocket& ClientSocket::GetInnerSocket ()
  {
    return socket_;
  }
} // namespace yap
