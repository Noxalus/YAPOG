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

  HitPoint& PokemonStat::GetHitPoint ()
  {
    return hitPoint_;
  }

  Attack& PokemonStat::GetAttack ()
  {
    return attack_;
  }

  Defense& PokemonStat::GetDefense ()
  {
    return defense_;
  }

  SpecialAttack& PokemonStat::GetSpecialAttack ()
  {
    return specialAttack_;
  }

  SpecialDefense& PokemonStat::GetSpecialDefense ()
  {
    return specialDefense_;
  }

  Speed& PokemonStat::GetSpeed ()
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