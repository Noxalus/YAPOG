#include "YAPOG/System/IO/Xml/XmlHelper.hpp"

namespace yap
{
  const String XmlHelper::XMLATTR_NODE_NAME_SUFFIX = "<xmlattr>.";

  String XmlHelper::GetAttrNodeName (const String& name)
  {
    return XMLATTR_NODE_NAME_SUFFIX + name;
  }
} // namespace yap
