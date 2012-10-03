#include "YAPOG/Graphics/Game/MoveController.hpp"
#include "YAPOG/Graphics/ISpatial.hpp"
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
    , elapsedTime_ (0)
    , progression_ ()
  {
    Reset ();
  }

  MoveController::~MoveController ()
  {
  }

  ISpatial& MoveController::GetElement ()
  { return element_; }

  void MoveController::SetStartPosition (const yap::Vector2& value)
  { 
    startPosition_ = value;
    Reset ();
  }

  void MoveController::SetEndPosition (const yap::Vector2& value)
  {
    startPosition_ = element_.GetPosition ();
    endPosition_ = value;
    Reset ();
  }

  void MoveController::SetTime (const yap::Time& value)
  {
    time_ = value;
    Reset ();
  }

  bool MoveController::Update (const yap::Time& dt)
  {
    if (element_.GetPosition () == endPosition_)
      return true;

    elapsedTime_ += dt;

    progression_ = elapsedTime_.GetValue () / time_.GetValue ();

    if (progression_ >= 1.0f)
      progression_ = 1.0f;

    element_.SetPosition (
      MathHelper::Lerp (startPosition_, endPosition_, progression_));

    return false;
  }

  void MoveController::Reset ()
  {
    element_.SetPosition (startPosition_);
    elapsedTime_ = yap::Time (0);
  }

} // namespace yap
