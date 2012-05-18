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

    while (isRunning_)
    {
      break;
    }
  }

  void Server::AddClient (ClientSession* client)
  {
    client->Init ();

    clients_.Add (client);
  }

  void Server::HandleListening ()
  {
    while (isRunning_)
    {
      ClientSession* client = new ClientSession ();

      if (!socket_.Accept (client->GetSocket ()))
        YAPOG_THROW("Failed to accept client `xxx'");

      yap::DebugLogger::Instance ().LogLine ("new commer");

      AddClient (client);
    }
  }
} // namespace yse
