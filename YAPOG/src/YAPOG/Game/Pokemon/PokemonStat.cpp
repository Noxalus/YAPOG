#include "YAPOG/Game/Pokemon/PokemonStat.hpp"

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

  void PokemonStat::ComputeStats (const PokemonInfo& pokeInfo, const UInt16& level)
  {
    ComputeHitPoint (pokeInfo.GetHitPoint (), level);
    ComputeAttack (pokeInfo.GetAttack (), level);
    ComputeDefense (pokeInfo.GetDefense (), level);
    ComputeSpecialAttack (pokeInfo.GetSpecialAttack(), level);
    ComputeSpecialDefense (pokeInfo.GetSpecialDefense (), level);
    ComputeSpeed (pokeInfo.GetSpeed (), level);
  }

  void PokemonStat::ComputeHitPoint (const int& baseHitPoint, const UInt16& level)
  {
    hitPoint_.SetValue = 42;
  }

  void PokemonStat::ComputeAttack (const int& baseAttack, const UInt16& level)
  {
  }

  void PokemonStat::ComputeDefense (const int& baseDefense, const UInt16& level)
  {
  }

  void PokemonStat::ComputeSpecialAttack (const int& baseSpecialAttack, const UInt16& level)
  {
  }

  void PokemonStat::ComputeSpecialDefense (const int& baseSpecialDefense, const UInt16& level)
  {
  }

  void PokemonStat::ComputeSpeed (const int& baseSpeed, const UInt16& level)
  {
  }

} // namespace yap