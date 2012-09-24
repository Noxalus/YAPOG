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

    npc_.SetDialogNode (
      &(new yap::DialogNode ())->AddEntry (
        new yap::DialogNodeEntry (
          new yap::DialogMessage ("Salut !"),
          nullptr,
          nullptr,
          nullptr)));
  }
} // namespace yse
