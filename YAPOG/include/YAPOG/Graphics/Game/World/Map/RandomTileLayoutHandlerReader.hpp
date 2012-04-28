#ifndef YAPOG_RANDOMTILELAYOUTHANDLERREADER_HPP
# define YAPOG_RANDOMTILELAYOUTHANDLERREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/World/Map/TileLayoutHandlerReader.hpp"

namespace yap
{
  class RandomTileLayoutHandler;

  class YAPOG_LIB RandomTileLayoutHandlerReader : public TileLayoutHandlerReader
  {
      DISALLOW_COPY(RandomTileLayoutHandlerReader);

    public:

      explicit RandomTileLayoutHandlerReader (
        RandomTileLayoutHandler& tileLayoutHandler);
      RandomTileLayoutHandlerReader (
        RandomTileLayoutHandler& tileLayoutHandler,
        const String& xmlRootNodeName);
      virtual ~RandomTileLayoutHandlerReader ();

      virtual void Visit (XmlReader& visitable);

    private:

      RandomTileLayoutHandler& tileLayoutHandler_;
  };
} // namespace yap

#endif // YAPOG_RANDOMTILELAYOUTHANDLERREADER_HPP
