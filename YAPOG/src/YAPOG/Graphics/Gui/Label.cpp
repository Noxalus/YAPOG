#include "YAPOG\Graphics\Gui\Label.hpp"
#include "YAPOG\Graphics\IDrawingContext.hpp"
#include <SFML\Graphics\Text.hpp>

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

  void Label::SetText (String& content)
  {
    if (content.empty)
      return;
    else if (content.compare (textContent_))
      return;

    textContent_ = content;
    drawableText_.setString (content);
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

} // namespace yap