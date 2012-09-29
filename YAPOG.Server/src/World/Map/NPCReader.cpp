#include "World/Map/NPCReader.hpp"
#include "World/Map/NPC.hpp"

/// @warning [TMP]
#include "YAPOG/Game/World/Map/Physics/BoundingBox.hpp"
#include "YAPOG/Game/World/Map/Dialog/DialogNode.hpp"
#include "YAPOG/Game/World/Map/Dialog/DialogNodeEntry.hpp"
#include "YAPOG/Game/World/Map/Dialog/DialogMessage.hpp"
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

    yap::DialogNode* d1 = new yap::DialogNode ();
    yap::DialogNodeEntry* d1_e1 = new yap::DialogNodeEntry (
      nullptr, nullptr, nullptr);
    d1->AddEntry (d1_e1);
    d1_e1->AddMessage (new yap::DialogMessage ("Salut !"));
    d1_e1->AddMessage (new yap::DialogMessage ("Second message ........"));

    npc_.SetDialogNode (d1);
  }
} // namespace yse
