#include "YAPOG/Graphics/Game/World/Map/DrawableWorldObjectOrderComparator.hpp"
#include "World/Map/Map.hpp"
#include "World/Map/Player.hpp"
#include "World/Map/MapElement.hpp"

namespace ycl
{
  const yap::String Map::DRAW_ORDER_HANDLER_NAME = "DrawOrder";

  Map::Map (const yap::ID& id)
    : yap::Map (id)
    , tileLayers_ ()
    , drawableObjects_ ()
    , packetHandler_ ()
  {
    ADD_HANDLER(ServerInfoObjectMoveInfo, Map::HandleServerInfoObjectMoveInfo);
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

  void Map::AddPlayer (Player* player)
  {
    player->AddRelay (this);

    player->OnMovedEvent ().AddHandler (
      DRAW_ORDER_HANDLER_NAME,
      [&] (yap::IDrawableDynamicWorldObject& sender,
           const yap::Vector2& args)
      {
        /// @todo Sort by adding manually.
        drawableObjects_.Sort<yap::DrawableWorldObjectOrderComparator> ();
      });

    AddDynamicObject (player);
    AddDrawableObject (player);
  }

  void Map::AddMapElement (MapElement* mapElement)
  {
    AddStaticObject (mapElement);
    AddDrawableObject (mapElement);
  }

  void Map::RemovePlayer (Player* player)
  {
    player->RemoveRelay (this);

    player->OnMovedEvent ().RemoveHandler (DRAW_ORDER_HANDLER_NAME);

    RemoveDrawableObject (player);
    RemoveDynamicObject (player);
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

  }
} // namespace ycl
