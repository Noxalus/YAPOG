#include "YAPOG/Graphics/Gui/LayoutBox.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/System/MathHelper.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"

namespace yap
{
  LayoutBox::LayoutBox ()
    : items_ ()
    , focusables_ ()
    , innerPad_ (0, 0, 0, 0)
    , externPad_ (0, 0, 0, 0)
    , realSize_ ()
    , focusedChild_ (0)
  {
  }

  LayoutBox::LayoutBox (Padding ext, Padding in, bool isExt)
    : items_ ()
    , focusables_ ()
    , innerPad_ (in)
    , externPad_ (ext)
    , realSize_ ()
    , focusedChild_ (0)
  {
    isExtensible_ = isExt;
  }

  void LayoutBox::Refresh ()
  {
    GeneratePosition ();

    RefreshBorder ();
    BaseWidget::Refresh ();
  }

  void LayoutBox::Clear ()
  {
    items_.Clear ();
    focusables_.Clear ();

    drawables_.Clear ();
    childen_.Clear();    
    updatables_.Clear();
    eventHandlers_.Clear();
  }

  bool LayoutBox::IsFocusable () const
  {
    return true;
  }

  void LayoutBox::SetExtensible (bool isExt)
  {
    isExtensible_ = isExt;
  }

  bool LayoutBox::GetExtensible ()
  {
    return isExtensible_;
  }

  void LayoutBox::SetAlign (Align global)
  {
    globalAlign_ = global;
  }

  LayoutBox::Align LayoutBox::GetAlign ()
  {
    return globalAlign_;
  }

  LayoutBox::~LayoutBox ()
  {
  }

  Vector2 LayoutBox::HandleGetSize () const
  {
    if (isExtensible_)
      return realSize_ + ((border_ != nullptr) ? 
      border_->GetSize () : Vector2 ());

    return spatialInfo_.GetSize ();
  }

  const Padding& LayoutBox::GetInnerPadding () const
  {
    return innerPad_;
  }

  void LayoutBox::AddChild (IWidget& child, Align align)
  {
    BaseWidget::AddChild (child);
    items_.Add (&child, align);

    if (child.IsFocusable ())    
      focusables_.Add (&child);

    GeneratePosition ();
  }

  void LayoutBox::RemoveChild (IWidget& child)
  {
    BaseWidget::RemoveChild (child);
    items_.Remove (&child);

    if (child.IsFocusable ())
      focusables_.Remove (&child);

    GeneratePosition ();
  }

  bool LayoutBox::HandleOnPriorityEvent (const GuiEvent& guiEvent)
  {
    if (guiEvent.type == sf::Event::KeyPressed)
    {
      if (guiEvent.key.code == sf::Keyboard::Tab)
      {
        if (focusables_.Count () == 0 || !isFocused_)
          return false;

        IWidget* child;
        uint cycle = focusedChild_;

        // if current focussable is a layout, give it control for tab
        if (focusables_[cycle]->OnPriorityEvent (guiEvent))
          return true;
        focusedChild_ = (focusedChild_ + 1) % focusables_.Count ();

        //Performed a cycle, give control to the parent
        if (focusedChild_ == 0)
        {
          child = focusables_[focusedChild_];

          eventHandlers_.Remove (child);
          eventHandlers_.AddFront (child);
          isFocused_ = false;
          return false;
        }

        child = focusables_[focusedChild_];
        child->SetFocused (true);
        eventHandlers_.Remove (child);
        eventHandlers_.AddFront (child);

        return true;
      }
      return false;
    }
    return false;
  }

  void LayoutBox::HandleDraw (IDrawingContext& context)
  {
  }

  void LayoutBox::HandleShow (bool isVisible)
  {
  }

  void LayoutBox::HandleMove (const Vector2& offset)
  {
  }

  void LayoutBox::HandleScale (const Vector2& factor)
  {
  }

  void LayoutBox::HandleUpdate (const Time& dt)
  {
  }

  void LayoutBox::HandleChangeColor (const sf::Color& color)
  {
  }

  float LayoutBox::MaxSize (char coord)
  {
    float maxSizeItem = 0;

    if (coord == 'x')
    {
      for (IWidget* item : childen_)
      {
        float currentSize = item->GetSize ().x;

        maxSizeItem = MathHelper::Max (maxSizeItem, currentSize);
      }

      return MathHelper::Max (
        maxSizeItem + externPad_.left + externPad_.right,
        spatialInfo_.GetSize ().x);
    }
    else if (coord == 'y')
    {
      for (IWidget* item : childen_)
      {
        float currentSize = item->GetSize ().y;

        maxSizeItem = MathHelper::Max (maxSizeItem, currentSize);
      }

      return MathHelper::Max (
        maxSizeItem + externPad_.top + externPad_.bottom,
        spatialInfo_.GetSize ().y);
    }

    // Error
    return -42;
  }
} //namespace yap