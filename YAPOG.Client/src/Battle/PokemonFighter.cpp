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
  {
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
  }

  void PokemonFighter::HandleShow (bool isVisible)
  {
  }

  void PokemonFighter::HandleChangeColor (const sf::Color& color)
  {
  }

  /// @name IDrawableBattleEntity members
  /// @{
  yap::ISprite& PokemonFighter::GetFrontSprite ()
  {
    return originalPokemon_->GetBattleFront ();
  }

  yap::ISprite& PokemonFighter::GetBackSprite ()
  {
    return originalPokemon_->GetBattleBack ();
  }
  /// @}

} // namespace yap