#include "YAPOG/Game/World/Map/StaticWorldObject.hpp"
#include "YAPOG/Game/World/Map/IStaticWorldObjectVisitor.hpp"
#include "YAPOG/Game/World/Map/IStaticWorldObjectConstVisitor.hpp"

namespace yap
{
  StaticWorldObject::StaticWorldObject (const ID& id)
    : WorldObject (id)
  {
  }

  StaticWorldObject::~StaticWorldObject ()
  {
  }

  StaticWorldObject::StaticWorldObject (const StaticWorldObject& copy)
    : WorldObject (copy)
  {
  }

  void StaticWorldObject::Accept (IStaticWorldObjectVisitor& visitor)
  {
    visitor.VisitStaticWorldObject (*this);
  }

  void StaticWorldObject::Accept (
    IStaticWorldObjectConstVisitor& visitor) const
  {
    visitor.VisitStaticWorldObject (*this);
  }

  void StaticWorldObject::Update (const Time& dt)
  {
    HandleUpdate (dt);
  }

  void StaticWorldObject::HandleUpdate (const Time& dt)
  {
  }
} // namespace yap
