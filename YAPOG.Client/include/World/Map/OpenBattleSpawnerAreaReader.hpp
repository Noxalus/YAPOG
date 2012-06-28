#ifndef YAPOG_CLIENT_OPENBATTLESPAWNERAREAREADER_HPP
# define YAPOG_CLIENT_OPENBATTLESPAWNERAREAREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/OpenBattleSpawnerAreaReader.hpp"

namespace ycl
{
  class OpenBattleSpawnerArea;

  class OpenBattleSpawnerAreaReader : public yap::OpenBattleSpawnerAreaReader
  {
      DISALLOW_COPY(OpenBattleSpawnerAreaReader);

    public:

      OpenBattleSpawnerAreaReader (
        OpenBattleSpawnerArea& openBattleSpawnerArea,
        const yap::String& xmlRootNodeName);
      virtual ~OpenBattleSpawnerAreaReader ();

      virtual void Visit (yap::XmlReader& visitable);

    private:

      static const yap::String DEFAULT_XML_BASE_SPRITE_TYPE_NODE_NAME;

      OpenBattleSpawnerArea& openBattleSpawnerArea_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_OPENBATTLESPAWNERAREAREADER_HPP
