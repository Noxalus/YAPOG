#ifndef YAPOG_POKEMONSTAT_HPP
# define YAPOG_POKEMONSTAT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
# include "YAPOG/Game/Pokemon/NatureInfo.hpp"
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

    const HitPoint& GetHitPoint () const;
    const Attack& GetAttack () const;
    const Defense& GetDefense () const;
    const SpecialAttack& GetSpecialAttack () const;
    const SpecialDefense& GetSpecialDefense () const;
    const Speed& GetSpeed () const;

    /// @brief Computes all the statistics of the Pokemon
    /// from its base statistics, its level and its nature
    /// @param pokeInfo Base statistics of the Pokemon.
    /// @param level Level of the Pokemon.
    /// @param natureInfo Contains the nature factors of all stats.
    void ComputeStats (
      const PokemonInfo& pokeInfo, 
      const UInt16& level, 
      const NatureInfo& natureInfo);

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