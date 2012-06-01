#ifndef YAPOG_PACKETHANDLER_HPP
# define YAPOG_PACKETHANDLER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/Collection/List.hpp"
# include "YAPOG/System/Network/PacketType.hpp"

# define ADD_HANDLER(TYPE, HANDLER)                              \
  packetHandler_.AddHandler (                                    \
    yap::PacketType::TYPE,                                       \
    static_cast<yap::PacketHandler::HandlerType> (&HANDLER),     \
    this)

namespace yap
{
  struct IPacket;
  struct ISocket;

  class YAPOG_LIB PacketHandler : public IPacketHandler
  {
      DISALLOW_COPY(PacketHandler);

    public:

      typedef void (IPacketHandler::*HandlerType) (IPacket&);
      typedef std::pair<HandlerType, IPacketHandler*> HandlerTargetPairType;

      PacketHandler ();
      virtual ~PacketHandler ();

      void AddHandler (
        PacketType packetType,
        HandlerType action,
        IPacketHandler* packetHandler);

      /// @name IPacketHandler members.
      /// @{
      virtual bool HandlePacket (IPacket& packet);
      virtual bool SendPacket (IPacket& packet);

      virtual void AddRelay (IPacketHandler* relay);
      virtual void RemoveRelay (IPacketHandler* relay);
      virtual void SetParent (IPacketHandler* parent);
      /// @}

    private:

      collection::Map<PacketType, HandlerTargetPairType> handlers_;

      collection::List<IPacketHandler*> relays_;
      IPacketHandler* parent_;
  };
} // namespace yap

#endif // YAPOG_PACKETHANDLER_HPP
