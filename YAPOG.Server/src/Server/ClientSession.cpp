#include "Server/ClientSession.hpp"

#include "YAPOG/System/IO/Log/DebugLogger.hpp"
namespace yse
{
  ClientSession::ClientSession ()
    : packetHandler_ ()
    , socket_ ()
  {
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

  /// @brief test.
  void ClientSession::HandleNone (yap::IPacket& packet)
  {
    yap::DebugLogger::Instance ().LogLine ("toto");
  }
} // namespace yse
