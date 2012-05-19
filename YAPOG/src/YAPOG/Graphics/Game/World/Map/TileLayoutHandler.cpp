#include "YAPOG/Graphics/Game/World/Map/TileLayoutHandler.hpp"

namespace yap
{
  TileLayoutHandler::TileLayoutHandler ()
  {
  }

  TileLayoutHandler::~TileLayoutHandler ()
  {
  }

  void TileLayoutHandler::Execute (TileLayer& tileLayer)
  {
    HandleExecute (tileLayer);
  }
} // namespace yap
