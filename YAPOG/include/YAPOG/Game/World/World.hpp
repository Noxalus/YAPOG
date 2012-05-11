#ifndef YAPOG_WORLD_HPP
# define YAPOG_WORLD_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/IUpdateable.hpp"

namespace yap
{
  class Map;

  class World : public IUpdateable
  {
      DISALLOW_COPY(World);

    public:

      virtual ~World ();

      /// @name IUpdateable members.
      /// @{
      virtual void Update (const Time& dt);
      /// @}

    protected:

      World ();

      virtual void HandleUpdate (const Time& dt);
  };
} // namespace yap

#endif // YAPOG_WORLD_HPP
