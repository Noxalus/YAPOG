#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"

#include "World/Map/MapElement.hpp"

namespace ycl
{
  const bool MapElement::DEFAULT_VISIBLE_STATE = true;
  const sf::Color MapElement::DEFAULT_COLOR = sf::Color ();

  const int MapElement::DEFAULT_LAYER_DEPTH = 1;

  MapElement::MapElement (const yap::ID& id)
    : yap::MapElement (id)
    , isVisible_ (DEFAULT_VISIBLE_STATE)
    , color_ (DEFAULT_COLOR)
    , sprite_ (nullptr)
  {
  }

  MapElement::~MapElement ()
  {
    delete sprite_;
    sprite_ = nullptr;
  }

  MapElement::MapElement (const MapElement& copy)
    : yap::MapElement (copy)
    , isVisible_ (copy.isVisible_)
    , color_ (copy.color_)
    , sprite_ (nullptr)
  {
    if (copy.sprite_ != nullptr)
      sprite_ = copy.sprite_->Clone ();
  }

  MapElement* MapElement::Clone () const
  {
    return new MapElement (*this);
  }

  void MapElement::SetSprite (yap::ISprite* sprite)
  {
    sprite_ = sprite;
  }

  void MapElement::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool MapElement::IsVisible () const
  {
    return isVisible_;
  }

  void MapElement::Show (bool isVisible)
  {
    isVisible_ = isVisible;
  }

  void MapElement::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  float MapElement::GetComparisonPoint () const
  {
    return HandleGetComparisonPoint ();
  }

  int MapElement::GetLayerDepth () const
  {
    return HandleGetLayerDepth ();
  }

  void MapElement::HandleUpdate (const yap::Time& dt)
  {
    yap::MapElement::HandleUpdate (dt);

    if (sprite_ != nullptr)
      sprite_->Update (dt);
  }

  yap::Vector2 MapElement::HandleGetSize () const
  {
    if (sprite_ == nullptr)
      return yap::WorldObject::HandleGetSize ();

    return sprite_->GetSize ();
  }

  void MapElement::HandleMove (const yap::Vector2& offset)
  {
    yap::MapElement::HandleMove (offset);

    if (sprite_ != nullptr)
      sprite_->Move (offset);
  }

  void MapElement::HandleDraw (yap::IDrawingContext& context)
  {
    if (sprite_ != nullptr)
      sprite_->Draw (context);
  }

  void MapElement::HandleChangeColor (const sf::Color& color)
  {
    if (sprite_ != nullptr)
      sprite_->ChangeColor (color);
  }

  float MapElement::HandleGetComparisonPoint () const
  {
    return GetBottomRight ().y;
  }

  int MapElement::HandleGetLayerDepth () const
  {
    return DEFAULT_LAYER_DEPTH;
  }
} // namespace ycl
