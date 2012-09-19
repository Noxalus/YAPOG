#include "TalkWorldObjectAction.cpp"

namespace yap
{
  TalkWorldObjectAction::TalkWorldObjectAction (
    DynamicWorldObject& parent
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

    dialogManager_.StartDialog (dialogActor_);
  }
} // namespace yap
