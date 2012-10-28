#ifndef YAPOG_CLIENT_REMOVEOBJECTHANDLER_HPP
# define YAPOG_CLIENT_REMOVEOBJECTHANDLER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/BaseDynamicWorldObjectConstVisitor.hpp"
# include "YAPOG/Game/ID.hpp"

namespace ycl
{
  class Map;

  class RemoveObjectHandler : public yap::BaseDynamicWorldObjectConstVisitor
  {
      DISALLOW_COPY(RemoveObjectHandler);

    public:

      RemoveObjectHandler (const yap::ID& worldID, Map& map);

      virtual ~RemoveObjectHandler ();

      virtual void VisitPlayer (const yap::IPlayer& visitable);
      virtual void VisitNPC (const yap::INPC& visitable);
      virtual void VisitTeleporter (const yap::Teleporter& visitable);
      virtual void VisitDestructibleObject (
        const yap::DestructibleObject& visitable);
      virtual void VisitBattleSpawnerArea (
        const yap::BattleSpawnerArea& visitable);

    private:

      void RemoveDrawableDynamicObject (const yap::ID& worldID);

      const yap::ID& worldID_;
      Map& map_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_REMOVEOBJECTHANDLER_HPP
