#ifndef YAPOG_CLIENT_POKEMONINFO_HPP
# define YAPOG_CLIENT_POKEMONINFO_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/PokemonInfo.hpp"

namespace ycl
{
  class PokemonInfo : public yap::PokemonInfo
  {
    DISALLOW_ASSIGN (PokemonInfo);

  public:
    PokemonInfo ();
    PokemonInfo (const yap::ID& id);
    virtual ~PokemonInfo ();

      /// @name ICloneable members.
      /// @{
      virtual PokemonInfo* Clone () const;
      /// @}

    protected:

      PokemonInfo (const PokemonInfo& copy);
  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONINFO_HPP

