#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Content/ContentManager.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"

namespace yap
{
  const bool Texture::DEFAULT_VISIBLE_STATE = true;

  Texture::Texture ()
    : spatialInfo_ ()
    , innerTexture_ (nullptr)
    , sprite_ ()
    , isVisible_ (DEFAULT_VISIBLE_STATE)
  {
  }

  Texture::Texture (const String& name)
    : spatialInfo_ ()
    , innerTexture_ (nullptr)
    , sprite_ ()
    , isVisible_ (DEFAULT_VISIBLE_STATE)
  {
    LoadFromFile (name);
  }

  Texture::Texture (const String& name, const sf::IntRect& rect)
    : spatialInfo_ ()
    , innerTexture_ (nullptr)
    , sprite_ ()
    , isVisible_ (DEFAULT_VISIBLE_STATE)
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
    sprite_.setTexture (*innerTexture_);

    spatialInfo_.SetSize (Vector2FromVector2u (innerTexture_->getSize ()));
  }

  void Texture::SetTextureRect (const sf::IntRect& rect)
  {
    spatialInfo_.SetSize (Vector2 (rect.width, rect.height));

    sprite_.setTextureRect (rect);
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

    sprite_.move (offset);
  }

  void Texture::Scale (const Vector2& factor)
  {
    spatialInfo_.SetSize (
      Vector2 (
        GetSize ().x * factor.x,
        GetSize ().y * factor.y));

    sprite_.scale (factor);
  }

  void Texture::SetPosition (const Vector2& position)
  {
    Move (position - GetPosition ());
  }

  void Texture::SetSize (const Vector2& size)
  {
    Scale (
      Vector2 (
        size.x / GetSize ().x,
        size.y / GetSize ().y));
  }

  void Texture::Draw (IDrawingContext& context)
  {
    if (!isVisible_)
      return;

    context.Draw (sprite_);
  }

  bool Texture::IsVisible () const
  {
    return isVisible_;
  }

  void Texture::Show (bool isVisible)
  {
    isVisible_ = isVisible;
  }

  void Texture::ChangeColor (const sf::Color& color)
  {
    sprite_.setColor (color);
  }
} // namespace yap
