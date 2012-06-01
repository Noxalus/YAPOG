#ifndef YAPOG_SERVER_SERVER_HPP
# define YAPOG_SERVER_SERVER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/System/Network/ServerSocket.hpp"
# include "YAPOG/Collection/List.hpp"
# include "YAPOG/System/Thread/Thread.hpp"
# include "YAPOG/System/Path.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/System/Time/Timer.hpp"

# include "World/World.hpp"
# include "Server/ClientManager.hpp"

namespace yap
{
  class ContentManager;
  class ObjectFactory;
  class WorldObjectStateFactory;
  class Logger;
} // namespace yap

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
      void Stop ();

    private:

      void AddClient (ClientSession* client);

      void HandleListening ();

      void Dispose ();

      void InitRandom ();
      void InitContentManager (const yap::Path& contentRootPath);
      void InitObjectFactory ();
      void InitWorldObjectStateFactory ();

      void InitLoggerManager ();

      void LoadMaps ();

      static const bool DEFAULT_RUNNING_STATE;
      static const yap::Int16 DEFAULT_PORT;

      static const float DEFAULT_WORLD_UPDATE_RATE;

      bool isRunning_;
      yap::ServerSocket socket_;
      yap::Thread listeningThread_;

      yap::Int16 port_;

      ClientManager clients_;

      World world_;
      yap::Timer worldUpdateTimer_;

      yap::ContentManager& contentManager_;

      yap::ObjectFactory& objectFactory_;
      yap::WorldObjectStateFactory& worldObjectStateFactory_;

      yap::Logger& logger_;
  };
} // namespace yse

#endif // YAPOG_SERVER_SERVER_HPP
