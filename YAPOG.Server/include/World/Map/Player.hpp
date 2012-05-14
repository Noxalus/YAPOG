#ifndef YAPOG_SERVER_PLAYER_HPP
# define YAPOG_SERVER_PLAYER_HPP

# include "YAPOG/Macros.hpp"

# include "World/Map/Character.hpp"

namespace yse
{
  class Player : public Character
  {
      DISALLOW_ASSIGN(Player);

    public:

      explicit Player (const yap::ID& id);
      virtual ~Player ();
  };
} // namespace yse

#endif // YAPOG_SERVER_PLAYER_HPP
