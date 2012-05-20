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

      virtual yap::String GetObjectFactoryTypeName () const;

    private:

      static const yap::String OBJECT_FACTORY_TYPE_NAME;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_PLAYER_HPP
