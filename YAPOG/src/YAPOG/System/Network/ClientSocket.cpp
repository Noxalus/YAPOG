#include <SFML/Network/IpAddress.hpp>

#include "YAPOG/System/Network/ClientSocket.hpp"
#include "YAPOG/System/Network/IPacket.hpp"

namespace yap
{
  const bool ClientSocket::DEFAULT_BLOCKING_STATE = false;
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

  bool ClientSocket::Connect (const String& ipAddress, UInt16 port)
  {
    socket_.setBlocking (true);

    if (socket_.connect (
          sf::IpAddress (ipAddress),
          port,
          sf::seconds (
            DEFAULT_CONNECTION_TIMEOUT.GetValue ())) != sf::Socket::Done)
      return false;

    socket_.setBlocking (DEFAULT_BLOCKING_STATE);

    return true;
  }

  void ClientSocket::Disconnect ()
  {
    socket_.disconnect ();
  }

  bool ClientSocket::Send (IPacket& packet)
  {
    return socket_.send (packet.GetInnerPacket ()) == sf::Socket::Done;
  }

  bool ClientSocket::Receive (IPacket& packet)
  {
    return socket_.receive (packet.GetInnerPacket ()) == sf::Socket::Done;
  }

  String ClientSocket::GetRemoteAddress () const
  {
    return socket_.getRemoteAddress ().toString ();
  }

  UInt16 ClientSocket::GetRemotePort () const
  {
    return socket_.getRemotePort ();
  }

  sf::TcpSocket& ClientSocket::GetInnerSocket ()
  {
    return socket_;
  }
} // namespace yap
