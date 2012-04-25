#include "YAPOG/Game/Pokemon/PokemonInfoReader.hpp"

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

    visitable.UpChangeRoot ();

    // </PokemonInfo>
  }
}