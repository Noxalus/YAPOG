#include "World/Map/Character.hpp"

namespace ycl
{
  const bool Character::DEFAULT_VISIBLE_STATE = true;
  const sf::Color Character::DEFAULT_COLOR = sf::Color ();

  Character::Character (const yap::ID& id)
    : yap::Character (id)
    , isVisible_ (DEFAULT_VISIBLE_STATE)
    , color_ (DEFAULT_COLOR)
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

  int Character::CompareOrder (const yap::IDrawableWorldObject& other) const
  {
    return HandleCompareOrder (other);
  }

  float Character::GetComparisonPoint () const
  {
    return HandleGetComparisonPoint ();
  }

  yap::Event<yap::IDrawableDynamicWorldObject&,
             const yap::Vector2&>& Character::OnMovedEvent ()
  {
    return OnMoved;
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

    sprites_->Move (offset);

    OnMovedEvent () (*this, offset);
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

  int Character::HandleCompareOrder (
    const yap::IDrawableWorldObject& other) const
  {
    return GetComparisonPoint () - other.GetComparisonPoint ();
  }

  float Character::HandleGetComparisonPoint () const
  {
    return GetBottomRight ().y;
  }
} // namespace ycl
