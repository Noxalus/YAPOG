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
#include "YAPOG/Game/World/Map/TeleporterReader.hpp"
#include "YAPOG/Game/World/Map/DestructibleObject.hpp"
#include "YAPOG/Game/World/Map/DestructibleObjectReader.hpp"
#include "YAPOG/Game/World/Map/OpenBattleSpawnerArea.hpp"
#include "YAPOG/Game/World/Map/OpenBattleSpawnerAreaReader.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfoReader.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
#include "YAPOG/Game/Pokemon/NatureInfoReader.hpp"
#include "YAPOG/Game/Pokemon/NatureInfo.hpp"
#include "YAPOG/Game/Pokemon/TypeInfoReader.hpp"
#include "YAPOG/Game/Pokemon/TypeInfo.hpp"
#include "YAPOG/Game/Pokemon/SkillInfoReader.hpp"
#include "YAPOG/Game/Pokemon/SkillInfo.hpp"
#include "YAPOG/Game/World/Map/Dialog/DialogNode.hpp"
#include "YAPOG/Game/World/Map/Dialog/DialogNodeReader.hpp"

#include "Server/Server.hpp"
#include "Server/ClientSession.hpp"
#include "World/Map/MapReader.hpp"
#include "World/Map/Map.hpp"
#include "World/Map/Player.hpp"
#include "World/Map/PlayerReader.hpp"
#include "World/Map/NPC.hpp"
#include "World/Map/NPCReader.hpp"
#include "World/Map/Teleporter.hpp"

namespace yse
{
  const bool Server::DEFAULT_RUNNING_STATE = false;
  const yap::Int16 Server::DEFAULT_PORT = 8008;

  const float Server::DEFAULT_WORLD_UPDATE_RATE = 100.0f;

  Server::Server ()
    : isRunning_ (DEFAULT_RUNNING_STATE)
    , socket_ ()
    , socketMutex_ ()
    , listeningThread_ ([&] () { HandleListening (); })
    , port_ (DEFAULT_PORT)
    , clients_ ()
    , clientsMutex_ ()
    , world_ ()
    , worldMutex_ ()
    , worldUpdateTimer_ ()
    , contentManager_ (yap::ContentManager::Instance ())
    , objectFactory_ (yap::ObjectFactory::Instance ())
    , worldObjectStateFactory_ (yap::WorldObjectStateFactory::Instance ())
    , logger_ (yap::DebugLogger::Instance ())
    , databaseManager_ ()
    , databaseManagerMutex_ ()
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

    databaseManager_.Connect ();

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

      {
        yap::Lock lock (clientsMutex_);

        clients_.Refresh ();
        clients_.ServerTick (dt);
      }

      {
        yap::Lock lock (worldMutex_);

        world_.Update (dt);
      }

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
    {
      yap::Lock lock (worldMutex_);
      client->GetUser ().SetWorld (&world_);
    }

    {
      yap::Lock lock (databaseManagerMutex_);
      client->GetUser ().SetDatabaseManager (&databaseManager_);
    }

    client->Init ();

    {
      yap::Lock lock (clientsMutex_);
      clients_.AddClient (client);
    }
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
      "DialogNode",
      new yap::XmlObjectLoader<yap::DialogNode, yap::DialogNodeReader> ());

    objectFactory_.RegisterLoader (
      "Map",
      new yap::XmlObjectIDLoader<Map, MapReader> (
      yap::Path ("Map"), "Map"));

    objectFactory_.RegisterLoader (
      "NPC",
      new yap::XmlObjectIDLoader<NPC, NPCReader> (
      yap::Path ("NPC"),
      "NPC"));

    objectFactory_.RegisterLoader (
      "DestructibleObject",
      new yap::XmlObjectIDLoader<
      yap::DestructibleObject,
      yap::DestructibleObjectReader> (
      yap::Path ("DestructibleObject"),
      "DestructibleObject"));

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

    objectFactory_.RegisterLoader (
      "OpenBattleSpawnerArea",
      new yap::XmlObjectIDLoader<
      yap::OpenBattleSpawnerArea,
      yap::OpenBattleSpawnerAreaReader> (
      yap::Path ("OpenBattleSpawnerArea"),
      "OpenBattleSpawnerArea"));

    objectFactory_.RegisterLoader (
      "Teleporter",
      new yap::XmlObjectIDLoader<Teleporter, yap::TeleporterReader> (
      yap::Path ("Teleporter"),
      "Teleporter"));

    objectFactory_.RegisterLoader (
      "PokemonInfo",
      new yap::XmlObjectIDLoader<yap::PokemonInfo, yap::PokemonInfoReader> (
      yap::Path ("Pokemon/Pokemon"),
      "PokemonInfo"));

    objectFactory_.RegisterLoader (
      "NatureInfo",
      new yap::XmlObjectIDLoader<yap::NatureInfo, yap::NatureInfoReader> (
      yap::Path ("Pokemon/Nature"),
      "Nature"));

    objectFactory_.RegisterLoader (
      "TypeInfo",
      new yap::XmlObjectIDLoader<yap::TypeInfo, yap::TypeInfoReader> (
      yap::Path ("Pokemon/Types"),
      "Type"));

    objectFactory_.RegisterLoader (
      "SkillInfo",
      new yap::XmlObjectIDLoader<yap::SkillInfo, yap::SkillInfoReader> (
      yap::Path ("Pokemon/Skills"),
      "Skill"));
  }

  void Server::InitWorldObjectStateFactory ()
  {
    worldObjectStateFactory_.AddState ("Inactive", "Inactive");
    worldObjectStateFactory_.AddState ("Moving", "Moving");
    worldObjectStateFactory_.AddState ("Listening", "Listening");
    worldObjectStateFactory_.AddState ("Talking", "Talking");
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
