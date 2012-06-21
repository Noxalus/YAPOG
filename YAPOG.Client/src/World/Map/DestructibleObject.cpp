#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"

#include "World/Map/DestructibleObject.hpp"

namespace ycl
{
  const bool DestructibleObject::DEFAULT_VISIBLE_STATE = true;
  const sf::Color DestructibleObject::DEFAULT_COLOR = sf::Color ();

  const yap::String DestructibleObject::OBJECT_FACTORY_TYPE_NAME =
    "DestructibleObject";

  DestructibleObject::DestructibleObject (const yap::ID& id)
    : yap::DestructibleObject (id)
    , isVisible_ (DEFAULT_VISIBLE_STATE)
    , color_ (DEFAULT_COLOR)
    , sprite_ (nullptr)
  {
  }

  DestructibleObject::~DestructibleObject ()
  {
  }

  DestructibleObject::DestructibleObject (const DestructibleObject& copy)
    : yap::DestructibleObject (copy)
    , isVisible_ (copy.isVisible_)
    , color_ (copy.color_)
    , sprite_ (nullptr)
  {
    if (copy.sprite_ != nullptr)
      sprite_ = copy.sprite_->Clone ();
  }

  DestructibleObject* DestructibleObject::Clone () const
  {
    return new DestructibleObject (*this);
  }

  void DestructibleObject::SetSprite (yap::ISprite* sprite)
  {
    sprite_ = sprite;
  }

  void DestructibleObject::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool DestructibleObject::IsVisible () const
  {
    return isVisible_;
  }

  void DestructibleObject::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void DestructibleObject::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  int DestructibleObject::CompareOrder (
    const yap::IDrawableWorldObject& other) const
  {
    return HandleCompareOrder (other);
  }

  float DestructibleObject::GetComparisonPoint () const
  {
    return HandleGetComparisonPoint ();
  }

  yap::Event<
    yap::IDrawableDynamicWorldObject&,
    const yap::Vector2&>& DestructibleObject::OnOrderStateChangedEvent ()
  {
    return OnOrderStateChanged;
  }

  const yap::String& DestructibleObject::GetObjectFactoryTypeName () const
  {
    return OBJECT_FACTORY_TYPE_NAME;
  }

  void DestructibleObject::HandleUpdate (const yap::Time& dt)
  {
    yap::DestructibleObject::HandleUpdate (dt);

    if (sprite_ != nullptr)
      sprite_->Update (dt);
  }

  yap::Vector2 DestructibleObject::HandleGetSize () const
  {
    if (sprite_ == nullptr)
      return yap::DestructibleObject::HandleGetSize ();

    return sprite_->GetSize ();
  }

  void DestructibleObject::HandleMove (const yap::Vector2& offset)
  {
    yap::DestructibleObject::HandleMove (offset);

    if (sprite_ != nullptr)
      sprite_->Move (offset);
  }

  void DestructibleObject::HandleDraw (yap::IDrawingContext& context)
  {
    if (sprite_ != nullptr)
      sprite_->Draw (context);
  }

  void DestructibleObject::HandleShow (bool isVisible)
  {
  }

  void DestructibleObject::HandleChangeColor (const sf::Color& color)
  {
    if (sprite_ != nullptr)
      sprite_->ChangeColor (color);
  }

  int DestructibleObject::HandleCompareOrder (
    const yap::IDrawableWorldObject& other) const
  {
    return GetComparisonPoint () - other.GetComparisonPoint ();
  }

  float DestructibleObject::HandleGetComparisonPoint () const
  {
    return GetBottomRight ().y;
  }
} // namespace ycl
