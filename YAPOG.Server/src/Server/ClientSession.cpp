#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/System/Network/Packet.hpp"

#include "Server/ClientSession.hpp"

#include "YAPOG/System/IO/Log/DebugLogger.hpp"
namespace yse
{
  ClientSession::ClientSession ()
    : OnDisconnected ()
    , packetHandler_ ()
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
    AddRelay (&user_);
    user_.SetParent (this);

    ADD_HANDLER(ClientRequestLogin, ClientSession::HandleClientRequestLogin);
    ADD_HANDLER(
      ClientInfoDeconnection,
      ClientSession::HandleClientInfoDeconnection);
  }

  void ClientSession::Refresh ()
  {
    while (!networkHandler_.IsEmpty ())
    {
      yap::PacketPtrType packet (networkHandler_.GetPacket ());

      yap::DebugLogger::Instance ().LogLine (
        "Packet: " + yap::StringHelper::ToString (
          static_cast<int> (packet->GetType ())));

      try
      {
        if (!HandlePacket (*packet))
          YAPOG_THROW("Wrong packet received.");
      }
      catch (const yap::Exception& ex)
      {
        ex.GetMessage (std::cout) << std::endl;
      }
    }
  }

  User& ClientSession::GetUser ()
  {
    return user_;
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

  void ClientSession::RemoveRelay (yap::IPacketHandler* relay)
  {
    relay->SetParent (nullptr);

    packetHandler_.RemoveRelay (relay);
  }

  void ClientSession::SetParent (yap::IPacketHandler* parent)
  {
    YAPOG_THROW("Unallowed to set parent for ClientSession.");
  }

  void ClientSession::Disconnect ()
  {
    user_.RemoveFromWorld ();

    socket_.Disconnect ();

    OnDisconnected (*this, yap::EmptyEventArgs ());
  }

  void ClientSession::HandleClientRequestLogin (yap::IPacket& packet)
  {
    yap::String login (packet.ReadString ());

    if (user_.Login (login))
    {
      yap::Packet loginValidationPacket;
      loginValidationPacket.CreateFromType (
        yap::PacketType::ServerInfoLoginValidation);
      SendPacket (loginValidationPacket);

      yap::Packet primaryDataPacket;
      primaryDataPacket.CreateFromType (
        yap::PacketType::ServerInfoPrimaryData);

      SendObjectFactoryTypes (
        primaryDataPacket,
        yap::ObjectFactory::Instance ());

      SendPacket (primaryDataPacket);
    }

    yap::DebugLogger::Instance ().LogLine ("Client logged: `" + login + "'.");
  }

  void ClientSession::HandleClientInfoDeconnection (yap::IPacket& packet)
  {
    yap::DebugLogger::Instance ().LogLine (
      "Client disconnected: `" +
      user_.GetLogin () +
      "'.");

    Disconnect ();
  }

  void ClientSession::SendObjectFactoryTypes (
    yap::IPacket& packet,
    const yap::ObjectFactory& objectFactory)
  {
    const auto& types = objectFactory.GetTypes ();

    packet.Write (static_cast<yap::UInt64> (types.Count ()));

    for (const auto& it : types)
    {
      packet.Write (it.first);
      packet.Write (it.second);
    }
  }
} // namespace yse
