#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Content/ContentManager.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"

namespace yap
{
  Texture::Texture ()
    : spatialInfo_ ()
    , innerTexture_ (nullptr)
    , sprite_ ()
  {
  }

  Texture::Texture (const String& name)
    : spatialInfo_ ()
    , innerTexture_ (nullptr)
    , sprite_ ()
  {
    LoadFromFile (name);
  }

  Texture::Texture (const String& name, const sf::IntRect& rect)
    : spatialInfo_ ()
    , innerTexture_ (nullptr)
    , sprite_ ()
  {
    LoadFromFile (name);
    SetTextureRect (rect);
  }

  Texture::~Texture ()
  {
  }

  void Texture::LoadFromFile (const String& name)
  {
    innerTexture_ = &ContentManager::Instance ().LoadTexture (name);
    sprite_.SetTexture (*innerTexture_);

    spatialInfo_.SetSize (
      Vector2 (innerTexture_->GetWidth (),
               innerTexture_->GetHeight ()));
  }

  void Texture::SetTextureRect (const sf::IntRect& rect)
  {
    spatialInfo_.SetSize (Vector2 (rect.Width, rect.Height));

    sprite_.SetTextureRect (rect);
  }

  const Vector2& Texture::GetPosition () const
  {
    return spatialInfo_.GetPosition ();
  }

  const Vector2& Texture::GetSize () const
  {
    return spatialInfo_.GetSize ();
  }

  const Vector2& Texture::GetTopLeft () const
  {
    return spatialInfo_.GetTopLeft ();
  }

  const Vector2& Texture::GetBottomRight () const
  {
    return spatialInfo_.GetBottomRight ();
  }

  const Vector2& Texture::GetCenter () const
  {
    return spatialInfo_.GetCenter ();
  }

  const sf::FloatRect& Texture::GetRectangle () const
  {
    return spatialInfo_.GetRectangle ();
  }

  void Texture::Move (const Vector2& offset)
  {
    spatialInfo_.SetPosition (GetPosition () + offset);

    sprite_.SetPosition (GetPosition ());
  }

  void Texture::Scale (const Vector2& factor)
  {
    spatialInfo_.SetSize (
      Vector2 (
        GetSize ().x * factor.x,
        GetSize ().y * factor.y));

    sprite_.SetScale (factor);
  }

  void Texture::Draw (IDrawingContext& context)
  {
    context.Draw (sprite_);
  }
} // namespace yap
