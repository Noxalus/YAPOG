#include "YAPOG/Graphics/Game/World/Map/DrawableWorldObjectOrderComparator.hpp"
#include "YAPOG/System/Network/IPacket.hpp"

#include "World/Map/Map.hpp"
#include "World/Map/Player.hpp"

namespace ycl
{
  const yap::String Map::DRAW_ORDER_HANDLER_NAME = "DrawOrder";

  Map::Map (const yap::ID& id)
    : yap::Map (id)
    , tileLayers_ ()
    , drawableObjects_ ()
    , drawableDynamicObjects_ ()
    , players_ ()
    , packetHandler_ ()
  {
    ADD_HANDLER(ServerInfoObjectMoveInfo, Map::HandleServerInfoObjectMoveInfo);
    ADD_HANDLER(
      ServerInfoUpdateObjectState,
      Map::HandleServerInfoUpdateObjectState);
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

  bool Map::ContainsPlayer (const yap::ID& worldID)
  {
    return players_.Contains (worldID);
  }

  void Map::AddPlayer (Player* player)
  {
    players_.Add (player->GetWorldID (), player);

    AddDrawableDynamicObject (player);
  }

  void Map::RemovePlayer (Player* player)
  {
    players_.Remove (player->GetWorldID ());

    RemoveDrawableDynamicObject (player);
  }

  void Map::RemovePlayer (const yap::ID& worldID)
  {
    RemovePlayer (&GetPlayer (worldID));
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

  void Map::AddDrawableObject (yap::IDrawableWorldObject* drawableObject)
  {
    drawableObjects_.Add (drawableObject);
  }

  void Map::RemoveDrawableObject (yap::IDrawableWorldObject* drawableObject)
  {
    drawableObjects_.Remove (drawableObject);
  }

  void Map::AddDrawableDynamicObject (
    const yap::ID& worldID,
    yap::IDrawableDynamicWorldObject* drawableObject)
  {
    AddDrawableObject (drawableObject);

    drawableDynamicObjects_.Add (worldID, drawableObject);
  }

  void Map::RemoveDrawableDynamicObject (const yap::ID& worldID)
  {
    RemoveDrawableObject (drawableDynamicObjects_[worldID]);

    drawableDynamicObjects_.Remove (worldID);
  }

  bool Map::SupportsEvents () const
  {
    return false;
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
} // namespace ycl
