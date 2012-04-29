#ifndef YAPOG_SKILLINFOREADER_HPP
# define YAPOG_SKILLINFOREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/IReaderVisitor.hpp"
# include "YAPOG/Game/Pokemon/SkillInfo.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/Error/Exception.hpp"
# include "YAPOG/System/IO/Xml/XmlReader.hpp"
# include "YAPOG/System/IO/Xml/XmlHelper.hpp"

namespace yap
{
  class YAPOG_LIB SkillInfoReader : public IReaderVisitor
  {
    DISALLOW_COPY(SkillInfoReader);

  public:
    SkillInfoReader (SkillInfo& skillInfo);
    SkillInfoReader (SkillInfo& map, const String& xmlRootNodeName);
    virtual ~SkillInfoReader ();

    virtual void Visit (XmlReader& visitable);
  private:
    SkillInfo& skillInfo_;
    String xmlRootNodeName_;

    static const String DEFAULT_XML_ROOT_NODE_NAME;
    static const String DEFAULT_XML_ID_NODE_NAME;
    static const String DEFAULT_XML_NAME_NODE_NAME;
    static const String DEFAULT_XML_DESCRIPTION_NODE_NAME;
    static const String DEFAULT_XML_POWER_NODE_NAME;
    static const String DEFAULT_XML_PP_NODE_NAME;
    static const String DEFAULT_XML_MAX_PP_NODE_NAME;
    static const String DEFAULT_XML_ACCURACY_NODE_NAME;
    static const String DEFAULT_XML_TYPE_NODE_NAME;
    static const String DEFAULT_XML_CATEGORY_NODE_NAME;
    static const String DEFAULT_XML_TARGET_NODE_NAME;
    static const String DEFAULT_XML_EFFECT_NODE_NAME;
    static const String DEFAULT_XML_USE_NODE_NAME;
    static const String DEFAULT_XML_PRIORITY_NODE_NAME;
  };
} // namespace yap

#endif // YAPOG_SKILLINFOREADER_HPP

