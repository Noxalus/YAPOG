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

  void PokemonFighter::AddExperience (int value)
  {
    const yap::PokemonExperience& oldValue = 
      originalPokemon_->GetExperience ();

    originalPokemon_->AddExperience (value);

    OnExperienceChanged (
      *this, yap::ChangeEventArgs<const yap::PokemonExperience&> 
      (oldValue, originalPokemon_->GetExperience ()));
  }

  void PokemonFighter::TakeDamage (int value)
  {
    yap::PokemonFighter::TakeDamage (value);
    SetCurrentHP (originalPokemon_->GetCurrentHP () - value);
  }

  yap::Event<
    const yap::IBattleEntity&, 
    const yap::ChangeEventArgs<const yap::HitPoint&>&>& 
    PokemonFighter::OnHPChangedEvent ()
  {
    return OnHPChanged;
  }

  yap::Event<
    const yap::IBattleEntity&, 
    const yap::ChangeEventArgs<const yap::PokemonExperience&>&>& 
    PokemonFighter::OnExperienceChangedEvent ()
  {
    return OnExperienceChanged;
  }

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

  // Private setters.
  void PokemonFighter::SetCurrentHP (int value)
  {
    if (value < 0)
      value = 0;

    const yap::HitPoint& oldValue = 
      originalPokemon_->GetStats ().GetHitPoint ();
    
    originalPokemon_->SetCurrentHP (value);

    OnHPChanged (*this, yap::ChangeEventArgs<const yap::HitPoint&> 
      (oldValue, originalPokemon_->GetStats ().GetHitPoint ()));
  }

} // namespace yap