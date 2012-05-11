#ifndef YAPOG_IPACKETSENDER_HPP
# define YAPOG_IPACKETSENDER_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  struct IPacket;

  struct IPacketSender
  {
      virtual ~IPacketSender () { }

      virtual bool SendPacket (IPacket& packet) = 0;
  };
} // namespace yap

#endif // YAPOG_IPACKETSENDER_HPP
