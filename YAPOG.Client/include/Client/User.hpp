#ifndef YAPOG_CLIENT_USER_HPP
# define YAPOG_CLIENT_USER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/System/Network/PacketHandler.hpp"
# include "YAPOG/System/Event/Event.hpp"

namespace ycl
{
  class Player;

  class User : public yap::IPacketHandler
  {
      DISALLOW_COPY(User);

    public:

      User ();
      virtual ~User ();

      /// @name IPacketHandler members.
      /// @{
      virtual bool HandlePacket (yap::IPacket& packet);
      virtual bool SendPacket (yap::IPacket& packet);

      virtual void AddRelay (yap::IPacketHandler* relay);
      virtual void SetParent (yap::IPacketHandler* parent);
      /// @}

      yap::Event<const User&, const Player*> OnPlayerCreated;

    private:

      void SetPlayer (Player* player);

      yap::PacketHandler packetHandler_;

      Player* player_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_USER_HPP
