#ifndef YAPOG_NETWORKHANDLER_HPP
# define YAPOG_NETWORKHANDLER_HPP

# include <memory>

# include <SFML/Network/SocketSelector.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Queue.hpp"

namespace yap
{
  struct IPacket;

  class ClientSocket;

  typedef std::shared_ptr<IPacket> IPacketPtrType;

  class NetworkHandler
  {
      DISALLOW_COPY(NetworkHandler);

    public:

      NetworkHandler (ClientSocket& socket);

      void Refresh (const sf::SocketSelector& selector);

      bool IsEmpty () const;
      IPacketPtrType GetPacket ();

    private:

      ClientSocket& socket_;

      collection::Queue<IPacketPtrType> packets_;
  };
} // namespace yap

#endif // YAPOG_NETWORKHANDLER_HPP
