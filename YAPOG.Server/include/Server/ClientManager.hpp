#ifndef YAPOG_SERVER_CLIENTMANAGER_HPP
# define YAPOG_SERVER_CLIENTMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/List.hpp"
# include "YAPOG/System/Thread/Thread.hpp"
# include "YAPOG/System/Time/Time.hpp"

namespace yse
{
  class ClientSession;

  class ClientManager
  {
      DISALLOW_COPY(ClientManager);

    public:

      ClientManager ();
      ~ClientManager ();

      void AddClient (ClientSession* client);
      void RemoveClient (ClientSession* client);

      void LaunchReception ();

      void Refresh ();
      void Dispose ();

    private:

      void HandleReception ();

      static const yap::Time DEFAULT_DATA_WAITING_DELAY;

      yap::collection::List<ClientSession*> clients_;

      yap::Thread receptionThread_;
      bool receptionIsActive_;
  };
} // namespace yse

#endif // YAPOG_SERVER_CLIENTMANAGER_HPP
