#ifndef YAPOG_TILELAYOUTHANDLERREADER_HPP
# define YAPOG_TILELAYOUTHANDLERREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/BaseReaderVisitor.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class TileLayoutHandler;

  class YAPOG_LIB TileLayoutHandlerReader : public BaseReaderVisitor
  {
      DISALLOW_COPY(TileLayoutHandlerReader);

    public:

      virtual ~TileLayoutHandlerReader ();

    protected:

      TileLayoutHandlerReader (
        TileLayoutHandler& tileLayoutHandler,
        const String& xmlRootNodeName);

      static const String DEFAULT_XML_TYPE_NODE_NAME;
      static const String DEFAULT_XML_TILE_NODE_NAME;

      String xmlRootNodeName_;

    private:

      TileLayoutHandler& tileLayoutHandler_;
  };
} // namespace yap

#endif // YAPOG_TILELAYOUTHANDLERREADER_HPP
