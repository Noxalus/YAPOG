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
    auto reader = visitable.ChangeRoot (xmlRootNodeName_);

    skillInfo_.SetID (
      reader->ReadID (
        XmlHelper::GetAttrNodeName (DEFAULT_XML_ID_NODE_NAME)));

    skillInfo_.SetName (reader->ReadString (DEFAULT_XML_NAME_NODE_NAME));

    skillInfo_.SetDescription (
      reader->ReadString (
        DEFAULT_XML_DESCRIPTION_NODE_NAME));

    skillInfo_.SetPower (reader->ReadInt (DEFAULT_XML_POWER_NODE_NAME));

    skillInfo_.SetPP (reader->ReadInt (DEFAULT_XML_PP_NODE_NAME));

    skillInfo_.SetMaxPP (reader->ReadInt (DEFAULT_XML_MAX_PP_NODE_NAME));

    skillInfo_.SetAccuracy (reader->ReadInt (DEFAULT_XML_ACCURACY_NODE_NAME));

    skillInfo_.SetType (reader->ReadInt (DEFAULT_XML_TYPE_NODE_NAME));

    skillInfo_.SetCategory (reader->ReadInt (DEFAULT_XML_CATEGORY_NODE_NAME));

    skillInfo_.SetTarget (reader->ReadInt (DEFAULT_XML_TARGET_NODE_NAME));

    skillInfo_.SetEffect (reader->ReadInt (DEFAULT_XML_EFFECT_NODE_NAME));

    skillInfo_.SetUse (reader->ReadInt (DEFAULT_XML_USE_NODE_NAME));

    skillInfo_.SetPriority (reader->ReadInt (DEFAULT_XML_PRIORITY_NODE_NAME));
  }
}
