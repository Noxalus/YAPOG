#ifndef YAPOG_CONFIGURATIONREADER_HPP
# define YAPOG_CONFIGURATIONREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/BaseReaderVisitor.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class ConfigurationReader : public BaseReaderVisitor
  {
      DISALLOW_COPY(ConfigurationReader);

    public:

      virtual ~ConfigurationReader ();

      virtual void Visit (XmlReader& visitable);

    protected:

      explicit ConfigurationReader (const String& xmlRootNodeName);

      virtual void HandleVisitXmlReader (XmlReader& visitable);

      String xmlRootNodeName_;
  };
} // namespace yap

#endif // YAPOG_CONFIGURATIONREADER_HPP
