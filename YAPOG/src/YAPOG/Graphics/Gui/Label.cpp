#include <SFML\Graphics\Text.hpp>

#include "YAPOG\Graphics\Gui\Label.hpp"
#include "YAPOG\Graphics\IDrawingContext.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"

namespace yap
{
  Label::Label ()
    : textContent_ ()
    , drawableText_ ()
  {
  }

  Label::Label (String content)
    : textContent_ (content)
    , drawableText_ (content)
  {
  }

  Label::~Label ()
  {
  }

  Vector2 Label::HandleGetSize () const
  {
    return Vector2 (padding_->left
      + drawableText_.getLocalBounds ().width
      + padding_->right,
      padding_->top
      + drawableText_.getLocalBounds ().height
      + padding_->bottom);
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
    drawableText_.move (offset);
    //drawableText_.setPosition (GetPosition() + offset);
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
    drawableText_.setPosition (Vector2 (GetPosition ().x + padding_->left,
      GetPosition ().y + padding_->top));
    OnTextChanged (*this, EventArgsString (content));
  }
} // namespace yap