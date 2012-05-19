#include <SFML/Network/IpAddress.hpp>

#include "YAPOG/System/Network/ClientSocket.hpp"
#include "YAPOG/System/Network/IPacket.hpp"

namespace yap
{
  const bool ClientSocket::DEFAULT_BLOCKING_STATE = true;
  const Time ClientSocket::DEFAULT_CONNECTION_TIMEOUT = Time (5.0f);

  ClientSocket::ClientSocket ()
    : Socket ()
    , socket_ ()
  {
    socket_.setBlocking (DEFAULT_BLOCKING_STATE);
  }

  ClientSocket::~ClientSocket ()
  {
  }

  bool ClientSocket::Connect (const String& ipAddress, Int16 port)
  {
    return socket_.connect (
      sf::IpAddress (ipAddress),
      port,
      sf::seconds (
        DEFAULT_CONNECTION_TIMEOUT.GetValue ())) == sf::Socket::Done;
  }

  void ClientSocket::Disconnect ()
  {
    socket_.disconnect ();
  }

  bool ClientSocket::Send (IPacket& packet)
  {
    return socket_.send (packet.GetInnerPacket ()) == sf::Socket::Done;
  }

  bool ClientSocket::Receive (
    const sf::SocketSelector& selector,
    IPacket& packet)
  {
    if (!selector.isReady (GetInnerSocket ()))
        return false;

    return socket_.receive (packet.GetInnerPacket ()) == sf::Socket::Done;
  }

  sf::TcpSocket& ClientSocket::GetInnerSocket ()
  {
    return socket_;
  }
} // namespace yap
