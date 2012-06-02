#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/System/Network/ClientSocket.hpp"
#include "YAPOG/System/Network/IPacket.hpp"
#include "YAPOG/System/Network/Packet.hpp"
#include "YAPOG/Content/ContentManager.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Game/Factory/XmlObjectIDLoader.hpp"
#include "YAPOG/Game/Factory/XmlObjectLoader.hpp"
#include "YAPOG/Game/World/Map/WorldObjectStateFactory.hpp"
#include "YAPOG/System/IO/Log/DebugLogger.hpp"
#include "YAPOG/System/IO/Log/CountLoggerMode.hpp"
#include "YAPOG/System/IO/Log/TimeLoggerMode.hpp"
#include "YAPOG/System/RandomHelper.hpp"
#include "YAPOG/Game/World/Map/MapElement.hpp"
#include "YAPOG/Game/World/Map/MapElementReader.hpp"

#include "Server/Server.hpp"
#include "Server/ClientSession.hpp"
#include "World/Map/MapReader.hpp"
#include "World/Map/Map.hpp"
#include "World/Map/Player.hpp"
#include "World/Map/PlayerReader.hpp"

namespace yse
{
  const bool Server::DEFAULT_RUNNING_STATE = false;
  const yap::Int16 Server::DEFAULT_PORT = 8008;

  const float Server::DEFAULT_WORLD_UPDATE_RATE = 100.0f;

  Server::Server ()
    : isRunning_ (DEFAULT_RUNNING_STATE)
    , socket_ ()
    , listeningThread_ ([&] () { HandleListening (); })
    , port_ (DEFAULT_PORT)
    , clients_ ()
    , world_ ()
    , worldUpdateTimer_ ()
    , contentManager_ (yap::ContentManager::Instance ())
    , objectFactory_ (yap::ObjectFactory::Instance ())
    , worldObjectStateFactory_ (yap::WorldObjectStateFactory::Instance ())
    , logger_ (yap::DebugLogger::Instance ())
  {
  }

  void Server::Init ()
  {
    InitRandom ();
#ifndef YAPOG_WIN
    InitContentManager (yap::Path ("../Content/"));
#else
    InitContentManager (yap::Path ("../../Content/"));
#endif // YAPOG_WIN
    InitObjectFactory ();
    InitWorldObjectStateFactory ();

    InitLoggerManager ();

    LoadMaps ();

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
      yap::Time dt = worldUpdateTimer_.GetCurrentTime ();
      worldUpdateTimer_.Reset ();

      clients_.Refresh ();

      world_.Update (dt);

      yap::Time sleepTime = yap::Time (1.0f / DEFAULT_WORLD_UPDATE_RATE) - dt;
      if (sleepTime.GetValue () > 0.0f)
        yap::Thread::Sleep (sleepTime);
    }

    Dispose ();
  }

  void Server::Stop ()
  {
    isRunning_ = false;
  }

  void Server::Dispose ()
  {
    clients_.Dispose ();

    socket_.Close ();
  }

  void Server::AddClient (ClientSession* client)
  {
    client->GetUser ().SetWorld (&world_);

    client->Init ();

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
    }
  }

  void Server::InitRandom ()
  {
    yap::RandomHelper::Init (time (nullptr));
  }

  void Server::InitContentManager (const yap::Path& contentRootPath)
  {
    contentManager_.Init (contentRootPath);
  }

  void Server::InitObjectFactory ()
  {
    objectFactory_.RegisterLoader (
      "Map",
      new yap::XmlObjectIDLoader<Map, MapReader> (
        yap::Path ("Map"), "Map"));

    objectFactory_.RegisterLoader (
      "Player",
      new yap::XmlObjectIDLoader<Player, PlayerReader> (
        yap::Path ("Player"),
        "Player"));

    objectFactory_.RegisterLoader (
      "MapElement",
      new yap::XmlObjectIDLoader<yap::MapElement, yap::MapElementReader> (
        yap::Path ("MapElement"),
        "MapElement"));
  }

  void Server::InitWorldObjectStateFactory ()
  {
    worldObjectStateFactory_.AddState ("Inactive", "Inactive");
    worldObjectStateFactory_.AddState ("Moving", "Moving");
  }

  void Server::InitLoggerManager ()
  {
    logger_.AddMode (new yap::CountLoggerMode ());
    logger_.AddMode (new yap::TimeLoggerMode ());
  }

  void Server::LoadMaps ()
  {
    world_.LoadMaps ();
  }
} // namespace yse
