#include "Pokemon/PokemonInfoReader.hpp"
#include "Pokemon/PokemonInfo.hpp"

namespace ycl
{
  PokemonInfoReader::PokemonInfoReader (PokemonInfo& pokeInfo)
    : yap::PokemonInfoReader (pokeInfo)
    , graphicPokemonInfo_ (pokeInfo)
  {
  }

  PokemonInfoReader::PokemonInfoReader (
    PokemonInfo& pokeInfo,
    const yap::String& xmlRootNodeName)
    : yap::PokemonInfoReader (pokeInfo, xmlRootNodeName)
    , graphicPokemonInfo_ (pokeInfo)
  {
  }

  PokemonInfoReader::~PokemonInfoReader ()
  {
  }

  void PokemonInfoReader::Visit (yap::XmlReader& visitable)
  {
    yap::PokemonInfoReader::Visit (visitable);
  }

} // namespace ycl