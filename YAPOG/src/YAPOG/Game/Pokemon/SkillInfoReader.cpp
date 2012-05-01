#include "YAPOG/Game/Pokemon/SkillInfoReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReaderCollection.hpp"

namespace yap
{
  const String SkillInfoReader::DEFAULT_XML_ROOT_NODE_NAME = "Skill";
  const String SkillInfoReader::DEFAULT_XML_ID_NODE_NAME = "id";
  const String SkillInfoReader::DEFAULT_XML_NAME_NODE_NAME = "name";
  const String SkillInfoReader::DEFAULT_XML_DESCRIPTION_NODE_NAME = "description";
    const String SkillInfoReader::DEFAULT_XML_POWER_NODE_NAME = "power";
    const String SkillInfoReader::DEFAULT_XML_PP_NODE_NAME = "pp";
    const String SkillInfoReader::DEFAULT_XML_MAX_PP_NODE_NAME = "maxPP";
    const String SkillInfoReader::DEFAULT_XML_ACCURACY_NODE_NAME = "accuracy";
    const String SkillInfoReader::DEFAULT_XML_TYPE_NODE_NAME = "type";
    const String SkillInfoReader::DEFAULT_XML_CATEGORY_NODE_NAME = "category";
    const String SkillInfoReader::DEFAULT_XML_TARGET_NODE_NAME = "target";
    const String SkillInfoReader::DEFAULT_XML_EFFECT_NODE_NAME = "effect";
    const String SkillInfoReader::DEFAULT_XML_USE_NODE_NAME = "use";
    const String SkillInfoReader::DEFAULT_XML_PRIORITY_NODE_NAME = "priority";

  SkillInfoReader::SkillInfoReader (SkillInfo& typeInfo)
    : skillInfo_ (typeInfo)
  {
  }

  SkillInfoReader::SkillInfoReader (
    SkillInfo& typeInfo, 
    const String& xmlRootNodeName)
    : skillInfo_ (typeInfo),
    xmlRootNodeName_ (xmlRootNodeName)
  {
  }

  SkillInfoReader::~SkillInfoReader ()
  {
  }

  void SkillInfoReader::Visit (XmlReader& visitable)
  {
    // <Skill id="{id}">

    if (!visitable.TryChangeRoot (DEFAULT_XML_ROOT_NODE_NAME))
    {
      throw Exception (
        "Failed to read `" + DEFAULT_XML_ROOT_NODE_NAME + "' node.");
    }

    skillInfo_.SetID (
      visitable.ReadID (
      XmlHelper::GetAttrNodeName (DEFAULT_XML_ID_NODE_NAME)));

    // <name>

    skillInfo_.SetName (visitable.ReadString (DEFAULT_XML_NAME_NODE_NAME));

    // </name>

    // <description>

    skillInfo_.SetDescription (visitable.ReadString (DEFAULT_XML_DESCRIPTION_NODE_NAME));

    // </description>

    // <power>

    skillInfo_.SetPower (visitable.ReadInt (DEFAULT_XML_POWER_NODE_NAME));

    // </power>

    // <pp>

    skillInfo_.SetPP (visitable.ReadInt (DEFAULT_XML_PP_NODE_NAME));

    // </pp>

    // <maxPP>

    skillInfo_.SetMaxPP (visitable.ReadInt (DEFAULT_XML_MAX_PP_NODE_NAME));

    // </maxPP>

    // <accuracy>

    skillInfo_.SetAccuracy (visitable.ReadInt (DEFAULT_XML_ACCURACY_NODE_NAME));

    // </accuracy>

    // <type>

    skillInfo_.SetType (visitable.ReadInt (DEFAULT_XML_TYPE_NODE_NAME));

    // </type>

    // <category>

    skillInfo_.SetCategory (visitable.ReadInt (DEFAULT_XML_CATEGORY_NODE_NAME));

    // </category>

    // <target>

    skillInfo_.SetTarget (visitable.ReadInt (DEFAULT_XML_TARGET_NODE_NAME));

    // </target>

    // <effect>

    skillInfo_.SetEffect (visitable.ReadInt (DEFAULT_XML_EFFECT_NODE_NAME));

    // </effect>

    // <use>

    skillInfo_.SetUse (visitable.ReadInt (DEFAULT_XML_USE_NODE_NAME));

    // </use>

    // <priority>

    skillInfo_.SetPriority (visitable.ReadInt (DEFAULT_XML_PRIORITY_NODE_NAME));

    // </priority>

    visitable.UpChangeRoot ();

    // </Skill>
  }
}