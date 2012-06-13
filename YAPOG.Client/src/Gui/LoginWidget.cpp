#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"

#include "Gui/LoginWidget.hpp"
#include "Game.hpp"

namespace ycl
{

  LoginWidget::LoginWidget ()
    : yap::BaseWidget ()
    , loginTextBox_ ()
    , passwordTextBox_ ()
  {
  }

  void LoginWidget::Init ()
  {
    yap::WidgetBackground* menuBck = 
      new yap::WidgetBackground (
      "WindowSkins/BasicSkin/Global/WindowBackgroundTexture.png", true);

    yap::Texture* ti = new yap::Texture ();
    yap::Texture* tri = new yap::Texture ();
    yap::Texture* ri = new yap::Texture ();
    yap::Texture* bri = new yap::Texture ();
    yap::Texture* bi = new yap::Texture ();
    yap::Texture* bli = new yap::Texture ();
    yap::Texture* li = new yap::Texture ();
    li->LoadFromFile ("WindowSkins/BasicSkin/Global/Cursor.png");
    yap::Texture* tli = new yap::Texture ();
    yap::WidgetBorder* menuItemBrd =
      new yap::WidgetBorder (*ti, *tri, *ri, *bri, *bi, *bli, *li, *tli, false);

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

    loginTextBox_.SetSize (yap::Vector2 (200, 32));
    passwordTextBox_.SetSize (yap::Vector2 (200, 32));

    SetSize (yap::Vector2 (200, 100));
    SetPosition (yap::Vector2 (
      Game::SCREEN_SIZE.x / 2 - GetSize ().x / 2,
      Game::SCREEN_SIZE.y / 2 - GetSize ().y / 2
      ));

    AddChild (loginTextBox_);
    AddChild (passwordTextBox_);

    SetBackground (*menuBck);
    SetBorder (*menuBorder);

    loginTextBox_.SetBorder (*new yap::WidgetBorder ("Test/Black.png"));
    passwordTextBox_.SetBorder (*new yap::WidgetBorder ("Test/Red.png"));
  }

  LoginWidget::~LoginWidget ()
  {
  }

  /// Getters
  yap::TextBoxWidget& LoginWidget::GetLoginTextBox ()
  { return loginTextBox_; }

  yap::TextBoxWidget& LoginWidget::GetPasswordTextBox ()
  { return passwordTextBox_; }

  bool LoginWidget::IsFocusable () const
  {
    return false;
  }

  void LoginWidget::HandleMove (const yap::Vector2& offset)
  {
  }

  void LoginWidget::HandleScale (const yap::Vector2& factor)
  {
  }

  void LoginWidget::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void LoginWidget::HandleShow (bool isVisible)
  {
  }

  void LoginWidget::HandleChangeColor (const sf::Color& color)
  {
  }

  void LoginWidget::HandleUpdate (const yap::Time& dt)
  {
  }

} // namespace ycl
