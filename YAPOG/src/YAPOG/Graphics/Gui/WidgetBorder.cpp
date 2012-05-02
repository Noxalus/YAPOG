#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"

namespace yap
{
  WidgetBorder::WidgetBorder ()
    : border_ (nullptr)
    , file_ ("")
    , tmTop_ (nullptr)
    , tmBottom_ (nullptr)
    , tmRight_ (nullptr)
    , tmLeft_ (nullptr)
    , isInit (false)
    , width_ (0)
  {
  }

  WidgetBorder::WidgetBorder (String file)
    : border_ (nullptr)
    , file_ (file)
    , tmTop_ (nullptr)
    , tmBottom_ (nullptr)
    , tmRight_ (nullptr)
    , tmLeft_ (nullptr)
    , isInit (false)
    , width_ (0)
  {
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
    if (border_ != nullptr)
    {
      Vector2 base = border_->GetSize ();
      Vector2 neo (base.x * factor.x, base.y * factor.y);

      if (isInit)
      {
        tmTop_->SetSize (neo);
        tmBottom_->SetSize (neo);
        tmRight_->SetSize (neo);
        tmLeft_->SetSize (neo);
      }
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
    if (border_ != nullptr)
      return *border_;
    return Texture ();
  }

  uint WidgetBorder::GetWidth () const
  {
    return width_;
  }

  void WidgetBorder::SetBorder (Vector2 size, uint width)
  {
    width_ = 0;
    if (border_ != nullptr)
      delete border_;

    border_ = new Texture (file_);
    border_->SetPosition (GetPosition ());

    if (tmTop_ != nullptr)
      delete tmTop_;
    if (tmBottom_ != nullptr)
      delete tmBottom_;
    if (tmLeft_ != nullptr)
      delete tmLeft_;
    if (tmRight_ != nullptr)
      delete tmRight_;

    tmTop_ = new TextureManager (*border_, size.x + width, width);
    tmTop_->SetPosition (GetPosition () - Vector2 (0, width));
    tmTop_->Init ();

    tmBottom_ = new TextureManager (*border_, size.x + width * 2, width);
    tmBottom_->SetPosition (GetPosition () - Vector2 (width, -size.y));
    tmBottom_->Init ();

    tmLeft_ = new TextureManager (*border_, width,  size.y + width);
    tmLeft_->SetPosition (GetPosition () - Vector2 (width, width));
    tmLeft_->Init ();

    tmRight_ = new TextureManager (*border_, width, size.y + width);
    tmRight_->SetPosition (GetPosition () + Vector2 (size.x, 0));
    tmRight_->Init ();

    OnBorderSet (*this, EventArgsTexture (*border_));
    isInit = true;
    width_ = width;
  }
} //namespace yap