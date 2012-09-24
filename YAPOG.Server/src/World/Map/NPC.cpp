#include "World/Map/NPC.hpp"

#include "YAPOG/Game/World/Map/IDynamicWorldObjectVisitor.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectConstVisitor.hpp"
#include "YAPOG/Game/World/Map/MapEvent.hpp"
#include "YAPOG/Game/World/Map/TalkMapEventAction.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogManager.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogNode.hpp"
#include "YAPOG/Game/World/Map/Physics/BoundingBox.hpp"

namespace yse
{
  const yap::String NPC::OBJECT_FACTORY_TYPE_NAME = "NPC";

  const yap::String NPC::DEFAULT_NAME = "<UNKNOWN_NPC>";

  NPC::NPC (const yap::ID& id)
    : Character (id)
    , name_ (DEFAULT_NAME)
    , dialogNode_ (nullptr)
    , talkEventArea_ (nullptr)
  {
  }

  NPC::~NPC ()
  {
  }

  NPC::NPC (const NPC& copy)
    : Character (copy)
    , name_ (copy.name_)
    , dialogNode_ (copy.dialogNode_->Clone ())
    , talkEventArea_ (nullptr)
  {
    SetTalkEventArea (new yap::BoundingBox (*copy.talkEventArea_));
  }

  NPC* NPC::Clone () const
  {
    return new NPC (*this);
  }

  void NPC::SetTalkEventArea (yap::BoundingBox* boundingBox)
  {
    talkEventArea_ = boundingBox;

    yap::MapEvent* talkEvent = new yap::MapEvent ();

    talkEvent->AddBoundingBox (talkEventArea_);

    yap::TalkMapEventAction* talkAction = new yap::TalkMapEventAction ();

    talkAction->SetSourceDialogActor (*this);

    talkEvent->AddAction (talkAction);

    AddEvent (talkEvent);
  }

  void NPC::SetDialogNode (yap::IDialogNode* dialogNode)
  {
    dialogNode_ = dialogNode;
  }

  const yap::String& NPC::GetName () const
  {
    return name_;
  }

  const yap::ID& NPC::GetWorldID () const
  {
    return Character::GetWorldID ();
  }

  bool NPC::CanTalk (yap::IDialogActor& dialogActor) const
  {
    return true;
  }

  void NPC::Talk (yap::IDialogActor& dialogActor)
  {
    TryChangeState ("Talking");
  }

  bool NPC::TryStartDialog (yap::IDialogManager& dialogManager)
  {
    if (dialogNode_ == nullptr)
      return false;

    dialogManager.StartDialog (*this, *dialogNode_);

    return true;
  }

  void NPC::Accept (yap::IDynamicWorldObjectVisitor& visitor)
  {
    Character::Accept (visitor);

    visitor.VisitNPC (*this);
  }

  void NPC::Accept (yap::IDynamicWorldObjectConstVisitor& visitor) const
  {
    Character::Accept (visitor);

    visitor.VisitNPC (*this);
  }

  const yap::String& NPC::GetObjectFactoryTypeName () const
  {
    return OBJECT_FACTORY_TYPE_NAME;
  }
} // namespace yse
