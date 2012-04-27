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

} // namespace yap