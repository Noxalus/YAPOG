#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
#include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
#include "YAPOG/Graphics/Gui/Menu.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Graphics/Texture.hpp"

#include "Gui/PokemonTeamWidget.hpp"

#include "Game.hpp"

namespace ycl
{

  PokemonTeamWidget::PokemonTeamWidget ()
    : state_ (nullptr)

  {

  }

  PokemonTeamWidget::~PokemonTeamWidget ()
  {
  }

  void PokemonTeamWidget::Init ()
  {
    SetBackground (*new yap::WidgetBackground ("Pictures/TeamManager/Partyfond.png", true));
    yap::Label* state_ = new yap::Label ("Choisir un POKéMON.");

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

    yap::WidgetBorder* stateBorder =
      new yap::WidgetBorder (*t, *tr, *r, *br, *b, *bl, *l, *tl, true);

    state_->SetSize (yap::Vector2 (250, 64));
    
    state_->SetBackground (*new yap::WidgetBackground ("Test/White.png", true));
    state_->SetPadding (yap::Padding (32, 0, 5, 32));
    AddChild (*state_);
    state_->SetPosition (GetSize () - state_->GetSize () - yap::Vector2 (15, 15));
    state_->SetBorder (*stateBorder);



  }

  bool PokemonTeamWidget::IsFocusable () const
  {
    return true;
  }

  yap::Vector2 PokemonTeamWidget::HandleGetSize () const
  {
    return yap::Vector2 (800, 600);
  }
  void PokemonTeamWidget::HandleMove (const yap::Vector2& offset)
  {

  }
  void PokemonTeamWidget::HandleScale (const yap::Vector2& factor)
  {

  }
  void PokemonTeamWidget::HandleDraw (yap::IDrawingContext& context)
  {

  }
  void PokemonTeamWidget::HandleShow (bool isVisible)
  {

  }
  void PokemonTeamWidget::HandleChangeColor (const sf::Color& color)
  {

  }
  void PokemonTeamWidget::HandleUpdate (const yap::Time& dt)
  {

  }
} // namespace ycl
