#include "YAPOG/Graphics/Game/World/Map/DrawableWorldObjectOrderComparator.hpp"
#include "YAPOG/System/Network/IPacket.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"

#include "World/Map/Map.hpp"
#include "World/Map/Player.hpp"
#include "World/Map/NPC.hpp"
#include "World/Map/MapElement.hpp"

namespace ycl
{
  const yap::String Map::DRAW_ORDER_HANDLER_NAME = "DrawOrder";

  Map::Map (const yap::ID& id)
    : yap::Map (id)
    , tileLayers_ ()
    , drawableObjects_ ()
    , players_ ()
    , packetHandler_ ()
  {
    ADD_HANDLER(ServerInfoObjectMoveInfo, Map::HandleServerInfoObjectMoveInfo);
    ADD_HANDLER(
      ServerInfoUpdateObjectState,
      Map::HandleServerInfoUpdateObjectState);
    ADD_HANDLER(ServerInfoAddPlayer, Map::HandleServerInfoAddPlayer);
    ADD_HANDLER(ServerInfoRemovePlayer, Map::HandleServerInfoRemovePlayer);
  }

  Map::~Map ()
  {
  }

  void Map::AddTileLayer (
    yap::uint height,
    yap::TileLayoutHandler* tileLayoutHandler)
  {
    tileLayers_.AddTileLayer (height, tileLayoutHandler);
  }

  Player& Map::GetPlayer (const yap::ID& worldID)
  {
    return *players_[worldID];
  }

  void Map::AddPlayer (Player* player)
  {
    players_.Add (player->GetWorldID (), player);

    AddDynamicObject (player);
    AddDrawableDynamicObject (player);
  }

  void Map::AddNPC (NPC* npc)
  {
    AddDynamicObject (npc);
    AddDrawableDynamicObject (npc);
  }

  void Map::AddMapElement (MapElement* mapElement)
  {
    AddStaticObject (mapElement);
    AddDrawableObject (mapElement);
  }

  void Map::RemovePlayer (Player* player)
  {
    players_.Remove (player->GetWorldID ());

    player->OnMovedEvent ().RemoveHandler (DRAW_ORDER_HANDLER_NAME);

    RemoveDrawableObject (player);
    RemoveDynamicObject (player);
  }

  void Map::RemovePlayer (const yap::ID& worldID)
  {
    RemovePlayer (&GetPlayer (worldID));
  }

  void Map::HandleLoadObjects (yap::IPacket& packet)
  {
    yap::UInt64 playerCount = packet.ReadUInt64 ();
    for (yap::UInt64 count = 0; count < playerCount; ++count)
    {
      HandleServerInfoAddPlayer (packet);
    }
  }

  void Map::AddDrawableDynamicObject (
    yap::IDrawableDynamicWorldObject* drawableObject)
  {
    drawableObject->OnMovedEvent ().AddHandler (
      DRAW_ORDER_HANDLER_NAME,
      [&] (yap::IDrawableDynamicWorldObject& sender,
           const yap::Vector2& args)
      {
        /// @todo Sort by adding manually.
        drawableObjects_.Sort<yap::DrawableWorldObjectOrderComparator> ();
      });

    AddDrawableObject (drawableObject);
  }

  void Map::AddDrawableObject (yap::IDrawableWorldObject* drawableObject)
  {
    drawableObjects_.Add (drawableObject);
  }

  void Map::RemoveDrawableObject (yap::IDrawableWorldObject* drawableObject)
  {
    drawableObjects_.Remove (drawableObject);
  }

  void Map::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    tileLayers_.Draw (context);

    for (yap::IDrawableWorldObject* drawableObject : drawableObjects_)
      drawableObject->Draw (context);
  }

  bool Map::IsVisible () const
  {
    return true;
  }

  void Map::Show (bool isVisible)
  {
  }

  void Map::ChangeColor (const sf::Color& color)
  {
  }

  bool Map::HandlePacket (yap::IPacket& packet)
  {
    return packetHandler_.HandlePacket (packet);
  }

  bool Map::SendPacket (yap::IPacket& packet)
  {
    return packetHandler_.SendPacket (packet);
  }

  void Map::AddRelay (yap::IPacketHandler* relay)
  {
    packetHandler_.AddRelay (relay);
  }

  void Map::RemoveRelay (yap::IPacketHandler* relay)
  {
    packetHandler_.RemoveRelay (relay);
  }

  void Map::SetParent (yap::IPacketHandler* parent)
  {
    packetHandler_.SetParent (parent);
  }

  void Map::HandleSetSize (yap::uint width, yap::uint height)
  {
    yap::Map::HandleSetSize (width, height);

    tileLayers_.SetSize (width, height);
  }

  void Map::HandleUpdate (const yap::Time& dt)
  {
    yap::Map::HandleUpdate (dt);
  }

  void Map::HandleServerInfoObjectMoveInfo (yap::IPacket& packet)
  {
    yap::ID objectWorldID = packet.ReadID ();
    yap::Vector2 objectPosition = packet.ReadVector2 ();
    yap::Vector2 objectVelocity = packet.ReadVector2 ();

    yap::DynamicWorldObject& object = GetObject (objectWorldID);

    object.SetPosition (objectPosition);
    object.RawSetVelocity (objectVelocity);
  }

  void Map::HandleServerInfoUpdateObjectState (yap::IPacket& packet)
  {
    yap::ID objectWorldID = packet.ReadID ();
    yap::Vector2 objectPosition = packet.ReadVector2 ();
    yap::String objectState = packet.ReadString ();

    yap::DynamicWorldObject& object = GetObject (objectWorldID);

    object.SetPosition (objectPosition);
    object.RawSetState (objectState);
  }

  void Map::HandleServerInfoAddPlayer (yap::IPacket& packet)
  {
    yap::ID worldID = packet.ReadID ();
    yap::ID typeID = packet.ReadID ();
    yap::ID id = packet.ReadID ();

    Player* player = yap::ObjectFactory::Instance ().Create<Player> (
      typeID,
      id);
    player->SetWorldID (worldID);

    AddPlayer (player);

    player->SetPosition (packet.ReadVector2 ());
  }

  void Map::HandleServerInfoRemovePlayer (yap::IPacket& packet)
  {
    yap::ID worldID = packet.ReadID ();

    RemovePlayer (&GetPlayer (worldID));
  }
} // namespace ycl
