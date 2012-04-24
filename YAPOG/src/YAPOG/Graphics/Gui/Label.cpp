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

  void Label::HandleDraw (IDrawingContext& context)
  {
    context.Draw (drawableText_);
  }

  void Label::HandleShow (bool isVisible)
  {
  }

  void Label::HandleMove (const Vector2& offset)
  {
    drawableText_.setPosition (GetPosition() + offset);
  }

  void Label::HandleScale (const Vector2& factor)
  {
    drawableText_.setScale (factor);
  }

  void Label::HandleUpdate (const Time& dt)
  {
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
    else if (content == textContent_)
      return;

    textContent_ = content;
    drawableText_.setString (content);
    OnTextChanged (*this, EventArgsString (content));
  }
} // namespace yap