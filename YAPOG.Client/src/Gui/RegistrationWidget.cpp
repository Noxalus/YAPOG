#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"

#include "Gui/RegistrationWidget.hpp"
#include "Game.hpp"

namespace ycl
{

  RegistrationWidget::RegistrationWidget ()
    : yap::BaseWidget ()
    , registrationBox_ ()
    , loginTextBox_ ()
    , passwordTextBox_ ()
    , emailTextBox_ ()
  {
  }

  void RegistrationWidget::Init ()
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

    registrationBox_.AddChild (loginTextBox_);
    registrationBox_.AddChild (passwordTextBox_);
    registrationBox_.AddChild (emailTextBox_);
    AddChild (registrationBox_);

    registrationBox_.SetSize (yap::Vector2 (200, 100));
    SetPosition (yap::Vector2 (
      Game::SCREEN_SIZE.x / 2 - GetSize ().x / 2,
      Game::SCREEN_SIZE.y / 2 - GetSize ().y / 2
      ));
    loginTextBox_.SetSize (yap::Vector2 (200, 32));
    passwordTextBox_.SetSize (yap::Vector2 (200, 32));

    registrationBox_.SetBackground (*menuBck);
    registrationBox_.SetBorder (*menuBorder);

    loginTextBox_.Move (yap::Vector2 (10, 0));
    passwordTextBox_.Move (yap::Vector2 (10, 5));
    emailTextBox_.Move (yap::Vector2 (10, 5));

    loginTextBox_.SetBorder (*new yap::WidgetBorder ("Test/Black.png"));
    passwordTextBox_.SetBorder (*new yap::WidgetBorder ("Test/Green.png"));
    emailTextBox_.SetBorder (*new yap::WidgetBorder ("Test/Red.png"));
  }

  RegistrationWidget::~RegistrationWidget ()
  {
  }

  /// Getters
  yap::TextBoxWidget& RegistrationWidget::GetLoginTextBox ()
  { return loginTextBox_; }

  yap::TextBoxWidget& RegistrationWidget::GetPasswordTextBox ()
  { return passwordTextBox_; }

  yap::TextBoxWidget& RegistrationWidget::GetEmailTextBox ()
  { return emailTextBox_; }

  bool RegistrationWidget::IsFocusable () const
  {
    return false;
  }

  void RegistrationWidget::HandleMove (const yap::Vector2& offset)
  {
  }

  void RegistrationWidget::HandleScale (const yap::Vector2& factor)
  {
  }

  void RegistrationWidget::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void RegistrationWidget::HandleShow (bool isVisible)
  {
  }

  void RegistrationWidget::HandleChangeColor (const sf::Color& color)
  {
  }

  void RegistrationWidget::HandleUpdate (const yap::Time& dt)
  {
  }

} // namespace ycl
