#ifndef YAPOG_SERVER_CHARACTER_HPP
# define YAPOG_SERVER_CHARACTER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Character.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/System/Network/PacketHandler.hpp"
# include "YAPOG/System/Network/IPacketSender.hpp"
# include "YAPOG/System/Network/PacketSender.hpp"

namespace yse
{
  class Character : public yap::Character
                  , public yap::IPacketHandler
                  , public yap::IPacketSender
  {
      DISALLOW_ASSIGN(Character);

    public:

      virtual ~Character ();

      /// @name IPacketHandler members.
      /// @{
      virtual bool HandlePacket (yap::IPacket& packet);
      /// @}

      /// @name IPacketSender members.
      /// @{
      virtual bool SendPacket (yap::IPacket& packet);
      /// @}

    protected:

      explicit Character (const yap::ID& id);
      Character (const Character& copy);

      yap::PacketHandler packetHandler_;
      yap::PacketSender packetSender_;

    private:

      void AddPacketHandlers ();
  };
} // namespace yse

#endif // YAPOG_SERVER_CHARACTER_HPP
