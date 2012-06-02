#ifndef YAPOG_MAPREADER_HPP
# define YAPOG_MAPREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/BaseReaderVisitor.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class Map;

  class YAPOG_LIB MapReader : public BaseReaderVisitor
  {
    DISALLOW_COPY(MapReader);

  public:

    virtual ~MapReader ();

    virtual void Visit (XmlReader& visitable);

  protected:

    MapReader (Map& map, const String& xmlRootNodeName);

    virtual void ReadMapElement (XmlReader& reader);

    String xmlRootNodeName_;

  private:

    static const String DEFAULT_XML_ID_NODE_NAME;
    static const String DEFAULT_XML_NAME_NODE_NAME;
    static const String DEFAULT_XML_WIDTH_NODE_NAME;
    static const String DEFAULT_XML_HEIGHT_NODE_NAME;

    Map& map_;
  };
} // namespace yap



#endif // YAPOG_MAPREADER_HPP
