#include "YAPOG/Game/Pokemon/PokemonStat.hpp"
#include "YAPOG/System/MathHelper.hpp"

namespace yap
{
  PokemonStat::PokemonStat ()
  {
  }

  PokemonStat::PokemonStat (
    UInt16 hp, 
    UInt16 atk, 
    UInt16 def, 
    UInt16 speAtk, 
    UInt16 speDef, 
    UInt16 speed)
    : hitPoint_ (hp)
    , attack_ (atk)
    , defense_ (def)
    , specialAttack_ (speAtk)
    , specialDefense_ (speDef)
    , speed_ (speed)
  {
  }

  const HitPoint& PokemonStat::GetHitPoint () const
  {
    return hitPoint_;
  }

  const Attack& PokemonStat::GetAttack () const
  {
    return attack_;
  }

  const Defense& PokemonStat::GetDefense () const
  {
    return defense_;
  }

  const SpecialAttack& PokemonStat::GetSpecialAttack () const
  {
    return specialAttack_;
  }

  const SpecialDefense& PokemonStat::GetSpecialDefense () const
  {
    return specialDefense_;
  }

  const Speed& PokemonStat::GetSpeed () const
  {
    return speed_;
  }

  void PokemonStat::ComputeStats (
    const PokemonInfo& pokeInfo, 
    const UInt16& level, 
    const NatureInfo& natureInfo)
  {
    hitPoint_.ComputeValue (pokeInfo.GetHitPoint (), level);

    attack_.ComputeValue (
      pokeInfo.GetAttack (), 
      level, 
      natureInfo.GetAttackFactor ());

    defense_.ComputeValue (
      pokeInfo.GetDefense (), 
      level, 
      natureInfo.GetDefenseFactor ());

    specialAttack_.ComputeValue (
      pokeInfo.GetSpecialAttack (), 
      level, 
      natureInfo.GetSpecialAttackFactor ());

    specialDefense_.ComputeValue (
      pokeInfo.GetSpecialDefense (), 
      level, 
      natureInfo.GetSpecialDefenseFactor ());

    speed_.ComputeValue (
      pokeInfo.GetSpeed (), 
      level, 
      natureInfo.GetSpeedFactor ());
  }

} // namespace yap