#include "YAPOG/Graphics/Gui/LayoutBox.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/System/MathHelper.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"

namespace yap
{

  LayoutBox::LayoutBox ()
    : items_ ()
    , innerPad_ (0, 0, 0, 0)
    , externPad_ (0, 0, 0, 0)
    , realSize_ ()
    , focusedChild_ (0)
  {
  }

  void LayoutBox::Refresh ()
  {
    GeneratePosition ();
    BaseWidget::Refresh ();
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

  LayoutBox::LayoutBox (Padding ext, Padding in, bool isExt)
    : items_ ()
    , innerPad_ (in)
    , externPad_ (ext)
    , realSize_ ()
  {
    isExtensible_ = isExt;
  }

  LayoutBox::~LayoutBox ()
  {
  }

  Vector2 LayoutBox::HandleGetSize () const
  {
    if (isExtensible_)
      return realSize_ + ((border_ != nullptr) ? Vector2 (border_->GetWidth ()
      * 2, border_->GetWidth () * 2) : Vector2 ());

    return spatialInfo_.GetSize ();
  }

  void LayoutBox::AddChild (IWidget& child, Align align)
  {
    BaseWidget::AddChild (child);
    items_.Add (&child, align);

    GeneratePosition ();
  }

  bool LayoutBox::HandleOnPriorityEvent (const GuiEvent& guiEvent)
  {
    if (guiEvent.type == sf::Event::KeyPressed)
    {
      if (guiEvent.key.code == sf::Keyboard::Tab)
      {
        IEventHandler* child;
        uint cycle = focusedChild_;
        do
        {
          focusedChild_ = (focusedChild_ + 1) % items_.Count ();
          child = eventHandlers_[focusedChild_];
        } while (!dynamic_cast<BaseWidget*> (child)->IsFocusable () && focusedChild_ != cycle);

        eventHandlers_[focusedChild_] = eventHandlers_[0];
        eventHandlers_[0] = child;

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

      return MathHelper::Max (maxSizeItem + externPad_.left + externPad_.right
        , spatialInfo_.GetSize ().x);
    }
    else if (coord == 'y')
    {
      for (IWidget* item : childen_)
      {
        float currentSize = item->GetSize ().y;

        maxSizeItem = MathHelper::Max (maxSizeItem, currentSize);
      }

      return MathHelper::Max (maxSizeItem + externPad_.top + externPad_.bottom
        , spatialInfo_.GetSize ().y);
    }

    // Error
    return -42;
  }
} //namespace yap