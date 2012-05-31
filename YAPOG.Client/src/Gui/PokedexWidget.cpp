#include "YAPOG/Graphics/Gui/BackgroundWidget.hpp"
#include "YAPOG/Graphics/Gui/BorderWidget.hpp"
#include "YAPOG/Game/Pokemon/Pokedex.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
#include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
#include "YAPOG/Graphics/Gui/Menu.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"

#include "Gui/PokedexWidget.hpp"

namespace ycl
{

  PokedexWidget::PokedexWidget ()
    : pokedex_ (new yap::Pokedex ())
  {
    yap::collection::Array<yap::PokemonInfo*> pokList;

    yap::PokemonInfo* pokInfo1 = new yap::PokemonInfo (yap::ID (1));
    yap::PokemonInfo* pokInfo2 = new yap::PokemonInfo (yap::ID (2));
    yap::PokemonInfo* pokInfo3 = new yap::PokemonInfo (yap::ID (3));
    yap::PokemonInfo* pokInfo4 = new yap::PokemonInfo (yap::ID (4));
    yap::PokemonInfo* pokInfo5 = new yap::PokemonInfo (yap::ID (5));
    yap::PokemonInfo* pokInfo6 = new yap::PokemonInfo (yap::ID (6));
    yap::PokemonInfo* pokInfo7 = new yap::PokemonInfo (yap::ID (7));
    yap::PokemonInfo* pokInfo8 = new yap::PokemonInfo (yap::ID (8));

    pokList.Add (pokInfo1);
    pokList.Add (pokInfo2);
    pokList.Add (pokInfo3);
    pokList.Add (pokInfo4);
    pokList.Add (pokInfo5);
    pokList.Add (pokInfo6);
    pokList.Add (pokInfo7);
    pokList.Add (pokInfo8);

    pokedex_->SetPokemonList (pokList);
  }

  PokedexWidget::~PokedexWidget ()
  {
  }

  void PokedexWidget::Init ()
  {
    yap::BackgroundWidget* background = new yap::BackgroundWidget ("pokedexSet/Background.png", true);
    SetBackground (*background);

    yap::HorizontalLayout* firstHLayout = new yap::HorizontalLayout (yap::Padding (10, 10, 10, 10), yap::Padding (10, 10, 10, 10), true);
    yap::HorizontalLayout* secondHLayout = new yap::HorizontalLayout (yap::Padding (5, 5, 5, 5), yap::Padding (5, 5, 5, 5), true);
    yap::VerticalLayout* firstVLayout = new yap::VerticalLayout (yap::Padding (10, 10, 10, 10), yap::Padding (10, 10, 10, 10), true);
    yap::VerticalLayout* secondVLayout = new yap::VerticalLayout (yap::Padding (5, 5, 5, 5), yap::Padding (5, 5, 5, 5), true);

    yap::PictureBox* title = new yap::PictureBox ();
    title->SetPicture ("pokedexSet/Title.png");

    yap::PictureBox* boxInfo = new yap::PictureBox ();
    title->SetPicture ("pokedexSet/PokemonBoxBackground.png");

    yap::BackgroundWidget* menuBackground = new yap::BackgroundWidget ("pokedexSet/ListBackground.png", true);
    yap::Menu* menu = new yap::Menu (yap::Menu::Type::VERTICAL, yap::Padding (5, 5, 5, 5), yap::Padding (5, 5, 5, 5), false);
    menu->SetSize (yap::Vector2 (128, GetUserSize ().y - GetUserSize ().y / 10));
    menu->SetBackground (*menuBackground);

    secondHLayout->AddChild (*secondVLayout);
    secondHLayout->AddChild (*boxInfo);

    firstVLayout->AddChild (*title);
    firstVLayout->AddChild (*secondHLayout);

    firstHLayout->AddChild (*firstVLayout);
    firstHLayout->AddChild (*menu);

    AddChild (*firstHLayout);
  }

  bool PokedexWidget::IsFocusable () const
  {
    return true;
  }

  yap::Vector2 PokedexWidget::HandleGetSize () const
  {
    return yap::Vector2 (600, 300);
  }
  void PokedexWidget::HandleMove (const yap::Vector2& offset)
  {

  }
  void PokedexWidget::HandleScale (const yap::Vector2& factor)
  {

  }
  void PokedexWidget::HandleDraw (yap::IDrawingContext& context)
  {

  }
  void PokedexWidget::HandleShow (bool isVisible)
  {

  }
  void PokedexWidget::HandleChangeColor (const sf::Color& color)
  {

  }
  void PokedexWidget::HandleUpdate (const yap::Time& dt)
  {

  }
} // namespace ycl
