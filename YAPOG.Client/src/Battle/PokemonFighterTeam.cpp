#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"
#include "YAPOG/Collection/Array.hpp"

#include "Pokemon/Pokemon.hpp"
#include "Pokemon/PokemonTeam.hpp"
#include "Battle/PokemonFighter.hpp"
#include "Battle/PokemonFighterTeam.hpp"

namespace ycl
{
  const bool PokemonFighterTeam::DEFAULT_VISIBLE_STATE = true;
  const sf::Color PokemonFighterTeam::DEFAULT_COLOR = sf::Color ();

  PokemonFighterTeam::PokemonFighterTeam ()
    : yap::PokemonFighterTeam ()
    , fighters_ (PokemonTeam::MAX_POKEMON_TEAM_NUMBER, nullptr)
  {
  }

  PokemonFighterTeam::~PokemonFighterTeam ()
  {
  }

  PokemonFighter* PokemonFighterTeam::GetPokemon (int index) const
  {
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

  PokemonFighter* PokemonFighterTeam::GetCurrentFighter () const
  {
    return fighters_[currentFighterIndex_];
  }

  /// @name IDrawableBattleEntity members
  /// @{
  void PokemonFighterTeam::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;
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
  }

  void PokemonFighterTeam::HandleShow (bool isVisible)
  {
  }

  void PokemonFighterTeam::HandleChangeColor (const sf::Color& color)
  {
  }

  /// @name IDrawableBattleEntity members
  /// @{
  yap::ISprite& PokemonFighterTeam::GetFrontSprite ()
  {
    return GetCurrentFighter ()->GetFrontSprite ();
  }

  yap::ISprite& PokemonFighterTeam::GetBackSprite ()
  {
    return GetCurrentFighter ()->GetBackSprite ();
  }
  /// @}
} // namespace yap