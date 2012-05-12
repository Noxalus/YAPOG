#include "YAPOG/Game/Battle/PokemonFighter.hpp"

namespace yap
{
  PokemonFighter::PokemonFighter (Pokemon* originalPokemon)
    : originalPokemon_ (originalPokemon)
  {
  }

  const String& PokemonFighter::GetName () const
  {
    return originalPokemon_->GetName ();
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

  void PokemonFighter::PrintBattleStats ()
  {
    std::cout 
      << GetName () << " ("
      << GetStringFromGender (GetGender ()) << ")"
      << " N." << GetLevel () << std::endl
      << "PV: " << GetCurrentHP () << "/" << GetMaxHP ()
      << std::endl;
  }

} // namespace yap