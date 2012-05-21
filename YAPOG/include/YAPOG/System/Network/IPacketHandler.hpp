#ifndef YAPOG_IPACKETHANDLER_HPP
# define YAPOG_IPACKETHANDLER_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  struct IPacket;

  struct IPacketHandler
  {
      virtual ~IPacketHandler () { }

      virtual bool HandlePacket (IPacket& packet) = 0;
      virtual bool SendPacket (IPacket& packet) = 0;

      virtual void AddRelay (IPacketHandler* relay) = 0;
      virtual void RemoveRelay (IPacketHandler* relay) = 0;

      virtual void SetParent (IPacketHandler* parent) = 0;
  };
} // namespace yap

#endif // YAPOG_IPACKETHANDLER_HPP
