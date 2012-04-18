#ifndef YAPOG_XMLHELPER_HPP
# define YAPOG_XMLHELPER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class YAPOG_LIB XmlHelper
  {
      DISALLOW_COPY(XmlHelper);

    public:

      static String GetAttrNodeName (const String& name);

    private:

      XmlHelper();
      ~XmlHelper ();

      static const String XMLATTR_NODE_NAME_PREFIX;
  };
} // namespace yap

#endif // YAPOG_XMLHELPER_HPP
