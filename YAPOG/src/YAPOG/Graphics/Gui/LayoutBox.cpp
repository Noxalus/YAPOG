#include "YAPOG/Graphics/Gui/LayoutBox.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"

namespace yap
{

  LayoutBox::LayoutBox ()
    : items_ ()
    , innerPad_ (1, 1, 1, 1)
    , externPad_ (1, 1, 1, 1)
  {
  }

  LayoutBox::LayoutBox (Padding ext, Padding in)
    : items_ ()
    , innerPad_ (ext)
    , externPad_ (in)
  {
  }

  LayoutBox::~LayoutBox ()
  {
  }

  void LayoutBox::AddChild (IWidget& child, Align align)
  {
    BaseWidget::AddChild (child);
    items_.Add (&child, align);

    //GeneratePosition ();
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
} //namespace yap