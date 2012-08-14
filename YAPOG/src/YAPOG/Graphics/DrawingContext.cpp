#include "YAPOG/Graphics/DrawingContext.hpp"

namespace yap
{
  DrawingContext::DrawingContext (const Vector2& size, const String& name)
    : window_ (sf::VideoMode (size.x, size.y), name)
    , currentMode_ ()
    , defaultMode_ ()
    , cameras_ ()
  {
  }

  DrawingContext::~DrawingContext ()
  {
    for (const auto it : cameras_)
      delete it.second;
  }

  void DrawingContext::AddCamera (const CameraMode& mode, ICamera* camera)
  {
    bool isEmpty = cameras_.IsEmpty ();

    cameras_.Add (mode, camera);

    if (!isEmpty)
      return;

    SetCurrentMode (mode);
    defaultMode_ = mode;
  }

  void DrawingContext::RemoveCamera (const CameraMode& mode)
  {
    cameras_.Remove (mode);
  }

  const ICamera& DrawingContext::GetCamera () const
  {
    return GetCamera (currentMode_);
  }

  ICamera& DrawingContext::GetCamera ()
  {
    return GetCamera (currentMode_);
  }

  const ICamera& DrawingContext::GetCamera (const CameraMode& mode) const
  {
    return *cameras_[mode];
  }

  ICamera& DrawingContext::GetCamera (const CameraMode& mode)
  {
    return *cameras_[mode];
  }

  void DrawingContext::SetMode (const CameraMode& mode)
  {
    SetCurrentMode (mode);
  }

  void DrawingContext::SetDefaultMode (const CameraMode& mode)
  {
    defaultMode_ = mode;
  }

  void DrawingContext::SetDefaultCamera ()
  {
    SetCurrentMode (defaultMode_);
  }

  const sf::RenderTarget& DrawingContext::GetRenderTarget () const
  {
    return window_;
  }

  sf::RenderTarget& DrawingContext::GetRenderTarget ()
  {
    return window_;
  }

  void DrawingContext::Draw (const sf::Drawable& drawable)
  {
    Draw (drawable, sf::RenderStates::Default);
  }

  void DrawingContext::Draw (
    const sf::Drawable& drawable,
    const sf::RenderStates& states)
  {
    HandleDraw (drawable, states);
  }

  void DrawingContext::HandleDraw (
    const sf::Drawable& drawable,
    const sf::RenderStates& states)
  {
    GetRenderTarget ().draw (drawable, states);
  }

  void DrawingContext::SetCurrentMode (const CameraMode& mode)
  {
    currentMode_ = mode;

    GetRenderTarget ().setView (GetCamera ().GetInnerView ());
  }

  sf::RenderWindow& DrawingContext::GetWindow ()
  {
    return window_;
  }
} // namespace yap
