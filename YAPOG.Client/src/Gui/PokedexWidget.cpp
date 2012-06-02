#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Game/Pokemon/Pokedex.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
#include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
#include "YAPOG/Graphics/Gui/Menu.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"

#include "Gui/PokedexWidget.hpp"

#include "Game.hpp"

namespace ycl
{

  PokedexWidget::PokedexWidget ()
    : pokedex_ (new yap::Pokedex ())
    , boxInfoContent_ (new yap::PictureBox ())
    , menu_ (nullptr)
    , validatedPokemon_ (nullptr)
  {
    yap::collection::Array<yap::PokemonInfo*> pokList;

    yap::PokemonInfo* pokInfo1 = new yap::PokemonInfo (yap::ID (1));    
    yap::PokemonInfo* pokInfo2 = new yap::PokemonInfo (yap::ID (5));
    yap::PokemonInfo* pokInfo3 = new yap::PokemonInfo (yap::ID (3));
    yap::PokemonInfo* pokInfo4 = new yap::PokemonInfo (yap::ID (4));
    yap::PokemonInfo* pokInfo5 = new yap::PokemonInfo (yap::ID (9));
    yap::PokemonInfo* pokInfo6 = new yap::PokemonInfo (yap::ID (10));
    yap::PokemonInfo* pokInfo7 = new yap::PokemonInfo (yap::ID (7));
    yap::PokemonInfo* pokInfo8 = new yap::PokemonInfo (yap::ID (16));

    pokInfo1->SetName ("Tortank");
    pokInfo2->SetName ("Bulbizare");
    pokInfo3->SetName ("Ratata");
    pokInfo4->SetName ("Pikachu");
    pokInfo5->SetName ("Dracofeu");
    pokInfo6->SetName ("Alakazham");
    pokInfo7->SetName ("Onyx");
    pokInfo8->SetName ("Morpho");

    pokList.Add (pokInfo1);
    pokList.Add (pokInfo2);
    pokList.Add (pokInfo3);
    pokList.Add (pokInfo4);
    pokList.Add (pokInfo5);
    pokList.Add (pokInfo6);
    pokList.Add (pokInfo7);
    pokList.Add (pokInfo8);

    pokedex_->SetPokemonSeenInfoList (pokList);
    pokedex_->SetPokemonList (pokList);
  }

  PokedexWidget::~PokedexWidget ()
  {
  }

  void PokedexWidget::Init ()
  {
    SetSize (yap::Vector2 (800, 600));
    yap::WidgetBackground* background = new yap::WidgetBackground ("WindowSkins/BasicSkin/Pokedex/Background.png", true);    
    SetBackground (*background);

    yap::HorizontalLayout* firstHLayout = new yap::HorizontalLayout (yap::Padding (10, 10, 10, 10), yap::Padding (10, 10, 10, 10), false);
    firstHLayout->SetSize (yap::Vector2 (600, 400));
    firstHLayout->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
    yap::HorizontalLayout* secondHLayout = new yap::HorizontalLayout (yap::Padding (5, 5, 5, 5), yap::Padding (5, 5, 5, 5), true);
    yap::VerticalLayout* firstVLayout = new yap::VerticalLayout (yap::Padding (10, 10, 10, 10), yap::Padding (10, 10, 10, 10), true);

    yap::VerticalLayout* secondVLayout = new yap::VerticalLayout (yap::Padding (5, 5, 5, 5), yap::Padding (5, 5, 5, 5), true);

    yap::PictureBox* title = new yap::PictureBox ();
    title->SetPicture ("WindowSkins/BasicSkin/Pokedex/Title.png");

    yap::HorizontalLayout* boxInfo = new yap::HorizontalLayout (yap::Padding (20, 20, 20, 20), yap::Padding (20, 20, 20, 20), false);
    yap::WidgetBackground* pokImgBackground = new yap::WidgetBackground ("WindowSkins/BasicSkin/Pokedex/PokemonBoxBackground.png", true);
    pokImgBackground->SetFixed (true);
    boxInfo->SetBackground (*pokImgBackground);
    boxInfoContent_->SetPicture ("WindowSkins/BasicSkin/Pokedex/PokemonBoxDefault.png");
    boxInfo->AddChild (*boxInfoContent_);

    firstVLayout->AddChild (*title);
    firstVLayout->SetBorder (*new yap::WidgetBorder ("Test/black.png"));

    yap::WidgetBackground* menuBackground = new yap::WidgetBackground ("WindowSkins/BasicSkin/Pokedex/ListBackground.png", true);
    menu_ = new yap::Menu (yap::Menu::Type::VERTICAL, yap::Padding (5, 5, 5, 5), yap::Padding (5, 5, 5, 5), true);
    yap::WidgetBackground* selectedBackground = new yap::WidgetBackground ("WindowSkins/BasicSkin/Pokedex/SelectionBackground.png", true);
    menu_->SetSelectedBackground (*selectedBackground);
    menu_->SetSize (yap::Vector2 (firstHLayout->GetSize ().x - firstVLayout->GetSize ().x, firstHLayout->GetSize ().y));
    menu_->SetBackground (*menuBackground);

    for (int i = 1; i <= pokedex_->GetMaxIDSeen (); i++)
    {
      yap::MenuItem* item = new yap::MenuItem (false);
      item->SetSize (yap::Vector2 (firstHLayout->GetSize ().x - firstVLayout->GetSize ().x - 10, 28));
      const yap::PokemonInfo* current = pokedex_->GetPokemonSeenID (i);

      if (current == nullptr)
      {
        item->SetContent ("N." + yap::StringHelper::ToString(i) + "    --------");
        item->OnSelected +=
          [&] (const yap::MenuItem& sender, const yap::EmptyEventArgs& args)
        {
          boxInfoContent_->SetPicture ("WindowSkins/BasicSkin/Pokedex/PokemonBoxDefault.png");
        };
      }
      else
      {
        item->SetContent ("N." + yap::StringHelper::ToString(i) + "    " + current->GetName ());
        item->OnActivated +=
          [&] (const yap::MenuItem& sender, const yap::EmptyEventArgs& args)
        {
          validatedPokemon_ = pokedex_->GetPokemon (menu_->GetCurrentSelect ());
        };
      }
      item->ChangeColor (sf::Color (0, 0, 0));
      item->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
      menu_->AddChild (*item, yap::LayoutBox::Align::LEFT);

    }
    yap::Label* pokSeen = new yap::Label ("Vus : "  + yap::StringHelper::ToString (pokedex_->GetPokemonSeenCount ()));
    yap::Label* pokCaught = new yap::Label ("Pris : "  + yap::StringHelper::ToString (pokedex_->GetPokemonCaughtCount ()));

    secondVLayout->AddChild (*pokSeen);
    secondVLayout->AddChild (*pokCaught);

    secondHLayout->AddChild (*secondVLayout, yap::LayoutBox::Align::TOP);
    secondHLayout->AddChild (*boxInfo);
    secondHLayout->Refresh ();
    secondHLayout->SetBorder (*new yap::WidgetBorder ("Test/black.png"));

    firstVLayout->AddChild (*secondHLayout, yap::LayoutBox::Align::RIGHT);

    firstHLayout->AddChild (*firstVLayout, yap::LayoutBox::Align::TOP);
    firstHLayout->AddChild (*menu_);

    AddChild (*firstHLayout);
  }

  bool PokedexWidget::IsFocusable () const
  {
    return true;
  }

  yap::Vector2 PokedexWidget::HandleGetSize () const
  {
    return yap::Vector2 (800, 600);
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
