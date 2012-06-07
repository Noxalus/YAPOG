#include "YAPOG/Game/Battle/PokemonFighter.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Game/Pokemon/HitPoint.hpp"

namespace yap
{
  PokemonFighter::PokemonFighter (Pokemon* originalPokemon)
    : originalPokemon_ (originalPokemon)
    , stats_ (PokemonStat (originalPokemon_->GetStats ()))
  {
    if (originalPokemon == nullptr)
      YAPOG_THROW("The original Pokemon doesn't exist !");
  }

  const Gender& PokemonFighter::GetGender () const
  {
    return originalPokemon_->GetGender ();
  }

  const collection::Array<PokemonSkill*>& PokemonFighter::GetMoves () const
  {
    return originalPokemon_->GetMoves ();
  }

  /// statics method
  static String GetStringFromGender (
    const Gender& gender)
  {
    switch (gender)
    {
    case Gender::Genderless:
      return "G";
    case Gender::Female:
      return "F";
    case Gender::Male:
      return "M";
    default:
      return "Error";
    }
  }

  const TypeInfo& PokemonFighter::GetType1 () const
  {
    return originalPokemon_->GetType1 ();
  }

  const TypeInfo& PokemonFighter::GetType2 () const
  {
    return originalPokemon_->GetType2 ();
  }

  float PokemonFighter::GetTypeEffectFactor (const TypeInfo& type) const
  {
    return originalPokemon_->GetTypeEffectFactor (type);
  }

  const Attack& PokemonFighter::GetAttack () const
  {
    return stats_.GetAttack ();
  }

  const Defense& PokemonFighter::GetDefense () const
  {
    return stats_.GetDefense ();
  }

  const SpecialAttack& PokemonFighter::GetSpecialAttack () const
  {
    return stats_.GetSpecialAttack ();
  }
  const SpecialDefense& PokemonFighter::GetSpecialDefense () const
  {
    return stats_.GetSpecialDefense ();
  }

  const Speed& PokemonFighter::GetSpeed () const
  {
    return stats_.GetSpeed ();
  }

  /// Displaying
  void PokemonFighter::PrintBattleStats ()
  {
    std::cout 
      << GetName () << " ("
      << GetStringFromGender (GetGender ()) << ")"
      << " N." << GetLevel () << std::endl
      << "PV: " << GetCurrentHP () << "/" << GetMaxHP ()
      << std::endl;
  }

  void PokemonFighter::PrintStats ()
  {
    originalPokemon_->PrintStats ();
  }

  /// @name IBattleEntity members
  /// @{
  const yap::String& PokemonFighter::GetName () const
  {
    return originalPokemon_->GetName ();
  }

  const UInt16& PokemonFighter::GetLevel () const
  {
    return originalPokemon_->GetLevel ();
  }

  const UInt16& PokemonFighter::GetCurrentHP () const
  {
    return stats_.GetHitPoint ().GetCurrentValue ();
  }

  const UInt16& PokemonFighter::GetMaxHP () const
  {
    return stats_.GetHitPoint ().GetValue ();
  }

  float PokemonFighter::GetHPPercentage () const
  {
    return  ((float)GetCurrentHP () / (float)GetMaxHP ()) * 100;
  }

  void PokemonFighter::TakeDamage (int value)
  {
    SetCurrentHP (GetCurrentHP () - value);
  }

  Event<
    const IBattleEntity&, 
    const ChangeEventArgs<const HitPoint&>&>& 
    PokemonFighter::OnHPChangedEvent ()
  {
    return OnHPChanged;
  }
  /// @}

  // Private setters.
  void PokemonFighter::SetCurrentHP (int value)
  {
    if (value < 0)
      value = 0;

    const HitPoint& oldValue = stats_.GetHitPoint ();
    stats_.SetCurrentHP (value);

    OnHPChanged (*this, yap::ChangeEventArgs<const HitPoint&> 
      (oldValue, stats_.GetHitPoint ()));
  }

  void PokemonFighter::Update (const Time& dt)
  {
    HandleUpdate (dt);
  }

  void PokemonFighter::HandleUpdate (const Time& dt)
  {
  }

} // namespace yap