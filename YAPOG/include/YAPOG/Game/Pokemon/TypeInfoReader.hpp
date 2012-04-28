#ifndef YAPOG_TYPEINFOREADER_HPP
# define YAPOG_TYPEINFOREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/IReaderVisitor.hpp"
# include "YAPOG/Game/Pokemon/TypeInfo.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/Error/Exception.hpp"
# include "YAPOG/System/IO/Xml/XmlReader.hpp"
# include "YAPOG/System/IO/Xml/XmlHelper.hpp"

namespace yap
{
  class YAPOG_LIB TypeInfoReader : public IReaderVisitor
  {
    DISALLOW_COPY(TypeInfoReader);

  public:
    TypeInfoReader (TypeInfo& pokeInfo);
    TypeInfoReader (TypeInfo& map, const String& xmlRootNodeName);
    virtual ~TypeInfoReader ();

    virtual void Visit (XmlReader& visitable);
  private:
    TypeInfo& typeInfo_;
    String xmlRootNodeName_;

    static const String DEFAULT_XML_ROOT_NODE_NAME;
    static const String DEFAULT_XML_ID_NODE_NAME;
    static const String DEFAULT_XML_NAME_NODE_NAME;
    static const String DEFAULT_XML_FACTORS_NODE_NAME;
    static const String DEFAULT_XML_TYPE_NODE_NAME;
  };
} // namespace yap

#endif // YAPOG_TYPEINFOREADER_HPP

