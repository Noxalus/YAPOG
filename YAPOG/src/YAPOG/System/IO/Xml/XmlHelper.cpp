#include "YAPOG/System/IO/Xml/XmlHelper.hpp"

namespace yap
{
  const String XmlHelper::XMLATTR_NODE_NAME_PREFIX = "<xmlattr>.";

  String XmlHelper::GetAttrNodeName (const String& name)
  {
    return XMLATTR_NODE_NAME_PREFIX + name;
  }
} // namespace yap
