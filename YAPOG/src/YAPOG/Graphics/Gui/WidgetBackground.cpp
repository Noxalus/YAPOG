#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"

namespace yap
{
  WidgetBackground::WidgetBackground ()
    : background_ ()
    , tm_ (nullptr)
    , resize_ (true)
    , isInit (false)
    , fixed_ (false)
  {
  }

  WidgetBackground::WidgetBackground (String file, bool resize)
    : background_ ()
    , tm_ (nullptr)
    , resize_ (resize)
    , isInit (false)
    , fixed_ (false)
  {
    background_.LoadFromFile (file);
  }

  bool WidgetBackground::IsFocusable () const
  {
    return false;
  }

  Vector2 WidgetBackground::HandleGetSize () const
  {    
    return background_.GetSize ();
  }
  void WidgetBackground::SetFixed (bool state)
  {
    fixed_ = state;
  }


  WidgetBackground::~WidgetBackground ()
  {
  }

  void WidgetBackground::HandleDraw (IDrawingContext& context)
  {
    if (isInit)
    {
      if (resize_)
        background_.Draw (context);
      else
        tm_->Draw (context);
    }
  }

  void WidgetBackground::HandleShow (bool isVisible)
  {
  }

  void WidgetBackground::HandleMove (const Vector2& offset)
  {
    if (isInit)
    {
      if (resize_)
        background_.Move (offset);
      else
        tm_->Move (offset);
    }
  }

  void WidgetBackground::HandleScale (const Vector2& factor)
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

  void WidgetBackground::HandleUpdate (const Time& dt)
  {
  }

  void WidgetBackground::HandleChangeColor (const sf::Color& color)
  {
    if (isInit)
    {
      if (resize_)
        background_.ChangeColor (color);
      else
        tm_->ChangeColor (color);
    }
  }

  bool WidgetBackground::GetFixed () const
  {
    return fixed_;
  }

  const Texture& WidgetBackground::GetBackground () const
  {
    return background_;
  }

  void WidgetBackground::SetBackground (Vector2 size)
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

  void WidgetBackground::SetBackground (String file
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
