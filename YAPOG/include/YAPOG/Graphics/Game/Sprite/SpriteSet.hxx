#ifndef YAPOG_SPRITESET_HXX
# define YAPOG_SPRITESET_HXX

namespace yap
{
  template <typename K>
  inline SpriteSet<K>::SpriteSet ()
    : BaseSprite ()
    , currentKey_ ()
    , defaultKey_ ()
    , currentSprite_ (nullptr)
    , sprites_ ()
  {
  }

  template <typename K>
  inline SpriteSet<K>::~SpriteSet ()
  {
    for (const auto& it : sprites_)
      delete it.second;
  }

  template <typename K>
  inline void SpriteSet<K>::AddSprite (const KeyType& key, ISprite* sprite)
  {
    if (sprites_.IsEmpty ())
    {
      SetDefaultKey (key);
      SetDefaultSprite ();
    }

    sprites_.Add (key, sprite);
  }

  template <typename K>
  inline void SpriteSet<K>::RemoveSprite (const KeyType& key)
  {
    if (currentKey_ == key)
      SetDefaultSprite ();

    sprites_.Remove (key);
  }

  template <typename K>
  inline void SpriteSet<K>::SetCurrentSprite (const KeyType& key)
  {
    if (!sprites_.Contains (key))
      return;

    currentKey_ = key;
    currentSprite_ = sprites_[currentKey_];
  }

  template <typename K>
  inline void SpriteSet<K>::SetDefaultKey (const KeyType& key)
  {
    defaultKey_ = key;
  }

  template <typename K>
  inline void SpriteSet<K>::SetDefaultSprite ()
  {
    SetCurrentSprite (defaultKey_);
  }

  template <typename K>
  inline Vector2 SpriteSet<K>::HandleGetSize () const
  {
    return currentSprite_->GetSize ();
  }

  template <typename K>
  inline void SpriteSet<K>::HandleMove (const Vector2& offset)
  {
    for (const auto& it : sprites_)
      it.second->Move (offset);
  }

  template <typename K>
  inline void SpriteSet<K>::HandleScale (const Vector2& factor)
  {
    for (const auto& it : sprites_)
      it.second->Scale (factor);
  }

  template <typename K>
  inline void SpriteSet<K>::HandleDraw (IDrawingContext& context)
  {
    currentSprite_->Draw (context);
  }

  template <typename K>
  inline void SpriteSet<K>::HandleShow (bool isVisible)
  {
  }

  template <typename K>
  inline void SpriteSet<K>::HandleChangeColor (const sf::Color& color)
  {
    for (const auto& it : sprites_)
      it.second->ChangeColor (color);
  }

  template <typename K>
  inline void SpriteSet<K>::HandleUpdate (const Time& dt)
  {
    currentSprite_->Update (dt);
  }
} // namesapce yap

#endif // YAPOG_SPRITESET_HXX
