#include "YAPOG/System/Network/IPacket.hpp"

#include "Server/ClientManager.hpp"
#include "Server/ClientSession.hpp"

namespace yse
{
  const yap::Time ClientManager::DEFAULT_RECEPTION_SLEEP_DELAY =
    yap::Time (0.05f);

  ClientManager::ClientManager ()
    : clients_ ()
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
    clients_.Add (client);
  }

  void ClientManager::RemoveClient (ClientSession* client)
  {
    clients_.Remove (client);
  }

  void ClientManager::LaunchReception ()
  {
    receptionIsActive_ = true;
    receptionThread_.Launch ();
  }

  void ClientManager::Refresh ()
  {
    for (ClientSession* client : clients_)
      client->Refresh ();
  }

  void ClientManager::Dispose ()
  {
    receptionIsActive_ = false;
  }

  void ClientManager::HandleReception ()
  {
    while (receptionIsActive_)
    {
      yap::Thread::Sleep (DEFAULT_RECEPTION_SLEEP_DELAY);

      for (ClientSession* client : clients_)
        client->HandleReception ();
    }
  }
} // namespace yse
