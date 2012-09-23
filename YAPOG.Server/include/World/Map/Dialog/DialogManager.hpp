#ifndef YAPOG_SERVER_DIALOGMANAGER_HPP
# define YAPOG_SERVER_DIALOGMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Dialog/IDialogManager.hpp"
# include "YAPOG/System/Network/PacketHandler.hpp"

namespace yap
{
  struct IDialogDisplay;
} // namespace yap

namespace yse
{
  class DialogManager : public yap::IDialogManager
                      , public yap::IPacketHandler
  {
      DISALLOW_COPY(DialogManager);

    public:

      DialogManager ();

      virtual ~DialogManager ();

      void SetDisplay (yap::IDialogDisplay& dialogDisplay);

      /// @name IDialogManager members.
      /// @{
      virtual void StartDialog (
        yap::IDialogActor& dialogActor,
        yap::IDialogNode& dialogNode);
      /// @}

      /// @name IPacketHandler members.
      /// @{
      virtual bool HandlePacket (yap::IPacket& packet);
      virtual bool SendPacket (yap::IPacket& packet);

      virtual void AddRelay (yap::IPacketHandler* relay);
      virtual void RemoveRelay (yap::IPacketHandler* relay);
      virtual void SetParent (yap::IPacketHandler* parent);
      /// @}

    private:

      yap::PacketHandler packetHandler_;

      yap::IDialogDisplay* dialogDisplay_;
  };
} // namespace yse

#endif // YAPOG_SERVER_DIALOGMANAGER_HPP
