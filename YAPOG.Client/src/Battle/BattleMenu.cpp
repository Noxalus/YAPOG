#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Audio/AudioManager.hpp"
#include "YAPOG/Graphics/Gui/Menu.hpp"

#include "Battle/BattleMenu.hpp"

namespace ycl
{
  const yap::String BattleMenu::DEFAULT_LABELS[ITEM_NUMBER] = 
  { "Attaque", "Sac", "Pokémon", "Fuite" };

  BattleMenu::BattleMenu ()
    : yap::GridMenu (
    yap::Vector2 (2, 2),
    yap::Padding (5, 5, 5, 5),
    yap::Padding (5, 5, 5, 5),
    true)
    , items_ (ITEM_NUMBER, nullptr)
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
    
    for (int i = 0; i < ITEM_NUMBER; i++)
    {
      items_[i] = new yap::MenuItem ();
      items_[i]->SetContent (DEFAULT_LABELS[i]);
      items_[i]->ChangeColor (sf::Color::Black);
      items_[i]->SetSize (yap::Vector2 (150, 45));
      this->AddChild (*items_[i], yap::LayoutBox::Align::LEFT);
    }

    SetBackground (*menuBck);
    SetBorder (*menuBorder);
  }

  BattleMenu::~BattleMenu ()
  {
  }

  yap::MenuItem& BattleMenu::GetItem (int index)
  {
    return *items_[index];
  }

  void BattleMenu::HandleItemActivated ()
  {
    //yap::Menu::HandleItemActivated ();

    // Play a sound
    yap::AudioManager::Instance ().PlaySound ("SE/Choose.wav");
  }

  void BattleMenu::HandleItemSelected ()
  {
    //yap::Menu::HandleItemSelected ();

    // Play a sound
    yap::AudioManager::Instance ().PlaySound ("SE/Select.wav");
  }

} // namespace yap
