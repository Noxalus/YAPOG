#ifndef YAPOG_TILEFAMILY_HPP
# define YAPOG_TILEFAMILY_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/Collection/Map.hpp"

namespace yap
{
  class TileFamily
  {
      DISABLE_COPY(TileFamily);

    public:

      /// @brief Different types of slots that describe a tile family.
      enum class SlotType
      {
          TopLeft,
          Center
      };

      TileFamily (const ID& id);

      void SetTile (SlotType slotType, const ID& tileID);

    private:

      ID id_;

      collection::Map<SlotType, ID> slots_;
  };
} // namespace yap

#endif // YAPOG_TILEFAMILY_HPP
