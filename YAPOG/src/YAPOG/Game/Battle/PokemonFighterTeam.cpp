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

  const UInt16& PokemonFighterTeam::GetLevel () const
  {
    return GetCurrentFighter ().GetLevel ();
  }

  const Gender& PokemonFighterTeam::GetGender () const
  {
    return GetCurrentFighter ().GetGender ();
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