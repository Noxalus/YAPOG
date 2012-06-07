#include "Battle/BattleActionMenu.hpp"

namespace ycl
{
  ActionBattleMenu::ActionBattleMenu ()
    : yap::Menu (yap::Menu::Type::VERTICAL,
    yap::Padding (5, 5, 5, 5),
    yap::Padding (5, 5, 5, 5),
    false)
    , fightItem_ ()
    , bagItem_ ()
    , pokemonItem_ ()
    , runItem_ ()
  {
    fightItem_.SetContent ("Attaque");
    bagItem_.SetContent ("Sac");
    pokemonItem_.SetContent ("Pokémon");
    runItem_.SetContent ("Fuite");

    fightItem_.ChangeColor (sf::Color (128, 128, 128));
    bagItem_.ChangeColor (sf::Color (128, 128, 128));
    pokemonItem_.ChangeColor (sf::Color (128, 128, 128));
    runItem_.ChangeColor (sf::Color (128, 128, 128));

    AddChild (fightItem_, yap::LayoutBox::Align::LEFT);
    AddChild (bagItem_, yap::LayoutBox::Align::LEFT);
    AddChild (pokemonItem_, yap::LayoutBox::Align::LEFT);
    AddChild (runItem_, yap::LayoutBox::Align::LEFT);
  }

  ActionBattleMenu::~ActionBattleMenu ()
  {
  }

} // namespace yap
