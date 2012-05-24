#include "YAPOG/Game/Battle/PokemonFighter.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace yap
{
  PokemonFighter::PokemonFighter (Pokemon* originalPokemon)
    : originalPokemon_ (originalPokemon)
    , stats_ ()
  {
    if (originalPokemon == nullptr)
      YAPOG_THROW("The original Pokemon doesn't exist !");
  }

  const Gender& PokemonFighter::GetGender () const
  {
    return originalPokemon_->GetGender ();
  }

  UInt16 PokemonFighter::GetCurrentHP () const
  {
    return originalPokemon_->GetCurrentHP ();
  }

  UInt16 PokemonFighter::GetMaxHP () const
  {
    return originalPokemon_->GetMaxHP ();
  }

  const UInt16& PokemonFighter::GetLevel () const
  {
    return originalPokemon_->GetLevel ();
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
  /// @}

} // namespace yap