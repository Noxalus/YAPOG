#include "World/Map/NPCReader.hpp"
#include "World/Map/NPC.hpp"

/// @warning [TMP]
#include "YAPOG/Game/World/Map/Physics/BoundingBox.hpp"
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
        yap::Vector2 (-600, -600),
        yap::Vector2 (1200, 1200),
        0,
        1));
  }
} // namespace yse
