#ifndef YAPOG_POKEMONSTAT_HPP
# define YAPOG_POKEMONSTAT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Game/Pokemon/HitPoint.hpp"
# include "YAPOG/Game/Pokemon/Attack.hpp"
# include "YAPOG/Game/Pokemon/Defense.hpp"
# include "YAPOG/Game/Pokemon/SpecialAttack.hpp"
# include "YAPOG/Game/Pokemon/SpecialDefense.hpp"
# include "YAPOG/Game/Pokemon/Speed.hpp"

namespace yap
{
  class YAPOG_LIB PokemonStat
  {
    DISALLOW_COPY (PokemonStat);

  public:
    PokemonStat ();

    PokemonStat (
      UInt16 hp, 
      UInt16 atk, 
      UInt16 def, 
      UInt16 speAtk, 
      UInt16 speDef, 
      UInt16 speed);

    HitPoint& GetHitPoint ();
    Attack& GetAttack ();
    Defense& GetDefense ();
    SpecialAttack& GetSpecialAttack ();
    SpecialDefense& GetSpecialDefense ();
    Speed& GetSpeed ();
  private:
    HitPoint hitPoint_;
    Attack attack_;
    Defense defense_;
    SpecialAttack specialAttack_;
    SpecialDefense specialDefense_;
    Speed speed_;
  };
} // namespace yap

#endif // YAPOG_POKEMONSTAT_HPP