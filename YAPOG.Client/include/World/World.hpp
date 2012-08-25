#ifndef YAPOG_CLIENT_WORLD_HPP
# define YAPOG_CLIENT_WORLD_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/World.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/Event/Event.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/System/Network/PacketHandler.hpp"

namespace yap
{
  struct IWorldDrawingPolicy;
} // namespace yap

namespace ycl
{
  class Map;

  class World : public yap::World
              , public yap::IDrawable
              , public yap::IPacketHandler
  {
      DISALLOW_COPY(World);

    public:

      World ();
      virtual ~World ();

      void AddMap (const yap::ID& worldID, const yap::ID& id);

      void ChangeMap (const yap::ID& worldID);
      Map& GetCurrentMap ();

      void SetDrawingPolicy (const yap::IWorldDrawingPolicy& drawingPolicy);

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

      /// @name Events.
      /// @{
      yap::Event<const World&, const yap::ChangeEventArgs<Map*>&> OnMapChanged;
      /// @}

      virtual void HandleUpdate (const yap::Time& dt);

      virtual void HandleDraw (yap::IDrawingContext& context);

      virtual void HandleShow (bool isVisible);
      virtual void HandleChangeColor (const sf::Color& color);

    private:

      void AddMap (Map* map);
      void RemoveMap (const yap::ID& worldID);

      static const bool DEFAULT_VISIBLE_STATE;
      static const sf::Color DEFAULT_COLOR;

      bool isVisible_;
      sf::Color color_;

      const yap::IWorldDrawingPolicy* drawingPolicy_;

      yap::ID currentMapID_;
      Map* currentMap_;
      yap::collection::Map<yap::ID, Map*> maps_;

      yap::PacketHandler packetHandler_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_WORLD_HPP
