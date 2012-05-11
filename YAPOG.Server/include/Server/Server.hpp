#ifndef YAPOG_SERVER_SERVER_HPP
# define YAPOG_SERVER_SERVER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/System/Network/ServerSocket.hpp"
# include "YAPOG/Collection/List.hpp"
# include "YAPOG/System/Thread/Thread.hpp"

# include "World/World.hpp"

namespace yse
{
  class ClientSession;

  class Server
  {
      DISALLOW_COPY(Server);

    public:

      Server ();

      void Init ();
      void Launch ();

    private:

      void AddClient (ClientSession* client);

      void HandleListening ();

      static const bool DEFAULT_RUNNING_STATE;
      static const yap::Int16 DEFAULT_PORT;

      bool isRunning_;
      yap::ServerSocket socket_;
      yap::Thread listeningThread_;

      yap::Int16 port_;

      yap::collection::List<ClientSession*> clients_;

      World world_;
  };
} // namespace yse

#endif // YAPOG_SERVER_SERVER_HPP
