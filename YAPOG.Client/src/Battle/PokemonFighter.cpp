#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"
#include "Battle/PokemonFighter.hpp"
#include "Pokemon/Pokemon.hpp"

namespace ycl
{
  const bool PokemonFighter::DEFAULT_VISIBLE_STATE = true;
  const sf::Color PokemonFighter::DEFAULT_COLOR = sf::Color ();
  const BattleSpriteType PokemonFighter::
    DEFAULT_BATTLE_SPRITE_TYPE = BattleSpriteType::FRONT;

  PokemonFighter::PokemonFighter (Pokemon* originalPokemon, bool isOpponent)
    : yap::PokemonFighter (originalPokemon)
    , isVisible_ (DEFAULT_VISIBLE_STATE)
    , originalPokemon_ (originalPokemon)
    , battleSprite_ (nullptr)
    , isOpponent_ (isOpponent)
  {
    if (isOpponent_)
      SetBattleSprite (BattleSpriteType::FRONT);
    else
      SetBattleSprite (BattleSpriteType::BACK);
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

  void PokemonFighter::SetBattleSprite (
    const BattleSpriteType& battleSpriteType)
  {
    switch (battleSpriteType)
    {
    case BattleSpriteType::BACK:
      battleSprite_ = &originalPokemon_->GetBattleBack ();
      break;
    case BattleSpriteType::FRONT:
      battleSprite_ = &originalPokemon_->GetBattleFront ();
      break;
    default:
      SetBattleSprite (DEFAULT_BATTLE_SPRITE_TYPE);
      break;
    }
  }

} // namespace yap