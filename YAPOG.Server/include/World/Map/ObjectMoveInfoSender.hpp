#ifndef YAPOG_SERVER_OBJECTMOVEINFOSENDER_HPP
# define YAPOG_SERVER_OBJECTMOVEINFOSENDER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/BaseDynamicWorldObjectConstVisitor.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  struct IPacket;

  class DynamicWorldObject;
} // namespace yap

namespace yse
{
  class ObjectMoveInfoSender
    : public yap::BaseDynamicWorldObjectConstVisitor
  {
      DISALLOW_COPY(ObjectMoveInfoSender);

    public:

      ObjectMoveInfoSender (
        yap::IPacket& packet,
        const yap::Vector2& objectVelocity);

      virtual ~ObjectMoveInfoSender ();

      virtual void VisitDynamicWorldObject (
        const yap::DynamicWorldObject& visitable);

    private:

      yap::IPacket& packet_;

      const yap::Vector2& objectVelocity_;
  };
} // namespace yse

#endif // YAPOG_SERVER_OBJECTMOVEINFOSENDER_HPP
