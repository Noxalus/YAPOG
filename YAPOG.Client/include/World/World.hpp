#ifndef YAPOG_CLIENT_WORLD_HPP
# define YAPOG_CLIENT_WORLD_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/World.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/Event/Event.hpp"

namespace ycl
{
  class Map;

  class World : public yap::World
              , public yap::IDrawable
  {
      DISALLOW_COPY(World);

    public:

      World ();
      virtual ~World ();

      void AddMap (const yap::ID& worldID, const yap::ID& id);

      void ChangeMap (const yap::ID& worldID);
      Map& GetCurrentMap ();

      /// @name IDrawable members.
      /// @{
      virtual void Draw (yap::IDrawingContext& context);

      virtual bool IsVisible () const;
      virtual void Show (bool isVisible);

      virtual void ChangeColor (const sf::Color& color);
      /// @}

      yap::Event<const World&, const yap::ChangeEventArgs<Map*>&> OnMapChanged;

    private:

      void AddMap (Map* map);

      virtual void HandleUpdate (const yap::Time& dt);

      virtual void HandleDraw (yap::IDrawingContext& context);

      virtual void HandleShow (bool isVisible);
      virtual void HandleChangeColor (const sf::Color& color);

      static const bool DEFAULT_VISIBLE_STATE;
      static const sf::Color DEFAULT_COLOR;

      bool isVisible_;
      sf::Color color_;

      yap::ID currentMapID_;
      Map* currentMap_;
      yap::collection::Map<yap::ID, Map*> maps_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_WORLD_HPP
