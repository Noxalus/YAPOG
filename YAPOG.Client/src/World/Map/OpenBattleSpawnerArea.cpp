#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"

#include "World/Map/OpenBattleSpawnerArea.hpp"

namespace ycl
{
  const bool OpenBattleSpawnerArea::DEFAULT_VISIBLE_STATE = true;
  const sf::Color OpenBattleSpawnerArea::DEFAULT_COLOR = sf::Color ();

  const int OpenBattleSpawnerArea::DEFAULT_LAYER_DEPTH = 0;

  const yap::String OpenBattleSpawnerArea::OBJECT_FACTORY_TYPE_NAME =
    "OpenBattleSpawnerArea";

  OpenBattleSpawnerArea::OpenBattleSpawnerArea (const yap::ID& id)
    : yap::OpenBattleSpawnerArea (id)
    , isVisible_ (DEFAULT_VISIBLE_STATE)
    , color_ (DEFAULT_COLOR)
    , baseSprite_ (nullptr)
    , sprites_ ()
  {
  }

  OpenBattleSpawnerArea::~OpenBattleSpawnerArea ()
  {
    delete baseSprite_;
    baseSprite_ = nullptr;

    for (yap::ISprite* sprite : sprites_)
      delete sprite;
  }

  OpenBattleSpawnerArea::OpenBattleSpawnerArea (
    const OpenBattleSpawnerArea& copy)
    : yap::OpenBattleSpawnerArea (copy)
    , isVisible_ (copy.isVisible_)
    , color_ (copy.color_)
    , baseSprite_ (nullptr)
    , sprites_ ()
  {
    if (copy.baseSprite_ != nullptr)
      baseSprite_ = copy.baseSprite_->Clone ();
  }

  OpenBattleSpawnerArea* OpenBattleSpawnerArea::Clone () const
  {
    return new OpenBattleSpawnerArea (*this);
  }

  void OpenBattleSpawnerArea::SetBaseSprite (yap::ISprite* baseSprite)
  {
    baseSprite_ = baseSprite;
  }

  void OpenBattleSpawnerArea::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool OpenBattleSpawnerArea::IsVisible () const
  {
    return isVisible_;
  }

  void OpenBattleSpawnerArea::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void OpenBattleSpawnerArea::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  float OpenBattleSpawnerArea::GetComparisonPoint () const
  {
    return HandleGetComparisonPoint ();
  }

  int OpenBattleSpawnerArea::GetLayerDepth () const
  {
    return HandleGetLayerDepth ();
  }

  yap::Event<
    yap::IDrawableDynamicWorldObject&,
    const yap::Vector2&>& OpenBattleSpawnerArea::OnOrderStateChangedEvent ()
  {
    return OnOrderStateChanged;
  }

  void OpenBattleSpawnerArea::HandleInitArea (uint width, uint height)
  {
    yap::OpenBattleSpawnerArea::HandleInitArea (width, height);

    for (uint y = 0; y < height; ++y)
      for (uint x = 0; x < width; ++x)
        AddSprite (x, y, baseSprite_->Clone ());
  }

  const yap::String& OpenBattleSpawnerArea::GetObjectFactoryTypeName () const
  {
    return OBJECT_FACTORY_TYPE_NAME;
  }

  void OpenBattleSpawnerArea::HandleUpdate (const yap::Time& dt)
  {
    yap::OpenBattleSpawnerArea::HandleUpdate (dt);

    for (yap::ISprite* sprite : sprites_)
      sprite->Update (dt);
  }

  void OpenBattleSpawnerArea::HandleMove (const yap::Vector2& offset)
  {
    yap::OpenBattleSpawnerArea::HandleMove (offset);

    for (yap::ISprite* sprite : sprites_)
      sprite->Move (offset);
  }

  void OpenBattleSpawnerArea::HandleDraw (yap::IDrawingContext& context)
  {
    for (yap::ISprite* sprite : sprites_)
      sprite->Draw (context);
  }

  void OpenBattleSpawnerArea::HandleShow (bool isVisible)
  {
  }

  void OpenBattleSpawnerArea::HandleChangeColor (const sf::Color& color)
  {
    for (yap::ISprite* sprite : sprites_)
      sprite->ChangeColor (color);
  }

  float OpenBattleSpawnerArea::HandleGetComparisonPoint () const
  {
    return GetBottomRight ().y;
  }

  int OpenBattleSpawnerArea::HandleGetLayerDepth () const
  {
    return DEFAULT_LAYER_DEPTH;
  }

  void OpenBattleSpawnerArea::AddSprite (uint x, uint y, yap::ISprite* sprite)
  {
    sprite->SetPosition (
      yap::Vector2 (
        x * DEFAULT_CELL_SIZE,
        y * DEFAULT_CELL_SIZE));

    sprites_.Add (sprite);
  }
} // namespace ycl
