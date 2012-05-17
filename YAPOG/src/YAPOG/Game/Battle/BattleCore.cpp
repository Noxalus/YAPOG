#include "YAPOG/Game/Battle/BattleCore.hpp"
#include "YAPOG/System/RandomHelper.hpp"

namespace yap
{
  BattleCore::BattleCore ()
  {
  }

  int BattleCore::ComputeDamage (
    const PokemonSkill& move, 
    const PokemonFighter& attacker, 
    const PokemonFighter& defender)
  {
    float stab = 1.f;
    float type = defender.GetTypeEffectFactor (move.GetType ());
    float critical = 1.f;
    float other = 1.f;
    float rand = RandomHelper::GetNext (0.85f, 1.0f);
    float modifier = stab * type * critical * other * rand;
    float levelFactor = (2 * attacker.GetLevel () + 10) / 250.f;
    float atkOverDef = 1.f;

    if (move.GetCategory () == 1)
    {
      if (defender.GetDefense ().GetValue () != 0)
      {
        atkOverDef = 
          attacker.GetAttack ().GetValue () / 
          defender.GetDefense ().GetValue ();
      }
    }
    else
    {
      if (defender.GetSpecialDefense ().GetValue () != 0)
      {
        atkOverDef = 
          attacker.GetSpecialAttack ().GetValue () / 
          defender.GetSpecialDefense ().GetValue ();
      }
    }

    float base = move.GetPower ();

    float damage = levelFactor * atkOverDef * base + 2;
    damage *= modifier;

    return damage;
  }
} // namespace yap