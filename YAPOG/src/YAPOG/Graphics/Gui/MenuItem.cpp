#include <SFML\Graphics\Text.hpp>

#include "YAPOG\Graphics\Gui\MenuItem.hpp"
#include "YAPOG\Graphics\IDrawingContext.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"

namespace yap
{
  MenuItem::MenuItem ()
    : label_ ("")
  {
    label_.SetPosition (GetPosition ());
  }

  MenuItem::~MenuItem ()
  {
  }

  void MenuItem::Refresh ()
  {
    label_.SetPosition (GetPosition ()
      + Vector2 (GetUserSize ().x / 2 - label_.GetSize ().x / 2 + 7,
      GetUserSize ().y / 2 - label_.GetSize ().y / 2));
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
    label_.SetPosition (GetPosition ()
      + Vector2 (GetUserSize ().x / 2 - label_.GetSize ().x / 2 + 7,
      GetUserSize ().y / 2 - label_.GetSize ().y / 2));
  }

  bool MenuItem::IsFocusable () const
  {
    return true;
  }

  Vector2 MenuItem::HandleGetSize () const
  {
    return GetUserSize ()
      + ((border_ != nullptr) ? Vector2 (border_->GetWidth ()
      * 2, border_->GetWidth () * 2) : Vector2 ());
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