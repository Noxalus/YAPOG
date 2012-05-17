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
  public:
    PokemonStat ();

    PokemonStat (
      UInt16 hp, 
      UInt16 atk, 
      UInt16 def, 
      UInt16 speAtk, 
      UInt16 speDef, 
      UInt16 speed);

    PokemonStat (
      const HitPoint& hp,
      const Attack& atk,
      const Defense& def,
      const SpecialAttack& speAtk,
      const SpecialDefense& speDef,
      const Speed& speed);

    /// Getters
    const HitPoint& GetHitPoint () const;
    const Attack& GetAttack () const;
    const Defense& GetDefense () const;
    const SpecialAttack& GetSpecialAttack () const;
    const SpecialDefense& GetSpecialDefense () const;
    const Speed& GetSpeed () const;

    /// Setters
    void SetHitPoint (const HitPoint& value);
    void SetAttack(const Attack& value);
    void SetDefense (const Defense& value);
    void SetSpecialAttack (const SpecialAttack& value);
    void SetSpecialDefense (const SpecialDefense& value);
    void SetSpeed (const Speed& value);

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