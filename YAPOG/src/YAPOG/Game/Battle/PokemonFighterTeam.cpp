#include "YAPOG/Game/Battle/PokemonFighterTeam.hpp"
#include "YAPOG/System/Error/Exception.hpp"

namespace yap
{
  PokemonFighterTeam::PokemonFighterTeam ()
    : fighters_ (PokemonTeam::MAX_POKEMON_TEAM_NUMBER, nullptr)
    , currentFighterIndex_ (0)
  {
  }

  PokemonFighter* PokemonFighterTeam::GetPokemon (int index) const
  {
    /*
    if (index >= PokemonTeam::MAX_POKEMON_TEAM_NUMBER)
    {
    YAPOG_THROW("Pokemon Team: index out of bound (" + 
    StringHelper::ToString (index) + ")");
    }

    if (fighters_[index] == nullptr)
    {
    YAPOG_THROW("Pokemon Team: no Pokemon at this index (" + 
    StringHelper::ToString (index) + ")");
    }
    */

    return fighters_[index];
  }

  bool PokemonFighterTeam::AddPokemon (PokemonFighter* pokemonFighter)
  {
    for (int i = 0; i < PokemonTeam::MAX_POKEMON_TEAM_NUMBER; i++)
    {
      if (fighters_[i] == nullptr)
      {
        fighters_[i] = pokemonFighter;
        return true;
      }
    }

    return false;
  }

  const collection::Array<PokemonFighter*>& PokemonFighterTeam::GetTeam () const
  {
    return fighters_;
  }

  /// Debug
  void PokemonFighterTeam::PrintTeam ()
  {
    for (int i = 0; i < PokemonTeam::MAX_POKEMON_TEAM_NUMBER; i++)
    {
      if (fighters_[i] != nullptr)
      {
        std::cout << fighters_[i]->GetName () 
          << " (lvl. " << fighters_[i]->GetLevel () << ")"
          << std::endl;

        fighters_[i]->PrintStats ();
      }
      else
        std::cout << "[NO POKEMON] " << std::endl;
    }
  }

  PokemonFighter* PokemonFighterTeam::GetCurrentFighter () const
  {
    return fighters_[currentFighterIndex_];
  }

  /// @name IBattleEntity members
  /// @{
  const String& PokemonFighterTeam::GetName () const
  {
    return GetCurrentFighter ()->GetName ();
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