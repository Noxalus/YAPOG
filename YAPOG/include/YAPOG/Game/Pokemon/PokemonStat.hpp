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

    HitPoint& GetHitPoint ();
    Attack& GetAttack ();
    Defense& GetDefense ();
    SpecialAttack& GetSpecialAttack ();
    SpecialDefense& GetSpecialDefense ();
    Speed& GetSpeed ();

    /// @brief Computes all the statistics of the Pokemon
    /// from its base statistics, its level and its nature
    /// @param pokeInfo Base statistics of the Pokemon.
    /// @param level Level of the Pokemon.
    /// @param natureInfo Contains the nature factors of all stats.
    void ComputeStats (const PokemonInfo& pokeInfo, const UInt16& level, const NatureInfo& natureInfo);

  private:

    /// @brief Computes the Hit Points of the Pokemon
    /// from its base statistics, its level and its nature.
    /// @param baseHitPoint Base Hit Points of the Pokemon.
    /// @param level Level of the Pokemon.
    void ComputeHitPoint (const int& baseHitPoint, const UInt16& level);

    /// @brief Computes the Attack of the Pokemon
    /// from its base statistics, its level and its nature.
    /// @param baseHitPoint Base Attack of the Pokemon.
    /// @param level Level of the Pokemon.
    /// @param natureFactor Nature factor of the pokemon for this specific stat.
    void ComputeAttack (const int& baseAttack, const UInt16& level, const float& natureFactor);

    /// @brief Computes the Defense of the Pokemon
    /// from its base statistics, its level and its nature.
    /// @param baseHitPoint Base Defense of the Pokemon.
    /// @param level Level of the Pokemon.
    /// @param natureFactor Nature factor of the pokemon for this specific stat.
    void ComputeDefense (const int& baseDefense, const UInt16& level, const float& natureFactor);

    /// @brief Computes the Special Attack of the Pokemon
    /// from its base statistics, its level and its nature.
    /// @param baseHitPoint Base Special Attack of the Pokemon.
    /// @param level Level of the Pokemon.
    /// @param natureFactor Nature factor of the pokemon for this specific stat.
    void ComputeSpecialAttack (const int& baseSpecialAttack, const UInt16& level, const float& natureFactor);

    /// @brief Computes the Special Defense of the Pokemon
    /// from its base statistics, its level and its nature.
    /// @param baseHitPoint Base Special Defense of the Pokemon.
    /// @param level Level of the Pokemon.
    /// @param natureFactor Nature factor of the pokemon for this specific stat.
    void ComputeSpecialDefense (const int& baseSpecialDefense, const UInt16& level, const float& natureFactor);

    /// @brief Computes the Speed of the Pokemon
    /// from its base statistics, its level and its nature.
    /// @param baseHitPoint Base Speed of the Pokemon.
    /// @param level Level of the Pokemon.
    /// @param natureFactor Nature factor of the pokemon for this specific stat.
    void ComputeSpeed (const int& baseSpeed, const UInt16& level, const float& natureFactor);

    HitPoint hitPoint_;
    Attack attack_;
    Defense defense_;
    SpecialAttack specialAttack_;
    SpecialDefense specialDefense_;
    Speed speed_;
  };
} // namespace yap

#endif // YAPOG_POKEMONSTAT_HPP