#include "YAPOG/Graphics/Game/Sprite/SquareComposedSprite.hpp"
#include "YAPOG/System/MathHelper.hpp"

namespace yap
{
  SquareComposedSprite::SquareComposedSprite (
    ISprite* topLeft,
    ISprite* topRight,
    ISprite* bottomLeft,
    ISprite* bottomRight)
    : ComposedSprite ()
  {
    AddSprite (topLeft);
    AddSprite (topRight);
    AddSprite (bottomLeft);
    AddSprite (bottomRight);
  }

  SquareComposedSprite::~SquareComposedSprite ()
  {
  }

  Vector2 SquareComposedSprite::HandleGetSize () const
  {
    return Vector2 (
      MathHelper::Max (
        GetSprite (0).GetSize ().x,
        GetSprite (2).GetSize ().x) +
      MathHelper::Max (
        GetSprite (1).GetSize ().x,
        GetSprite (3).GetSize ().x),
      MathHelper::Max (
        GetSprite (0).GetSize ().y,
        GetSprite (2).GetSize ().y) +
      MathHelper::Max (
        GetSprite (1).GetSize ().y,
        GetSprite (3).GetSize ().y));
  }

  void SquareComposedSprite::UpdatePosition ()
  {
    GetSprite (1).SetPosition (
      Vector2 (
        MathHelper::Max (
          GetSprite (0).GetBottomRight ().x,
          GetSprite (2).GetBottomRight ().x),
        GetSprite (0).GetTopLeft ().y));

    GetSprite (2).SetPosition (
      Vector2 (
        GetSprite (0).GetTopLeft ().x,
        MathHelper::Max (
          GetSprite (0).GetBottomRight ().y,
          GetSprite (1).GetBottomRight ().y)));

    GetSprite (3).SetPosition (
      Vector2 (
        MathHelper::Max (
          GetSprite (0).GetBottomRight ().x,
          GetSprite (2).GetBottomRight ().x),
        MathHelper::Max (
          GetSprite (0).GetBottomRight ().y,
          GetSprite (1).GetBottomRight ().y)));
  }
} // namespace yap
