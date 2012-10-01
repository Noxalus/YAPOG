#include "YAPOG/Graphics/Game/MoveController.hpp"
#include "YAPOG/Graphics/Vector2.hpp"
#include "YAPOG/Graphics/ISpatial.hpp"
#include "YAPOG/System/Time/Time.hpp"
#include "YAPOG/System/MathHelper.hpp"

namespace yap
{
  MoveController::MoveController (
    ISpatial& element, 
    const Vector2& startPosition, 
    const Vector2& endPosition,
    const Time& time)
    : element_ (element)
    , startPosition_ (startPosition)
    , endPosition_ (endPosition)
    , time_ (time)
    , elapsedTime_ ()
    , progression_ ()
  {
  }

  MoveController::~MoveController ()
  {
  }

  bool MoveController::Update (const yap::Time& dt)
  {
    if (startPosition_ == endPosition_)
      return true;

    elapsedTime_ += dt;

    progression_ = time_.GetValue () / elapsedTime_.GetValue ();

    if (progression_ >= 1.0f)
      progression_ = 1.0f;

    element_.SetPosition (
      MathHelper::Lerp (startPosition_, endPosition_, progression_));

    return false;
  }

} // namespace yap
