#ifndef YAPOG_TILELAYOUTHANDLERREADER_HPP
# define YAPOG_TILELAYOUTHANDLERREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/BaseReaderVisitor.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class YAPOG_LIB TileLayoutHandlerReader : public BaseReaderVisitor
  {
      DISALLOW_COPY(TileLayoutHandlerReader);

    public:

      TileLayoutHandlerReader ();
      explicit TileLayoutHandlerReader (const String& xmlRootNodeName);
      virtual ~TileLayoutHandlerReader ();

    protected:

      static const String DEFAULT_XML_ROOT_NODE_NAME;
      static const String DEFAULT_XML_TYPE_NODE_NAME;
      static const String DEFAULT_XML_TILE_NODE_NAME;

      String xmlRootNodeName_;
  };
} // namespace yap

#endif // YAPOG_TILELAYOUTHANDLERREADER_HPP
