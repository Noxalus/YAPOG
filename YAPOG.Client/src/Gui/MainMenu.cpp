#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Graphics/Gui/BackgroundWidget.hpp"
#include "YAPOG/Graphics/Gui/BorderWidget.hpp"

#include "Gui/MainMenu.hpp"

namespace ycl
{

  MainMenu::MainMenu ()
    : Menu (yap::Menu::Type::VERTICAL, 
    yap::Padding (5, 5, 5, 5), 
    yap::Padding (5, 5, 5, 5), 
    false)
    , loginItem_ (nullptr)
    , registrationItem_ (nullptr)
    , exitItem_ (nullptr)
  {  
  }

  void MainMenu::Init ()
  {
    yap::BackgroundWidget* menuBck = new yap::BackgroundWidget ("WindowSkins/BasicSkin/Global/WindowBackgroundTexture.png", true);

    yap::Texture* ti = new yap::Texture ();
    yap::Texture* tri = new yap::Texture ();
    yap::Texture* ri = new yap::Texture ();    
    yap::Texture* bri = new yap::Texture ();    
    yap::Texture* bi = new yap::Texture ();    
    yap::Texture* bli = new yap::Texture ();    
    yap::Texture* li = new yap::Texture ();
    li->LoadFromFile ("WindowSkins/BasicSkin/Global/Cursor.png");
    yap::Texture* tli = new yap::Texture ();
    yap::BorderWidget* menuItemBrd = 
      new yap::BorderWidget (*ti, *tri, *ri, *bri, *bi, *bli, *li, *tli, false);

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

    yap::BorderWidget* menuBorder = 
      new yap::BorderWidget (*t, *tr, *r, *br, *b, *bl, *l, *tl, true);

    //    SetSelectedBackground (*menuItemBck);
    SetSelectedBorder (*menuItemBrd);

    loginItem_ = new yap::MenuItem (true);
    registrationItem_ = new yap::MenuItem (true);
    exitItem_ = new yap::MenuItem (true);

    loginItem_->SetContent ("Connexion");
    registrationItem_->SetContent ("Inscription");
    exitItem_->SetContent ("Sortie");

    loginItem_->ChangeColor (sf::Color (128, 128, 128));
    registrationItem_->ChangeColor (sf::Color (128, 128, 128));
    exitItem_->ChangeColor (sf::Color (128, 128, 128));

    AddChild (*loginItem_, yap::LayoutBox::Align::LEFT);
    AddChild (*registrationItem_, yap::LayoutBox::Align::LEFT);
    AddChild (*exitItem_, yap::LayoutBox::Align::LEFT);

    SetBackground (*menuBck);
    SetBorder (*menuBorder);
  }

  MainMenu::~MainMenu ()
  {
  }

  /// Getters
  yap::MenuItem& MainMenu::GetLoginItem ()
  { return *loginItem_; }

  const yap::MenuItem& MainMenu::GetRegistrationItem () const
  { return *registrationItem_; }

  const yap::MenuItem& MainMenu::GetExitItem () const
  { return *exitItem_; }

} // namespace ycl