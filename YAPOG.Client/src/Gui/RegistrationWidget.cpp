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
    , registrationBox_ (
    yap::Padding (5, 5, 5, 5)
    , yap::Padding (5, 5, 5, 5)
    , true)
    , loginBox_ (
    yap::Padding (5, 5, 5, 5)
    , yap::Padding (5, 5, 5, 5)
    , true)
    , loginTextBox_ ()
    , loginLabel_ ("Votre nom d'utilisateur: ")
    , passwordBox_ (
    yap::Padding (5, 5, 5, 5)
    , yap::Padding (5, 5, 5, 5)
    , true)
    , passwordTextBox_ ()
    , passwordLabel_ ("Votre mot de passe: ")
    , emailBox_ (
    yap::Padding (5, 5, 5, 5)
    , yap::Padding (5, 5, 5, 5)
    , true)
    , emailTextBox_ ()
    , emailLabel_ ("Votre Email: ")
    , errorLabel_ ()
  {
  }

  void RegistrationWidget::Init ()
  {
    yap::WidgetBackground* menuBck = 
      new yap::WidgetBackground (
      "WindowSkins/BasicSkin/Global/WindowBackgroundTexture.png", true);

    /*
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
    */
      
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

    loginTextBox_.SetSize (yap::Vector2 (242, 32));
    passwordTextBox_.SetSize (yap::Vector2 (242, 32));
    emailTextBox_.SetSize (yap::Vector2 (242, 32));

    errorLabel_.ChangeColor (sf::Color::Red);

    loginBox_.AddChild (loginLabel_);
    loginBox_.AddChild (loginTextBox_);

    passwordBox_.AddChild (passwordLabel_);
    passwordBox_.AddChild (passwordTextBox_);

    emailBox_.AddChild (emailLabel_);
    emailBox_.AddChild (emailTextBox_);

    registrationBox_.AddChild (loginBox_, yap::LayoutBox::Align::LEFT);
    registrationBox_.AddChild (passwordBox_, yap::LayoutBox::Align::LEFT);
    registrationBox_.AddChild (emailBox_, yap::LayoutBox::Align::LEFT);

    registrationBox_.AddChild (errorLabel_, yap::LayoutBox::Align::LEFT);

    AddChild (registrationBox_);

    SetPosition (yap::Vector2 (
      (Game::SCREEN_SIZE.x - registrationBox_.GetSize ().x) / 2,
      (Game::SCREEN_SIZE.y - registrationBox_.GetSize ().y) / 2
      ));

    registrationBox_.SetBackground (*menuBck);
    registrationBox_.SetBorder (*menuBorder);

    loginTextBox_.SetBorder (*new yap::WidgetBorder ("Test/Black.png"));
    passwordTextBox_.SetBorder (*new yap::WidgetBorder ("Test/Green.png"));
    emailTextBox_.SetBorder (*new yap::WidgetBorder ("Test/Red.png"));
    menuBck->Move (yap::Vector2 (-20, -20));
    menuBck->SetSize (registrationBox_.GetSize ());
    menuBck->ChangeColor (sf::Color (255, 255, 255, 200));
    loginTextBox_.Move (yap::Vector2 (10, 0));
    passwordTextBox_.Move (yap::Vector2 (55, 0));
    emailTextBox_.Move (yap::Vector2 (140, 0));
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

  /// Setters
  void RegistrationWidget::SetErrorText (const yap::String& error)
  {
    errorLabel_.SetText (error);
  }

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
