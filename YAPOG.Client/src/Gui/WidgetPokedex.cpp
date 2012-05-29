#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Game/Pokemon/Pokedex.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
#include "YAPOG/Graphics/Gui/LayoutH.hpp"
#include "YAPOG/Graphics/Gui/LayoutV.hpp"
#include "YAPOG/Graphics/Gui/Menu.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"

#include "Gui/WidgetPokedex.hpp"

namespace ycl
{

  WidgetPokedex::WidgetPokedex ()
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

  WidgetPokedex::~WidgetPokedex ()
  {
  }

  void WidgetPokedex::Init ()
  {
    yap::WidgetBackground* background = new yap::WidgetBackground ("pokedexSet/Background.png", true);
    SetBackground (*background);

    yap::LayoutH* firstHLayout = new yap::LayoutH (yap::Padding (10, 10, 10, 10), yap::Padding (10, 10, 10, 10), true);
    yap::LayoutH* secondHLayout = new yap::LayoutH (yap::Padding (5, 5, 5, 5), yap::Padding (5, 5, 5, 5), true);
    yap::LayoutV* firstVLayout = new yap::LayoutV (yap::Padding (10, 10, 10, 10), yap::Padding (10, 10, 10, 10), true);
    yap::LayoutV* secondVLayout = new yap::LayoutV (yap::Padding (5, 5, 5, 5), yap::Padding (5, 5, 5, 5), true);

    yap::PictureBox* title = new yap::PictureBox ();
    title->SetPicture ("pokedexSet/Title.png");

    yap::PictureBox* boxInfo = new yap::PictureBox ();
    title->SetPicture ("pokedexSet/PokemonBoxBackground.png");

    yap::WidgetBackground* menuBackground = new yap::WidgetBackground ("pokedexSet/ListBackground.png", true);
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

  bool WidgetPokedex::IsFocusable () const
  {
    return true;
  }

  yap::Vector2 WidgetPokedex::HandleGetSize () const
  {
    return yap::Vector2 (600, 300);
  }
  void WidgetPokedex::HandleMove (const yap::Vector2& offset)
  {

  }
  void WidgetPokedex::HandleScale (const yap::Vector2& factor)
  {

  }
  void WidgetPokedex::HandleDraw (yap::IDrawingContext& context)
  {

  }
  void WidgetPokedex::HandleShow (bool isVisible)
  {

  }
  void WidgetPokedex::HandleChangeColor (const sf::Color& color)
  {

  }
  void WidgetPokedex::HandleUpdate (const yap::Time& dt)
  {

  }
} // namespace ycl
