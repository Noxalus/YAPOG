#ifndef YAPOG_BATTLESPAWNERAREA_HPP
# define YAPOG_BATTLESPAWNERAREA_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  class BattleSpawnerArea : public DynamicWorldObject
  {
      DISALLOW_ASSIGN(BattleSpawnerArea);

    public:

      virtual ~BattleSpawnerArea ();

    protected:

      explicit BattleSpawnerArea (const ID& id);

      BattleSpawnerArea (const BattleSpawnerArea& copy);

      void SetArea (const FloatRect& area);

    private:

      FloatRect area_;
  };
} // namespace yap

#endif // YAPOG_BATTLESPAWNERAREA_HPP
