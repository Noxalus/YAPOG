#include <SFML/Graphics/Text.hpp>

#include "YAPOG/Graphics/Gui/Label.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Content/ContentManager.hpp"

namespace yap
{
  const String Label::DEFAULT_FONT = "pkmnemn.ttf";
  const UInt32 Label::DEFAULT_SIZE = 30;

  Label::Label ()
    : textContent_ ()
    , drawableText_ ()
    , isPosSet_ (false)
  {
    drawableText_.setFont 
      (ContentManager::Instance ().LoadFont (DEFAULT_FONT));
    drawableText_.setColor (userColor_);
  }

  Label::Label (String content)
    : textContent_ (content)
    , drawableText_ ()
    , isPosSet_ (false)
  {
    /*drawableText_.setPosition (Vector2 (GetPosition ().x + padding_.left,
    GetPosition ().y + padding_.top));*/
    drawableText_.setColor (userColor_);
    drawableText_.setPosition (GetPosition ().x,
      GetPosition ().y);

    drawableText_.setString (content);
    drawableText_.setFont (
      ContentManager::Instance ().LoadFont (DEFAULT_FONT));
    drawableText_.setCharacterSize (DEFAULT_SIZE);

    isPosSet_ = true;
  }

  Label::~Label ()
  {
  }

  bool Label::IsFocusable () const
  {
    return false;
  }

  float Label::GetCharWidth () const
  {
    return drawableText_.getCharacterSize () / 1.5;
  }

  Vector2 Label::CharPos (uint pos) const
  {
    return drawableText_.findCharacterPos (pos);
  }

  void Label::Refresh ()
  {
    drawableText_.setPosition (
      GetPosition ().x + padding_.left,
      GetPosition ().y + padding_.top);
    isPosSet_ = false;
  }

  void Label::SetDefaultColor (const sf::Color& color)
  {
    if (!isChangeColorCall_)
    {
      drawableText_.setColor (color);
      isChangeColorCall_ = true;
    }
  }
  uint Label::Length () const
  {
    return textContent_.length ();
  }

  uint Label::GetCharHeight () const
  {
    return drawableText_.getCharacterSize ();
  }

  Vector2 Label::HandleGetSize () const
  {
    if (userSize_ == Vector2 (0, 0))
      return Vector2 (padding_.left
      + drawableText_.getGlobalBounds ().width
      + padding_.right,
      padding_.top
      + /*drawableText_.getGlobalBounds ().height*/drawableText_.getCharacterSize ()
      + padding_.bottom)
      + ((border_ != nullptr) ? Vector2 (border_->GetWidth ()
      * 2, border_->GetWidth () * 2) : Vector2 ());
    else
      return GetUserSize ();
  }

  void Label::HandleDraw (IDrawingContext& context)
  {
    if (isVisible_)
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

  void Label::SetTextSize (uint size)
  {
    drawableText_.setCharacterSize (size);
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

  void Label::SetBackground (WidgetBackground& background)
  {
    background_= &background;
    background_->SetPosition (GetPosition ()/* + Vector2 (0,
                                            drawableText_.getGlobalBounds ().height
                                            - drawableText_.getCharacterSize ())*/);
    background_->SetBackground (GetSize ());
  }

  void Label::SetText (const String& content)
  {
    if (content == textContent_)
      return;

    if (!isChangeColorCall_)
      drawableText_.setColor (userColor_);
    textContent_ = content;
    drawableText_.setString (content);
    /*drawableText_.setPosition (Vector2 (GetPosition ().x + padding_.left,
    GetPosition ().y + padding_.top));*/

    if (isPosSet_)
    {
      drawableText_.setPosition (
        GetPosition ().x + padding_.left,
        GetPosition ().y + padding_.top);
      isPosSet_ = false;
    }

    OnTextChanged (*this, EventArgsString (content));
  }
} // namespace yap