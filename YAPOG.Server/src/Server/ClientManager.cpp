#include "YAPOG/System/Network/IPacket.hpp"

#include "Server/ClientManager.hpp"
#include "Server/ClientSession.hpp"

namespace yse
{
  const yap::Time ClientManager::DEFAULT_RECEPTION_SLEEP_DELAY =
    yap::Time (0.05f);

  ClientManager::ClientManager ()
    : clients_ ()
    , clientsMutex_ ()
    , receptionThread_ ([this] () { HandleReception (); })
    , receptionIsActive_ (false)
  {
  }

  ClientManager::~ClientManager ()
  {
    for (ClientSession* client : clients_)
      delete client;
  }

  void ClientManager::AddClient (ClientSession* client)
  {
    {
      yap::Lock lock (clientsMutex_);
      clients_.Add (client);
    }
  }

  void ClientManager::RemoveClient (ClientSession* client)
  {
    {
      yap::Lock lock (clientsMutex_);
      clients_.Remove (client);
    }
  }

  void ClientManager::LaunchReception ()
  {
    receptionIsActive_ = true;
    receptionThread_.Launch ();
  }

  void ClientManager::Refresh ()
  {
    {
      yap::Lock lock (clientsMutex_);

      for (ClientSession* client : clients_)
        client->Refresh ();
    }
  }

  void ClientManager::Dispose ()
  {
    receptionIsActive_ = false;
  }

  void ClientManager::ServerTick (const yap::Time& dt)
  {
    {
      yap::Lock lock (clientsMutex_);

      for (ClientSession* client : clients_)
        client->ServerTick (dt);
    }
  }

  void ClientManager::HandleReception ()
  {
    while (receptionIsActive_)
    {
      yap::Thread::Sleep (DEFAULT_RECEPTION_SLEEP_DELAY);

      {
        yap::Lock lock (clientsMutex_);

        for (ClientSession* client : clients_)
          client->HandleReception ();
      }
    }
  }
} // namespace yse
