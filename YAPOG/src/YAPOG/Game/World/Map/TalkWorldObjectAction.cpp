#include "YAPOG/Game/World/Map/TalkWorldObjectAction.hpp"
#include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogManager.hpp"

namespace yap
{
  TalkWorldObjectAction::TalkWorldObjectAction (
    DynamicWorldObject& parent,
    IDialogActor& dialogActor,
    IDialogManager& dialogManager)
    : WorldObjectAction (parent)
    , dialogActor_ (dialogActor)
    , dialogManager_ (dialogManager)
  {
  }

  TalkWorldObjectAction::~TalkWorldObjectAction ()
  {
  }

  void TalkWorldObjectAction::HandlePerform ()
  {
    WorldObjectAction::HandlePerform ();

    if (!GetParent ().TryChangeState ("Talking"))
      return;

    dialogManager_.StartDialog (dialogActor_);
  }
} // namespace yap
