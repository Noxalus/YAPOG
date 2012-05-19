#include "YAPOG/Game/World/Map/Physics/CharacterMoveController.hpp"

namespace yap
{
  const Direction CharacterMoveController::DEFAULT_LAST_DIRECTION =
    Direction::South;

  CharacterMoveController::CharacterMoveController ()
    : WorldObjectMoveController ()
    , directions_ ()
    , lastDirection_ (DEFAULT_LAST_DIRECTION)
  {
    directions_.Add (Direction::North, false);
    directions_.Add (Direction::East, false);
    directions_.Add (Direction::South, false);
    directions_.Add (Direction::West, false);
  }

  CharacterMoveController::~CharacterMoveController ()
  {
  }

  void CharacterMoveController::EnableDirection (Direction direction)
  {
    directions_[direction] = true;

    lastDirection_ = direction;

    Update ();
  }

  void CharacterMoveController::DisableDirection (Direction direction)
  {
    directions_[direction] = false;

    Update ();
  }

  void CharacterMoveController::Update ()
  {
    int enabledDirectionCount = 0;
    Direction currentDirection = lastDirection_;

    for (auto& it : directions_)
    {
      if (!it.second)
        continue;

      ++enabledDirectionCount;

      currentDirection = it.first;
    }

    if (enabledDirectionCount == 0)
    {
      force_ = Vector2 ();
      return;
    }

    if (enabledDirectionCount > 1)
      currentDirection = lastDirection_;

    switch (currentDirection)
    {
      case Direction::North: force_ = Vector2 (0.0f, -value_.y); break;
      case Direction::East: force_ = Vector2 (value_.x, 0.0f); break;
      case Direction::South: force_ = Vector2 (0.0f, value_.y); break;
      case Direction::West: force_ = Vector2 (-value_.x, 0.0f); break;
      default: break;
    }
  }
} // namespace yap
