#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"

#include "Gui/MainMenu.hpp"

namespace ycl
{

  MainMenu::MainMenu ()
    : Menu (yap::Menu::Type::VERTICAL,
    yap::Padding (5, 5, 5, 5),
    yap::Padding (5, 5, 5, 5),
    false)

  {
  }

  void MainMenu::Init ()
  {
    return;
    yap::WidgetBackground* menuBck = new yap::WidgetBackground ("whiteBckgrd.png", true);
    //    yap::WidgetBackground* menuItemBck = new yap::WidgetBackground ("whiteBckgrd.png", true);

    yap::Texture* ti = new yap::Texture ();
    yap::Texture* tri = new yap::Texture ();
    yap::Texture* ri = new yap::Texture ();
    yap::Texture* bri = new yap::Texture ();
    yap::Texture* bi = new yap::Texture ();
    yap::Texture* bli = new yap::Texture ();
    yap::Texture* li = new yap::Texture ();
    li->LoadFromFile ("menuCursor.png");
    yap::Texture* tli = new yap::Texture ();
    yap::WidgetBorder* menuItemBrd = new yap::WidgetBorder (*ti, *tri, *ri, *bri, *bi, *bli, *li, *tli, false);

    yap::Texture* t = new yap::Texture ();
    t->LoadFromFile ("T.png");
    yap::Texture* tr = new yap::Texture ();
    tr->LoadFromFile ("TR.png");
    yap::Texture* r = new yap::Texture ();
    r->LoadFromFile ("R.png");
    yap::Texture* br = new yap::Texture ();
    br->LoadFromFile  ("BR.png");
    yap::Texture* b = new yap::Texture ();
    b->LoadFromFile ("B.png");
    yap::Texture* bl = new yap::Texture ();
    bl->LoadFromFile ("BL.png");
    yap::Texture* l = new yap::Texture ();
    l->LoadFromFile ("L.png");
    yap::Texture* tl = new yap::Texture ();
    tl->LoadFromFile ("TL.png");

    yap::WidgetBorder* menuBorder = new yap::WidgetBorder (*t, *tr, *r, *br, *b, *bl, *l, *tl, true);

    //    SetSelectedBackground (*menuItemBck);
    SetSelectedBorder (*menuItemBrd);

    yap::MenuItem* item1 = new yap::MenuItem (true);
    yap::MenuItem* item2 = new yap::MenuItem (true);
    yap::MenuItem* item3 = new yap::MenuItem (true);

    item1->SetContent ("Connexion");
    item2->SetContent ("Inscription");
    item3->SetContent ("Sortie");

    item1->ChangeColor (sf::Color (128, 128, 128));
    item2->ChangeColor (sf::Color (128, 128, 128));
    item3->ChangeColor (sf::Color (128, 128, 128));

    AddChild (*item1, yap::LayoutBox::Align::LEFT);
    AddChild (*item2, yap::LayoutBox::Align::LEFT);
    AddChild (*item3, yap::LayoutBox::Align::LEFT);

    SetBackground (*menuBck);
    SetBorder (*menuBorder);
  }

  MainMenu::~MainMenu ()
  {
  }
} // namespace ycl
