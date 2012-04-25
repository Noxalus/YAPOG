#ifndef YAPOG_TILELAYOUTHANDLER_HPP
# define YAPOG_TILELAYOUTHANDLER_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  class TileLayer;

  class TileLayoutHandler
  {
      DISALLOW_COPY(TileLayoutHandler);

    public:

      void Execute (TileLayer& tileLayer);

    protected:

      TileLayoutHandler ();
      virtual ~TileLayoutHandler ();

    private:

      virtual void HandleExecute (TileLayer& tileLayer) = 0;
  };
} // namespace yap

#endif // YAPOG_TILELAYOUTHANDLER_HPP
