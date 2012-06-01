#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"

namespace yap
{
  Sprite::Sprite ()
    : BaseSprite ()
    , texture_ (nullptr)
  {
  }

  Sprite::Sprite (Texture* texture)
    : BaseSprite ()
    , texture_ (texture)
  {
  }

  Sprite::Sprite (const String& textureName)
    : BaseSprite ()
    , texture_ (new Texture (textureName))
  {
  }

  Sprite::Sprite (const String& textureName, const sf::IntRect& textureRect)
    : BaseSprite ()
    , texture_ (new Texture (textureName, textureRect))
  {
  }

  Sprite::~Sprite ()
  {
    delete texture_;
    texture_ = nullptr;
  }

  void Sprite::SetTexture (Texture* texture)
  {
    texture_ = texture;
  }

  Sprite* Sprite::Clone () const
  {
    return new Sprite (*this);
  }

  Sprite::Sprite (const Sprite& copy)
    : BaseSprite (copy)
    , texture_ (copy.texture_->Clone ())
  {
  }

  Vector2 Sprite::HandleGetSize () const
  {
    return texture_->GetSize ();
  }

  void Sprite::HandleMove (const Vector2& offset)
  {
    texture_->Move (offset);
  }

  void Sprite::HandleScale (const Vector2& factor)
  {
    texture_->Scale (factor);
  }

  void Sprite::HandleDraw (IDrawingContext& context)
  {
    texture_->Draw (context);
  }

  void Sprite::HandleShow (bool isVisible)
  {
  }

  void Sprite::HandleChangeColor (const sf::Color& color)
  {
    texture_->ChangeColor (color);
  }

  void Sprite::HandleUpdate (const Time& dt)
  {
  }
} // namespace yap
