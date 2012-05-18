#include "YAPOG/Graphics/Game/World/Map/TileFamily.hpp"

namespace yap
{
  TileFamily::TileFamily (const ID& id)
    : id_ (id)
    , slots_ ()
  {
  }

  void TileFamily::SetTile (SlotType slotType, const ID& tileID)
  {
    slots_.Add (slotType, tileID);
  }
} // namespace yap
