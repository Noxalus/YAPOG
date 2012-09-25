#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"
#include "YAPOG/Collection/Array.hpp"
#include "YAPOG/System/Error/Exception.hpp"

#include "Pokemon/Pokemon.hpp"
#include "Pokemon/PokemonTeam.hpp"
#include "Battle/PokemonFighterTeam.hpp"

namespace ycl
{
  const bool PokemonFighterTeam::DEFAULT_VISIBLE_STATE = true;
  const sf::Color PokemonFighterTeam::DEFAULT_COLOR = sf::Color ();

  PokemonFighterTeam::PokemonFighterTeam ()
    : yap::PokemonFighterTeam ()
    , isVisible_ (DEFAULT_VISIBLE_STATE)
    , fighters_ (PokemonTeam::MAX_POKEMON_TEAM_NUMBER, nullptr)
  {
  }

  PokemonFighterTeam::~PokemonFighterTeam ()
  {
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

  void PokemonFighterTeam::LoadFromPokemonTeam (
    PokemonTeam& pokemonTeam, 
    bool isOpponent)
  {
    int counter = pokemonTeam.GetPokemonCount ();

    for (int i = 0; i < counter; i++)
    {
      try
      {
        AddPokemon (new PokemonFighter (
          &pokemonTeam.GetPokemon (i), isOpponent));
      }
      catch (yap::Exception)
      {
        continue;
      }
    }
  }

  PokemonFighter& PokemonFighterTeam::GetCurrentFighter ()
  {
    return *fighters_[currentFighterIndex_];
  }

  const PokemonFighter& PokemonFighterTeam::GetCurrentFighter () const
  {
    return *fighters_[currentFighterIndex_];
  }

  /// @name IDrawableBattleEntity members
  /// @{
  void PokemonFighterTeam::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool PokemonFighterTeam::IsVisible () const
  {
    return isVisible_;
  }

  void PokemonFighterTeam::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void PokemonFighterTeam::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }
  /// @}

  void PokemonFighterTeam::HandleInit ()
  {
  }

  void PokemonFighterTeam::HandleUpdate (const yap::Time& dt)
  {
  }

  void PokemonFighterTeam::HandleDraw (yap::IDrawingContext& context)
  {
    GetCurrentFighter ().Draw (context);
  }

  void PokemonFighterTeam::HandleShow (bool isVisible)
  {
  }

  void PokemonFighterTeam::HandleChangeColor (const sf::Color& color)
  {
  }

  /// @name IDrawableBattleEntity members
  /// @{
  yap::ISprite& PokemonFighterTeam::GetBattleSprite ()
  {
    return GetCurrentFighter ().GetBattleSprite ();
  }
  /// @}

} // namespace yap