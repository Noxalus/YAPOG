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

    yap::DialogNode* d1 = new yap::DialogNode ();
    yap::DialogNodeEntry* d1_e1 = new yap::DialogNodeEntry (
      nullptr, nullptr, nullptr);
    d1->AddEntry (d1_e1);
    d1_e1->AddMessage (new yap::DialogMessage ("Salut !"));
    d1_e1->AddMessage (new yap::DialogMessage ("Second message ........."));

    npc_.SetDialogNode (d1);
  }
} // namespace ycl
