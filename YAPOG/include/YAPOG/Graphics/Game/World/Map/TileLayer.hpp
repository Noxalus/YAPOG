#ifndef YAPOG_TILELAYER_HPP
# define YAPOG_TILELAYER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/Graphics/SpatialInfo.hpp"

namespace yap
{
  class TileLayoutHandler;
  class Tile;

  class TileLayer : public IDrawable
                  , public IUpdateable
  {
      DISALLOW_COPY(TileLayer);

    public:

      TileLayer (uint width, uint height);
      virtual ~TileLayer ();

      const Tile& GetTile (uint x, uint y) const;
      Tile& GetTile (uint x, uint y);

      void SetTile (uint x, uint y, Tile* tile);

      void SetLayoutHandler (TileLayoutHandler* layoutHandler);
      void PerformLayout ();

      const uint& GetWidth () const;
      const uint& GetHeight () const;

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

      static const bool DEFAULT_VISIBLE_STATE;
      static const sf::Color DEFAULT_COLOR;

      uint width_;
      uint height_;

      collection::Array<Tile*> tiles_;

      TileLayoutHandler* layoutHandler_;

      bool isVisible_;
      sf::Color color_;
  };
} // namespace yap

#endif // YAPOG_TILELAYER_HPP
