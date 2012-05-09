#ifndef YAPOG_NATUREINFOREADER_HPP
# define YAPOG_NATUREINFOREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/BaseReaderVisitor.hpp"
# include "YAPOG/Game/Pokemon/NatureInfo.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/Error/Exception.hpp"
# include "YAPOG/System/IO/Xml/XmlReader.hpp"
# include "YAPOG/System/IO/Xml/XmlHelper.hpp"

namespace yap
{
  class YAPOG_LIB NatureInfoReader : public BaseReaderVisitor
  {
    DISALLOW_COPY(NatureInfoReader);

  public:
    NatureInfoReader (NatureInfo& pokeInfo);
    NatureInfoReader (NatureInfo& map, const String& xmlRootNodeName);
    virtual ~NatureInfoReader ();

    virtual void Visit (XmlReader& visitable);
  private:
    NatureInfo& natureInfo_;
    String xmlRootNodeName_;

    static const String DEFAULT_XML_ROOT_NODE_NAME;
    static const String DEFAULT_XML_ID_NODE_NAME;
    static const String DEFAULT_XML_NAME_NODE_NAME;
    static const String DEFAULT_XML_FACTORS_NODE_NAME;
    static const String DEFAULT_XML_ATTACK_NODE_NAME;
    static const String DEFAULT_XML_DEFENSE_NODE_NAME;
    static const String DEFAULT_XML_SPECIAL_ATTACK_NODE_NAME;
    static const String DEFAULT_XML_SPECIAL_DEFENSE_NODE_NAME;
    static const String DEFAULT_XML_SPEED_NODE_NAME;
  };
} // namespace yap

#endif // YAPOG_NATUREINFOREADER_HPP

