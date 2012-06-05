#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"
#include "Battle/PokemonFighter.hpp"
#include "Pokemon/Pokemon.hpp"

namespace ycl
{
  const bool PokemonFighter::DEFAULT_VISIBLE_STATE = true;
  const sf::Color PokemonFighter::DEFAULT_COLOR = sf::Color ();

  PokemonFighter::PokemonFighter (Pokemon* originalPokemon)
    : yap::PokemonFighter (originalPokemon)
    , originalPokemon_ (originalPokemon)
    , battleSprite_ (nullptr)
  {
    battleSprite_ = &originalPokemon->GetBattleFront ();
  }

  PokemonFighter::~PokemonFighter ()
  {
  }

  /// @name IDrawableBattleEntity members
  /// @{
  void PokemonFighter::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool PokemonFighter::IsVisible () const
  {
    return isVisible_;
  }

  void PokemonFighter::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void PokemonFighter::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }
  /// @}
  
  void PokemonFighter::HandleInit ()
  {
  }

  void PokemonFighter::HandleUpdate (const yap::Time& dt)
  {
  }

  void PokemonFighter::HandleDraw (yap::IDrawingContext& context)
  {
    battleSprite_->Draw (context);
  }

  void PokemonFighter::HandleShow (bool isVisible)
  {
  }

  void PokemonFighter::HandleChangeColor (const sf::Color& color)
  {
  }

  /// @name IDrawableBattleEntity members
  /// @{
  yap::ISprite& PokemonFighter::GetBattleSprite ()
  {
    return *battleSprite_;
  }
  /// @}

} // namespace yap