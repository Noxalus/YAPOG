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
    UInt16 result = MathHelper::Floor ((((hitPoint_.GetIndividualValue () + (2 * baseHitPoint) + 
      MathHelper::Floor (hitPoint_.GetEffortValue () / 4) + 100) * level) / 100)) + 10;

    hitPoint_.SetValue (result);
  }

  void PokemonStat::ComputeAttack (const int& baseAttack, const UInt16& level)
  {
    UInt16 result = MathHelper::Floor (((hitPoint_.GetIndividualValue () + (2 * baseAttack) + 
      MathHelper::Floor (hitPoint_.GetEffortValue () / 4)) * level) / 100) + 5;

    attack_.SetValue (result);
  }

  void PokemonStat::ComputeDefense (const int& baseDefense, const UInt16& level)
  {
    UInt16 result = MathHelper::Floor (((hitPoint_.GetIndividualValue () + (2 * baseDefense) + 
      MathHelper::Floor (hitPoint_.GetEffortValue () / 4)) * level) / 100) + 5;

    defense_.SetValue (result);
  }

  void PokemonStat::ComputeSpecialAttack (const int& baseSpecialAttack, const UInt16& level)
  {
    UInt16 result = MathHelper::Floor (((hitPoint_.GetIndividualValue () + (2 * baseSpecialAttack) + 
      MathHelper::Floor (hitPoint_.GetEffortValue () / 4)) * level) / 100) + 5;

    specialAttack_.SetValue (result);
  }

  void PokemonStat::ComputeSpecialDefense (const int& baseSpecialDefense, const UInt16& level)
  {
    UInt16 result = MathHelper::Floor (((hitPoint_.GetIndividualValue () + (2 * baseSpecialDefense) + 
      MathHelper::Floor (hitPoint_.GetEffortValue () / 4)) * level) / 100) + 5;

    specialDefense_.SetValue (result);
  }

  void PokemonStat::ComputeSpeed (const int& baseSpeed, const UInt16& level)
  {
    UInt16 result = MathHelper::Floor (((hitPoint_.GetIndividualValue () + (2 * baseSpeed) + 
      MathHelper::Floor (hitPoint_.GetEffortValue () / 4)) * level) / 100) + 5;

    speed_.SetValue (result);
  }

} // namespace yap