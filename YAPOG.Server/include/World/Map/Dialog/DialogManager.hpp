#ifndef YAPOG_SERVER_DIALOGMANAGER_HPP
# define YAPOG_SERVER_DIALOGMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Dialog/IDialogManager.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/System/Network/PacketHandler.hpp"
# include "YAPOG/Game/ID.hpp"

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

      void SetDisplay (yap::IDialogDisplay* dialogDisplay);

      void AddListener (yap::IDialogActor& dialogActor);

      /// @name IDialogResponseAcceptor members.
      /// @{
      virtual void TreatResponseProvider (
        yap::IDialogResponseProvider& dialogResponseProvider);
      /// @}

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

      typedef yap::collection::List<yap::IDialogActor*> DialogActorCollection;

      void HandleStartDialog ();
      void HandleStopDialog ();
      void ExecuteNode (yap::IDialogNode& dialogNode);

      void SendStartDialog ();
      void SendStopDialog ();
      void SendChangeDialogNode (const yap::ID& dialogNodeID);

      void HandleClientInfoDialogResponse (yap::IPacket& packet);

      yap::PacketHandler packetHandler_;

      yap::IDialogDisplay* dialogDisplay_;

      yap::IDialogActor* speaker_;
      DialogActorCollection listeners_;

      yap::IDialogResponseProvider* currentResponseProvider_;
  };
} // namespace yse

#endif // YAPOG_SERVER_DIALOGMANAGER_HPP
