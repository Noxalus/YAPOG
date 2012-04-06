#ifndef YAPOG_SPRITESET_HPP
# define YAPOG_SPRITESET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"
# include "YAPOG/Collection/Map.hpp"

namespace yap
{
  /// @brief Maps ISprite with keys.
  /// Represents an ISprite that changes of state over the time.
  template <typename K>
  class SpriteSet : public ISprite
  {
      DISALLOW_COPY(SpriteSet);

    public:

      typedef K KeyType;

      virtual ~SpriteSet ();

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
      /// @}

      /// @name IDrawable members.
      /// @{
      virtual void Draw (IDrawingContext& context);

      virtual bool IsVisible () const;
      virtual void Show (bool isVisible);

      virtual void ChangeColor (const sf::Color color);
      /// @}

      /// @name IUpdateable members.
      /// @{
      virtual void Update (const Time& dt);
      /// @}

      void AddSprite (const KeyType& key, ISprite* sprite);
      void RemoveSprite (const KeyType& key);

      void SetCurrentSprite (const KeyType& key);

    private:

      KeyType currentKey_;
      ISprite* currentSprite_;
      collection::Map<KeyType, ISprite*> sprites_;
  };
} // namespace yap

#endif // YAPOG_SPRITESET_HPP
