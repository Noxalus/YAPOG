#include "YAPOG/Game/Pokemon/NatureInfoReader.hpp"

namespace yap
{
  const String NatureInfoReader::DEFAULT_XML_ROOT_NODE_NAME = "Nature";
  const String NatureInfoReader::DEFAULT_XML_ID_NODE_NAME = "id";
  const String NatureInfoReader::DEFAULT_XML_NAME_NODE_NAME = "name";
  const String NatureInfoReader::DEFAULT_XML_FACTORS_NODE_NAME = "factors";
  const String NatureInfoReader::DEFAULT_XML_ATTACK_NODE_NAME = "attack";
  const String NatureInfoReader::DEFAULT_XML_DEFENSE_NODE_NAME = "defense";
  const String NatureInfoReader::DEFAULT_XML_SPECIAL_ATTACK_NODE_NAME =
    "specialAttack";
  const String NatureInfoReader::DEFAULT_XML_SPECIAL_DEFENSE_NODE_NAME =
    "specialDefense";
  const String NatureInfoReader::DEFAULT_XML_SPEED_NODE_NAME = "speed";

  NatureInfoReader::NatureInfoReader (NatureInfo& natureInfo)
    : natureInfo_ (natureInfo)
  {
  }

  NatureInfoReader::NatureInfoReader (
    NatureInfo& natureInfo,
    const String& xmlRootNodeName)
    : natureInfo_ (natureInfo),
    xmlRootNodeName_ (xmlRootNodeName)
  {
  }

  NatureInfoReader::~NatureInfoReader ()
  {
  }

  void NatureInfoReader::Visit (XmlReader& visitable)
  {
    auto reader = visitable.ChangeRoot (xmlRootNodeName_);

    natureInfo_.SetID (
      reader->ReadID (
      XmlHelper::GetAttrNodeName (DEFAULT_XML_ID_NODE_NAME)));

    natureInfo_.SetName (reader->ReadString (DEFAULT_XML_NAME_NODE_NAME));

    reader = reader->ChangeRoot (DEFAULT_XML_FACTORS_NODE_NAME);

    natureInfo_.SetAttackFactor (
      reader->ReadFloat (
        DEFAULT_XML_ATTACK_NODE_NAME));

    natureInfo_.SetDefenseFactor (
      reader->ReadFloat (
        DEFAULT_XML_DEFENSE_NODE_NAME));

    natureInfo_.SetSpecialAttackFactor (
      reader->ReadFloat (
        DEFAULT_XML_SPECIAL_ATTACK_NODE_NAME));

    natureInfo_.SetSpecialDefenseFactor (
      reader->ReadFloat (
        DEFAULT_XML_SPECIAL_DEFENSE_NODE_NAME));

    natureInfo_.SetSpeedFactor (
      reader->ReadFloat (
        DEFAULT_XML_SPEED_NODE_NAME));
  }
}
