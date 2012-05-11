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
  };
} // namespace yap

#endif // YAPOG_IPACKETHANDLER_HPP
