#ifndef YAPOG_SERVER_SERVERINFOADDOBJECTVISITOR_HPP
# define YAPOG_SERVER_SERVERINFOADDOBJECTVISITOR_HPP

# include "YAPOG/Macros.hpp"

# include "YAPOG/Game/World/Map/BaseDynamicWorldObjectConstVisitor.hpp"

namespace yap
{
  struct IPacket;

  class DynamicWorldObject;
} // namespace yap

namespace yse
{
  class ServerInfoAddObjectVisitor
    : public yap::BaseDynamicWorldObjectConstVisitor
  {
      DISALLOW_COPY(ServerInfoAddObjectVisitor);

    public:

      explicit ServerInfoAddObjectVisitor (yap::IPacket& packet);
      virtual ~ServerInfoAddObjectVisitor ();

      virtual void VisitCharacter (const yap::Character& visitable);
      virtual void VisitPlayer (const yap::IPlayer& visitable);
      virtual void VisitTeleporter (const yap::Teleporter& visitable);
      virtual void VisitDestructibleObject (
        const yap::DestructibleObject& visitable);
      virtual void VisitBattleSpawnerArea (
        const yap::BattleSpawnerArea& visitable);

    private:

      void WriteAddObject (const yap::DynamicWorldObject& object);

      yap::IPacket& packet_;
  };
} // namespace yse

#endif // YAPOG_SERVER_SERVERINFOADDOBJECTVISITOR_HPP
