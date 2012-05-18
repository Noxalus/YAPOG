#ifndef YAPOG_CHARACTERMOVECONTROLLER_HPP
# define YAPOG_CHARACTERMOVECONTROLLER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Physics/WorldObjectMoveController.hpp"
# include "YAPOG/Game/World/Map/Direction.hpp"
# include "YAPOG/Collection/Map.hpp"

namespace yap
{
  class YAPOG_LIB CharacterMoveController : public WorldObjectMoveController
  {
      DISALLOW_COPY(CharacterMoveController);

    public:

      CharacterMoveController ();
      virtual ~CharacterMoveController ();

      void EnableDirection (Direction direction);
      void DisableDirection (Direction direction);

    private:

      void Update ();

      static const Direction DEFAULT_LAST_DIRECTION;

      collection::Map<Direction, bool> directions_;
      Direction lastDirection_;
  };
} // namespace yap

#endif // YAPOG_CHARACTERMOVECONTROLLER_HPP
