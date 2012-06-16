#ifndef YAPOG_CLIENT_PLAYER_HPP
# define YAPOG_CLIENT_PLAYER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/IPlayer.hpp"

# include "World/Map/Character.hpp"

namespace ycl
{
  class Player : public Character
               , public yap::IPlayer
  {
      DISALLOW_ASSIGN(Player);

    public:

      Player (const yap::ID& id);
      virtual ~Player ();

      /// @name ICloneable members.
      /// @{
      virtual Player* Clone () const;
      /// @}

      /// @name IPlayer members.
      /// @{
      virtual void Accept (yap::IDynamicWorldObjectVisitor& visitor);
      virtual void Accept (
        yap::IDynamicWorldObjectConstVisitor& visitor) const;

      virtual bool HasInput (yap::GameInputType gameInputType) const;

      virtual void Warp (const yap::ID& mapWorldID, const yap::Vector2& point);

      virtual void DestroyObject (const yap::ID& objectWorldID);
      /// @}

    protected:

      Player (const Player& copy);

      virtual const yap::String& GetObjectFactoryTypeName () const;

    private:

      static const yap::String OBJECT_FACTORY_TYPE_NAME;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_PLAYER_HPP
