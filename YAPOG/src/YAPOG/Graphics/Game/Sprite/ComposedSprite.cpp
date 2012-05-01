#include "YAPOG/Graphics/Game/Sprite/ComposedSprite.hpp"

namespace yap
{
  ComposedSprite::ComposedSprite ()
    : BaseSprite ()
    , sprites_ ()
  {
  }

  ComposedSprite::~ComposedSprite ()
  {
    for (const auto& it : sprites_)
      delete it;
  }

  void ComposedSprite::Init ()
  {
    UpdatePosition ();
  }

  void ComposedSprite::AddSprite (ISprite* sprite)
  {
    sprites_.Add (sprite);
  }

  ISprite& ComposedSprite::GetSprite (
    const collection::Array<ISprite*>::SizeType& index) const
  {
    return *sprites_[index];
  }

  void ComposedSprite::HandleMove (const Vector2& offset)
  {
    for (auto& it : sprites_)
      it->Move (offset);
  }

  void ComposedSprite::HandleScale (const Vector2& factor)
  {
    for (auto& it : sprites_)
      it->Scale (factor);

    UpdatePosition ();
  }

  void ComposedSprite::HandleDraw (IDrawingContext& context)
  {
    for (auto& it : sprites_)
      it->Draw (context);
  }

  void ComposedSprite::HandleShow (bool isVisible)
  {
  }

  void ComposedSprite::HandleChangeColor (const sf::Color& color)
  {
    for (auto& it : sprites_)
      it->ChangeColor (color);
  }

  void ComposedSprite::HandleUpdate (const Time& dt)
  {
    for (auto& it : sprites_)
      it->Update (dt);
  }
} // namespace yap
