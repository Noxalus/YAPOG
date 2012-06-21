#ifndef YAPOG_CLIENT_MAP_HPP
# define YAPOG_CLIENT_MAP_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Map.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"
# include "YAPOG/Graphics/Game/World/Map/IDrawableWorldObject.hpp"
# include "YAPOG/Graphics/Game/World/Map/IDrawableDynamicWorldObject.hpp"
# include "YAPOG/Graphics/Game/World/Map/TileLayerStack.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Collection/List.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/System/Network/PacketHandler.hpp"

namespace ycl
{
  class Player;

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

      Player& GetPlayer (const yap::ID& worldID);
      bool ContainsPlayer (const yap::ID& worldID);

      void AddPlayer (Player* player);
      void RemovePlayer (Player* player);
      void RemovePlayer (const yap::ID& worldID);

      template <typename T>
      void AddDrawableStaticObject (T* object);
      template <typename T>
      void RemoveDrawableStaticObject (T* object);

      template <typename T>
      void AddDrawableDynamicObject (T* object);
      void RemoveDrawableDynamicObject (const yap::ID& worldID);
      void ClearDynamicObjects ();

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

      virtual void HandleSetSize (yap::uint width, yap::uint height);
      virtual void HandleUpdate (const yap::Time& dt);

    private:

      void AddDrawableDynamicObject (
        const yap::ID& worldID,
        yap::IDrawableDynamicWorldObject* drawableObject);

      void AddDrawableObject (yap::IDrawableWorldObject* drawableObject);
      void RemoveDrawableObject (yap::IDrawableWorldObject* drawableObject);

      virtual bool SupportsEvents () const;

      void HandleServerInfoObjectMoveInfo (yap::IPacket& packet);
      void HandleServerInfoUpdateObjectState (yap::IPacket& packet);

      static const yap::String DRAW_ORDER_HANDLER_NAME;

      yap::TileLayerStack tileLayers_;

      yap::collection::List<yap::IDrawableWorldObject*> drawableObjects_;
      yap::collection::Map<
        yap::ID,
        yap::IDrawableDynamicWorldObject*> drawableDynamicObjects_;

      yap::collection::Map<yap::ID, Player*> players_;

      yap::PacketHandler packetHandler_;
  };
} // namespace ycl

# include "World/Map/Map.hxx"

#endif // YAPOG_CLIENT_MAP_HPP
