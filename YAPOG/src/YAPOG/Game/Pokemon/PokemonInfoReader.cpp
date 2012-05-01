#include "YAPOG/Game/Pokemon/PokemonInfoReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReaderCollection.hpp"

namespace yap
{
  const String PokemonInfoReader::DEFAULT_XML_ROOT_NODE_NAME = "PokemonInfo";
  const String PokemonInfoReader::DEFAULT_XML_ID_NODE_NAME = "id";
  const String PokemonInfoReader::DEFAULT_XML_NAME_NODE_NAME = "name";
  const String PokemonInfoReader::DEFAULT_XML_DESCRIPTION_NODE_NAME = "description";
  const String PokemonInfoReader::DEFAULT_XML_SPECIES_NODE_NAME = "species";
  const String PokemonInfoReader::DEFAULT_XML_HEIGHT_NODE_NAME = "height";
  const String PokemonInfoReader::DEFAULT_XML_WEIGHT_NODE_NAME = "weight";
  const String PokemonInfoReader::DEFAULT_XML_RARITY_NODE_NAME = "rarity";
  const String PokemonInfoReader::DEFAULT_XML_EXPERIENCE_NODE_NAME = "experience";
  const String PokemonInfoReader::DEFAULT_XML_BASE_STATS_NODE_NAME = "baseStats";
  const String PokemonInfoReader::DEFAULT_XML_HP_NODE_NAME = "hp";
  const String PokemonInfoReader::DEFAULT_XML_ATTACK_NODE_NAME = "attack";
  const String PokemonInfoReader::DEFAULT_XML_DEFENSE_NODE_NAME = "defense";
  const String PokemonInfoReader::DEFAULT_XML_SPECIAL_ATTACK_NODE_NAME = "specialAttack";
  const String PokemonInfoReader::DEFAULT_XML_SPECIAL_DEFENSE_NODE_NAME = "specialDefense";
  const String PokemonInfoReader::DEFAULT_XML_SPEED_NODE_NAME = "speed";
  const String PokemonInfoReader::DEFAULT_XML_TYPES_NODE_NAME = "types";
  const String PokemonInfoReader::DEFAULT_XML_TYPE1_NODE_NAME = "type1";
  const String PokemonInfoReader::DEFAULT_XML_TYPE2_NODE_NAME = "type2";
  const String PokemonInfoReader::DEFAULT_XML_EXPERIENCE_TYPE_NODE_NAME = "experienceType";
  const String PokemonInfoReader::DEFAULT_XML_BASE_SKILLS_NODE_NAME = "baseSkills";
  const String PokemonInfoReader::DEFAULT_XML_SKILL_NODE_NAME = "skill";
  const String PokemonInfoReader::DEFAULT_XML_LEVEL_ATTR_NAME = "level";


  PokemonInfoReader::PokemonInfoReader (PokemonInfo& pokeInfo)
    : pokeInfo_ (pokeInfo)
  {
  }

  PokemonInfoReader::PokemonInfoReader (
    PokemonInfo& pokeInfo,
    const String& xmlRootNodeName)
    : pokeInfo_ (pokeInfo),
    xmlRootNodeName_ (xmlRootNodeName)
  {
  }

  PokemonInfoReader::~PokemonInfoReader ()
  {
  }

  void PokemonInfoReader::Visit (XmlReader& visitable)
  {
    // <PokemonInfo id="{id}">

    if (!visitable.TryChangeRoot (DEFAULT_XML_ROOT_NODE_NAME))
    {
      throw Exception (
        "Failed to read `" + DEFAULT_XML_ROOT_NODE_NAME + "' node.");
    }

    pokeInfo_.SetID (
      visitable.ReadID (
      XmlHelper::GetAttrNodeName (DEFAULT_XML_ID_NODE_NAME)));

    // <name>

    pokeInfo_.SetName (visitable.ReadString (DEFAULT_XML_NAME_NODE_NAME));

    // </name>

    // <description>

    pokeInfo_.SetDescription (visitable.ReadString (DEFAULT_XML_DESCRIPTION_NODE_NAME));

    // </description>

    // <species>

    pokeInfo_.SetSpecies (visitable.ReadString (DEFAULT_XML_SPECIES_NODE_NAME));

    // </species>

    // <height>

    pokeInfo_.SetHeight (visitable.ReadFloat (DEFAULT_XML_HEIGHT_NODE_NAME));

    // </height>

    // <weight>

    pokeInfo_.SetWeight (visitable.ReadFloat (DEFAULT_XML_WEIGHT_NODE_NAME));

    // </weight>

    // <rarity>

    pokeInfo_.SetRarity (visitable.ReadInt (DEFAULT_XML_RARITY_NODE_NAME));

    // </rarity>

    // <experience>

    pokeInfo_.SetExperience (visitable.ReadInt (DEFAULT_XML_EXPERIENCE_NODE_NAME));

    // </experience>

    // <experienceType>

    pokeInfo_.SetExperienceType (visitable.ReadInt (DEFAULT_XML_EXPERIENCE_TYPE_NODE_NAME));

    // </experienceType>

    // <baseStat>

    if (!visitable.TryChangeRoot (DEFAULT_XML_BASE_STATS_NODE_NAME))
    {
      throw Exception (
        "Failed to read `" + DEFAULT_XML_BASE_STATS_NODE_NAME + "' node.");
    }

    pokeInfo_.SetHitPoint (visitable.ReadInt (DEFAULT_XML_HP_NODE_NAME));
    pokeInfo_.SetAttack (visitable.ReadInt (DEFAULT_XML_ATTACK_NODE_NAME));
    pokeInfo_.SetDefense (visitable.ReadInt (DEFAULT_XML_DEFENSE_NODE_NAME));
    pokeInfo_.SetSpecialAttack (visitable.ReadInt (DEFAULT_XML_SPECIAL_ATTACK_NODE_NAME));
    pokeInfo_.SetSpecialDefense (visitable.ReadInt (DEFAULT_XML_SPECIAL_DEFENSE_NODE_NAME));
    pokeInfo_.SetSpeed (visitable.ReadInt (DEFAULT_XML_SPEED_NODE_NAME));

    visitable.UpChangeRoot ();

    // </baseStat>

    // <baseSkills>

    if (!visitable.TryChangeRoot (DEFAULT_XML_BASE_SKILLS_NODE_NAME))
    {
      throw Exception (
        "Failed to read `" + DEFAULT_XML_BASE_SKILLS_NODE_NAME + "' node.");
    }

    yap::XmlReaderCollection skillReaders;
    visitable.ReadNodes (DEFAULT_XML_SKILL_NODE_NAME, skillReaders);
    for (auto& skillReader : skillReaders)
    {
      UInt16 level = skillReader->ReadInt (
        XmlHelper::GetAttrNodeName (DEFAULT_XML_LEVEL_ATTR_NAME));
      ID skillID = skillReader->ReadID ();

      pokeInfo_.AddBaseSkill (level, skillID);
      
    }

    visitable.UpChangeRoot ();

    // </baseSkills>

    // <types>

    if (!visitable.TryChangeRoot (DEFAULT_XML_TYPES_NODE_NAME))
    {
      throw Exception (
        "Failed to read `" + DEFAULT_XML_TYPES_NODE_NAME + "' node.");
    }

    // <type1>

    pokeInfo_.SetType1 (visitable.ReadInt (DEFAULT_XML_TYPE1_NODE_NAME));

    // </type1>

    // <type2>

    pokeInfo_.SetType2 (visitable.ReadInt (DEFAULT_XML_TYPE2_NODE_NAME));

    // </type2>

    visitable.UpChangeRoot ();

    // </types>

    visitable.UpChangeRoot ();

    // </PokemonInfo>
  }
}
