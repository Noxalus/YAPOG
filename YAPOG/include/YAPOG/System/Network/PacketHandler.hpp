#ifndef YAPOG_PACKETHANDLER_HPP
# define YAPOG_PACKETHANDLER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/System/Network/PacketType.hpp"

namespace yap
{
  struct IPacket;
  struct ISocket;

  class PacketHandler : public IPacketHandler
  {
      DISALLOW_COPY(PacketHandler);

    public:

      typedef void (PacketHandler::* Action) (IPacket&);

      virtual ~PacketHandler ();

      void SetRelay (PacketHandler* relay);

      bool HandlePacket (IPacket& packet);

    protected:

      PacketHandler ();

      void AddAction (PacketType packetType, Action action);

    private:

      collection::Map<PacketType, Action> actions_;

      PacketHandler* relay_;
  };
} // namespace yap

#endif // YAPOG_PACKETHANDLER_HPP
