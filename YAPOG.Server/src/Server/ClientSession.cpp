#include "Server/ClientSession.hpp"

#include "YAPOG/System/IO/Log/DebugLogger.hpp"
namespace yse
{
  ClientSession::ClientSession ()
    : packetHandler_ ()
    , socket_ ()
    , user_ ()
  {
    AddRelay (&user_);

    ADD_HANDLER(None, ClientSession::HandleNone);
  }

  ClientSession::~ClientSession ()
  {
  }

  yap::ClientSocket& ClientSession::GetSocket ()
  {
    return socket_;
  }

  bool ClientSession::HandlePacket (yap::IPacket& packet)
  {
    return packetHandler_.HandlePacket (packet);
  }

  bool ClientSession::SendPacket (yap::IPacket& packet)
  {
    return socket_.Send (packet);
  }

  void ClientSession::AddRelay (yap::IPacketHandler* relay)
  {
    packetHandler_.AddRelay (relay);
  }

  void ClientSession::SetParent (yap::IPacketHandler* parent)
  {
    packetHandler_.SetParent (parent);
  }

  /// @brief test.
  void ClientSession::HandleNone (yap::IPacket& packet)
  {
    yap::DebugLogger::Instance ().LogLine ("toto");
  }
} // namespace yse
