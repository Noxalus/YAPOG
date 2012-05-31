#include <SFML/Graphics/Text.hpp>

#include "YAPOG/Graphics/Gui/MenuItem.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Gui/BorderWidget.hpp"

namespace yap
{
  MenuItem::MenuItem ()
    : label_ ("")
    , isScalable_ (false)
  {
    label_.SetPosition (GetPosition ());
  }

  MenuItem::MenuItem (bool isScalable)
    : label_ ("")
    , isScalable_ (isScalable)
  {
    label_.SetPosition (GetPosition ());
  }

  MenuItem::~MenuItem ()
  {
  }

  void MenuItem::Refresh ()
  {
    if (!isScalable_)
      label_.SetPosition (GetPosition ()
      + Vector2 (GetUserSize ().x / 2 - label_.GetSize ().x / 2 + 7,
      GetUserSize ().y / 2
      - label_.GetSize ().y / 2 + label_.GetCharHeight ()));
    else
    {
      label_.SetPosition (GetPosition () +
        ((border_ != nullptr) ? border_->GetSize () : Vector2 ()));
    }
    BaseWidget::Refresh ();
  }

  void MenuItem::Do ()
  {

  }

  String MenuItem::GetContent () const
  {
    return label_.GetText ();
  }

  void MenuItem::SetContent (String content)
  {
    label_.SetText (content);
    Refresh ();
  }

  bool MenuItem::IsFocusable () const
  {
    return false;
  }

  Vector2 MenuItem::HandleGetSize () const
  {
    Vector2 result;
    if (!isScalable_)
      result =  GetUserSize ()
      + ((border_ != nullptr) ? border_->GetSize () : Vector2 ());
    else
      result = label_.GetSize ()
      + ((border_ != nullptr) ? border_->GetSize () : Vector2 ());
    return result;
  }

  void MenuItem::HandleDraw (IDrawingContext& context)
  {
    label_.Draw (context);
  }

  void MenuItem::HandleShow (bool isVisible)
  {
  }

  void MenuItem::HandleMove (const Vector2& offset)
  {
    label_.Move (offset);
  }

  void MenuItem::HandleScale (const Vector2& factor)
  {
    label_.Scale (factor);
  }

  void MenuItem::HandleUpdate (const Time& dt)
  {
    label_.Update (dt);
  }

  void MenuItem::HandleChangeColor (const sf::Color& color)
  {
    label_.ChangeColor (color);
  }
} // namespace yap
