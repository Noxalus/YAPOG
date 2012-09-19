#ifndef YAPOG_CLIENT_SERVERINFOREMOVEOBJECTVISITOR_HPP
# define YAPOG_CLIENT_SERVERINFOREMOVEOBJECTVISITOR_HPP

# include "YAPOG/Macros.hpp"

namespace ycl
{
  class ServerInfoRemoveObjectVisitor
    : public yap::IStaticWorldObjectConstVisitor
    , public yap::IDynamicWOrldObjectConstVisitor
  {
      DISALLOW_COPY(ServerInfoRemoveObjectVisitor);

    public:

      ServerInfoRemoveObjectVisitor (Map& map, yap::IPacket& packet);

      virtual ~ServerInfoRemoveObjectVisitor ();

      virtual void VisitStaticWorldObject (
        const yap::StaticWorldObject& visitable);
      virtual void VisitMapElement (const yap::MapElement& visitable);
  };
} // namespace ycl

#endif // YAPOG_CLIENT_SERVERINFOREMOVEOBJECTVISITOR_HPP
