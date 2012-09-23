#include "YAPOG/Game/Battle/PokemonFighterTeam.hpp"
#include "YAPOG/Game/Battle/PokemonFighter.hpp"
#include "YAPOG/System/Error/Exception.hpp"

namespace yap
{
  PokemonFighterTeam::PokemonFighterTeam ()
    : currentFighterIndex_ (0)
  {
  }

  /// @name IBattleEntity members
  /// @{
  const String& PokemonFighterTeam::GetName () const
  {
    return GetCurrentFighter ().GetName ();
  }

  const PokemonExperience& PokemonFighterTeam::GetExperience () const
  {
    return GetCurrentFighter ().GetExperience ();
  }

  UInt16 PokemonFighterTeam::GetLevel () const
  {
    return GetCurrentFighter ().GetLevel ();
  }

  Gender PokemonFighterTeam::GetGender () const
  {
    return GetCurrentFighter ().GetGender ();
  }

  UInt16 PokemonFighterTeam::GetCurrentHP () const
  {
    return GetCurrentFighter ().GetCurrentHP ();
  }

  UInt16 PokemonFighterTeam::GetMaxHP () const
  {
    return GetCurrentFighter ().GetMaxHP ();
  }

  const TypeInfo& PokemonFighterTeam::GetType1 () const
  {
    return GetCurrentFighter ().GetType1 ();
  }

  const TypeInfo& PokemonFighterTeam::GetType2 () const
  {
    return GetCurrentFighter ().GetType2 ();
  }

  float PokemonFighterTeam::GetTypeEffectFactor (const TypeInfo& type) const
  {
    return GetCurrentFighter ().GetTypeEffectFactor (type);
  }

  const Attack& PokemonFighterTeam::GetAttack () const
  {
    return GetCurrentFighter ().GetStats ().GetAttack ();
  }

  const Defense& PokemonFighterTeam::GetDefense () const
  {
    return GetCurrentFighter ().GetStats ().GetDefense ();
  }

  const SpecialAttack& PokemonFighterTeam::GetSpecialAttack () const
  {
    return GetCurrentFighter ().GetStats ().GetSpecialAttack ();
  }
  const SpecialDefense& PokemonFighterTeam::GetSpecialDefense () const
  {
    return GetCurrentFighter ().GetStats ().GetSpecialDefense ();
  }

  const Speed& PokemonFighterTeam::GetSpeed () const
  {
    return GetCurrentFighter ().GetStats ().GetSpeed ();
  }

   void PokemonFighterTeam::AddExperience (int value)
  {
    GetCurrentFighter ().AddExperience (value);
  }

  void PokemonFighterTeam::TakeDamage (int value)
  {
    GetCurrentFighter ().TakeDamage (value);
  }

  float PokemonFighterTeam::GetHPPercentage () const
  {
    return GetCurrentFighter ().GetHPPercentage ();
  }

  const PokemonMoveSet& PokemonFighterTeam::GetMoveSet () const
  {
    return GetCurrentFighter ().GetMoveSet ();
  }

  const PokemonMove& PokemonFighterTeam::GetMove (int index) const
  {
    return GetCurrentFighter ().GetMove (index);
  }

  const PokemonStat& PokemonFighterTeam::GetStats () const
  {
    return GetCurrentFighter ().GetStats ();
  }

  Event<
      const IBattleEntity&, 
      const ChangeEventArgs<const HitPoint&>&>& 
      PokemonFighterTeam::OnHPChangedEvent ()
  {
    return GetCurrentFighter ().OnHPChangedEvent ();
  }

  Event<
      const IBattleEntity&, 
      const ChangeEventArgs<const PokemonExperience&>&>& 
      PokemonFighterTeam::OnExperienceChangedEvent ()
  {
    return GetCurrentFighter ().OnExperienceChangedEvent ();
  }
  /// @}

  void PokemonFighterTeam::Update (const Time& dt)
  {
    HandleUpdate (dt);
  }

  void PokemonFighterTeam::HandleUpdate (const Time& dt)
  {
  }

} // namespace yap