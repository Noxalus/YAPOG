#ifndef YAPOG_MAPREADER_HPP
# define YAPOG_MAPREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/IReaderVisitor.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class Map;

  class YAPOG_LIB MapReader : public IReaderVisitor
  {
    public:

      MapReader (Map& map);
      MapReader (Map& map, const String& xmlRootNodeName);
      virtual ~MapReader ();

      virtual void Visit (XmlReader& visitable);

    private:

      static const String DEFAULT_XML_ROOT_NODE_NAME;
      static const String DEFAULT_XML_NAME_NODE_NAME;

      Map& map_;
      String xmlRootNodeName_;
  };
} // namespace yap

#endif // YAPOG_MAPREADER_HPP
