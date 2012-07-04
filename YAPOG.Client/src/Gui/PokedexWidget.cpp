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
#include "Gui/PokedexCompositeWidget.hpp"

#include "Game.hpp"

namespace ycl
{

  PokedexWidget::PokedexWidget (yap::Pokedex* pokedex)
    : pokedex_ (pokedex)
    , boxInfoContent_ (new yap::PictureBox ())
    , menu_ (nullptr)    
    , validatedPokemon_ (nullptr)
    , firstHLayout_ (nullptr)
    , firstVLayout_ (nullptr)
    , pokedexInfo_ (nullptr)    
    , pokSeen_ (nullptr)
    , pokCaught_ (nullptr)
  {
    /*pokedexInfo_ = new PokedexCompositeWidget ();
    pokedexInfo_->Init ();
    pokedexInfo_->Close ();
    AddChild (*pokedexInfo_);*/

    pokedex_->OnAddPokemon += [this] (yap::Pokedex& sender, const yap::EmptyEventArgs& args)
    {
      RefreshAfterAdd ();
    };
  }

  PokedexWidget::~PokedexWidget ()
  {
  }

  void PokedexWidget::Init ()
  {
    SetSize (yap::Vector2 (800, 600));
    yap::WidgetBackground* background = new yap::WidgetBackground ("WindowSkins/BasicSkin/Pokedex/Background.png", true);    
    SetBackground (*background);

    firstHLayout_ = new yap::HorizontalLayout (yap::Padding (10, 10, 10, 10), yap::Padding (10, 10, 10, 10), false);
    firstHLayout_->SetSize (yap::Vector2 (600, 400));
    yap::HorizontalLayout* secondHLayout = new yap::HorizontalLayout (yap::Padding (5, 5, 5, 5), yap::Padding (5, 5, 5, 5), true);
    yap::VerticalLayout* firstVLayout_ = new yap::VerticalLayout (yap::Padding (10, 10, 10, 10), yap::Padding (10, 10, 10, 10), true);

    yap::VerticalLayout* secondVLayout = new yap::VerticalLayout (yap::Padding (5, 5, 5, 5), yap::Padding (5, 5, 5, 5), true);
    secondHLayout->SetDefaultColor (sf::Color::White);
    yap::PictureBox* title = new yap::PictureBox ();
    title->SetPicture ("WindowSkins/BasicSkin/Pokedex/Title.png");

    yap::HorizontalLayout* boxInfo = new yap::HorizontalLayout (yap::Padding (20, 20, 20, 20), yap::Padding (20, 20, 20, 20), false);
    yap::WidgetBackground* pokImgBackground = new yap::WidgetBackground ("WindowSkins/BasicSkin/Pokedex/PokemonBoxBackground.png", true);
    pokImgBackground->SetFixed (true);
    boxInfo->SetBackground (*pokImgBackground);
    boxInfoContent_->SetPicture ("WindowSkins/BasicSkin/Pokedex/PokemonBoxDefault.png");
    boxInfo->AddChild (*boxInfoContent_);

    firstVLayout_->AddChild (*title);    

    yap::WidgetBackground* menuBackground = new yap::WidgetBackground ("WindowSkins/BasicSkin/Pokedex/ListBackground.png", true);
    menu_ = new yap::Menu (yap::Menu::Type::VERTICAL, yap::Padding (5, 5, 5, 5), yap::Padding (5, 5, 5, 5), true);
    yap::WidgetBackground* selectedBackground = new yap::WidgetBackground ("WindowSkins/BasicSkin/Pokedex/SelectionBackground.png", true);
    menu_->SetSelectedBackground (*selectedBackground);
    menu_->SetSize (yap::Vector2 (firstHLayout_->GetSize ().x - firstVLayout_->GetSize ().x, firstHLayout_->GetSize ().y));
    menu_->SetBackground (*menuBackground);

    for (int i = 1; i <= pokedex_->GetMaxIDSeen (); i++)
    {
      yap::MenuItem* item = new yap::MenuItem (false);
      item->SetSize (yap::Vector2 (firstHLayout_->GetSize ().x - firstVLayout_->GetSize ().x - 10, 28));
      const yap::PokemonInfo* current = pokedex_->GetPokemonSeenID (i);

      if (current == nullptr)
      {
        item->SetContent ("N." + yap::StringHelper::ToString(i) + "    --------");
        item->OnSelected +=
          [&] (yap::MenuItem& sender, const yap::EmptyEventArgs& args)
        {
          boxInfoContent_->SetPicture ("WindowSkins/BasicSkin/Pokedex/PokemonBoxDefault.png");
        };
      }
      else
      {
        item->SetContent ("N." + yap::StringHelper::ToString(i) + "    " + current->GetName ());
        item->OnSelected +=
          [this, current] (yap::MenuItem& sender, const yap::EmptyEventArgs& args)
        {
          boxInfoContent_->SetPicture (current->GetMaleFront ());
        };
        item->OnActivated +=
          [&] (yap::MenuItem& sender, const yap::EmptyEventArgs& args)
        {
          validatedPokemon_ = pokedex_->GetPokemon (menu_->GetCurrentSelect ());
          //firstHLayout_->Close ();
          //pokedexInfo_->Open ();
        };
      }
      item->ChangeColor (sf::Color (0, 0, 0));
      /*item->SetBorder (*new yap::WidgetBorder ("Test/red.png"));*/
      menu_->AddChild (*item, yap::LayoutBox::Align::LEFT);

    }
    pokSeen_ = new yap::Label ("Vus : "  + yap::StringHelper::ToString (pokedex_->GetPokemonSeenCount ()));
    pokCaught_ = new yap::Label ("Pris : "  + yap::StringHelper::ToString (pokedex_->GetPokemonCaughtCount ()));
    pokSeen_->ChangeColor (sf::Color::White);
    pokCaught_->ChangeColor (sf::Color::White);

    
    secondVLayout->AddChild (*pokSeen_);
    secondVLayout->AddChild (*pokCaught_);

    secondHLayout->AddChild (*secondVLayout, yap::LayoutBox::Align::TOP);
    secondHLayout->AddChild (*boxInfo);
    secondHLayout->Refresh ();    

    firstVLayout_->AddChild (*secondHLayout, yap::LayoutBox::Align::RIGHT);

    firstHLayout_->AddChild (*firstVLayout_, yap::LayoutBox::Align::TOP);
    firstHLayout_->AddChild (*menu_);

    AddChild (*firstHLayout_);
  }

  void PokedexWidget::RefreshAfterAdd ()
  {
    if (menu_ != nullptr)
      menu_->Clear ();
    else
      return;

    if (pokedex_ != nullptr)
      for (int i = 1; i <= pokedex_->GetMaxIDSeen (); i++)
      {
        yap::MenuItem* item = new yap::MenuItem (false);
        item->SetSize (yap::Vector2 (firstHLayout_->GetSize ().x - firstVLayout_->GetSize ().x - 10, 28));
        const yap::PokemonInfo* current = pokedex_->GetPokemonSeenID (i);

        if (current == nullptr)
        {
          item->SetContent ("N." + yap::StringHelper::ToString(i) + "    --------");
          item->OnSelected +=
            [&] (yap::MenuItem& sender, const yap::EmptyEventArgs& args)
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
            //firstHLayout_->Close ();
            //pokedexInfo_->Open ();
          };
        }
        item->ChangeColor (sf::Color (0, 0, 0));
        /*item->SetBorder (*new yap::WidgetBorder ("Test/red.png"));*/
        menu_->AddChild (*item, yap::LayoutBox::Align::LEFT);

      }
      pokSeen_->SetText ("Vus : "  + yap::StringHelper::ToString (pokedex_->GetPokemonSeenCount ()));
      pokCaught_->SetText ("Pris : "  + yap::StringHelper::ToString (pokedex_->GetPokemonCaughtCount ()));
  }
  yap::PokemonInfo* PokedexWidget::GetActivatedPokemon () const
  {
    return validatedPokemon_;
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
