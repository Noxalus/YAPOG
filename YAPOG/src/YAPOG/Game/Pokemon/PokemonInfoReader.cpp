#include "YAPOG/Game/Pokemon/PokemonInfoReader.hpp"

namespace yap
{
  const String PokemonInfoReader::DEFAULT_XML_ROOT_NODE_NAME = "PokemonInfo";
  const String PokemonInfoReader::DEFAULT_XML_ID_NODE_NAME = "id";
  const String PokemonInfoReader::DEFAULT_XML_NAME_NODE_NAME = "name";
  const String PokemonInfoReader::DEFAULT_XML_GRAPHICS_NODE_NAME = "graphics";
  const String PokemonInfoReader::DEFAULT_XML_GRAPHICS_ICON_NODE_NAME = "icon";
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

    // <graphic>

    // <icon>
    /*
    visitable.DownChangeRoot (DEFAULT_XML_GRAPHICS_NODE_NAME);
    pokeInfo_.SetAttack (visitable.ReadString 
      (DEFAULT_XML_GRAPHICS_ICON_NODE_NAME));
    visitable.UpChangeRoot ();
    */
    // </icon>

    // </graphic>

    // <name>

    pokeInfo_.SetName (visitable.ReadString (DEFAULT_XML_NAME_NODE_NAME));

    // </name>

    visitable.UpChangeRoot ();

    // </PokemonInfo>
  }
}