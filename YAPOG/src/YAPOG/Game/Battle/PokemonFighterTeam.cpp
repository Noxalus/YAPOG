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
  const yap::ID& PokemonFighterTeam::GetID () const
  {
    return GetCurrentFighter ().GetID ();
  }

  const String& PokemonFighterTeam::GetName () const
  {
    return GetCurrentFighter ().GetName ();
  }

  const UInt16& PokemonFighterTeam::GetLevel () const
  {
    return GetCurrentFighter ().GetLevel ();
  }

  const Gender& PokemonFighterTeam::GetGender () const
  {
    return GetCurrentFighter ().GetGender ();
  }

  const UInt16& PokemonFighterTeam::GetCurrentHP () const
  {
    return GetCurrentFighter ().GetCurrentHP ();
  }

  const UInt16& PokemonFighterTeam::GetMaxHP () const
  {
    return GetCurrentFighter ().GetMaxHP ();
  }

  void PokemonFighterTeam::TakeDamage (int value)
  {
    GetCurrentFighter ().TakeDamage (value);
  }

  float PokemonFighterTeam::GetHPPercentage () const
  {
    return GetCurrentFighter ().GetHPPercentage ();
  }

  const collection::Array<PokemonSkill*>& PokemonFighterTeam::GetMoves () const
  {
    return GetCurrentFighter ().GetMoves ();
  }

  const PokemonSkill& PokemonFighterTeam::GetMove (int index) const
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
  /// @}

  void PokemonFighterTeam::Update (const Time& dt)
  {
    HandleUpdate (dt);
  }

  void PokemonFighterTeam::HandleUpdate (const Time& dt)
  {
  }

} // namespace yap