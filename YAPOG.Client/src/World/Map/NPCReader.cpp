#include "World/Map/NPCReader.hpp"

#include "YAPOG/Game/World/Map/Dialog/IDialogNode.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"

#include "World/Map/NPC.hpp"

namespace ycl
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

    auto reader = visitable.ChangeRoot (xmlRootNodeName_);

    auto dialogReader = reader->ChangeRoot ("dialog");

    yap::String dialogNodeType = dialogReader->ReadString ("dialogNodeType");

    npc_.SetDialogNode (
      yap::ObjectFactory::Instance ().Create <yap::IDialogNode> (
        dialogNodeType,
        *dialogReader,
        dialogNodeType));
  }
} // namespace ycl
