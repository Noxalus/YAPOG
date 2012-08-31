#include "YAPOG/Graphics/Gui/BaseWidget.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/System/IntTypes.hpp"

namespace yap
{
  const bool BaseWidget::DEFAULT_VISIBLE_STATE = true;
  const bool BaseWidget::DEFAULT_ENABLED_STATE = true;

  const sf::Color BaseWidget::DEFAULT_COLOR = sf::Color::Black;

  BaseWidget::BaseWidget ()
    : spatialInfo_ ()
    , isVisible_ (DEFAULT_VISIBLE_STATE)
    , isEnabled_ (DEFAULT_ENABLED_STATE)
    , color_ (DEFAULT_COLOR)
    , drawables_ ()
    , eventHandlers_ ()
    , childen_ ()
    , root_ (nullptr)
    , parent_ (nullptr)
    , padding_ ()
    , background_ (nullptr)
    , border_ (nullptr)
    , userSize_ (0, 0)
    , isExtensible_ (false)
    , isFocused_ (true)
    , userColor_ (DEFAULT_COLOR)
    , isChangeColorCall_ (false)
  {
  }

  BaseWidget::~BaseWidget ()
  {
  }

  WidgetBorder* BaseWidget::GetBorder () const
  {
    return border_;
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

    if (border_ != nullptr)
      border_->Move (offset);

    if (background_ != nullptr)
      background_->Move (offset);

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
    if (border_ != nullptr)
      border_->Scale (factor);
    if (background_ != nullptr)
      background_->Scale (factor);

    spatialInfo_.SetSize (
      Vector2 (
      GetSize ().x * factor.x,
      GetSize ().y * factor.y));

    OnScaled (*this, EventArgs (factor));
    HandleScale (factor);

    Refresh ();
  }

  void BaseWidget::SetPosition (const Vector2& position)
  {
    Move (position - GetPosition ());
  }

  void BaseWidget::UnsetBackground ()
  {
    background_ = nullptr;
  }
  void BaseWidget::UnsetBorder ()
  {
    border_ = nullptr;
  }

  void BaseWidget::SetSize (const Vector2& size)
  {
    userSize_ = size;
    Vector2 scaleFactor (size.x / GetSize ().x,
      size.y / GetSize ().y);

    for (IWidget* child : childen_)
    {
      child->SetSize (size);
    }
    if (border_ != nullptr)
      border_->SetSize (size);
    if (background_ != nullptr)
      background_->SetSize (size);

    spatialInfo_.SetSize (
      Vector2 (
      size.x,
      size.y));

    OnSizeSet (*this, EventArgs (size));
    HandleScale (scaleFactor);

    Refresh ();
  }

  void BaseWidget::Draw (IDrawingContext& context)
  {
    if (!isVisible_)
      return;
    if (background_ != nullptr)
      background_->Draw (context);
    if (border_ != nullptr)
      border_->Draw (context);

    OnDraw (*this, EventArgsDraw (context));
    HandleDraw (context);

    for (IDrawable* child : drawables_)
    {
      child->Draw (context);
    }
  }

  Vector2 BaseWidget::GetUserSize () const
  {
    return userSize_;
  }

  void BaseWidget::SetToTop()
  {
    if (parent_ == nullptr)
      return;

    parent_->RemoveChild (*this);
    parent_->FrontAddChild (*this);

    parent_->SetToTop ();
  }

  bool BaseWidget::IsVisible () const
  {
    return isVisible_;
  }

  void BaseWidget::SetFocused (bool state)
  {
    isFocused_ = state;
  }


  void BaseWidget::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void BaseWidget::ChangeColor (const sf::Color& color)
  {
    isChangeColorCall_ = true;
    for (IWidget* child : childen_)
    {
      child->ChangeColor (color);
    }
    if (border_ != nullptr)
      border_->ChangeColor (color);
    if (background_ != nullptr)
      background_->ChangeColor (color);

    color_ = color;
    OnColorChanged (*this, EventArgsColor (color));
    HandleChangeColor (color);
  }

  bool BaseWidget::OnEvent (const GuiEvent& guiEvent)
  {
    if (!isEnabled_)
      return false;

    for (IEventHandler* child : eventHandlers_)
    {
      if (child->OnEvent (guiEvent))
        return true;
    }
    if (border_ != nullptr)
      if (border_->OnEvent (guiEvent))
        return true;
    if (background_ != nullptr)
      if (background_->OnEvent (guiEvent))
        return true;

    return HandleOnEvent (guiEvent);
  }

  bool BaseWidget::OnPriorityEvent (const GuiEvent& guiEvent)
  {
    if (!isEnabled_)
      return false;

    if (HandleOnPriorityEvent (guiEvent))
      return true;

    for (IEventHandler* child : eventHandlers_)
    {
      if (child->OnPriorityEvent (guiEvent))
        return true;
    }
    if (border_ != nullptr)
      if (border_->OnPriorityEvent (guiEvent))
        return true;
    if (background_ != nullptr)
      if (background_->OnPriorityEvent (guiEvent))
        return true;

    return false;
  }

  void BaseWidget::SetDefaultColor (const sf::Color& color)
  {
    userColor_ = color;
  }

  void BaseWidget::Update (const Time& dt)
  {
    for (IWidget* child : childen_)
    {
      child->Update (dt);
    }
    if (border_ != nullptr)
      border_->Update (dt);
    if (background_ != nullptr)
      background_->Update (dt);

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
    child.SetDefaultColor (userColor_);
    childen_.Add (&child);
    AddDrawable (child);
    updatables_.Add (&child);
    eventHandlers_.Add (&child);

    //child.SetPosition (GetPosition ());
    child.SetParent (*this);
    OnChildAdded (*this, EventArgsIWidget (child));
  }

  void BaseWidget::FrontAddChild (IWidget& child)
  {
    child.SetParent (*this);

    child.SetDefaultColor (userColor_);

    childen_.AddFront (&child);
    drawables_.AddFront (&child);
    updatables_.AddFront (&child);
    eventHandlers_.AddFront (&child);

    OnChildAdded (*this, EventArgsIWidget (child));
  }

  void BaseWidget::RemoveChild (IWidget& child)
  {
    childen_.Remove (&child);
    drawables_.Remove (&child);
    updatables_.Remove (&child);
    eventHandlers_.Remove (&child);
  }

  IWidget& BaseWidget::GetRoot () const
  {
    return *root_;
  }

  void BaseWidget::SetParent (IWidget& parent)
  {
    parent_ = &parent;
    root_ = &parent.GetRoot ();
  }

  void BaseWidget::SetPadding (const Padding& padding)
  {
    padding_ = padding;
    Refresh ();
  }

  void BaseWidget::Refresh ()
  {
    if (parent_ != nullptr)
      parent_->Refresh ();
  }

  void BaseWidget::SetBackground (WidgetBackground& background)
  {
    background_= &background;
    background_->SetPosition (GetPosition ());
    if (background_->GetFixed ())
      SetSize (background_->GetSize ());
    background_->SetBackground (GetSize ());
  }


  void BaseWidget::SetPosAfterBorder (uint width, uint height, bool refreshing)
  {
    if (spatialInfo_.GetPosition ().x > width)
      spatialInfo_.SetPosition (GetPosition () - Vector2 (width, 0));
    else
    {
      Move (Vector2 (width - GetPosition ().x, 0));
      spatialInfo_.SetPosition (GetPosition () - Vector2 (width/2, 0));
    }
    if (spatialInfo_.GetPosition ().y > height)
      spatialInfo_.SetPosition (GetPosition () - Vector2 (0, height));
    else
    {
      Move (Vector2 (0, height - GetPosition ().y));
      spatialInfo_.SetPosition (GetPosition () - Vector2 (0, height/2));
    }
    if (refreshing)
      Refresh ();
  }

  void BaseWidget::SetBorder (WidgetBorder& border, uint width)
  {
    border_ = &border;
    border_->SetPosition (GetPosition ());
    if (isExtensible_ || GetUserSize () == Vector2 (0, 0))
      border_->SetBorder (GetSize (), width);
    else
      border_->SetBorder (GetUserSize (), width);

    uint paddingBorder = border.GetTexture ().GetSize ().y > 0
      ? border.GetTexture ().GetSize ().y : border.GetTexture ().GetSize ().x;
    if (border.GetTexture ().GetSize ().y == 0)
      SetPosAfterBorder (paddingBorder, 0, true);
    else
      SetPosAfterBorder (paddingBorder, paddingBorder, true);
  }

  void BaseWidget::RefreshBorder ()
  {
    if (border_ == nullptr)
      return;

    border_->SetPosition (GetPosition ());
    if (isExtensible_ || GetUserSize () == Vector2 (0, 0))
      border_->SetBorder (GetSize ());
    else
      border_->SetBorder (GetUserSize ());
    uint paddingBorder = border_->GetSize ().y > 0
      ? border_->GetSize ().y : border_->GetSize ().x;
    /*  if (border_->GetSize ().y == 0)
    SetPosAfterBorder (paddingBorder, 0, false);
    else
    SetPosAfterBorder (paddingBorder, paddingBorder, false);*/
  }
  void BaseWidget::SetBorder (WidgetBorder& border)
  {

    border.SetPosition (GetPosition ());
    if (isExtensible_ || GetUserSize () == Vector2 (0, 0))
      border.SetBorder (GetSize ());
    else
      border.SetBorder (GetUserSize ());
    border_ = &border;
    uint paddingBorder = border.GetSize ().y > 0
      ? border.GetSize ().y : border.GetSize ().x;
    if (border.GetSize ().y == 0)
      SetPosAfterBorder (paddingBorder, 0, true);
    else
      SetPosAfterBorder (paddingBorder, paddingBorder, true);
  }

  bool BaseWidget::HandleOnEvent (const GuiEvent& guiEvent)
  {
    return false;
  }

  bool BaseWidget::HandleOnPriorityEvent (const GuiEvent& guiEvent)
  {
    return false;
  }

  void BaseWidget::SetEnable (bool enable)
  {
    isEnabled_ = enable;
  }

  void BaseWidget::Open ()
  {
    SetEnable (true);
    Show (true);
  }

  void BaseWidget::Close ()
  {
    SetEnable (false);
    Show (false);
  }

  void BaseWidget::HandleMove (const Vector2& offset)
  {
  }

  void BaseWidget::HandleScale (const Vector2& factor)
  {
  }

  void BaseWidget::HandleDraw (IDrawingContext& context)
  {
  }

  void BaseWidget::HandleShow (bool isVisible)
  {
  }

  void BaseWidget::HandleChangeColor (const sf::Color& color)
  {
  }

  void BaseWidget::HandleUpdate (const Time& dt)
  {
  }
} // namespace yap
