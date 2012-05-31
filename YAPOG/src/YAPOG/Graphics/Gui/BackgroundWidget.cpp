#include "YAPOG/Graphics/Gui/BackgroundWidget.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"

namespace yap
{
  BackgroundWidget::BackgroundWidget ()
    : background_ ()
    , tm_ (nullptr)
    , resize_ (true)
    , isInit (false)
    , fixed_ (false)
  {
  }

  bool BackgroundWidget::IsFocusable () const
  {
    return false;
  }

  Vector2 BackgroundWidget::HandleGetSize () const
  {    
      return background_.GetSize ();
  }
  void BackgroundWidget::SetFixed (bool state)
  {
    fixed_ = state;
  }
  BackgroundWidget::BackgroundWidget (String file, bool resize)
    : background_ ()
    , tm_ (nullptr)
    , resize_ (resize)
    , isInit (false)
  {
    background_.LoadFromFile (file);
  }

  BackgroundWidget::~BackgroundWidget ()
  {
  }

  void BackgroundWidget::HandleDraw (IDrawingContext& context)
  {
    if (isInit)
    {
      if (resize_)
        background_.Draw (context);
      else
        tm_->Draw (context);
    }
  }

  void BackgroundWidget::HandleShow (bool isVisible)
  {
  }

  void BackgroundWidget::HandleMove (const Vector2& offset)
  {
    if (isInit)
    {
      if (resize_)
        background_.Move (offset);
      else
        tm_->Move (offset);
    }
  }

  void BackgroundWidget::HandleScale (const Vector2& factor)
  {
    Vector2 base = background_.GetSize ();
    Vector2 neo (base.x * factor.x, base.y * factor.y);

    if (isInit)
    {
      if (resize_)
        background_.SetSize (neo);
      else
        tm_->SetSize (neo);
    }
  }

  void BackgroundWidget::HandleUpdate (const Time& dt)
  {
  }

  void BackgroundWidget::HandleChangeColor (const sf::Color& color)
  {
  }

  bool BackgroundWidget::GetFixed () const
  {
    return fixed_;
  }

  const Texture& BackgroundWidget::GetBackground () const
  {
    return background_;
  }

  void BackgroundWidget::SetBackground (Vector2 size)
  {
    background_.SetPosition (GetPosition ());
    if (resize_)
      background_.SetSize (size);
    else
    {
      tm_ = new TextureManager (background_, size.x, size.y);
      tm_->SetPosition (GetPosition ());
      tm_->Init ();
    }
    OnBackgroundSet (*this, EventArgsTexture (background_));
    isInit = true;
  }

  void BackgroundWidget::SetBackground (String file
    , uint width
    , uint height
    , bool resize)
  {
    resize_ = resize;
    background_.LoadFromFile (file);
    background_.SetPosition (GetPosition ());
    if (resize)
      background_.SetSize (Vector2 (width, height));
    else
    {
      tm_ = new TextureManager (background_, width, height);
      tm_->SetPosition (GetPosition ());
      tm_->Init ();
    }
    OnBackgroundSet (*this, EventArgsTexture (background_));
    isInit = true;
  }
} //namespace yap
