#include "YAPOG/Audio/AudioManager.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"

#include "Battle/PokemonFighter.hpp"
#include "Pokemon/Pokemon.hpp"

namespace ycl
{
  const bool PokemonFighter::DEFAULT_VISIBLE_STATE = true;
  const sf::Color PokemonFighter::DEFAULT_COLOR = sf::Color ();

  PokemonFighter::PokemonFighter (Pokemon* originalPokemon, bool isOpponent)
    : yap::PokemonFighter (originalPokemon)
    , isVisible_ (DEFAULT_VISIBLE_STATE)
    , battleSprite_ (nullptr)
    , isOpponent_ (isOpponent)
    , originalPokemon_ (originalPokemon) // IDrawableEntity
  {
    if (isOpponent_)
      battleSprite_ = &originalPokemon->GetBattleFront ();
    else
      battleSprite_ = &originalPokemon->GetBattleBack ();
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
  const yap::ISprite& PokemonFighter::GetBattleSprite () const
  {
    return *battleSprite_;
  }

  const yap::ISprite& PokemonFighter::GetIcon () const
  { return originalPokemon_->GetIcon (); }

  const yap::ISprite& PokemonFighter::GetGenderIcon () const
  { return originalPokemon_->GetGenderIcon (); }

  const yap::ISprite& PokemonFighter::GetBattleBack () const
  { return originalPokemon_->GetBattleBack (); }

  const yap::ISprite& PokemonFighter::GetBattleFront () const
  { return originalPokemon_->GetBattleBack (); }

  const yap::ISprite& PokemonFighter::GetType1Icon () const
  { return originalPokemon_->GetType1Icon (); }

  const yap::ISprite& PokemonFighter::GetType2Icon () const
  { return originalPokemon_->GetType2Icon (); }

  void PokemonFighter::PlayCry () const
  {
    yap::AudioManager::Instance ().PlaySound ("Cries/" + 
      yap::StringHelper::ToString (
      GetOriginalPokemon ().GetStaticID ().GetValue ()) + ".wav");
  }
  /// @}
} // namespace yap