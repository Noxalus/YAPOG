#include "YAPOG/Graphics/Gui/TextureManager.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"


namespace yap
{
  TextureManager::TextureManager (Texture& base, uint w, uint h)
    : spatialInfo_ ()
    , isEnable_ (true)
    , color_  (sf::Color ())
    , textures_ ()
    , isVisble_ (true)
    , width_ (w)
    , height_ (h)
    , baseTexture_ (&base)
  {
    base.SetPosition (GetPosition ());
  }

  void TextureManager::GetLimits (int& width, int& height)
  {
    Texture* base = baseTexture_;

    width = width_ / base->GetSize ().x;
    height = height_ / base->GetSize ().y;

    if (width == 0)
      width = 1;
    if (height == 0)
      height = 1;
  }

  void TextureManager::Init ()
  {
    Texture* base = baseTexture_;

    int widthIt = 0;
    int heightIt = 0;

    GetLimits (widthIt, heightIt);

    for (int i = 0; i < widthIt; i++)
    {
      for (int j = 0; j < heightIt; j++)
      {
        Texture* current = base->Clone ();
        textures_.Add (current);
      }
    }
    UpdatePosition ();
  }

  void TextureManager::UpdatePosition ()
  {
    Texture* base = baseTexture_;

    int widthIt = 0;
    int heightIt = 0;

    GetLimits (widthIt, heightIt);

    int currentWidth = GetPosition ().x;
    int currentHeight = GetPosition ().y;

    for (int i = 0; i < widthIt; i++)
    {
      for (int j = 0; j < heightIt; j++)
      {
        textures_[i * heightIt + j]->SetPosition (
          Vector2 (currentWidth, currentHeight));

        currentWidth += base->GetSize ().x;
      }
      currentHeight += base->GetSize ().y;
      currentWidth = GetPosition ().x;
    }
  }

  TextureManager::~TextureManager ()
  {
  }

  const Vector2& TextureManager::GetPosition () const
  {
    return spatialInfo_.GetPosition ();
  }

  const Vector2& TextureManager::GetSize () const
  {
    Vector2 size (width_, height_);

    spatialInfo_.SetSize (size);

    return spatialInfo_.GetSize ();
  }

  const Vector2& TextureManager::GetTopLeft () const
  {
    return spatialInfo_.GetTopLeft ();
  }

  const Vector2& TextureManager::GetBottomRight () const
  {
    return spatialInfo_.GetBottomRight ();
  }

  const Vector2& TextureManager::GetCenter () const
  {
    return spatialInfo_.GetCenter ();
  }

  const sf::FloatRect& TextureManager::GetRectangle () const
  {
    return spatialInfo_.GetRectangle ();
  }

  void TextureManager::Move (const Vector2& offset)
  {
    for (Texture* child : textures_)
    {
      child->Move (offset);
    }
    spatialInfo_.SetPosition (GetPosition () + offset);
  }

  void TextureManager::Scale (const Vector2& factor)
  {
    for (Texture* child : textures_)
      child->Scale (factor);

    UpdatePosition ();
    spatialInfo_.SetSize (
      Vector2 (
      GetSize ().x * factor.x,
      GetSize ().y * factor.y));
  }

  void TextureManager::SetPosition (const Vector2& position)
  {
    Move (position - GetPosition ());
  }

  void TextureManager::SetSize (const Vector2& size)
  {
    for (Texture* child : textures_)
    {
      child->SetSize (size);
    }

    Scale (
      Vector2 (
      size.x / GetSize ().x,
      size.y / GetSize ().y));
  }

  void TextureManager::Draw (IDrawingContext& context)
  {
    if (!isVisble_)
      return;

    for (Texture* child : textures_)
    {
      child->Draw (context);
    }
  }

  bool TextureManager::IsVisible () const
  {
    return isVisble_;
  }

  void TextureManager::Show (bool isVisible)
  {
    for (Texture* child : textures_)
    {
      child->Show (isVisible);
    }

    isVisble_ = isVisible;
  }

  void TextureManager::ChangeColor (const sf::Color& color)
  {
    for (Texture* child : textures_)
    {
      child->ChangeColor (color);
    }

    color_ = color;
  }

} //namespace yap