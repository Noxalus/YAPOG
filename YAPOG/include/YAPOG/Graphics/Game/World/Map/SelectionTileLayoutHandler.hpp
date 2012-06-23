#ifndef YAPOG_SELECTIONTILELAYOUTHANDLER_HPP
# define YAPOG_SELECTIONTILELAYOUTHANDLER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/World/Map/TileLayoutHandler.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/Collection/Matrix.hpp"
# include "YAPOG/System/IntTypes.hpp"

namespace yap
{
  class Tile;

  /// @brief TileLayoutHandler that fills by default with a given Tile
  /// and allows to change any Tile from that default selection.
  class YAPOG_LIB SelectionTileLayoutHandler : public TileLayoutHandler
  {
      DISALLOW_COPY(SelectionTileLayoutHandler);

    public:

      SelectionTileLayoutHandler ();
      virtual ~SelectionTileLayoutHandler ();

      void SetSize (uint width, uint height);
      void SetDefaultTile (Tile* tile);
      void SetTile (uint x, uint y, Tile* tile);

    private:

      virtual void HandleExecute (TileLayer& tileLayer);

      static const uint DEFAULT_WIDTH;
      static const uint DEFAULT_HEIGHT;

      uint width_;
      uint height_;

      Tile* defaultTile_;
      collection::Matrix<Tile*> tiles_;
  };
} // namespace yap

#endif // YAPOG_SELECTIONTILELAYOUTHANDLER_HPP
