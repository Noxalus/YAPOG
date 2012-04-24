#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"

namespace yap
{
  WidgetBackground::WidgetBackground ()
    : background_ ()
  {
  }

  WidgetBackground::~WidgetBackground ()
  {
  }

  void WidgetBackground::HandleDraw (IDrawingContext& context)
  {
    background_.Draw (context);
  }

  void WidgetBackground::HandleShow (bool isVisible)
  {
  }

  void WidgetBackground::HandleMove (const Vector2& offset)
  {
    background_.SetPosition (GetPosition() + offset);
  }

  void WidgetBackground::HandleScale (const Vector2& factor)
  {
    Vector2 base = background_.GetSize ();
    Vector2 neo (base.x * factor.x, base.y * factor.y);

    background_.SetSize (neo);
  }

  void WidgetBackground::HandleUpdate (const Time& dt)
  {
  }

  void WidgetBackground::HandleChangeColor (const sf::Color& color)
  {
  }

  const Texture& WidgetBackground::GetBackground () const
  {
    return background_;
  }

  void WidgetBackground::SetBackground (String file)
  {
    background_.LoadFromFile (file);
    background_.SetSize (GetSize ());
    OnBackgroundSet (*this, EventArgsTexture (background_));
  }
} //namespace yap