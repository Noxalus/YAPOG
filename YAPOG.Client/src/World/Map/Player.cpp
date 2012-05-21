#include "World/Map/Player.hpp"

namespace ycl
{
  const yap::String Player::OBJECT_FACTORY_TYPE_NAME = "Player";

  Player::Player (const yap::ID& id)
    : Character (id)
  {
  }

  Player::~Player ()
  {
  }

  Player::Player (const Player& copy)
    : Character (copy)
  {
  }

  Player* Player::Clone () const
  {
    return new Player (*this);
  }

  yap::String Player::GetObjectFactoryTypeName () const
  {
    return OBJECT_FACTORY_TYPE_NAME;
  }
} // namespace ycl
