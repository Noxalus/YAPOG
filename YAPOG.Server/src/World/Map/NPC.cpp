#include "World/Map/NPC.hpp"

#include "World/Map/TalkWorldObjectAction.hpp"

namespace yse
{
  const yap::String NPC::OBJECT_FACTORY_TYPE_NAME = "NPC";

  const yap::String NPC::DEFAULT_NAME = "<UNKNOWN_NPC>";

  NPC::NPC (const yap::ID& id)
    : Character (id)
    , name_ (DEFAULT_NAME)
  {
  }

  NPC::~NPC ()
  {
  }

  NPC::NPC (const NPC& copy)
    : Character (copy)
    , name_ (copy.name_)
  {
  }

  NPC* NPC::Clone () const
  {
    return new NPC (*this);
  }

  void NPC::SetDialogManager (yap::IDialogManager& dialogManager)
  {
    dialogManager_ = &dialogManager;

    AddAction (
      "Talk",
      new TalkWorldObjectAction (*this, *this, *dialogManager_));
  }

  const yap::String& NPC::GetName () const
  {
    return name_;
  }

  const yap::String& NPC::GetObjectFactoryTypeName () const
  {
    return OBJECT_FACTORY_TYPE_NAME;
  }
} // namespace yse
