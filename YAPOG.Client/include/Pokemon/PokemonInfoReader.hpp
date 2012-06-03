#ifndef YAPOG_CLIENT_POKEMONINFOREADER_HPP
# define YAPOG_CLIENT_POKEMONINFOREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/PokemonInfoReader.hpp"

namespace ycl
{
  class PokemonInfo;

  class PokemonInfoReader : public yap::PokemonInfoReader
  {
    DISALLOW_COPY (PokemonInfoReader);

  public:
    PokemonInfoReader (PokemonInfo& pokeInfo);
    PokemonInfoReader (PokemonInfo& map, const yap::String& xmlRootNodeName);
    virtual ~PokemonInfoReader ();

    virtual void Visit (yap::XmlReader& visitable);
  private:
    PokemonInfo& graphicPokemonInfo_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONINFOREADER_HPP

