#include "YAPOG/System/IOStream.hpp"
#include "YAPOG/Graphics/Gui/Label.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
#include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Gui/BackgroundWidget.hpp"
#include "YAPOG/Graphics/Gui/BorderWidget.hpp"
#include "YAPOG/Graphics/Gui/Menu.hpp"
#include "YAPOG/Graphics/Gui/MenuItem.hpp"
#include "YAPOG/Graphics/Gui/TextBoxWidget.hpp"
#include "YAPOG/Graphics/Gui/GuiManager.hpp"
#include "YAPOG/Graphics/Gui/DialogBoxWidget.hpp"

#include "YAPOG/System/RandomHelper.hpp"

#include "YAPOG/Game/Pokemon/Pokemon.hpp"
#include "YAPOG/Game/Pokemon/PokemonTeam.hpp"
#include "YAPOG/Game/Battle/PokemonFighter.hpp"
#include "YAPOG/Game/Battle/PokemonFighterTeam.hpp"

#include "Gui/GameMainMenu.hpp"
#include "GameScreen/LoginScreen.hpp"
#include "Client/Session.hpp"

#include "Battle/WildBattle.hpp"

#include "Gui/PokedexWidget.hpp"
#include "Gui/MainMenu.hpp"

namespace ycl
{
  const yap::ScreenType LoginScreen::DEFAULT_NAME = "Login";

  LoginScreen::LoginScreen ()
    : BaseScreen (DEFAULT_NAME)
  {
  }

  LoginScreen::~LoginScreen ()
  {
  }

  void LoginScreen::HandleInit ()
  {
    BaseScreen::HandleInit ();
/*
    MainMenu* mainMenu = new MainMenu ();
    mainMenu->Init ();
    guiManager_->AddChild (*mainMenu);

    PokedexWidget* pokedex = new PokedexWidget ();
    pokedex->Init ();
    GameMainMenu* menu = new GameMainMenu ();
    menu->Init ("PsykoBlackMetal");
    
    yap::VerticalLayout* layout = new yap::VerticalLayout (
    yap::Padding (2, 2, 2, 2),
    yap::Padding (9, 9 , 9, 9), false);

    yap::BackgroundWidget* bckgrd4 = new yap::BackgroundWidget ("bckgrd4.png", true);
    layout->SetBackground (*bckgrd4);

    layout->SetSize (yap::Vector2 (1024, 768));

    yap::TextBoxWidget* label = new yap::TextBoxWidget ();
    label->SetText ("Ceci est un label.");
    label->SetSize (yap::Vector2 (100, 32));
    label->ChangeColor (sf::Color (255, 0, 128));

    yap::PictureBox* pb = new yap::PictureBox ();
    pb->SetPicture (yap::String("jarri_j.png"));
    pb->Scale (yap::Vector2 (1, 1));

    yap::BorderWidget* border = new yap::BorderWidget ("heart.gif");
    border->SetScalable (false);
    pb->SetBorder (*border, 16);

    yap::HorizontalLayout* layouth = new yap::HorizontalLayout (
    yap::Padding (20, 20, 20, 20),
    yap::Padding (9, 9 , 9, 9), true);

    yap::BackgroundWidget* bckgr5 =
    new yap::BackgroundWidget (
    "bckgrd5.png",
    true);

    yap::TextBoxWidget* ts = new yap::TextBoxWidget ("Element1");
    ts->SetSize (yap::Vector2 (100, 32));
    yap::TextBoxWidget* ts3 = new yap::TextBoxWidget ("Element2");
    ts3->SetSize (yap::Vector2 (100, 32));
    yap::BackgroundWidget* bckgr = new yap::BackgroundWidget (
    "bckgrd3.png",
    false);

    ts->SetBackground (*bckgr);

    layouth->AddChild (*ts, yap::LayoutBox::Align::TOP);
    layouth->AddChild (*ts3, yap::LayoutBox::Align::TOP);

    layouth->SetBackground (*bckgr5);

    yap::TextBoxWidget* ts2 = new yap::TextBoxWidget ("Last Element");
    ts2->SetSize (yap::Vector2 (100, 32));
    layout->AddChild (*menu, yap::LayoutBox::Align::CENTER);
    layout->AddChild (*label, yap::LayoutBox::Align::CENTER);
    layout->AddChild (*pb, yap::LayoutBox::Align::CENTER);
    layout->AddChild (*layouth, yap::LayoutBox::Align::CENTER);
    layout->AddChild (*ts2, yap::LayoutBox::Align::CENTER);


    yap::TextBoxWidget* txtbox = new yap::TextBoxWidget ();
    txtbox->SetSize (yap::Vector2 (256, 64));
    yap::Texture* cursor = new yap::Texture ();
    cursor->LoadFromFile ("cursor.png");
    txtbox->SetCursor (*cursor);
    yap::BackgroundWidget* bckgrd = new yap::BackgroundWidget (
    "bckgrd.png",
    true);
    txtbox->SetBackground (*bckgrd);

    //yap::BackgroundWidget* bckgr = new BackgroundWidget ();
    //bckgr->setbackground ("jarri_j.jpg", 1024, 512, false);

    yap::DialogBoxWidget* dialog = new yap::DialogBoxWidget ();
    dialog->SetSize (yap::Vector2 (256, 128));
    yap::BackgroundWidget* dialogbck = new yap::BackgroundWidget ("bckgrd.png", true);
    dialog->SetBackground (*dialogbck);
    dialog->AddText (yap::String ("Il était une fois l'histoire de Mohammed Ali (baba)."));
    dialog->AddText (yap::String ("Ali alla à la halle à alakazham."));
    dialog->AddText (yap::String ("C'était sans compté sur la mise à jour de la divinité."));

    guiManager_->AddChild (*pokedex);
    guiManager_->AddChild (*menu);
    guiManager_->AddChild (*layout);
    guiManager_->AddChild (*txtbox);
    guiManager_->AddChild (*dialog);
    
    guiManager_->AddChild (*bckgr);
    */
  }

  const yap::ScreenType& LoginScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    Login ();

    return BaseScreen::HandleRun (dt, context);
  }

  //!\\ tmp
  void LoginScreen::Login ()
  {
    yap::String login;

    std::cout << "Enter a login: ";
    std::cin >> login;

    session_.Login (login);

    nextScreen_ = "Gameplay";
  }
} // namespace ycl
