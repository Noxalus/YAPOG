#ifndef YAPOG_CLIENT_MAP_HPP
# define YAPOG_CLIENT_MAP_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Map.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"
# include "YAPOG/Graphics/Game/World/Map/TileLayerStack.hpp"
# include "YAPOG/System/IntTypes.hpp"

namespace ycl
{
  class Map : public yap::Map
            , public yap::IDrawable
  {
      DISALLOW_ASSIGN(Map);

    public:

      Map (const yap::ID& id);
      virtual ~Map ();

      void AddTileLayer (
        yap::uint height,
        yap::TileLayoutHandler* tileLayoutHandler);

      /// @name ICloneable members.
      /// @{
      virtual Map* Clone () const;
      /// @}

      /// @name IDrawable members.
      /// @{
      virtual void Draw (yap::IDrawingContext& context);

      virtual bool IsVisible () const;
      virtual void Show (bool isVisible);

      virtual void ChangeColor (const sf::Color& color);
      /// @}

    protected:

      Map (const Map& copy);

    private:

      virtual void HandleSetSize (yap::uint width, yap::uint height);
      virtual void HandleUpdate (const yap::Time& dt);

      yap::TileLayerStack tileLayers_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_MAP_HPP
