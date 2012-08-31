#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
#include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
#include "YAPOG/Graphics/Gui/GridMenu.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Graphics/Texture.hpp"

#include "Gui/PokemonTeamWidget.hpp"
#include "Gui/PokemonInfoBox.hpp"

#include "Pokemon/PokemonTeam.hpp"

namespace ycl
{
  PokemonTeamWidget::PokemonTeamWidget (const PokemonTeam& team)
    : state_ (nullptr)
    , menu_ (nullptr)
    , team_ (team)
    , pokemonInfoBoxes_ ()
    , index_ (0)
    , pokemonInfoWidget_ ()
  {

  }

  PokemonTeamWidget::~PokemonTeamWidget ()
  {
  }

  void PokemonTeamWidget::Init ()
  {
    SetBackground (*new yap::WidgetBackground (
      "Pictures/TeamManager/Partyfond.png", true));

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


    for (int i = 0; i < team_.GetPokemonCount (); i++)
    {
      PokemonInfoBox* box = nullptr; 

      if (i == 0)
      {
        box = new PokemonInfoBox (true, team_.GetPokemon (i));
        box->SetPosition (GetPosition () + yap::Vector2 (39, 101));
      }
      else
      {
        box = new PokemonInfoBox (false, team_.GetPokemon (i));
        box->SetPosition (GetPosition () + yap::Vector2 (364, 41 + 90 * (i - 1)));
      }

      pokemonInfoBoxes_.Add (box);

      AddChild (*box);
    }

    AddChild (pokemonInfoWidget_);

    pokemonInfoWidget_.Init ();
    pokemonInfoWidget_.Close ();

    pokemonInfoBoxes_[index_]->SetIsSelected (true);
  }

  bool PokemonTeamWidget::IsFocusable () const
  {
    return true;
  }

  bool PokemonTeamWidget::HandleOnEvent (const yap::GuiEvent& guiEvent)
  {
    if (pokemonInfoBoxes_.Count () == 0)
      return false;

    if (guiEvent.type == sf::Event::KeyPressed)
    {
      if (guiEvent.key.code == sf::Keyboard::Up)
      {
        if (pokemonInfoWidget_.IsVisible ())
        {
          pokemonInfoWidget_.Close ();
          
          if (index_ == 0)
            index_ = pokemonInfoBoxes_.Count () - 1;
          else
            index_--;

          pokemonInfoWidget_.SetPokemon (&team_.GetPokemon (index_));
          pokemonInfoWidget_.Open ();
        }
        else
        {
          pokemonInfoBoxes_[index_]->SetIsSelected (false);

          if (index_ == 0)
            index_ = pokemonInfoBoxes_.Count () - 1;
          else
            index_--;

          pokemonInfoBoxes_[index_]->SetIsSelected (true);
        }
        return true;
      }

      if (guiEvent.key.code == sf::Keyboard::Down)
      {
        if (pokemonInfoWidget_.IsVisible ())
        {
          pokemonInfoWidget_.Close ();
          index_ = (index_ + 1) % pokemonInfoBoxes_.Count ();
          pokemonInfoWidget_.SetPokemon (&team_.GetPokemon (index_));
          pokemonInfoWidget_.Open ();
        }
        else
        {
          pokemonInfoBoxes_[index_]->SetIsSelected (false);

          index_ = (index_ + 1) % pokemonInfoBoxes_.Count ();

          pokemonInfoBoxes_[index_]->SetIsSelected (true);
        }

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
        pokemonInfoWidget_.SetPokemon (&team_.GetPokemon (index_));
        pokemonInfoWidget_.Open ();

        return true;
      }

      if (guiEvent.key.code == sf::Keyboard::Escape)
      {
        Close ();

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
