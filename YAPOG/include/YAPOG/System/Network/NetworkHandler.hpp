#ifndef YAPOG_NETWORKHANDLER_HPP
# define YAPOG_NETWORKHANDLER_HPP

# include <memory>

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Queue.hpp"

namespace yap
{
  class Packet;

  class ClientSocket;

  typedef std::shared_ptr<Packet> PacketPtrType;

  class YAPOG_LIB NetworkHandler
  {
      DISALLOW_COPY(NetworkHandler);

    public:

      NetworkHandler (ClientSocket& socket);

      void Refresh ();

      bool IsEmpty () const;
      PacketPtrType GetPacket ();

    private:

      ClientSocket& socket_;

      collection::Queue<PacketPtrType> packets_;
  };
} // namespace yap

#endif // YAPOG_NETWORKHANDLER_HPP
