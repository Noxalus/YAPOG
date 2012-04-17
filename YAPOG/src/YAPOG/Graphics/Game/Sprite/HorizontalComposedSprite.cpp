#include "YAPOG/Graphics/Game/Sprite/HorizontalComposedSprite.hpp"
#include "YAPOG/System/MathHelper.hpp"

namespace yap
{
  HorizontalComposedSprite::HorizontalComposedSprite (
    ISprite* left,
    ISprite* right)
    : ComposedSprite ()
  {
    AddSprite (left);
    AddSprite (right);
  }

  HorizontalComposedSprite::~HorizontalComposedSprite ()
  {
  }

  Vector2 HorizontalComposedSprite::HandleGetSize () const
  {
    return Vector2 (
      GetSprite (0).GetSize ().x + GetSprite (1).GetSize ().x,
      MathHelper::Max (
        GetSprite (0).GetSize ().y,
        GetSprite (1).GetSize ().y));
  }

  void HorizontalComposedSprite::UpdatePosition ()
  {
    GetSprite (1).SetPosition (
      Vector2 (
        GetSprite (0).GetBottomRight ().x,
        GetSprite (0).GetTopLeft ().y));
  }
} // namespace yap
