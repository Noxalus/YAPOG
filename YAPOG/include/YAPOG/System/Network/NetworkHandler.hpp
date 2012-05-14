#ifndef YAPOG_NETWORKHANDLER_HPP
# define YAPOG_NETWORKHANDLER_HPP

# include <memory>

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Queue.hpp"

namespace yap
{
  struct IPacket;

  class ClientSocket;

  typedef std::shared_ptr<IPacket> IPacketPtrType;

  class YAPOG_LIB NetworkHandler
  {
      DISALLOW_COPY(NetworkHandler);

    public:

      NetworkHandler (ClientSocket& socket);

      void Refresh ();

      bool IsEmpty () const;
      IPacketPtrType GetPacket ();

    private:

      ClientSocket& socket_;

      collection::Queue<IPacketPtrType> packets_;
  };
} // namespace yap

#endif // YAPOG_NETWORKHANDLER_HPP
