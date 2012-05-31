#ifndef YAPOG_CLIENT_MAP_HPP
# define YAPOG_CLIENT_MAP_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Map.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"
# include "YAPOG/Graphics/Game/World/Map/IDrawableWorldObject.hpp"
# include "YAPOG/Graphics/Game/World/Map/TileLayerStack.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Collection/List.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/System/Network/PacketHandler.hpp"

namespace ycl
{
  class Player;
  class MapElement;

  class Map : public yap::Map
            , public yap::IDrawable
            , public yap::IPacketHandler
  {
      DISALLOW_COPY(Map);

    public:

      Map (const yap::ID& id);
      virtual ~Map ();

      void AddTileLayer (
        yap::uint height,
        yap::TileLayoutHandler* tileLayoutHandler);

      void AddPlayer (Player* player);
      void AddMapElement (MapElement* mapElement);

      void RemovePlayer (Player* player);
      void RemoveMapElement (MapElement* mapElement);

      /// @name IDrawable members.
      /// @{
      virtual void Draw (yap::IDrawingContext& context);

      virtual bool IsVisible () const;
      virtual void Show (bool isVisible);

      virtual void ChangeColor (const sf::Color& color);
      /// @}

      /// @name IPacketHandler members.
      /// @{
      virtual bool HandlePacket (yap::IPacket& packet);
      virtual bool SendPacket (yap::IPacket& packet);

      virtual void AddRelay (yap::IPacketHandler* relay);
      virtual void RemoveRelay (yap::IPacketHandler* relay);
      virtual void SetParent (yap::IPacketHandler* parent);
      /// @}

    protected:

      void AddDrawableObject (yap::IDrawableWorldObject* drawableObject);
      void RemoveDrawableObject (yap::IDrawableWorldObject* drawableObject);

      virtual void HandleSetSize (yap::uint width, yap::uint height);
      virtual void HandleUpdate (const yap::Time& dt);

    private:

      void HandleServerInfoObjectMoveInfo (yap::IPacket& packet);

      static const yap::String DRAW_ORDER_HANDLER_NAME;

      yap::TileLayerStack tileLayers_;

      yap::collection::List<yap::IDrawableWorldObject*> drawableObjects_;

      yap::PacketHandler packetHandler_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_MAP_HPP
