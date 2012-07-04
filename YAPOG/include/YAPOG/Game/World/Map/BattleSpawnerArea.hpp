#ifndef YAPOG_BATTLESPAWNERAREA_HPP
# define YAPOG_BATTLESPAWNERAREA_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/MapArea.hpp"

namespace yap
{
  class YAPOG_LIB BattleSpawnerArea : public MapArea
  {
      DISALLOW_ASSIGN(BattleSpawnerArea);

    public:

      virtual ~BattleSpawnerArea ();

      void InitArea (uint width, uint height);

      const uint& GetWidth () const;
      const uint& GetHeight () const;

    protected:

      explicit BattleSpawnerArea (const ID& id);

      BattleSpawnerArea (const BattleSpawnerArea& copy);

      void SetBattleSpawningArea (const FloatRect& battleSpawningArea);

      virtual void HandleInitArea (uint width, uint height);

      static const uint DEFAULT_CELL_SIZE;

    private:

      void InitBattleSpawningEvent (const FloatRect& battleSpawningArea);

      static const uint DEFAULT_WIDTH;
      static const uint DEFAULT_HEIGHT;

      static const int DEFAULT_BATTLE_SPAWNING_AREA_Z;
      static const int DEFAULT_BATTLE_SPAWNING_AREA_H;

      static const String OBJECT_ENTERING_HANDLER_NAME;

      uint width_;
      uint height_;

      FloatRect battleSpawningArea_;
  };
} // namespace yap

#endif // YAPOG_BATTLESPAWNERAREA_HPP
