#include "YAPOG/Game/Factory/ObjectFactory.hpp"

#include "World/World.hpp"
#include "World/Map/Map.hpp"

namespace yse
{
  World::World ()
    : yap::World ()
    , maps_ ()
    , packetHandler_ ()
  {
  }

  World::~World ()
  {
  }

  void World::LoadMaps ()
  {
    /// @todo Add folder traversals algo into ContentManager.
    /// Add all maps.

    /// TMP
    for (yap::ID::ValueType it = 1; it <= 2; ++it)
    {
      Map* map = yap::ObjectFactory::Instance ().Get<Map> (
        "Map",
        yap::ID (it));

      map->SetWorldID (yap::ID (it));

      AddMap (map);
    }
  }

  bool World::HandlePacket (yap::IPacket& packet)
  {
    return packetHandler_.HandlePacket (packet);
  }

  bool World::SendPacket (yap::IPacket& packet)
  {
    bool success = true;

    for (auto& it : maps_)
      if (!it.second->SendPacket (packet))
        success = false;

    return success;
  }

  void World::AddRelay (yap::IPacketHandler* relay)
  {
    packetHandler_.AddRelay (relay);
  }

  void World::RemoveRelay (yap::IPacketHandler* relay)
  {
    packetHandler_.RemoveRelay (relay);
  }

  void World::SetParent (yap::IPacketHandler* parent)
  {
    packetHandler_.SetParent (parent);
  }

  void World::AddMap (Map* map)
  {
    map->AddRelay (this);

    maps_.Add (map->GetWorldID (), map);
  }

  void World::RemoveMap (const yap::ID& worldID)
  {
    GetMap (worldID).RemoveRelay (this);

    maps_.Remove (worldID);
  }

  Map& World::GetMap (const yap::ID& worldID)
  {
    return *maps_[worldID];
  }

  void World::HandleUpdate (const yap::Time& dt)
  {
    yap::World::HandleUpdate (dt);

    for (auto& it : maps_)
      it.second->Update (dt);
  }
} // namespace yse
