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

  void PokemonStat::ComputeStats (const PokemonInfo& pokeInfo, const UInt16& level, const NatureInfo& natureInfo)
  {
    ComputeHitPoint (pokeInfo.GetHitPoint (), level);
    ComputeAttack (pokeInfo.GetAttack (), level, natureInfo.GetAttackFactor ());
    ComputeDefense (pokeInfo.GetDefense (), level, natureInfo.GetDefenseFactor ());
    ComputeSpecialAttack (pokeInfo.GetSpecialAttack(), level, natureInfo.GetSpecialAttackFactor ());
    ComputeSpecialDefense (pokeInfo.GetSpecialDefense (), level, natureInfo.GetSpecialDefenseFactor ());
    ComputeSpeed (pokeInfo.GetSpeed (), level, natureInfo.GetSpeedFactor ());
  }

  void PokemonStat::ComputeHitPoint (const int& baseHitPoint, const UInt16& level)
  {
    UInt16 result = MathHelper::Floor ((((hitPoint_.GetIndividualValue () + (2 * baseHitPoint) + 
      MathHelper::Floor (hitPoint_.GetEffortValue () / 4) + 100) * level) / 100)) + 10;

    hitPoint_.SetValue (result);
  }

  void PokemonStat::ComputeAttack (const int& baseAttack, const UInt16& level, const float& natureFactor)
  {
    UInt16 result = MathHelper::Floor (((hitPoint_.GetIndividualValue () + (2 * baseAttack) + 
      MathHelper::Floor (hitPoint_.GetEffortValue () / 4)) * level) / 100) + 5;

    result = MathHelper::Floor (result * natureFactor);

    attack_.SetValue (result);
  }

  void PokemonStat::ComputeDefense (const int& baseDefense, const UInt16& level, const float& natureFactor)
  {
    UInt16 result = MathHelper::Floor (((hitPoint_.GetIndividualValue () + (2 * baseDefense) + 
      MathHelper::Floor (hitPoint_.GetEffortValue () / 4)) * level) / 100) + 5;

    result = MathHelper::Floor (result * natureFactor);

    defense_.SetValue (result);
  }

  void PokemonStat::ComputeSpecialAttack (const int& baseSpecialAttack, const UInt16& level, const float& natureFactor)
  {
    UInt16 result = MathHelper::Floor (((hitPoint_.GetIndividualValue () + (2 * baseSpecialAttack) + 
      MathHelper::Floor (hitPoint_.GetEffortValue () / 4)) * level) / 100) + 5;

    result = MathHelper::Floor (result * natureFactor);

    specialAttack_.SetValue (result);
  }

  void PokemonStat::ComputeSpecialDefense (const int& baseSpecialDefense, const UInt16& level, const float& natureFactor)
  {
    UInt16 result = MathHelper::Floor (((hitPoint_.GetIndividualValue () + (2 * baseSpecialDefense) + 
      MathHelper::Floor (hitPoint_.GetEffortValue () / 4)) * level) / 100) + 5;

    result = MathHelper::Floor (result * natureFactor);

    specialDefense_.SetValue (result);
  }

  void PokemonStat::ComputeSpeed (const int& baseSpeed, const UInt16& level, const float& natureFactor)
  {
    UInt16 result = MathHelper::Floor (((hitPoint_.GetIndividualValue () + (2 * baseSpeed) + 
      MathHelper::Floor (hitPoint_.GetEffortValue () / 4)) * level) / 100) + 5;


    result = MathHelper::Floor (result * natureFactor);
    speed_.SetValue (result);
  }

} // namespace yap