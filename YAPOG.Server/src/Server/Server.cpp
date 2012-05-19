#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/System/Network/ClientSocket.hpp"
#include "YAPOG/System/Network/Packet.hpp"

#include "YAPOG/System/IO/Log/DebugLogger.hpp"

#include "Server/Server.hpp"
#include "Server/ClientSession.hpp"

namespace yse
{
  const bool Server::DEFAULT_RUNNING_STATE = false;
  const yap::Int16 Server::DEFAULT_PORT = 8008;

  Server::Server ()
    : isRunning_ (DEFAULT_RUNNING_STATE)
    , socket_ ()
    , listeningThread_ ([&] () { HandleListening (); })
    , port_ (DEFAULT_PORT)
    , clients_ ()
    , world_ ()
  {
  }

  void Server::Init ()
  {
    if (!socket_.Listen (port_))
      YAPOG_THROW(
        "Failed to listen port `" +
        yap::StringHelper::ToString (port_) +
        "'.");
  }

  void Server::Launch ()
  {
    isRunning_ = true;

    listeningThread_.Launch ();

    clients_.LaunchReception ();

    while (isRunning_)
    {
      clients_.Refresh ();
    }

    clients_.Dispose ();
  }

  void Server::AddClient (ClientSession* client)
  {
    clients_.AddClient (client);
  }

  void Server::HandleListening ()
  {
    while (isRunning_)
    {
      ClientSession* client = new ClientSession ();

      if (!socket_.Accept (client->GetSocket ()))
        YAPOG_THROW("Failed to accept client `" +
                    client->GetSocket ().GetRemoteAddress () +
                    "'.");

      yap::DebugLogger::Instance ().LogLine (
        "Client connected: `" +
        client->GetSocket ().GetRemoteAddress () +
        "'.");

      AddClient (client);

      /// @todo erase (tmp)
      yap::Packet packet;
      packet.CreateFromType (yap::PacketType::ServerInfoLoginValidation);
      client->SendPacket (packet);
    }
  }
} // namespace yse
