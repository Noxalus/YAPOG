#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace yap
{
  WidgetBorder::WidgetBorder ()
    : border_ (nullptr)
    , file_ ("")
    , textures_ ()
    , tms_ ()
    , tmTop_ (nullptr)
    , tmBottom_ (nullptr)
    , tmLeft_ (nullptr)
    , tmRight_ (nullptr)
    , width_ (0)
    , isInit (false)
    , basic_ (false)
    , isScalable_ (true)
  {
  }

  bool WidgetBorder::IsFocusable () const
  {
    return false;
  }

  WidgetBorder::WidgetBorder (String file)
    : border_ (nullptr)
    , file_ (file)
    , textures_ ()
    , tms_ ()
    , tmTop_ (nullptr)
    , tmBottom_ (nullptr)
    , tmLeft_ (nullptr)
    , tmRight_ (nullptr)
    , width_ (0)
    , isInit (false)
    , basic_ (true)
    , isScalable_ (true)
  {
  }

  WidgetBorder::WidgetBorder (Texture& top,
    Texture& topRight,
    Texture& right,
    Texture& botRight,
    Texture& bot,
    Texture& botLeft,
    Texture& left,
    Texture& topLeft,
    bool isScalable)
    : border_ (nullptr)
    , file_ ("NoImage")
    , textures_ ()
    , tms_ ()
    , tmTop_ (nullptr)
    , tmBottom_ (nullptr)
    , tmLeft_ (nullptr)
    , tmRight_ (nullptr)
    , width_ (0)
    , isInit (false)
    , basic_ (false)
    , isScalable_ (isScalable)
  {
    textures_.Add (&top);
    textures_.Add (&topRight);
    textures_.Add (&right);
    textures_.Add (&botRight);
    textures_.Add (&bot);
    textures_.Add (&botLeft);
    textures_.Add (&left);
    textures_.Add (&topLeft);

    if (!isScalable_)
      for (int i = 0; i < 8; i++)
        tms_.Add (new TextureManager ());
  }


  WidgetBorder::~WidgetBorder ()
  {
  }

  void WidgetBorder::HandleDraw (IDrawingContext& context)
  {
    if (isInit && basic_ && !isScalable_)
    {
      tmTop_->Draw (context);
      tmBottom_->Draw (context);
      tmRight_->Draw (context);
      tmLeft_->Draw (context);
    }
    else if (isInit && !isScalable_)
      for (TextureManager* txtr : tms_)
        txtr->Draw (context);
    else if (isInit)
      for (Texture* txtr : textures_)
        txtr->Draw (context);
  }

  void WidgetBorder::HandleShow (bool isVisible)
  {
  }

  void WidgetBorder::HandleMove (const Vector2& offset)
  {
    if (isInit && basic_ && !isScalable_)
    {
      tmTop_->Move (offset);
      tmBottom_->Move (offset);
      tmRight_->Move (offset);
      tmLeft_->Move (offset);
    }
    else if (isInit && !isScalable_)
      for (TextureManager* txtr : tms_)
        txtr->Move (offset);
    else if (isInit)
      for (Texture* txtr : textures_)
        txtr->Move (offset);
  }

  void WidgetBorder::SetScalable (bool state)
  {
    isScalable_ = state;
  }
  void WidgetBorder::HandleScale (const Vector2& factor)
  {
    if (border_ != nullptr)
    {
      Vector2 base = border_->GetSize ();
      Vector2 neo (base.x * factor.x, base.y * factor.y);

      if (isInit && basic_ && !isScalable_)
      {
        tmTop_->SetSize (neo);
        tmBottom_->SetSize (neo);
        tmRight_->SetSize (neo);
        tmLeft_->SetSize (neo);
      }
      else if (isInit && !isScalable_)
        for (TextureManager* txtr : tms_)
          txtr->SetSize (neo);
      else if (isInit)
        for (Texture* txtr : textures_)
          txtr->Scale (neo);
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
    else if (textures_.Count () >= 1)
      return *textures_[0];

    YAPOG_THROW("No texture defined.");
  }

  uint WidgetBorder::GetWidth () const
  {
    if (width_ > 0)
      return width_;
    else
    {
      return GetTextureWidth ();
    }
  }
  Vector2 WidgetBorder::HandleGetSize () const
  {
    if (basic_)
    {
      return Vector2 (GetWidth () * 2, GetWidth () * 2);
    }
    else
    {
      uint x = 0;
      uint y = 0;

      if (textures_[0]->GetSize () != Vector2 (1, 1))
        y += textures_[0]->GetSize ().y;
      if (textures_[2]->GetSize () != Vector2 (1, 1))
        x += textures_[2]->GetSize ().x;
      if (textures_[4]->GetSize () != Vector2 (1, 1))
        y += textures_[4]->GetSize ().y;
      if (textures_[6]->GetSize () != Vector2 (1, 1))
        x += textures_[6]->GetSize ().x;

      return Vector2 (x, y);
    }
  }

  uint WidgetBorder::GetTextureWidth () const
  {
    uint maxWidth = 0;
    uint currentSize = 0;
    for (int i = 0; i < textures_.Count (); ++i)    
    {

      if (i == 0 || i == 4)
        currentSize = textures_[i]->GetSize ().y ;
      else
        currentSize = textures_[i]->GetSize ().x ;
      maxWidth = currentSize > maxWidth
        ? currentSize : maxWidth;
    }
    return maxWidth;
  }

  void WidgetBorder::SetBorder (Vector2 size)
  {
    if (basic_)
    {
      border_ = new Texture (file_);
      int width = border_->GetSize ().y;
      delete border_;

      return SetBorder (size, width);
    }
    else if (!isScalable_)
    {
      width_ = GetTextureWidth ();
      tms_[0] = new TextureManager (*textures_[0], size.x, width_);
      tms_[0]->SetPosition (GetPosition () - Vector2 (0, width_));
      tms_[0]->Init ();

      tms_[1] = new TextureManager (*textures_[1], width_, width_);
      tms_[1]->SetPosition (GetPosition () - Vector2 (-size.x, width_));
      tms_[1]->Init ();

      tms_[2] = new TextureManager (*textures_[2], width_, size.y);
      tms_[2]->SetPosition (GetPosition () + Vector2 (size.x , 0));
      tms_[2]->Init ();

      tms_[3] = new TextureManager (*textures_[3], width_, width_);
      tms_[3]->SetPosition (GetPosition () + Vector2 (size.x, size.y));
      tms_[3]->Init ();

      tms_[4] = new TextureManager (*textures_[4], size.x, width_);
      tms_[4]->SetPosition (GetPosition () + Vector2 (0, size.y));
      tms_[4]->Init ();

      tms_[5] = new TextureManager (*textures_[5], width_, width_);
      tms_[5]->SetPosition (GetPosition () - Vector2 (width_, -size.y));
      tms_[5]->Init ();

      tms_[6] = new TextureManager (*textures_[6], width_, size.y);
      tms_[6]->SetPosition (GetPosition () - Vector2 (width_, 0));
      tms_[6]->Init ();

      tms_[7] = new TextureManager (*textures_[7], width_, width_);
      tms_[7]->SetPosition (GetPosition () - Vector2 (width_, width_));
      tms_[7]->Init ();
    }
    else
    {
      width_ = GetTextureWidth ();
      textures_[0]->SetSize (Vector2 (size.x, width_));
      textures_[0]->SetPosition (GetPosition () - Vector2 (0, width_));

      textures_[1]->SetPosition (GetPosition () - Vector2 (-size.x, width_));

      textures_[2]->SetSize (Vector2 (width_, size.y));
      textures_[2]->SetPosition (GetPosition () + Vector2 (size.x , 0));

      textures_[3]->SetPosition (GetPosition () + Vector2 (size.x, size.y));

      textures_[4]->SetSize (Vector2 (size.x, width_));
      textures_[4]->SetPosition (GetPosition () + Vector2 (0, size.y));

      textures_[5]->SetPosition (GetPosition () - Vector2 (width_, -size.y));

      textures_[6]->SetSize (Vector2 ( width_, size.y));
      textures_[6]->SetPosition (GetPosition () - Vector2 (width_, 0));

      textures_[7]->SetPosition (GetPosition () - Vector2 (width_, width_));
    }

    OnBorderSet (*this, EventArgsTexture (*textures_[1]));
    isInit = true;
  }

  void WidgetBorder::SetBorder (Vector2 size, uint width)
  {
    if (!basic_)
      return;

    width_ = 0;

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

    if (isScalable_)
    {
      textures_.Clear ();
      Texture* top = new Texture (file_);
      top->SetSize (Vector2(size.x + width, width));
      top->SetPosition (GetPosition () - Vector2 (0, width));

      Texture* bottom = new Texture (file_);
      bottom->SetSize (Vector2(size.x + width * 2, width));
      bottom->SetPosition (GetPosition () - Vector2 (width, -size.y));

      Texture* left = new Texture (file_);
      left->SetSize (Vector2(width,  size.y + width));
      left->SetPosition (GetPosition () - Vector2 (width, width));

      Texture* right = new Texture (file_);
      right->SetSize (Vector2(width, size.y + width));
      right->SetPosition (GetPosition () + Vector2 (size.x, 0));

      textures_.Add (top);
      textures_.Add (bottom);
      textures_.Add (right);
      textures_.Add (left);

    }
    else
    {
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
    }

    OnBorderSet (*this, EventArgsTexture (*border_));
    isInit = true;
    width_ = width;
  }
} //namespace yap
