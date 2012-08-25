#include "World/Map/MapElement.hpp"

#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"
#include "YAPOG/Graphics/Game/World/IWorldDrawingPolicy.hpp"

namespace ycl
{
  const bool MapElement::DEFAULT_VISIBLE_STATE = true;
  const sf::Color MapElement::DEFAULT_COLOR = sf::Color ();

  const int MapElement::DEFAULT_LAYER_DEPTH = 1;

  MapElement::MapElement (const yap::ID& id)
    : yap::MapElement (id)
    , isVisible_ (DEFAULT_VISIBLE_STATE)
    , color_ (DEFAULT_COLOR)
    , layerDepth_ (DEFAULT_LAYER_DEPTH)
    , worldDrawingPolicy_ (nullptr)
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
    , layerDepth_ (copy.layerDepth_)
    , worldDrawingPolicy_ (copy.worldDrawingPolicy_)
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

  void MapElement::SetLayerDepth (int layerDepth)
  {
    layerDepth_ = layerDepth;
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

  void MapElement::ChangeWorldDrawingPolicy (
    const yap::IWorldDrawingPolicy& worldDrawingPolicy)
  {
    worldDrawingPolicy_ = &worldDrawingPolicy;

    HandleChangeWorldDrawingPolicy (worldDrawingPolicy);
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

    if (sprite_ != nullptr && worldDrawingPolicy_ != nullptr)
      sprite_->Move (
        worldDrawingPolicy_->ToScreenOffset (
          yap::Vector3 (
            offset.x,
            offset.y,
            0.0f)));
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
    return worldDrawingPolicy_->GetComparisonPoint (*this);
  }

  int MapElement::HandleGetLayerDepth () const
  {
    return layerDepth_;
  }

  void MapElement::HandleChangeWorldDrawingPolicy (
    const yap::IWorldDrawingPolicy& worldDrawingPolicy)
  {
    sprite_->SetPosition (
      worldDrawingPolicy_->ToScreenPosition (
        yap::Vector3 (
          GetPosition ().x,
          GetPosition ().y,
          GetZ ())));
  }
} // namespace ycl
