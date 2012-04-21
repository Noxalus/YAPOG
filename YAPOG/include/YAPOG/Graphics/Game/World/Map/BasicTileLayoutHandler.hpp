#ifndef YAPOG_BASICTILELAYOUTHANDLER_HPP
# define YAPOG_BASICTILELAYOUTHANDLER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/World/Map/TileLayoutHandler.hpp"

namespace yap
{
  class BasicTileLayoutHandler : public TileLayoutHandler
  {
      DISALLOW_COPY(BasicTileLayoutHandler);

    public:

      BasicTileLayoutHandler ();
      virtual ~BasicTileLayoutHandler ();

    private:

      virtual void HandleExecute ();
  };
} // namespace yap

#endif // YAPOG_BASICTILELAYOUTHANDLER_HPP
