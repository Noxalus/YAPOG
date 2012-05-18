#ifndef YAPOG_SERVER_CLIENTMANAGER_HPP
# define YAPOG_SERVER_CLIENTMANAGER_HPP

# include "YAPOG/Macros.hpp"

namespace yse
{
  class ClientSession;

  /// @todo Maintains a reception thread and refresh the ClientSessions.
  class ClientManager
  {
      DISALLOW_COPY(ClientManager);

    public:

      ClientManager ();
  };
} // namespace yse

#endif // YAPOG_SERVER_CLIENTMANAGER_HPP
