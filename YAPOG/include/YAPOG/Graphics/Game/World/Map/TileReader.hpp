#ifndef YAPOG_TILEREADER_HPP
# define YAPOG_TILEREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/IReaderVisitor.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class Tile;

  class YAPOG_LIB TileReader : public IReaderVisitor
  {
      DISALLOW_COPY(TileReader);

    public:

      explicit TileReader (Tile& tile);
      TileReader (Tile& tile, const String& xmlRootNodeName);
      virtual ~TileReader ();

      virtual void Visit (XmlReader& visitable);

    private:

      static const String DEFAULT_XML_ROOT_NODE_NAME;
      static const String DEFAULT_XML_ID_NODE_NAME;

      Tile& tile_;

      String xmlRootNodeName_;
  };
} // namespace yap

#endif // YAPOG_TILEREADER_HPP
