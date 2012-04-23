#include <SFML\Graphics\Text.hpp>

#include "YAPOG\Graphics\Gui\Label.hpp"
#include "YAPOG\Graphics\IDrawingContext.hpp"

namespace yap
{
  Label::Label ()
    : textContent_ ()
    , drawableText_ ()
  {
  }

  Label::~Label ()
  {
  }

  void Label::HandleMove (const Vector2& offset)
  {
  }
  void Label::HandleScale (const Vector2& offset)
  {
  }

  void Label::HandleDraw (IDrawingContext& context)
  {
    context.Draw (drawableText_);
  }

  void Label::HandleShow (bool isVisible)
  {
  }

  bool Label::HandleOnEvent (const GuiEvent& guiEvent)
  {
    return true;
  }

  bool Label::HandleOnPriorityEvent (const GuiEvent& guiEvent)
  {
    return true;
  }

  void Label::HandleUpdate (const Time& dt)
  {
    for each (IWidget* child in childen_)
    {
      child->Update (dt);
    }
  }

  void Label::HandleChangeColor (const sf::Color& color)
  {
    drawableText_.setColor (color);
  }

  String Label::GetText () const
  {
    return textContent_;
  }

  void Label::SetText (String& content)
  {
    if (content.empty())
      return;
    else if (content.compare (textContent_))
      return;

    textContent_ = content;
    drawableText_.setString (content);
  }
} // namespace yap