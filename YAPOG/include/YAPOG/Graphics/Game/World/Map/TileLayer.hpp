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

  class TileLayer : public IDrawable,
                    public IUpdateable
  {
      DISALLOW_COPY(TileLayer);

    public:

      TileLayer (UInt32 width, UInt32 height);
      virtual ~TileLayer ();

      const Tile& GetTile (UInt32 x, UInt32 y) const;
      Tile& GetTile (UInt32 x, UInt32 y);

      void SetTile (UInt32 x, UInt32 y, Tile* tile);

      void SetLayoutHandler (TileLayoutHandler* layoutHandler);
      void PerformLayout ();

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

      UInt32 width_;
      UInt32 height_;

      collection::Array<Tile*> tiles_;

      TileLayoutHandler* layoutHandler_;

      bool isVisible_;
      sf::Color color_;
  };
} // namespace yap

#endif // YAPOG_TILELAYER_HPP
