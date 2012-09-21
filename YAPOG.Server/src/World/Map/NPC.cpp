#include "World/Map/NPC.hpp"

#include "YAPOG/Game/World/Map/IDynamicWorldObjectVisitor.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectConstVisitor.hpp"

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
  }

  const yap::String& NPC::GetName () const
  {
    return name_;
  }

  void NPC::Talk (yap::IDialogActor& dialogActor)
  {
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
