#ifndef YAPOG_TILE_HPP
# define YAPOG_TILE_HPP

# include <SFML/Graphics/Color.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Graphics/ISpatial.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/Graphics/SpatialInfo.hpp"

namespace yap
{
  struct ISprite;

  class TileFamily;

  class Tile : public ISpatial,
               public IDrawable,
               public IUpdateable
  {
      DISALLOW_COPY(Tile);

    public:

      static const UInt32 DEFAULT_SIZE;

      Tile (const ID& id);
      virtual ~Tile ();

      /// @name ISpatial members.
      /// @{
      virtual const Vector2& GetPosition () const;
      virtual const Vector2& GetSize () const;

      virtual const Vector2& GetTopLeft () const;
      virtual const Vector2& GetBottomRight () const;
      virtual const Vector2& GetCenter () const;

      virtual const sf::FloatRect& GetRectangle () const;

      virtual void Move (const Vector2& offset);
      virtual void Scale (const Vector2& factor);

      virtual void SetPosition (const Vector2& position);
      virtual void SetSize (const Vector2& size);
      /// @}

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

      ID id_;

      ISprite* sprite_;
      TileFamily* family_;

      SpatialInfo spatialInfo_;
      bool isVisible_;
      sf::Color color_;
  };
} // namespace yap

#endif // YAPOG_TILE_HPP
