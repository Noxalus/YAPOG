#ifndef YAPOG_SELECTIONTILELAYOUTHANDLERREADER_HPP
# define YAPOG_SELECTIONTILELAYOUTHANDLERREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/World/Map/TileLayoutHandlerReader.hpp"

namespace yap
{
  class SelectionTileLayoutHandler;

  class YAPOG_LIB SelectionTileLayoutHandlerReader
    : public TileLayoutHandlerReader
  {
      DISALLOW_COPY(SelectionTileLayoutHandlerReader);

    public:

      SelectionTileLayoutHandlerReader (
        SelectionTileLayoutHandler& selectionTileLayoutHandler,
        const String& xmlRootNodeName);
      virtual ~SelectionTileLayoutHandlerReader ();

      virtual void Visit (XmlReader& visitable);

    private:

      SelectionTileLayoutHandler& selectionTileLayoutHandler_;
  };
} // namespace yap

#endif // YAPOG_SELECTIONTILELAYOUTHANDLERREADER_HPP
