#ifndef YAPOG_CLIENT_CHARACTER_HPP
# define YAPOG_CLIENT_CHARACTER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Character.hpp"

class Character : public yap::Character
{
    DISALLOW_ASSIGN(Character);

  public:

    virtual ~Character ();

  protected:

    explicit Character (const yap::ID& id);

    Character (const Character& copy);
};

#endif // YAPOG_CLIENT_CHARACTER_HPP
