#ifndef YAPOG_POKEMONINFO_HPP
# define YAPOG_POKEMONINFO_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class YAPOG_LIB PokemonInfo
  {
    public:
      PokemonInfo ();
    private:
     int pokedexId_;
     String name_;
     int baseHitPoint_;
     int baseAttack_;
     int baseDefense_;
     int baseSpeed_;
     int baseSpecialAttack_;
     int baseSpecialDefense_;
     int type1_;
     int type2_;
  };
} // namespace yap

#endif // YAPOG_POKEMONINFO_HPP

