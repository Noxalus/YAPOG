#include "YAPOG/Graphics/Game/World/Map/TileLayerStack.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Graphics/Game/World/Map/TileLayer.hpp"

namespace yap
{
  const uint TileLayerStack::DEFAULT_WIDTH = 0;
  const uint TileLayerStack::DEFAULT_HEIGHT = 0;
  const uint TileLayerStack::DEFAULT_MAX_HEIGHT = 3;

  TileLayerStack::TileLayerStack ()
    : width_ (DEFAULT_WIDTH)
    , height_ (DEFAULT_HEIGHT)
    , tileLayers_ ()
  {
  }

  TileLayerStack::~TileLayerStack ()
  {
    for (const auto& it : tileLayers_)
      delete it.second;
  }

  void TileLayerStack::SetSize (uint width, uint height)
  {
    width_ = width;
    height_ = height;
  }

  void TileLayerStack::AddTileLayer (
    uint height,
    TileLayoutHandler* layoutHandler)
  {
    if (height > DEFAULT_MAX_HEIGHT)
      throw Exception (
        "TileLayer level `" +
        StringHelper::ToString (height) +
        "' is too high");

    if (tileLayers_.Contains (height))
      throw Exception (
        "TileLayer `" + StringHelper::ToString (height) + "' already exists.");

    TileLayer* tileLayer = new TileLayer (width_, height_);
    tileLayer->SetLayoutHandler (layoutHandler);

    tileLayers_.Add (height, tileLayer);
  }

  const TileLayer& TileLayerStack::GetTileLayer (uint height) const
  {
    return *tileLayers_[height];
  }

  TileLayer& TileLayerStack::GetTileLayer (uint height)
  {
    return *tileLayers_[height];
  }

  void TileLayerStack::Draw (IDrawingContext& context)
  {
    for (auto& it : tileLayers_)
      it.second->Draw (context);
  }

  bool TileLayerStack::IsVisible () const
  {
    for (const auto& it : tileLayers_)
      if (!it.second->IsVisible ())
        return false;

    return true;
  }

  void TileLayerStack::Show (bool isVisible)
  {
    for (auto& it : tileLayers_)
      it.second->Show (isVisible);
  }

  void TileLayerStack::ChangeColor (const sf::Color& color)
  {
    for (auto& it : tileLayers_)
      it.second->ChangeColor (color);
  }

  void TileLayerStack::Update (const Time& dt)
  {
    for (auto& it : tileLayers_)
      it.second->Update (dt);
  }
} // namespace yap
