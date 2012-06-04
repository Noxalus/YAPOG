#ifndef YAPOG_CLIENT_NPCREADER_HPP
# define YAPOG_CLIENT_NPCREADER_HPP

# include "YAPOG/Macros.hpp"
# include "World/Map/CharacterReader.hpp"

namespace ycl
{
  class NPC;

  class NPCReader : public CharacterReader
  {
      DISALLOW_COPY(NPCReader);

    public:

      NPCReader (
        NPC& character,
        const yap::String& xmlRootNodeName);
      virtual ~NPCReader ();

      virtual void Visit (yap::XmlReader& visitable);

    private:

      NPC& npc_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_NPCREADER_HPP
