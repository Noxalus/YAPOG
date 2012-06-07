#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"

#include "Battle/BattleMenu.hpp"

namespace ycl
{
  BattleMenu::BattleMenu ()
    : yap::GridMenu (
    yap::Vector2 (2, 2),
    yap::Padding (5, 5, 5, 5),
    yap::Padding (5, 5, 5, 5),
    true)
    , fightItem_ ()
    , bagItem_ ()
    , pokemonItem_ ()
    , runItem_ ()
  {
    yap::WidgetBackground* menuBck = 
      new yap::WidgetBackground (
      "WindowSkins/BasicSkin/Global/WindowBackgroundTexture.png", true);

    yap::WidgetBorder* menuItemBrd =
      new yap::WidgetBorder ("Test/black.png");

    yap::Texture* t = new yap::Texture ();
    t->LoadFromFile ("WindowSkins/BasicSkin/Global/TopBorder.png");
    yap::Texture* tr = new yap::Texture ();
    tr->LoadFromFile ("WindowSkins/BasicSkin/Global/TopRightCorner.png");
    yap::Texture* r = new yap::Texture ();
    r->LoadFromFile ("WindowSkins/BasicSkin/Global/RightBorder.png");
    yap::Texture* br = new yap::Texture ();
    br->LoadFromFile  ("WindowSkins/BasicSkin/Global/BottomRightCorner.png");
    yap::Texture* b = new yap::Texture ();
    b->LoadFromFile ("WindowSkins/BasicSkin/Global/BottomBorder.png");
    yap::Texture* bl = new yap::Texture ();
    bl->LoadFromFile ("WindowSkins/BasicSkin/Global/BottomLeftCorner.png");
    yap::Texture* l = new yap::Texture ();
    l->LoadFromFile ("WindowSkins/BasicSkin/Global/LeftBorder.png");
    yap::Texture* tl = new yap::Texture ();
    tl->LoadFromFile ("WindowSkins/BasicSkin/Global/TopLeftCorner.png");

    yap::WidgetBorder* menuBorder =
      new yap::WidgetBorder (*t, *tr, *r, *br, *b, *bl, *l, *tl, true);

    SetSelectedBorder (*menuItemBrd);
    
    fightItem_.SetContent ("Attaque");
    bagItem_.SetContent ("Sac");
    pokemonItem_.SetContent ("Pokémon");
    runItem_.SetContent ("Fuite");

    fightItem_.ChangeColor (sf::Color (128, 128, 128));
    bagItem_.ChangeColor (sf::Color (128, 128, 128));
    pokemonItem_.ChangeColor (sf::Color (128, 128, 128));
    runItem_.ChangeColor (sf::Color (128, 128, 128));

    fightItem_.SetSize (yap::Vector2 (150, 45));
    bagItem_.SetSize (yap::Vector2 (150, 45));
    pokemonItem_.SetSize (yap::Vector2 (150, 45));
    runItem_.SetSize (yap::Vector2 (150, 45));

    this->AddChild (fightItem_, yap::LayoutBox::Align::RIGHT);
    this->AddChild (bagItem_, yap::LayoutBox::Align::RIGHT);
    this->AddChild (pokemonItem_, yap::LayoutBox::Align::RIGHT);
    this->AddChild (runItem_, yap::LayoutBox::Align::RIGHT);

    SetBackground (*menuBck);
    SetBorder (*menuBorder);
  }

  BattleMenu::~BattleMenu ()
  {
  }

} // namespace yap
