#ifndef YAPOG_SERVER_NPCREADER_HPP
# define YAPOG_SERVER_NPCREADER_HPP

# include "YAPOG/Macros.hpp"
# include "World/Map/CharacterReader.hpp"

namespace yse
{
  class NPC;

  class NPCReader : public CharacterReader
  {
      DISALLOW_COPY(NPCReader);

    public:

      NPCReader (
        NPC& npc,
        const yap::String& xmlRootNodeName);
      virtual ~NPCReader ();

      virtual void Visit (yap::XmlReader& visitable);

    private:

      NPC& npc_;
  };
} // namespace yse

#endif // YAPOG_SERVER_NPCREADER_HPP
