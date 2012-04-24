#include "YAPOG/Graphics/Gui/BaseWidget.hpp"

namespace yap
{
  const bool BaseWidget::DEFAULT_VISIBLE_STATE = true;
  const sf::Color BaseWidget::DEFAULT_COLOR = sf::Color ();

  BaseWidget::BaseWidget ()
    : spatialInfo_ ()
    , isVisible_ (DEFAULT_VISIBLE_STATE)
    , color_ (DEFAULT_COLOR)
    , drawables_ ()
    , eventHandlers_ ()
    , childen_ ()
    , root_ (nullptr)
    , parent_ (nullptr)
    , focusedChildren_ (nullptr)
    , padding_ ()
    , background_ (nullptr)
    , border_ (nullptr)
  {
  }

  BaseWidget::~BaseWidget ()
  {
  }

  const Vector2& BaseWidget::GetPosition () const
  {
    return spatialInfo_.GetPosition ();
  }

  const Vector2& BaseWidget::GetSize () const
  {
    spatialInfo_.SetSize (HandleGetSize ());

    return spatialInfo_.GetSize ();
  }

  const Vector2& BaseWidget::GetTopLeft () const
  {
    return spatialInfo_.GetTopLeft ();
  }

  const Vector2& BaseWidget::GetBottomRight () const
  {
    return spatialInfo_.GetBottomRight ();
  }

  const Vector2& BaseWidget::GetCenter () const
  {
    return spatialInfo_.GetCenter ();
  }

  const sf::FloatRect& BaseWidget::GetRectangle () const
  {
    return spatialInfo_.GetRectangle ();
  }

  void BaseWidget::Move (const Vector2& offset)
  {
    for (IWidget* child : childen_)
    {
      child->Move (offset);
    }
    spatialInfo_.SetPosition (GetPosition () + offset);
    OnMoved (*this, EventArgs (offset));
    HandleMove (offset);
  }

  void BaseWidget::Scale (const Vector2& factor)
  {
    for (IWidget* child : childen_)
    {
      child->Scale (factor);
    }

    spatialInfo_.SetSize (
      Vector2 (
      GetSize ().x * factor.x,
       GetSize ().y * factor.y));

    OnScaled (*this, EventArgs (factor));
    HandleScale (factor);
  }

  void BaseWidget::SetPosition (const Vector2& position)
  {
    for (IWidget* child : childen_)
    {
      child->SetPosition (position);
    }

    spatialInfo_.SetPosition (position);
    OnPositionSet (*this, EventArgs (position));

    //Move (position - GetPosition ());
  }

  void BaseWidget::SetSize (const Vector2& size)
  {
    for (IWidget* child : childen_)
    {
      child->SetSize (size);
    }

    Scale (
      Vector2 (
      size.x / GetSize ().x,
      size.y / GetSize ().y));
    OnSizeSet (*this, EventArgs (size));
  }

  void BaseWidget::Draw (IDrawingContext& context)
  {
    if (!isVisible_)
      return;

    for (IWidget* child : childen_)
    {
      child->Draw (context);
    }

    OnDraw (*this, EventArgsDraw (context));
    HandleDraw (context);
  }

  bool BaseWidget::IsVisible () const
  {
    return isVisible_;
  }

  void BaseWidget::Show (bool isVisible)
  {
    for (IWidget* child : childen_)
    {
      child->Show (isVisible);
    }

    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void BaseWidget::ChangeColor (const sf::Color& color)
  {
    for (IWidget* child : childen_)
    {
      child->ChangeColor (color);
    }

    color_ = color;
    OnColorChanged (*this, EventArgsColor (color));
    HandleChangeColor (color);
  }

  bool BaseWidget::OnEvent (const GuiEvent& guiEvent)
  {
    for (IWidget* child : childen_)
    {
      if (child->OnEvent (guiEvent))
        return true;
    }

    return HandleOnEvent (guiEvent);
  }

  bool BaseWidget::OnPriorityEvent (const GuiEvent& guiEvent)
  {
    for (IWidget* child : childen_)
    {
      if (child->OnPriorityEvent (guiEvent))
        return true;
    }

    return HandleOnPriorityEvent (guiEvent);
  }

  void BaseWidget::Update (const Time& dt)
  {
    for (IWidget* child : childen_)
    {
      child->Update (dt);
    }

    HandleUpdate (dt);
  }

  Vector2 BaseWidget::HandleGetSize () const
  {
    return spatialInfo_.GetSize ();
  }

  void BaseWidget::AddDrawable (IDrawable& drawable)
  {
    drawables_.Add (&drawable);
  }

  void BaseWidget::AddChild (IWidget& child)
  {
    childen_.Add (&child);

    OnChildAdded (*this, EventArgsIWidget (child));
  }

  IWidget& BaseWidget::GetRoot () const
  {
    return *root_;
  }

  void BaseWidget::SetParent (IWidget& parent)
  {
    parent_ = &parent;
  }

  void BaseWidget::SetPadding (Padding* padding)
  {
    padding_ = padding;
  }

  void BaseWidget::SetBackground (WidgetBackground& background)
  {
    background_= &background;
  }

  void BaseWidget::SetBorder (WidgetBorder& border)
  {
    border_ = &border;
  }

  bool BaseWidget::HandleOnEvent (const GuiEvent& guiEvent)
  {
    return false;
  }

  bool BaseWidget::HandleOnPriorityEvent (const GuiEvent& guiEvent)
  {
    return false;
  }
} // namespace yap
