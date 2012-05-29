#ifndef YAPOG_SERVER_CHARACTER_HPP
# define YAPOG_SERVER_CHARACTER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Character.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/System/Network/PacketHandler.hpp"

namespace yse
{
  class Character : public yap::Character
                  , public yap::IPacketHandler
  {
      DISALLOW_ASSIGN(Character);

    public:

      virtual ~Character ();

      /// @name IPacketHandler members.
      /// @{
      virtual bool HandlePacket (yap::IPacket& packet);
      virtual bool SendPacket (yap::IPacket& packet);

      virtual void AddRelay (yap::IPacketHandler* relay);
      virtual void RemoveRelay (yap::IPacketHandler* relay);
      virtual void SetParent (yap::IPacketHandler* parent);
      /// @}

    protected:

      explicit Character (const yap::ID& id);
      Character (const Character& copy);

    private:

      yap::PacketHandler packetHandler_;
  };
} // namespace yse

#endif // YAPOG_SERVER_CHARACTER_HPP
