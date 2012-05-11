#include "GameScreen/TestScreen.hpp"
#include "YAPOG/System/IO/Log/DebugLogger.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"
#include "YAPOG/Graphics/ICamera.hpp"
#include "World/Map/MapReader.hpp"
#include "World/Map/Map.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Graphics/Game/Sprite/SpriteSet.hpp"
#include "YAPOG/Graphics/Game/Sprite/DirectionalSpriteSet.hpp"
#include "YAPOG/Graphics/Game/Sprite/ComposedSprite.hpp"
#include "YAPOG/Graphics/Gui/GameInput/GameInputManager.hpp"
#include "YAPOG/Graphics/Gui/GameInput/GameInputType.hpp"
#include "YAPOG/Graphics/Gui/GameInput/KeyboardGameInputEntry.hpp"
#include "YAPOG/Graphics/Gui/GameInput/GameInput.hpp"
#include "YAPOG/Content/ContentManager.hpp"

#include "YAPOG/Graphics/Gui/Label.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/Gui/LayoutH.hpp"
#include "YAPOG/Graphics/Gui/LayoutV.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/Gui/Menu.hpp"
#include "YAPOG/Graphics/Gui/MenuItem.hpp"
#include "YAPOG/Graphics/Gui/WidgetTextBox.hpp"

///////////////////////////////
/// Just some ugly tests... ///
///////////////////////////////

using namespace yap;

DirectionalSpriteSet dss1;
GameInputManager& gim = yap::GameInputManager::Instance ();
ContentManager& cm = ContentManager::Instance ();

TestScreen::TestScreen ()
  : yap::GameScreen ("Test")
  , textures_ ()
  , backTextures_ ()
  , anim1_ (100)
  , mover_ (1, 1)
{
  gim.AddGameInput (
    new GameInput (
    GameInputType::Action,
    new KeyboardGameInputEntry (Key::Return)));
  gim.AddGameInput (
    new GameInput (
    GameInputType::Misc,
    new KeyboardGameInputEntry (Key::M)));

  yap::IFStream input;
  cm.LoadFile ("Map/1.xml", input);
  yap::XmlReader xmlR (input, "Map");

  yap::Map map (yap::ID (1));
  yap::MapReader mapReader (map);

  xmlR.Accept (mapReader);

  yap::DebugLogger::Instance ()
    .LogLine ("MAP::ID=[" +
    yap::StringHelper::ToString (map.GetID ().GetValue ()) +
    "]")
    .LogLine ("MAP::NAME=[" + map.GetName () + "]");

  int animFlag = 0;

  for (int i = 0; i < 2000; ++i)
  {
    yap::Vector2 scaleFactor (0.7f, 0.7f);

    yap::Texture* texture = new yap::Texture ();

    texture->LoadFromFile ("boo.png");
    //    texture->Move (yap::Vector2 (i * 400.0f, 0.0f));
    texture->Scale (scaleFactor);
    texture->ChangeColor (sf::Color (255, 90, 128, 128));
    textures_.Add (texture);

    if (animFlag++ < 2)
    {
      //      dss1.AddSprite (yap::Direction::North, new yap::Sprite (texture));
      anim1_.AddFrame (new yap::Sprite (texture));
      //      spr1_.SetTexture (texture);
    }

    texture = new yap::Texture ();
    texture->LoadFromFile ("boo.png");
    //    texture->Move (yap::Vector2 (i * 400.0f + 200.0f, 0.0f));
    texture->ChangeColor (sf::Color (128, 255, 128, 128));
    texture->Scale (scaleFactor);
    backTextures_.Add (texture);
    if (animFlag++ < 2)
    {
      //      dss1.AddSprite (yap::Direction::South, new yap::Sprite (texture));
      anim1_.AddFrame (new yap::Sprite (texture));
    }
  }

  //  anim1_.Move (yap::Vector2 (100.0f, 100.0f));

  anim1_.ChangeState (yap::AnimatedSprite::PlayState::Loop);
  //  anim1_.ChangeColor (sf::Color::Blue);
}

TestScreen::~TestScreen ()
{
  /*  for (const auto& it : textures_)
  delete it;

  for (const auto& it : backTextures_)
  delete it;*/
}

const yap::ScreenType& TestScreen::HandleRun (
  const yap::Time& dt,
  yap::IDrawingContext& context)
{
  //  yap::DebugLogger::Instance ().LogLine (1.0f / dt.GetValue ());

  //  context.GetCamera ("Background World").Move (
  //    yap::Vector2 (140.0f * dt.GetValue (), 0.0f));

  context.SetMode ("Background World");

  //  for (auto it : backTextures_)
  //    it->Draw (context);

  context.SetDefaultCamera ();

  //  context.GetCamera ("World").Move (
  //    yap::Vector2 (300.0f * dt.GetValue (), 0.0f));

  //  for (auto it : textures_)
  //    it->Draw (context);

  //anim1_.Update (dt);


  //anim1_.Draw (context);
  //  dss1.Draw (context);
  //  spr1_.Draw (context);

  //guiManager_->Move (mover_);
  guiManager_->Update (dt);
  guiManager_->Draw (context);
  DebugLogger::Instance().LogLine (1.0f/dt.GetValue());

  return nextScreen_;
}

void TestScreen::HandleInit ()
{
  guiManager_ = new yap::GuiManager ();

  Menu* menu = new Menu (Menu::Type::HORIZONTAL, Padding (1, 1, 1, 1), Padding (5, 5, 5, 5), false);
  menu->SetSize (Vector2 (400, 88));
  MenuItem* item1 = new MenuItem ();
  MenuItem* item2 = new MenuItem ();
  MenuItem* item3 = new MenuItem ();

  item1->SetSize (Vector2 (88, 64));
  item2->SetSize (Vector2 (88, 64));
  item3->SetSize (Vector2 (88, 64));

  item1->SetContent ("Item 1");
  item2->SetContent ("Item 2");
  item3->SetContent ("Item 3");

  item1->ChangeColor (sf::Color (128, 64, 32));
  item2->ChangeColor (sf::Color (128, 64, 32));
  item3->ChangeColor (sf::Color (128, 64, 32));

  menu->AddChild (*item1, LayoutBox::Align::LEFT);
  menu->AddChild (*item2, LayoutBox::Align::LEFT);
  menu->AddChild (*item3, LayoutBox::Align::LEFT);

  yap::LayoutV* layout = new LayoutV (Padding (2, 2, 2, 2),
    Padding (9, 9 , 9, 9), false);
  WidgetBackground* bckgrd4 = new WidgetBackground ("bckgrd4.png", true);
  layout->SetBackground (*bckgrd4);

  layout->SetSize (Vector2 (1024, 768));

  yap::WidgetTextBox* label = new yap::WidgetTextBox ();
  label->SetText (String("Ceci est un label."));
  label->SetSize (Vector2 (100, 32));
  label->ChangeColor (sf::Color (255, 0, 128));

  yap::PictureBox* pb = new PictureBox ();
  pb->SetPicture (String("jarri_j.png"));
  pb->Scale (Vector2 (1, 1));

  WidgetBorder* border = new WidgetBorder ("heart.gif");
  pb->SetBorder (*border, 16);

  

  LayoutH* layouth = new LayoutH (Padding (20, 20, 20, 20),
    Padding (9, 9 , 9, 9), true);
  yap::WidgetBackground* bckgr5 = new WidgetBackground ("bckgrd5.png", true);
  

  WidgetTextBox* ts = new WidgetTextBox ("Element1");
  ts->SetSize (Vector2 (100, 32));
  WidgetTextBox* ts3 = new WidgetTextBox ("Element2");
  ts3->SetSize (Vector2 (100, 32));
  yap::WidgetBackground* bckgr = new WidgetBackground ("bckgrd3.png", false);

  ts->SetBackground (*bckgr);
  
  layouth->AddChild (*ts, LayoutBox::Align::TOP);
  layouth->AddChild (*ts3, LayoutBox::Align::TOP);

  layouth->SetBackground (*bckgr5);

  WidgetTextBox* ts2 = new WidgetTextBox ("Last Element");
  ts2->SetSize (Vector2 (100, 32));
  layout->AddChild (*label, LayoutBox::Align::CENTER);
  layout->AddChild (*pb, LayoutBox::Align::CENTER);
  layout->AddChild (*layouth, LayoutBox::Align::CENTER);
  layout->AddChild (*ts2, LayoutBox::Align::CENTER);
  layout->AddChild (*menu, LayoutBox::Align::CENTER);

  WidgetTextBox* txtbox = new WidgetTextBox ();
  txtbox->SetSize (Vector2 (256, 64));
  Texture* cursor = new Texture ();
  cursor->LoadFromFile ("cursor.png");
  txtbox->SetCursor (*cursor);
  WidgetBackground* bckgrd = new WidgetBackground ("bckgrd.png", true);
  txtbox->SetBackground (*bckgrd);

  //yap::widgetbackground* bckgr = new widgetbackground ();
  //bckgr->setbackground ("jarri_j.jpg", 1024, 512, false);

  
  guiManager_->AddChild (*layout);
  guiManager_->AddChild (*txtbox);
  
  // guiManager_->AddChild (*bckgr);

}

void TestScreen::HandleActivate ()
{
}

void TestScreen::HandleDeactivate ()
{
}

bool TestScreen::HandleOnEvent (const yap::GuiEvent& guiEvent)
{
  if (gim.GameInputIsActivated (yap::GameInputType::Action, guiEvent))
    dss1.SetCurrentSprite (yap::Direction::North);

  if (gim.GameInputIsActivated (yap::GameInputType::Misc, guiEvent))
    dss1.SetCurrentSprite (yap::Direction::South);

  return false;
}

bool TestScreen::HandleOnPriorityEvent (const yap::GuiEvent& guiEvent)
{
  return false;
}
