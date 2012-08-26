#ifndef YAPOG_CLIENT_OBJECTMOVEINFOHANDLER_HPP
# define YAPOG_CLIENT_OBJECTMOVEINFOHANDLER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/BaseDynamicWorldObjectVisitor.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  struct IPacket;

  class DynamicWorldObject;
} // namespace yap

namespace ycl
{
  class ObjectMoveInfoHandler
    : public yap::BaseDynamicWorldObjectVisitor
  {
      DISALLOW_COPY(ObjectMoveInfoHandler);

    public:

      explicit ObjectMoveInfoHandler (yap::IPacket& packet);

      virtual ~ObjectMoveInfoHandler ();

      virtual void VisitDynamicWorldObject (
        yap::DynamicWorldObject& visitable);

    private:

      yap::IPacket& packet_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_OBJECTMOVEINFOHANDLER_HPP
