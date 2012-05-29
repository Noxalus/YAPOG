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

      /// @name ICloneable members.
      /// @{
      virtual Player* Clone () const;
      /// @}

    protected:

      Player (const Player& copy);

      const yap::String& GetObjectFactoryTypeName () const;

    private:

      static const yap::String OBJECT_FACTORY_TYPE_NAME;
  };
} // namespace yse

#endif // YAPOG_SERVER_PLAYER_HPP
