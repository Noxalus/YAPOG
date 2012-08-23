#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
#include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
#include "YAPOG/Graphics/Gui/GridMenu.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Graphics/Texture.hpp"

#include "Gui/PokemonTeamWidget.hpp"
#include "Pokemon/PokemonTeam.hpp"

#include "Game.hpp"

namespace ycl
{

  PokemonTeamWidget::PokemonTeamWidget (const PokemonTeam& team)
    : state_ (nullptr)
    , current_ (nullptr)
    , menu_ (nullptr)
    , vlayoutMenu_ (nullptr)
    , team_ (team)
    , pokemons ()
    , ite_ (0)
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

    InfoBox* box = new InfoBox (true, team_.GetPokemon (0));
    box->SetPosition (GetPosition () + yap::Vector2 (39, 101));
    pokemons.Add (box);

    for (int i = 1; i < team_.GetPokemonCount (); i++)
    {
      InfoBox* box = new InfoBox (false, team_.GetPokemon (i));
      box->SetPosition (GetPosition () + yap::Vector2 (364, 41 + 90 * (i - 1)));
      pokemons.Add (box);
    }

    vlayoutMenu_ = new yap::VerticalLayout (yap::Padding (), yap::Padding (), true);

    for (int i = 1; i < 1; i++) // iterate over team.
    {
      InfoBox* box = new InfoBox (false, team_.GetPokemon (i));
      vlayoutMenu_->AddChild (*box);
      pokemons.Add (box);
    }

    AddChild (*vlayoutMenu_);

  }

  bool PokemonTeamWidget::IsFocusable () const
  {
    return true;
  }

  bool PokemonTeamWidget::HandleOnEvent (const yap::GuiEvent& guiEvent)
  {
    if (pokemons.Count () == 0)
      return false;

    if (guiEvent.type == sf::Event::KeyPressed)
    {
      if (guiEvent.key.code == sf::Keyboard::Up)
      {

        return true;
      }
      if (guiEvent.key.code == sf::Keyboard::Down)
      {

        return true;
      }
      if (guiEvent.key.code == sf::Keyboard::Left)
      {

        return true;
      }
      if (guiEvent.key.code == sf::Keyboard::Right)
      {

        return true;
      }
      if (guiEvent.key.code == sf::Keyboard::Return)
      {

        return true;
      }

      if (guiEvent.key.code == sf::Keyboard::Escape)
      {
        return true;
      }
    }

    return false;
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
    for (InfoBox* b : pokemons)
    {
      b->Draw (context);
    }
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
