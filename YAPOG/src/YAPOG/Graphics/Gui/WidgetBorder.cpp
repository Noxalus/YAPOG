#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"

namespace yap
{
  WidgetBorder::WidgetBorder ()
    : border_ ()
    , tmTop_ (nullptr)
    , tmBottom_ (nullptr)
    , tmRight_ (nullptr)
    , tmLeft_ (nullptr)
    , isInit (false)
    , width_ (0)
  {
  }

  WidgetBorder::WidgetBorder (String file)
    : border_ ()
    , tmTop_ (nullptr)
    , tmBottom_ (nullptr)
    , tmRight_ (nullptr)
    , tmLeft_ (nullptr)
    , isInit (false)
    , width_ (0)
  {
    border_.LoadFromFile (file);
  }

  WidgetBorder::~WidgetBorder ()
  {
  }

  void WidgetBorder::HandleDraw (IDrawingContext& context)
  {
    if (isInit)
    {
      tmTop_->Draw (context);
      tmBottom_->Draw (context);
      tmRight_->Draw (context);
      tmLeft_->Draw (context);
    }
  }

  void WidgetBorder::HandleShow (bool isVisible)
  {
  }

  void WidgetBorder::HandleMove (const Vector2& offset)
  {
    if (isInit)
    {
      tmTop_->Move (offset);
      tmBottom_->Move (offset);
      tmRight_->Move (offset);
      tmLeft_->Move (offset);
    }
  }

  void WidgetBorder::HandleScale (const Vector2& factor)
  {
    Vector2 base = border_.GetSize ();
    Vector2 neo (base.x * factor.x, base.y * factor.y);

    if (isInit)
    {
      tmTop_->SetSize (neo);
      tmBottom_->SetSize (neo);
      tmRight_->SetSize (neo);
      tmLeft_->SetSize (neo);
    }
  }

  void WidgetBorder::HandleUpdate (const Time& dt)
  {
  }

  void WidgetBorder::HandleChangeColor (const sf::Color& color)
  {
  }

  const Texture& WidgetBorder::GetBorder () const
  {
    return border_;
  }

  uint WidgetBorder::GetWidth () const
  {
    return width_;
  }

  void WidgetBorder::SetBorder (Vector2 size, uint width)
  {
    border_.SetPosition (GetPosition ());

    tmTop_ = new TextureManager (border_, size.x + width, width);
    tmTop_->SetPosition (GetPosition () - Vector2 (0, width));
    tmTop_->Init ();

    tmBottom_ = new TextureManager (border_, size.x + width, width);
    tmBottom_->SetPosition (GetPosition () - Vector2 (width, -size.y));
    tmBottom_->Init ();
    
    tmLeft_ = new TextureManager (border_, width,  size.y + width);
    tmLeft_->SetPosition (GetPosition () - Vector2 (width, width));
    tmLeft_->Init ();
    
    tmRight_ = new TextureManager (border_, width, size.y + width);
    tmRight_->SetPosition (GetPosition () + Vector2 (size.x, 0));
    tmRight_->Init ();

    OnBorderSet (*this, EventArgsTexture (border_));
    isInit = true;
    width_ = width;
  }
} //namespace yap