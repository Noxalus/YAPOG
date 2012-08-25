#include "World/Map/Character.hpp"

#include "YAPOG/Graphics/Game/World/IWorldDrawingPolicy.hpp"

namespace ycl
{
  const bool Character::DEFAULT_VISIBLE_STATE = true;
  const sf::Color Character::DEFAULT_COLOR = sf::Color ();

  const int Character::DEFAULT_LAYER_DEPTH = 1;

  Character::Character (const yap::ID& id)
    : yap::Character (id)
    , isVisible_ (DEFAULT_VISIBLE_STATE)
    , color_ (DEFAULT_COLOR)
    , worldDrawingPolicy_ (nullptr)
    , sprites_ (new yap::SpriteSet<yap::String> ())
    , directionSprites_ ()
  {
  }

  Character::~Character ()
  {
    delete sprites_;
    sprites_ = nullptr;
  }

  Character::Character (const Character& copy)
    : yap::Character (copy)
    , isVisible_ (copy.isVisible_)
    , color_ (copy.color_)
    , worldDrawingPolicy_ (copy.worldDrawingPolicy_)
    , sprites_ (new yap::SpriteSet<yap::String> ())
    , directionSprites_ ()
  {
    for (auto& it : copy.directionSprites_)
      AddSprite (it.first, it.second->Clone ());
  }

  void Character::AddSprite (
    const yap::String& state,
    yap::SpriteSet<yap::Direction>* directionSprite)
  {
    sprites_->AddSprite (state, directionSprite);
    directionSprites_.Add (state, directionSprite);
  }

  void Character::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool Character::IsVisible () const
  {
    return isVisible_;
  }

  void Character::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void Character::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  float Character::GetComparisonPoint () const
  {
    return HandleGetComparisonPoint ();
  }

  int Character::GetLayerDepth () const
  {
    return HandleGetLayerDepth ();
  }

  void Character::ChangeWorldDrawingPolicy (
    const yap::IWorldDrawingPolicy& worldDrawingPolicy)
  {
    worldDrawingPolicy_ = &worldDrawingPolicy;

    HandleChangeWorldDrawingPolicy (worldDrawingPolicy);
  }

  yap::Event<
    yap::IDrawableDynamicWorldObject&,
    const yap::Vector2&>& Character::OnOrderStateChangedEvent ()
  {
    return OnOrderStateChanged;
  }

  yap::Vector2 Character::HandleGetSize () const
  {
    return sprites_->GetSize ();
  }

  void Character::HandleUpdate (const yap::Time& dt)
  {
    yap::Character::HandleUpdate (dt);

    sprites_->Update (dt);
  }

  void Character::HandleSetState (const yap::String& state)
  {
    yap::Character::HandleSetState (state);

    sprites_->SetCurrentSprite (state);
  }

  void Character::HandleMove (const yap::Vector2& offset)
  {
    yap::Character::HandleMove (offset);

    if (worldDrawingPolicy_ != nullptr)
      sprites_->Move (
        worldDrawingPolicy_->ToScreenOffset (
          yap::Vector3 (offset.x, offset.y, 0.0f)));

    OnOrderStateChangedEvent () (*this, offset);
  }

  void Character::HandleSetDirection (yap::Direction direction)
  {
    yap::Character::HandleSetDirection (direction);

    for (auto& it : directionSprites_)
      it.second->SetCurrentSprite (direction);
  }

  void Character::HandleDraw (yap::IDrawingContext& context)
  {
    sprites_->Draw (context);
  }

  void Character::HandleShow (bool isVisible)
  {
  }

  void Character::HandleChangeColor (const sf::Color& color)
  {
    sprites_->ChangeColor (color);
  }

  float Character::HandleGetComparisonPoint () const
  {
    return worldDrawingPolicy_->GetComparisonPoint (*this);
  }

  int Character::HandleGetLayerDepth () const
  {
    return DEFAULT_LAYER_DEPTH;
  }

  void Character::HandleChangeWorldDrawingPolicy (
    const yap::IWorldDrawingPolicy& worldDrawingPolicy)
  {
    sprites_->SetPosition (
      worldDrawingPolicy_->ToScreenPosition (
        yap::Vector3 (
          GetPosition ().x,
          GetPosition ().y,
          GetZ ())));
  }
} // namespace ycl
