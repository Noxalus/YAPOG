#ifndef YAPOG_IDREADER_HPP
# define YAPOG_IDREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/IReaderVisitor.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class ID;

  class YAPOG_LIB IDReader : public IReaderVisitor
  {
      DISALLOW_COPY(IDReader);

    public:

      IDReader (ID& id);
      IDReader (ID& id, const String& xmlRootNodeName);
      virtual ~IDReader ();

      virtual void Visit (XmlReader& visitable);

    private:

      static const String DEFAULT_XML_ROOT_NODE_NAME;

      ID& id_;
      String xmlRootNodeName_;
  };
} // namespace yap

#endif // YAPOG_IDREADER_HPP
