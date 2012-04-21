#include "YAPOG/Game/IDReader.hpp"
#include "YAPOG/Game/ID.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"

namespace yap
{
  const String IDReader::DEFAULT_XML_ROOT_NODE_NAME = "id";

  IDReader::IDReader (ID& id)
    : id_ (id)
    , xmlRootNodeName_ (DEFAULT_XML_ROOT_NODE_NAME)
  {
  }

  IDReader::IDReader (ID& id, const String& xmlRootNodeName)
    : id_ (id)
    , xmlRootNodeName_ (xmlRootNodeName)
  {
  }

  IDReader::~IDReader ()
  {
  }

  void IDReader::Visit (XmlReader& visitable)
  {
    id_.SetValue (visitable.ReadUInt64 (xmlRootNodeName_));
  }
} // namespace yap
