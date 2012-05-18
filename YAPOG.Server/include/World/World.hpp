#ifndef YAPOG_SERVER_WORLD_HPP
# define YAPOG_SERVER_WORLD_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/World.hpp"
# include "YAPOG/Collection/List.hpp"

namespace yse
{
  class Map;

  class World : public yap::World
  {
      DISALLOW_COPY(World);

    public:

      World ();
      virtual ~World ();

      void AddMap (Map* map);

    private:

      virtual void HandleUpdate (const yap::Time& dt);

      yap::collection::List<Map*> maps_;
  };
} // namespace yap

#endif // YAPOG_SERVER_WORLD_HPP
