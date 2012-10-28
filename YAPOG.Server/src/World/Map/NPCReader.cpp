#include "World/Map/NPCReader.hpp"

#include "YAPOG/Game/World/Map/Dialog/IDialogNode.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Game/World/Map/Physics/BoundingBox.hpp"

#include "World/Map/NPC.hpp"

namespace yse
{
  NPCReader::NPCReader (
    NPC& npc,
    const yap::String& xmlRootNodeName)
    : CharacterReader (npc, xmlRootNodeName)
    , npc_ (npc)
  {
  }

  NPCReader::~NPCReader ()
  {
  }

  void NPCReader::Visit (yap::XmlReader& visitable)
  {
    CharacterReader::Visit (visitable);

    /// @warning [TMP]
    npc_.SetTalkEventArea (
      new yap::BoundingBox (
        yap::Vector2 (-60, -60),
        yap::Vector2 (120, 120),
        0,
        1));

    auto reader = visitable.ChangeRoot (xmlRootNodeName_);

    auto dialogReader = reader->ChangeRoot ("dialog");

    yap::String dialogNodeType = dialogReader->ReadString ("dialogNodeType");

    npc_.SetDialogNode (
      yap::ObjectFactory::Instance ().Create <yap::IDialogNode> (
        dialogNodeType,
        *dialogReader,
        dialogNodeType));
  }
} // namespace yse
