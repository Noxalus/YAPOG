#include <SFML\Graphics\Text.hpp>

#include "YAPOG\Graphics\Gui\MenuItem.hpp"
#include "YAPOG\Graphics\IDrawingContext.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"

namespace yap
{
  MenuItem::MenuItem ()
  {
  }
  MenuItem::~MenuItem ()
  {
  }

  void MenuItem::Do ()
  {

  }

  Vector2 MenuItem::HandleGetSize () const
  {
    return GetUserSize ()
      + ((border_ != nullptr) ? Vector2 (border_->GetWidth ()
      * 2, border_->GetWidth () * 2) : Vector2 ());
  }

  void MenuItem::HandleDraw (IDrawingContext& context)
  {
  }

  void MenuItem::HandleShow (bool isVisible)
  {
  }

  void MenuItem::HandleMove (const Vector2& offset)
  {
  }

  void MenuItem::HandleScale (const Vector2& factor)
  {
  }

  void MenuItem::HandleUpdate (const Time& dt)
  {
  }

  void MenuItem::HandleChangeColor (const sf::Color& color)
  {

  }
} // namespace yap