#include "YAPOG/Graphics/Gui/ProgressBarWidget.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace yap
{
  ProgressBarWidget::ProgressBarWidget ()
    : width_ (0)
    , isScalable_ (true)
  {
  }

  ProgressBarWidget::~ProgressBarWidget ()
  {
  }
                                                                               
  void ProgressBarWidget::HandleDraw (IDrawingContext& context)
  {
  }

  void ProgressBarWidget::HandleShow (bool isVisible)
  {
  }

  void ProgressBarWidget::HandleMove (const Vector2& offset)
  {
  }

  void ProgressBarWidget::SetScalable (bool state)
  {
    isScalable_ = state;
  }

  void ProgressBarWidget::HandleScale (const Vector2& factor)
  {
  }

  void ProgressBarWidget::HandleUpdate (const Time& dt)
  {
  }

  void ProgressBarWidget::HandleChangeColor (const sf::Color& color)
  {
  }

  uint ProgressBarWidget::GetWidth () const
  {
    if (width_ > 0)
      return width_;
    else
    {
      //return GetTextureWidth ();
    }
  }
  Vector2 ProgressBarWidget::HandleGetSize () const
  {
    return Vector2();
  }
} //namespace yap
