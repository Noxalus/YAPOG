#ifndef YAPOG_TILELAYERSTACK_HPP
# define YAPOG_TILELAYERSTACK_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Collection/Map.hpp"

namespace yap
{
  class TileLayer;
  class TileLayoutHandler;

  class TileLayerStack : public IDrawable
                       , public IUpdateable
  {
      DISALLOW_COPY(TileLayerStack);

    public:

      TileLayerStack ();
      virtual ~TileLayerStack ();

      void SetSize (uint width, uint height);

      void AddTileLayer (uint height, TileLayoutHandler* layoutHandler);

      const TileLayer& GetTileLayer (uint height) const;
      TileLayer& GetTileLayer (uint height);

      /// @name IDrawable members.
      /// @{
      virtual void Draw (IDrawingContext& context);

      virtual bool IsVisible () const;
      virtual void Show (bool isVisible);

      virtual void ChangeColor (const sf::Color& color);
      /// @}

      /// @name IUpdateable members.
      /// @{
      virtual void Update (const Time& dt);
      /// @}

    private:

      static const uint DEFAULT_WIDTH;
      static const uint DEFAULT_HEIGHT;
      static const uint DEFAULT_MAX_HEIGHT;

      uint width_;
      uint height_;
      collection::Map<uint, TileLayer*> tileLayers_;
  };
} // namespace yap

#endif // YAPOG_TILELAYERSTACK_HPP
