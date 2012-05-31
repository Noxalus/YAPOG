#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Graphics/Gui/BackgroundWidget.hpp"

#include "Battle/PokemonBattleInfoWidget.hpp"

namespace ycl
{
  PokemonBattleInfoWidget::PokemonBattleInfoWidget ()
    : pokemonName_ ()
    , horizontalLayout_ ()
    , verticalLayout_ ()
  {
    horizontalLayout_.SetSize (yap::Vector2 (100.f, 200.f));
    verticalLayout_.SetBackground (
      *new yap::BackgroundWidget ("Pictures/pokemon_battle_info.png", false));

    this->AddChild (pokemonName_);
    this->AddChild (verticalLayout_);
  }

  /// Getters
  yap::Label& PokemonBattleInfoWidget::GetPokemonName ()
  {
    return pokemonName_;
  }
}
