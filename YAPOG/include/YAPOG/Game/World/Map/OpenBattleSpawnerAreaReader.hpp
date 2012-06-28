#ifndef YAPOG_OPENBATTLESPAWNERAREAREADER_HPP
# define YAPOG_OPENBATTLESPAWNERAREAREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/BattleSpawnerAreaReader.hpp"

namespace yap
{
  class OpenBattleSpawnerArea;

  class YAPOG_LIB OpenBattleSpawnerAreaReader
    : public BattleSpawnerAreaReader
  {
    DISALLOW_COPY(OpenBattleSpawnerAreaReader);

  public:

    OpenBattleSpawnerAreaReader (
      OpenBattleSpawnerArea& openBattleSpawnerArea,
      const String& xmlRootNodeName);

    virtual ~OpenBattleSpawnerAreaReader ();

  private:

    OpenBattleSpawnerArea& openBattleSpawnerArea_;
  };
} // namespace yap

#endif // YAPOG_OPENBATTLESPAWNERAREAREADER_HPP
