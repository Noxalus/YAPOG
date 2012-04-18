#ifndef YAPOG_SPRITESET_HPP
# define YAPOG_SPRITESET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/Sprite/BaseSprite.hpp"
# include "YAPOG/Collection/Map.hpp"

namespace yap
{
  /// @brief Maps ISprite with keys.
  /// Represents an ISprite that changes of state over the time.
  template <typename K>
  class YAPOG_LIB SpriteSet : public BaseSprite
  {
      DISALLOW_COPY(SpriteSet);

    public:

      typedef K KeyType;

      SpriteSet ();
      virtual ~SpriteSet ();

      void AddSprite (const KeyType& key, ISprite* sprite);
      void RemoveSprite (const KeyType& key);

      void SetCurrentSprite (const KeyType& key);
      void SetDefaultKey (const KeyType& key);
      void SetDefaultSprite ();

    private:

      virtual Vector2 HandleGetSize () const;

      virtual void HandleMove (const Vector2& offset);
      virtual void HandleScale (const Vector2& factor);

      virtual void HandleDraw (IDrawingContext& context);

      virtual void HandleShow (bool isVisible);
      virtual void HandleChangeColor (const sf::Color& color);

      virtual void HandleUpdate (const Time& dt);

      KeyType currentKey_;
      KeyType defaultKey_;
      ISprite* currentSprite_;
      collection::Map<KeyType, ISprite*> sprites_;
  };
} // namespace yap

# include "YAPOG/Graphics/Game/Sprite/SpriteSet.hxx"

#endif // YAPOG_SPRITESET_HPP
