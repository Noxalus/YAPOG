#ifndef YAPOG_TILELAYOUTHANDLER_HPP
# define YAPOG_TILELAYOUTHANDLER_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  class TileLayoutHandler
  {
      DISALLOW_COPY(TileLayoutHandler);

    public:

      virtual ~TileLayoutHandler ();

      void Execute ();

    protected:

      TileLayoutHandler ();

    private:

      virtual void HandleExecute () = 0;

  };
} // namespace yap

#endif // YAPOG_TILELAYOUTHANDLER_HPP
