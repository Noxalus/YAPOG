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

  PokemonStat::PokemonStat (
    const HitPoint& hp,
    const Attack& atk,
    const Defense& def,
    const SpecialAttack& speAtk,
    const SpecialDefense& speDef,
    const Speed& speed)
    : hitPoint_ (hp)
    , attack_ (atk)
    , defense_ (def)
    , specialAttack_ (speAtk)
    , specialDefense_ (speDef)
    , speed_ (speed)
  {
  }

  PokemonStat::PokemonStat (const PokemonStat& copy)
    : hitPoint_ (copy.GetHitPoint ())
    , attack_ (copy.GetAttack ())
    , defense_ (copy.GetDefense ())
    , specialAttack_ (copy.GetSpecialAttack ())
    , specialDefense_ (copy.GetSpecialDefense ())
    , speed_ (copy.GetSpeed ())
  {
  }

  const HitPoint& PokemonStat::GetHitPoint () const
  { return hitPoint_; }

  const Attack& PokemonStat::GetAttack () const
  { return attack_; }

  const Defense& PokemonStat::GetDefense () const
  { return defense_; }

  const SpecialAttack& PokemonStat::GetSpecialAttack () const
  { return specialAttack_; }

  const SpecialDefense& PokemonStat::GetSpecialDefense () const
  { return specialDefense_; }

  const Speed& PokemonStat::GetSpeed () const
  { return speed_; }

  void PokemonStat::SetHitPoint (const HitPoint& value)
  { hitPoint_ = value; }

  void PokemonStat::SetAttack(const Attack& value)
  { attack_ = value; }

  void PokemonStat::SetDefense (const Defense& value)
  { defense_ = value; }

  void PokemonStat::SetSpecialAttack (const SpecialAttack& value)
  { specialAttack_ = value; }

  void PokemonStat::SetSpecialDefense (const SpecialDefense& value)
  { specialDefense_ = value; }

  void PokemonStat::SetSpeed (const Speed& value)
  { speed_ = value; }

  void PokemonStat::SetCurrentHP (const yap::UInt16& value)
  { hitPoint_.SetCurrentValue (value); }

  void PokemonStat::ModifyHitPoint (int value)
  {
    hitPoint_.AddValue (value);
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

  void PokemonStat::RestoreHP ()
  {
    hitPoint_.Restore ();
  }

} // namespace yap