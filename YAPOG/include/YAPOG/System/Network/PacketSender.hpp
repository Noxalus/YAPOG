#ifndef YAPOG_PACKETSENDER_HPP
# define YAPOG_PACKETSENDER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Network/IPacketSender.hpp"

namespace yap
{
  struct IPacket;

  class YAPOG_LIB PacketSender : public IPacketSender
  {
      DISALLOW_COPY(PacketSender);

    public:

      PacketSender ();
      virtual ~PacketSender ();

      void SetParent (IPacketSender* parent);

      /// @name IPacketSender members.
      /// @{
      virtual bool SendPacket (IPacket& packet);
      /// @}

    private:

      IPacketSender* parent_;
  };
} // namespace yap

#endif // YAPOG_PACKETSENDER_HPP
