#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/System/Network/Packet.hpp"
#include "YAPOG/System/IO/Log/DebugLogger.hpp"

#include "Server/ClientSession.hpp"
#include "Account/PlayerData.hpp"
#include "World/Map/Player.hpp"

namespace yse
{
  ClientSession::ClientSession ()
    : OnDisconnected ()
    , isConnected_ (true)
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
      ClientRequestRegistration,
      ClientSession::HandleClientRequestRegistration);
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

  void ClientSession::SetDatabaseManager (
    yap::DatabaseManager* databaseManager)
  {
    databaseManager_ = databaseManager;
  }

  bool ClientSession::HandlePacket (yap::IPacket& packet)
  {
    return packetHandler_.HandlePacket (packet);
  }

  bool ClientSession::SendPacket (yap::IPacket& packet)
  {
    if (!IsConnected ())
      return false;

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

  bool ClientSession::IsConnected () const
  {
    return isConnected_;
  }

  void ClientSession::Disconnect ()
  {
    isConnected_ = false;

    socket_.Disconnect ();

    user_.RemoveFromWorld ();

    OnDisconnected (*this, yap::EmptyEventArgs ());
  }

  void ClientSession::HandleClientRequestLogin (yap::IPacket& packet)
  {
    yap::String login (packet.ReadString ());
    yap::String password (packet.ReadString ());

    try
    {
      if (user_.Login (login, password, socket_.GetRemoteAddress ()))
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

      yap::DebugLogger::Instance ().LogLine (
        "Client logged: `" + login + "'.");
    }
    catch (...)
    {
      yap::Packet loginErrorPacket;
      loginErrorPacket.CreateFromType (
        yap::PacketType::ServerInfoLoginError);

      SendPacket (loginErrorPacket);
    }
  }

  void ClientSession::HandleClientRequestRegistration (yap::IPacket& packet)
  {
    yap::String login (packet.ReadString ());
    yap::String password (packet.ReadString ());
    yap::String email (packet.ReadString ());

    try
    {
      if (user_.Register (login, password, email, socket_.GetRemoteAddress ()))
      {
        yap::Packet registrationValidationPacket;
        registrationValidationPacket.CreateFromType (
          yap::PacketType::ServerInfoRegistrationValidation);
        SendPacket (registrationValidationPacket);

        yap::Packet primaryDataPacket;
        primaryDataPacket.CreateFromType (
          yap::PacketType::ServerInfoPrimaryData);

        SendObjectFactoryTypes (
          primaryDataPacket,
          yap::ObjectFactory::Instance ());

        SendPacket (primaryDataPacket);

        yap::DebugLogger::Instance ().LogLine (
          "New account created: `" + login + "'.");
      }
      else
      {
        yap::Packet registrationErrorPacket;
        registrationErrorPacket.CreateFromType (
          yap::PacketType::ServerInfoRegistrationError);

        SendPacket (registrationErrorPacket);
      }
    }
    catch (...)
    {
      yap::Packet registrationErrorPacket;
      registrationErrorPacket.CreateFromType (
        yap::PacketType::ServerInfoRegistrationError);

      SendPacket (registrationErrorPacket);
    }
  }

  void ClientSession::HandleClientInfoDeconnection (yap::IPacket& packet)
  {
    // Copy some data to prepare update of the database
    yap::Vector2 currentPosition = user_.GetPlayer ().GetPosition ();
    user_.GetAccount ().GetPlayerData ().SetPosition (currentPosition);

    // Save the player data in the database
    user_.SaveAccountData ();

    yap::DebugLogger::Instance ().LogLine (
      user_.GetLogin () +
      "'s player data have been save.");

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
