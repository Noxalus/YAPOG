#include "World/Map/Player.hpp"

namespace ycl
{
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
} // namespace ycl
