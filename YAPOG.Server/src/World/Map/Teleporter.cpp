#include "World/Map/Teleporter.hpp"

namespace yse
{
  const yap::String Teleporter::OBJECT_FACTORY_TYPE_NAME = "Teleporter";

  Teleporter::Teleporter (const yap::ID& id)
    : yap::Teleporter (id)
  {
  }

  Teleporter::~Teleporter ()
  {
  }

  Teleporter::Teleporter (const Teleporter& copy)
    : yap::Teleporter (copy)
  {
  }

  Teleporter* Teleporter::Clone () const
  {
    return new Teleporter (*this);
  }

  void Teleporter::Init (
    const yap::ID& mapWorldID,
    const yap::Vector2& mapPoint,
    const yap::FloatRect& area)
  {
    SetMapWorldID (mapWorldID);
    SetMapPoint (mapPoint);

    SetArea (area);
  }

  const yap::String& Teleporter::GetObjectFactoryTypeName () const
  {
    return OBJECT_FACTORY_TYPE_NAME;
  }
} // namespace yse
