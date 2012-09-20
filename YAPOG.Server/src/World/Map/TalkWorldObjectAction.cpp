#include "World/Map/TalkWorldObjectAction.hpp"

#include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"

namespace yse
{
  TalkWorldObjectAction::TalkWorldObjectAction (
    yap::DynamicWorldObject& parent,
    yap::IDialogActor& dialogActor,
    yap::IDialogManager& dialogManager)
    : yap::TalkWorldObjectAction (parent, dialogActor, dialogManager)
  {
  }

  TalkWorldObjectAction::~TalkWorldObjectAction ()
  {
  }

  void TalkWorldObjectAction::HandlePerform ()
  {
    yap::TalkWorldObjectAction::HandlePerform ();

    /// @warning ACTUALY DOES NOTHING... todo ==> remove
    /// 1 DialogManager / User in server.


    /// @todo move into yse::Map: add OnActionPerformed event in yap::DynObj.

//    yap::Packet packet;
//    packet.CreateFromType (yap::PacketType::ServerInfoPerformObjectAction);

    // todo here: make an IWorldObjectActionReader/Writer in ::yap
    /**
     * yse::TalkWorldObjectActionWriter writer (*this);
     * packet.Accept (writer);
     *
     * in client:
     * packet.ReadID (); <-- object world id
     * paclet.ReadID (); <-- action unique id
     * ycl::WorldObjectActionFactory::Create ...
     */

//    SendPacket (packet);
  }
} // namespace yse
