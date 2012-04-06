#include "YAPOG/Graphics/Gui/WidgetBase.hpp"

namespace yap
{
  const bool WidgetBase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color WidgetBase::DEFAULT_COLOR = sf::Color ();

  WidgetBase::WidgetBase ()
    : spatialInfo_ ()
    , isVisible_ (DEFAULT_VISIBLE_STATE)
    , color_ (DEFAULT_COLOR)
  {
  }

  WidgetBase::~WidgetBase ()
  {
  }

  const Vector2& WidgetBase::GetPosition () const
  {
    return spatialInfo_.GetPosition ();
  }

  const Vector2& WidgetBase::GetSize () const
  {
    return spatialInfo_.GetSize ();
  }

  const Vector2& WidgetBase::GetTopLeft () const
  {
    return spatialInfo_.GetTopLeft ();
  }

  const Vector2& WidgetBase::GetBottomRight () const
  {
    return spatialInfo_.GetBottomRight ();
  }

  const Vector2& WidgetBase::GetCenter () const
  {
    return spatialInfo_.GetCenter ();
  }

  const sf::FloatRect& WidgetBase::GetRectangle () const
  {
    return spatialInfo_.GetRectangle ();
  }

  void WidgetBase::Move (const Vector2& offset)
  {
    spatialInfo_.SetPosition (GetPosition () + offset);

    HandleMove (offset);
  }

  void WidgetBase::Scale (const Vector2& factor)
  {
    spatialInfo_.SetSize (
      Vector2 (
        GetSize ().x * factor.x,
        GetSize ().y * factor.y));

    HandleScale (factor);
  }

  void WidgetBase::SetPosition (const Vector2& position)
  {
    Move (position - GetPosition ());
  }

  void WidgetBase::SetSize (const Vector2& size)
  {
    Scale (
      Vector2 (
        size.x / GetSize ().x,
        size.y / GetSize ().y));
  }

  void WidgetBase::Draw (IDrawingContext& context)
  {
    if (!isVisible_)
      return;

    HandleDraw (context);
  }

  bool WidgetBase::IsVisible () const
  {
    return isVisible_;
  }

  void WidgetBase::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void WidgetBase::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  bool WidgetBase::OnEvent (const GuiEvent& guiEvent)
  {
    return HandleOnEvent (guiEvent);
  }

  void WidgetBase::Update (const Time& dt)
  {
    HandleUpdate (dt);
  }
} // namespace yap
