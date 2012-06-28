#ifndef YAPOG_BATTLESPAWNERAREAREADER_HPP
# define YAPOG_BATTLESPAWNERAREAREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/MapAreaReader.hpp"

namespace yap
{
  class BattleSpawnerArea;

  class YAPOG_LIB BattleSpawnerAreaReader : public MapAreaReader
  {
    DISALLOW_COPY(BattleSpawnerAreaReader);

  public:

    virtual ~BattleSpawnerAreaReader ();

  protected:

    BattleSpawnerAreaReader (
      BattleSpawnerArea& battleSpawnerArea,
      const String& xmlRootNodeName);

  private:

    BattleSpawnerArea& battleSpawnerArea_;
  };
} // namespace yap

#endif // YAPOG_BATTLESPAWNERAREAREADER_HPP
