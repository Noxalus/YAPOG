#include "YAPOG/System/Configuration/ConfigurationReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"

namespace yap
{
  ConfigurationReader::ConfigurationReader (const String& xmlRootNodeName)
    : BaseReaderVisitor ()
    , xmlRootNodeName_ (xmlRootNodeName)
  {
  }

  ConfigurationReader::~ConfigurationReader ()
  {
  }

  void ConfigurationReader::Visit (XmlReader& visitable)
  {
    auto reader = visitable.ChangeRoot (xmlRootNodeName_);

    HandleVisitXmlReader (*reader);
  }

  void ConfigurationReader::HandleVisitXmlReader (XmlReader& visitable)
  {
  }
} // namespace yap
