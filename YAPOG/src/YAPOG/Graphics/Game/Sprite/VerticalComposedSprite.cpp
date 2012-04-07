#include "YAPOG/Graphics/Game/Sprite/VerticalComposedSprite.hpp"
#include "YAPOG/System/MathHelper.hpp"

namespace yap
{
  VerticalComposedSprite::VerticalComposedSprite (
    ISprite* top,
    ISprite* bottom)
    : ComposedSprite ()
  {
    AddSprite (top);
    AddSprite (bottom);
  }

  VerticalComposedSprite::~VerticalComposedSprite ()
  {
  }

  Vector2 VerticalComposedSprite::HandleGetSize () const
  {
    return Vector2 (
      MathHelper::Max (
        GetSprite (0).GetSize ().x,
        GetSprite (1).GetSize ().x),
      GetSprite (0).GetSize ().y + GetSprite (1).GetSize ().y);
  }

  void VerticalComposedSprite::UpdatePosition ()
  {
    GetSprite (1).SetPosition (
      Vector2 (
        GetSprite (0).GetTopLeft ().x,
        GetSprite (0).GetBottomRight ().y));
  }
} // namespace yap
