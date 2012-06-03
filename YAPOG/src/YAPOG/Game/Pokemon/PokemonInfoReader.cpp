#include "YAPOG/Game/Pokemon/PokemonInfoReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReaderCollection.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace yap
{
  const String PokemonInfoReader::
    DEFAULT_XML_ROOT_NODE_NAME = "PokemonInfo";
  const String PokemonInfoReader::
    DEFAULT_XML_ID_NODE_NAME = "id";
  const String PokemonInfoReader::
    DEFAULT_XML_NAME_NODE_NAME = "name";
  const String PokemonInfoReader::
    DEFAULT_XML_DESCRIPTION_NODE_NAME = "description";
  const String PokemonInfoReader::
    DEFAULT_XML_SPECIES_NODE_NAME = "species";
  const String PokemonInfoReader::
    DEFAULT_XML_HEIGHT_NODE_NAME = "height";
  const String PokemonInfoReader::
    DEFAULT_XML_WEIGHT_NODE_NAME = "weight";
  const String PokemonInfoReader::
    DEFAULT_XML_RARITY_NODE_NAME = "rarity";
  const String PokemonInfoReader::
    DEFAULT_XML_EXPERIENCE_NODE_NAME = "experience";
  const String PokemonInfoReader::
    DEFAULT_XML_BASE_STATS_NODE_NAME = "baseStats";
  const String PokemonInfoReader::
    DEFAULT_XML_HP_NODE_NAME = "hp";
  const String PokemonInfoReader::
    DEFAULT_XML_ATTACK_NODE_NAME = "attack";
  const String PokemonInfoReader::
    DEFAULT_XML_DEFENSE_NODE_NAME = "defense";
  const String PokemonInfoReader::
    DEFAULT_XML_SPECIAL_ATTACK_NODE_NAME = "specialAttack";
  const String PokemonInfoReader::
    DEFAULT_XML_SPECIAL_DEFENSE_NODE_NAME = "specialDefense";
  const String PokemonInfoReader::
    DEFAULT_XML_SPEED_NODE_NAME = "speed";
  const String PokemonInfoReader::
    DEFAULT_XML_TYPES_NODE_NAME = "types";
  const String PokemonInfoReader::
    DEFAULT_XML_TYPE1_NODE_NAME = "type1";
  const String PokemonInfoReader::
    DEFAULT_XML_TYPE2_NODE_NAME = "type2";
  const String PokemonInfoReader::
    DEFAULT_XML_EXPERIENCE_TYPE_NODE_NAME = "experienceType";
  const String PokemonInfoReader::
    DEFAULT_XML_BASE_SKILLS_NODE_NAME = "baseSkills";
  const String PokemonInfoReader::
    DEFAULT_XML_SKILL_NODE_NAME = "skill";
  const String PokemonInfoReader::
    DEFAULT_XML_LEVEL_ATTR_NAME = "level";
  const String PokemonInfoReader::
    DEFAULT_XML_EVOLUTION_NODE_NAME = "evolution";
  const String PokemonInfoReader::
    DEFAULT_XML_POKEMON_ID_NODE_NAME = "pokemonID";
  const String PokemonInfoReader::
    DEFAULT_XML_STONE_NODE_NAME = "stone";
  const String PokemonInfoReader::
    DEFAULT_XML_ITEM_HOLD_NODE_NAME = "itemHold";
  const String PokemonInfoReader::
    DEFAULT_XML_EFFORT_VALUES_NODE_NAME = "effortValues";
  const String PokemonInfoReader::
    DEFAULT_XML_GENDER_NODE_NAME = "gender";
  const String PokemonInfoReader::
    DEFAULT_XML_GRAPHICS_NODE_NAME = "graphics";
  const String PokemonInfoReader::
    DEFAULT_XML_ICON_NODE_NAME = "icon";
  const String PokemonInfoReader::
    DEFAULT_XML_MALE_NODE_NAME = "male";
  const String PokemonInfoReader::
    DEFAULT_XML_FEMALE_NODE_NAME = "female";
  const String PokemonInfoReader::
    DEFAULT_XML_FRONT_NODE_NAME = "front";
  const String PokemonInfoReader::
    DEFAULT_XML_BACK_NODE_NAME = "back";
  const String PokemonInfoReader::
    DEFAULT_XML_SHINY_NODE_NAME = "shiny";


  PokemonInfoReader::PokemonInfoReader (PokemonInfo& pokemonInfo)
    : pokemonInfo_ (pokemonInfo)
  {
  }

  PokemonInfoReader::PokemonInfoReader (
    PokemonInfo& pokemonInfo,
    const String& xmlRootNodeName)
    : pokemonInfo_ (pokemonInfo),
    xmlRootNodeName_ (xmlRootNodeName)
  {
  }

  PokemonInfoReader::~PokemonInfoReader ()
  {
  }

  void PokemonInfoReader::Visit (XmlReader& visitable)
  {
    auto reader = visitable.ChangeRoot (xmlRootNodeName_);

    pokemonInfo_.SetID (
      reader->ReadID (
      XmlHelper::GetAttrNodeName (DEFAULT_XML_ID_NODE_NAME)));

    pokemonInfo_.SetName (reader->ReadString (DEFAULT_XML_NAME_NODE_NAME));

    pokemonInfo_.SetDescription (
      reader->ReadString (DEFAULT_XML_DESCRIPTION_NODE_NAME));

    pokemonInfo_.SetSpecies (
      reader->ReadString (DEFAULT_XML_SPECIES_NODE_NAME));

    pokemonInfo_.SetHeight (
      reader->ReadFloat (DEFAULT_XML_HEIGHT_NODE_NAME));

    pokemonInfo_.SetWeight (
      reader->ReadFloat (DEFAULT_XML_WEIGHT_NODE_NAME));

    pokemonInfo_.SetRarity (
      reader->ReadInt (DEFAULT_XML_RARITY_NODE_NAME));

    pokemonInfo_.SetGenderProbability (
      reader->ReadFloat (DEFAULT_XML_GENDER_NODE_NAME));

    pokemonInfo_.SetExperience (
      reader->ReadInt (DEFAULT_XML_EXPERIENCE_NODE_NAME));

    pokemonInfo_.SetExperienceType (StringHelper::Parse<ExperienceType>
      (reader->ReadString (DEFAULT_XML_EXPERIENCE_TYPE_NODE_NAME)));

    auto statsReader = 
      reader->ChangeRoot (DEFAULT_XML_BASE_STATS_NODE_NAME);

    pokemonInfo_.SetHitPoint (
      statsReader->ReadInt (DEFAULT_XML_HP_NODE_NAME));
    pokemonInfo_.SetAttack (
      statsReader->ReadInt (DEFAULT_XML_ATTACK_NODE_NAME));
    pokemonInfo_.SetDefense (
      statsReader->ReadInt (DEFAULT_XML_DEFENSE_NODE_NAME));
    pokemonInfo_.SetSpecialAttack (
      statsReader->ReadInt (DEFAULT_XML_SPECIAL_ATTACK_NODE_NAME));
    pokemonInfo_.SetSpecialDefense (
      statsReader->ReadInt (DEFAULT_XML_SPECIAL_DEFENSE_NODE_NAME));
    pokemonInfo_.SetSpeed (
      statsReader->ReadInt (DEFAULT_XML_SPEED_NODE_NAME));

    auto EVReader = 
      reader->ChangeRoot (DEFAULT_XML_EFFORT_VALUES_NODE_NAME);

    pokemonInfo_.SetHitPointEV (
      EVReader->ReadInt (DEFAULT_XML_HP_NODE_NAME));
    pokemonInfo_.SetAttackEV (
      EVReader->ReadInt (DEFAULT_XML_ATTACK_NODE_NAME));
    pokemonInfo_.SetDefenseEV (
      EVReader->ReadInt (DEFAULT_XML_DEFENSE_NODE_NAME));
    pokemonInfo_.SetSpecialAttackEV (
      EVReader->ReadInt (DEFAULT_XML_SPECIAL_ATTACK_NODE_NAME));
    pokemonInfo_.SetSpecialDefenseEV (
      EVReader->ReadInt (DEFAULT_XML_SPECIAL_DEFENSE_NODE_NAME));
    pokemonInfo_.SetSpeedEV (
      EVReader->ReadInt (DEFAULT_XML_SPEED_NODE_NAME));

    if (reader->NodeExists (DEFAULT_XML_EVOLUTION_NODE_NAME))
    {
      auto evolutionReader = reader->ChangeRoot (
        DEFAULT_XML_EVOLUTION_NODE_NAME);

      pokemonInfo_.SetEvolutionLevel (
        evolutionReader->ReadInt (
        XmlHelper::GetAttrNodeName (DEFAULT_XML_LEVEL_ATTR_NAME)));
      pokemonInfo_.SetPokemonEvolutionID (evolutionReader->ReadID ());
    }

    auto baseSkillsReader = 
      reader->ChangeRoot (DEFAULT_XML_BASE_SKILLS_NODE_NAME);

    yap::XmlReaderCollection skillReaders;
    baseSkillsReader->ReadNodes 
      (DEFAULT_XML_SKILL_NODE_NAME, skillReaders);
    for (auto& skillReader : skillReaders)
    {
      UInt16 level = skillReader->ReadInt (
        XmlHelper::GetAttrNodeName (DEFAULT_XML_LEVEL_ATTR_NAME));
      ID skillID = skillReader->ReadID ();

      pokemonInfo_.AddBaseSkill (level, skillID);
    }

    auto typeReader = reader->ChangeRoot (DEFAULT_XML_TYPES_NODE_NAME);

    pokemonInfo_.SetType1 
      (typeReader->ReadInt (DEFAULT_XML_TYPE1_NODE_NAME));

    pokemonInfo_.SetType2 
      (typeReader->ReadInt (DEFAULT_XML_TYPE2_NODE_NAME));

    auto graphicReader = reader->ChangeRoot (DEFAULT_XML_GRAPHICS_NODE_NAME);

    pokemonInfo_.SetIcon (graphicReader->ReadString (DEFAULT_XML_ICON_NODE_NAME));

    // <male>
    auto maleReader = graphicReader->ChangeRoot (DEFAULT_XML_MALE_NODE_NAME);
    pokemonInfo_.SetMaleFront 
      (maleReader->ReadString (DEFAULT_XML_FRONT_NODE_NAME));
    pokemonInfo_.SetMaleBack 
      (maleReader->ReadString (DEFAULT_XML_BACK_NODE_NAME));

    auto shinyMaleReader = maleReader->ChangeRoot (DEFAULT_XML_SHINY_NODE_NAME);
    pokemonInfo_.SetShinyMaleFront 
      (shinyMaleReader->ReadString (DEFAULT_XML_FRONT_NODE_NAME));
    pokemonInfo_.SetShinyMaleBack 
      (shinyMaleReader->ReadString (DEFAULT_XML_BACK_NODE_NAME));
    // </male>

    // <female>
    auto femaleReader = graphicReader->ChangeRoot (DEFAULT_XML_FEMALE_NODE_NAME);
    pokemonInfo_.SetFemaleFront 
      (femaleReader->ReadString (DEFAULT_XML_FRONT_NODE_NAME));
    pokemonInfo_.SetFemaleBack 
      (femaleReader->ReadString (DEFAULT_XML_BACK_NODE_NAME));

    auto shinyFemaleReader = femaleReader->ChangeRoot (DEFAULT_XML_SHINY_NODE_NAME);
    pokemonInfo_.SetShinyFemaleFront 
      (shinyFemaleReader->ReadString (DEFAULT_XML_FRONT_NODE_NAME));
    pokemonInfo_.SetShinyFemaleBack 
      (shinyFemaleReader->ReadString (DEFAULT_XML_BACK_NODE_NAME));
    // </female>
  }
}
