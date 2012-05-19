#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/System/Network/Packet.hpp"

#include "Server/ClientSession.hpp"

#include "YAPOG/System/IO/Log/DebugLogger.hpp"
namespace yse
{
  ClientSession::ClientSession ()
    : packetHandler_ ()
    , socket_ ()
    , networkHandler_ (socket_)
    , user_ ()
  {
  }

  ClientSession::~ClientSession ()
  {
  }

  void ClientSession::Init ()
  {
//    AddRelay (&user_);

//    ADD_HANDLER(
//      ClientInfoDeconnection,
//      ClientSession::HandleClientInfoDeconnection);
  }

  void ClientSession::Refresh ()
  {
//    yap::DebugLogger::Instance ().LogLine ("session_refresh");
    while (!networkHandler_.IsEmpty ())
    {
      yap::PacketPtrType packet (networkHandler_.GetPacket ());

      yap::DebugLogger::Instance ().LogLine (
        "Packet: " + yap::StringHelper::ToString (static_cast<int> (packet->GetType ())));
      if (!HandlePacket (*packet));
//        YAPOG_THROW("Wrong packet received.");
    }
  }

  void ClientSession::HandleReception ()
  {
    networkHandler_.Refresh ();
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

  void ClientSession::HandleClientInfoDeconnection (yap::IPacket& packet)
  {
    yap::DebugLogger::Instance ().LogLine ("Client disconnected: `" +
                                           socket_.GetRemoteAddress () +
                                           "'.");
  }
} // namespace yse
