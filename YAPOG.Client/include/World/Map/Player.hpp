#ifndef YAPOG_CLIENT_PLAYER_HPP
# define YAPOG_CLIENT_PLAYER_HPP

# include "YAPOG/Macros.hpp"
# include "World/Map/Character.hpp"

namespace ycl
{
  class Player : public Character
  {
      DISALLOW_ASSIGN(Player);

    public:

      Player (const yap::ID& id);
      virtual ~Player ();

      /// @name ICloneable members.
      /// @{
      virtual Player* Clone () const;
      /// @}

    protected:

      Player (const Player& copy);
  };
} // namespace ycl

#endif // YAPOG_CLIENT_PLAYER_HPP
