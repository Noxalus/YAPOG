#ifndef YAPOG_TILELAYER_HPP
# define YAPOG_TILELAYER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection.hpp"

namespace yap
{
  class TileLayer : public IDrawable,
                    public IUpdateable
  {
      DISALLOW_COPY(TileLayer);

    public:

      TileLayer (UInt32 width, UInt32 height);
      virtual ~TileLayer ();

      void SetLayoutHandler (TileLayoutHandler* layoutHandler);

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

      UInt32 width_;
      UInt32 height_;

      collection::Array<collection::Array<Tile*>> tiles_;

      TileLayoutHandler* layoutHandler_;
  };
} // namespace yap

#endif // YAPOG_TILELAYER_HPP
