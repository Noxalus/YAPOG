#include "YAPOG/Graphics/Game/World/Map/TileLayerStack.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Graphics/Game/World/Map/TileLayer.hpp"
#include "YAPOG/Graphics/Game/World/Map/TileLayoutHandler.hpp"

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

  TileLayerStack::TileLayerStack (const TileLayerStack& copy)
    : width_ (copy.width_)
    , height_ (copy.height_)
    , tileLayers_ ()
  {
    for (const auto& it : copy.tileLayers_)
      AddTileLayer (it.first, it.second->Clone ());
  }

  TileLayerStack* TileLayerStack::Clone () const
  {
    return new TileLayerStack (*this);
  }

  void TileLayerStack::SetSize (uint width, uint height)
  {
    width_ = width;
    height_ = height;
  }

  void TileLayerStack::AddTileLayer (uint height, TileLayer* tileLayer)
  {
    tileLayers_.Add (height, tileLayer);
  }

  void TileLayerStack::AddTileLayer (
    uint height,
    TileLayoutHandler* layoutHandler)
  {
    if (height > DEFAULT_MAX_HEIGHT)
      YAPOG_THROW(
        "TileLayer level `" +
        StringHelper::ToString (height) +
        "' is too high.");

    if (tileLayers_.Contains (height))
      YAPOG_THROW(
        "TileLayer `" + StringHelper::ToString (height) + "' already exists.");

    TileLayer* tileLayer = new TileLayer (width_, height_);
    layoutHandler->Execute (*tileLayer);

    AddTileLayer (height, tileLayer);
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
