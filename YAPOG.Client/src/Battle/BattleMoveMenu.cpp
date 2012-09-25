#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"

#include "Battle/BattleMoveMenu.hpp"

namespace ycl
{
  BattleMoveMenu::BattleMoveMenu ()
    : yap::GridMenu (
    yap::Vector2 (2, 2),
    yap::Padding (5, 5, 5, 5),
    yap::Padding (5, 5, 5, 5),
    true)
    , moves_ ()
    , indexes_ ()
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

    for (int i = 0; i < 4; i++)
    {
      yap::MenuItem* menuItem = new yap::MenuItem ();
      menuItem ->ChangeColor (sf::Color::Black);
      menuItem ->SetSize (yap::Vector2 (800 / 2 - 150, 45));
      Add (*menuItem, i);

      this->AddChild (*menuItem, yap::LayoutBox::Align::CENTER);
    }

    SetBackground (*menuBck);
    SetBorder (*menuBorder);
  }

  BattleMoveMenu::~BattleMoveMenu ()
  {
  }

  /// Getters.
  yap::MenuItem& BattleMoveMenu::GetItem (int index)
  {
  return *moves_[index];
  }

  int BattleMoveMenu::GetIndex (yap::MenuItem& menuItem) const
  {
    return indexes_[&menuItem];
  }

  /// Setters.
  void BattleMoveMenu::SetItemContent (int index, const yap::String& content)
  {
    moves_[index]->SetContent (content);
  }

  void BattleMoveMenu::Add (yap::MenuItem& menuItem, int index)
  {
    indexes_.Add (&menuItem, index);
    moves_.Add (index, &menuItem);
  }
} // namespace yap
