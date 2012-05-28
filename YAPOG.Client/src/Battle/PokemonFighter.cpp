#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"
#include "Battle/PokemonFighter.hpp"
#include "Pokemon/Pokemon.hpp"

namespace ycl
{
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