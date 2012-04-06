#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"

namespace yap
{
  Sprite::Sprite ()
    : SpriteBase ()
    , texture_ ()
  {
  }

  Sprite::Sprite (const String& textureName)
    : SpriteBase ()
    , texture_ (textureName)
  {
  }

  Sprite::Sprite (const String& textureName, const sf::IntRect& textureRect)
    : SpriteBase ()
    , texture_ (textureName, textureRect)
  {
  }

  Sprite::~Sprite ()
  {
  }

  void Sprite::HandleMove (const Vector2& offset)
  {
    texture_.Move (offset);
  }

  void Sprite::HandleScale (const Vector2& factor)
  {
    texture_.Scale (factor);
  }

  void Sprite::HandleDraw (IDrawingContext& context)
  {
    texture_.Draw (context);
  }

  void Sprite::HandleShow (bool isVisible)
  {
  }

  void Sprite::HandleChangeColor (const sf::Color& color)
  {
    texture_.ChangeColor (color);
  }

  void Sprite::HandleUpdate (const Time& dt)
  {
  }
} // namespace yap
