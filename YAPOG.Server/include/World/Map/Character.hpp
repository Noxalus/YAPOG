#ifndef YAPOG_SERVER_CHARACTER_HPP
# define YAPOG_SERVER_CHARACTER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Character.hpp"

namespace yse
{
  class Map;

  class Character : public yap::Character
  {
      DISALLOW_ASSIGN(Character);

    public:

      virtual ~Character ();

      void SetMap (Map* map);

    protected:

      explicit Character (const yap::ID& id);
      Character (const Character& copy);

    private:

      Map* map_;
  };
} // namespace yse

#endif // YAPOG_SERVER_CHARACTER_HPP
