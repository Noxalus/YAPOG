#include "YAPOG/Game/Pokemon/PokemonInfoReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReaderCollection.hpp"
#include "YAPOG/System/StringHelper.hpp"

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
  const String PokemonInfoReader:: DEFAULT_XML_EVOLUTION_NODE_NAME = "evolution";
  const String PokemonInfoReader:: DEFAULT_XML_POKEMON_ID_NODE_NAME = "pokemonID";
  const String PokemonInfoReader:: DEFAULT_XML_STONE_NODE_NAME = "stone";
  const String PokemonInfoReader:: DEFAULT_XML_ITEM_HOLD_NODE_NAME = "itemHold";
  const String PokemonInfoReader::DEFAULT_XML_EFFORT_VALUES_NODE_NAME = "effortValues";


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
    auto reader = visitable.ChangeRoot (xmlRootNodeName_);

    pokeInfo_.SetID (
      reader->ReadID (
      XmlHelper::GetAttrNodeName (DEFAULT_XML_ID_NODE_NAME)));

    pokeInfo_.SetName (reader->ReadString (DEFAULT_XML_NAME_NODE_NAME));

    pokeInfo_.SetDescription (reader->ReadString (DEFAULT_XML_DESCRIPTION_NODE_NAME));

    pokeInfo_.SetSpecies (reader->ReadString (DEFAULT_XML_SPECIES_NODE_NAME));

    pokeInfo_.SetHeight (reader->ReadFloat (DEFAULT_XML_HEIGHT_NODE_NAME));

    pokeInfo_.SetWeight (reader->ReadFloat (DEFAULT_XML_WEIGHT_NODE_NAME));

    pokeInfo_.SetRarity (reader->ReadInt (DEFAULT_XML_RARITY_NODE_NAME));

    pokeInfo_.SetExperience (reader->ReadInt (DEFAULT_XML_EXPERIENCE_NODE_NAME));

    pokeInfo_.SetExperienceType (StringHelper::Parse<ExperienceType>
      (reader->ReadString (DEFAULT_XML_EXPERIENCE_TYPE_NODE_NAME)));

    reader = reader->ChangeRoot (DEFAULT_XML_BASE_STATS_NODE_NAME);

    pokeInfo_.SetHitPoint (reader->ReadInt (DEFAULT_XML_HP_NODE_NAME));
    pokeInfo_.SetAttack (reader->ReadInt (DEFAULT_XML_ATTACK_NODE_NAME));
    pokeInfo_.SetDefense (reader->ReadInt (DEFAULT_XML_DEFENSE_NODE_NAME));
    pokeInfo_.SetSpecialAttack (reader->ReadInt (DEFAULT_XML_SPECIAL_ATTACK_NODE_NAME));
    pokeInfo_.SetSpecialDefense (reader->ReadInt (DEFAULT_XML_SPECIAL_DEFENSE_NODE_NAME));
    pokeInfo_.SetSpeed (reader->ReadInt (DEFAULT_XML_SPEED_NODE_NAME));

    reader = reader->ChangeRoot (DEFAULT_XML_EFFORT_VALUES_NODE_NAME);

    pokeInfo_.SetHitPointEV (reader->ReadInt (DEFAULT_XML_HP_NODE_NAME));
    pokeInfo_.SetAttackEV (reader->ReadInt (DEFAULT_XML_ATTACK_NODE_NAME));
    pokeInfo_.SetDefenseEV (reader->ReadInt (DEFAULT_XML_DEFENSE_NODE_NAME));
    pokeInfo_.SetSpecialAttackEV (reader->ReadInt (DEFAULT_XML_SPECIAL_ATTACK_NODE_NAME));
    pokeInfo_.SetSpecialDefenseEV (reader->ReadInt (DEFAULT_XML_SPECIAL_DEFENSE_NODE_NAME));
    pokeInfo_.SetSpeedEV (reader->ReadInt (DEFAULT_XML_SPEED_NODE_NAME));

    if (reader->NodeExists (DEFAULT_XML_EVOLUTION_NODE_NAME))
    {
      auto evolutionReader = reader->ChangeRoot (
        DEFAULT_XML_EVOLUTION_NODE_NAME);

      pokeInfo_.SetEvolutionLevel (
        evolutionReader->ReadInt (
          XmlHelper::GetAttrNodeName (DEFAULT_XML_LEVEL_ATTR_NAME)));
      pokeInfo_.SetPokemonEvolutionID (evolutionReader->ReadID ());
    }

    reader = reader->ChangeRoot (DEFAULT_XML_BASE_SKILLS_NODE_NAME);

    yap::XmlReaderCollection skillReaders;
    reader->ReadNodes (DEFAULT_XML_SKILL_NODE_NAME, skillReaders);
    for (auto& skillReader : skillReaders)
    {
      UInt16 level = skillReader->ReadInt (
        XmlHelper::GetAttrNodeName (DEFAULT_XML_LEVEL_ATTR_NAME));
      ID skillID = skillReader->ReadID ();

      pokeInfo_.AddBaseSkill (level, skillID);
    }

    reader = reader->ChangeRoot (DEFAULT_XML_TYPES_NODE_NAME);

    pokeInfo_.SetType1 (reader->ReadInt (DEFAULT_XML_TYPE1_NODE_NAME));

    pokeInfo_.SetType2 (reader->ReadInt (DEFAULT_XML_TYPE2_NODE_NAME));
  }

  void PokemonInfoReader::ParseEvolution ()
  {
  }
}
