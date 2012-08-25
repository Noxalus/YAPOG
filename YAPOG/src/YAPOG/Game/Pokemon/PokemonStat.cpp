#include "YAPOG/Game/Pokemon/PokemonStat.hpp"
#include "YAPOG/System/MathHelper.hpp"

namespace yap
{
  PokemonStat::PokemonStat ()
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

  void PokemonStat::SetCurrentHP (const yap::UInt16& value)
  { hitPoint_.SetCurrentValue (value); }

  void PokemonStat::LoadFromPokemonStat (const PokemonStat& stats)
  {
    hitPoint_ = stats.GetHitPoint ();
    attack_ = stats.GetAttack ();
    defense_ = stats.GetDefense ();
    specialAttack_ = stats.GetSpecialAttack ();
    specialDefense_ = stats.GetSpecialDefense ();
    speed_ = stats.GetSpeed ();
  }

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