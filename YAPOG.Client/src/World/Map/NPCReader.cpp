#include "World/Map/NPCReader.hpp"

#include "YAPOG/Game/World/Map/Dialog/DialogNode.hpp"
#include "YAPOG/Game/World/Map/Dialog/DialogNodeEntry.hpp"
#include "YAPOG/Game/World/Map/Dialog/DialogMessage.hpp"

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

    npc_.SetDialogNode (
      &(new yap::DialogNode ())->AddEntry (
        new yap::DialogNodeEntry (
          new yap::DialogMessage ("Salut !"),
          nullptr,
          nullptr,
          nullptr)));
  }
} // namespace ycl
