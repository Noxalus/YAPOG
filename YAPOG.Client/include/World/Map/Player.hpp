#ifndef YAPOG_CLIENT_PLAYER_HPP
# define YAPOG_CLIENT_PLAYER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Event/Event.hpp"

# include "World/Map/Character.hpp"

namespace ycl
{
  class Map;

  class Player : public Character
  {
      DISALLOW_ASSIGN(Player);

    public:

      Player (const yap::ID& id);
      virtual ~Player ();

      void SetMap (Map* map);

      /// @name ICloneable members.
      /// @{
      virtual Player* Clone () const;
      /// @}

      yap::Event<
        const Player&,
        const yap::ConstChangeEventArgs<Map*>&> OnMapChanged;

    protected:

      Player (const Player& copy);

    private:

      Map* map_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_PLAYER_HPP
