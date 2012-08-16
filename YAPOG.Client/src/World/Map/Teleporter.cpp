#include "World/Map/Teleporter.hpp"

namespace ycl
{
  const bool Teleporter::DEFAULT_VISIBLE_STATE = true;
  const sf::Color Teleporter::DEFAULT_COLOR = sf::Color ();

  const int Teleporter::DEFAULT_LAYER_DEPTH = 1;

  const yap::String Teleporter::OBJECT_FACTORY_TYPE_NAME = "Teleporter";

  Teleporter::Teleporter (const yap::ID& id)
    : yap::Teleporter (id)
    , isVisible_ (DEFAULT_VISIBLE_STATE)
    , color_ (DEFAULT_COLOR)
    , worldDrawingPolicy_ (nullptr)
  {
  }

  Teleporter::~Teleporter ()
  {
  }

  Teleporter::Teleporter (const Teleporter& copy)
    : yap::Teleporter (copy)
    , isVisible_ (copy.isVisible_)
    , color_ (copy.color_)
    , worldDrawingPolicy_ (copy.worldDrawingPolicy_)
  {
  }

  Teleporter* Teleporter::Clone () const
  {
    return new Teleporter (*this);
  }

  void Teleporter::Init (
    const yap::ID& mapWorldID,
    const yap::Vector2& mapPoint,
    const yap::FloatRect& area)
  {
    SetMapWorldID (mapWorldID);
    SetMapPoint (mapPoint);

    SetArea (area);
  }

  void Teleporter::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool Teleporter::IsVisible () const
  {
    return isVisible_;
  }

  void Teleporter::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void Teleporter::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  float Teleporter::GetComparisonPoint () const
  {
    return HandleGetComparisonPoint ();
  }

  int Teleporter::GetLayerDepth () const
  {
    return HandleGetLayerDepth ();
  }

  void Teleporter::ChangeWorldDrawingPolicy (
    const yap::IWorldDrawingPolicy& worldDrawingPolicy)
  {
    worldDrawingPolicy_ = &worldDrawingPolicy;

    HandleChangeWorldDrawingPolicy (worldDrawingPolicy);
  }

  yap::Event<
    yap::IDrawableDynamicWorldObject&,
    const yap::Vector2&>& Teleporter::OnOrderStateChangedEvent ()
  {
    return OnOrderStateChanged;
  }

  const yap::String& Teleporter::GetObjectFactoryTypeName () const
  {
    return OBJECT_FACTORY_TYPE_NAME;
  }

  void Teleporter::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void Teleporter::HandleShow (bool isVisible)
  {
  }

  void Teleporter::HandleChangeColor (const sf::Color& color)
  {
  }

  float Teleporter::HandleGetComparisonPoint () const
  {
    return GetBottomRight ().y;
  }

  int Teleporter::HandleGetLayerDepth () const
  {
    return DEFAULT_LAYER_DEPTH;
  }

  void Teleporter::HandleChangeWorldDrawingPolicy (
    const yap::IWorldDrawingPolicy& worldDrawingPolicy)
  {
  }
} // namespace ycl
