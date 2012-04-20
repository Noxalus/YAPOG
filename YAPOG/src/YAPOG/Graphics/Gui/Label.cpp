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
  void Label::HandleDraw (IDrawingContext& context)
  {
    context.Draw (drawableText_);
  }

  String Label::GetText () const
  {
    return textContent_;
  }

  void Label::HandleMove (const Vector2& offset)
  {
    drawableText_.setPosition (offset);
  }

  void Label::HandleScale (const Vector2& factor)
  {
    drawableText_.setScale (factor);
  }


  void Label::SetText (String& content)
  {
    if (content.empty)
      return;
    else if (content.compare (textContent_))
      return;

    textContent_ = content;
    drawableText_.setString (content);

    OnTextChanged (*this, EventArgs (content));
  }

  void Label::HandleUpdate (const Time& dt)
  {
  }

  void Label::HandleChangeColor (const sf::Color& color)
  {
    drawableText_.setColor (color);
  }

} // namespace yap