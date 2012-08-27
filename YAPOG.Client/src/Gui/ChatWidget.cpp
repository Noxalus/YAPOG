#include "YAPOG/Game/Chat/ChatHeader.hpp"
#include "YAPOG/Game/Chat/Chat.hpp"
#include "YAPOG/Game/Chat/ChatDisplayer.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Game/Chat/GameMessage.hpp"

#include "Gui/ChatWidget.hpp"
#include "Game.hpp"

namespace ycl
{

  ChatWidget::ChatWidget (const yap::String& userLogin)
    : userLogin_ (userLogin)
    , chat_ (new yap::Chat ())
    , line_ ("")
    , lineCatcher_ (new yap::TextBoxWidget ("", 12))
    , tabTitle_ ()
    , tabLayout_ (new yap::HorizontalLayout (yap::Padding (5, 5, 0, 0),
    yap::Padding (0, 5, 0, 0), false))
    , dialog_ (new yap::MultiLabelWidget (yap::Padding (5, 5, 5, 5),
    yap::Padding (0, 0, 0, 0), false))
    , dialLayout_ (new yap::HorizontalLayout (yap::Padding (5, 5, 0, 0),
    yap::Padding (0, 0, 0, 0), false))
    , entryLayout_ (new yap::HorizontalLayout (yap::Padding (5, 5, 0, 0),
    yap::Padding (0, 10, 0, 0), false))
    , bigLayout_ (new yap::VerticalLayout (yap::Padding (5, 5, 5, 5),
    yap::Padding (5, 5, 5, 5), false))
  {
    yap::Texture* cursor = new yap::Texture ();
    cursor->LoadFromFile ("WindowSkins/BasicSkin/Global/TextCursor.png");
    bigLayout_->SetSize (yap::Vector2 (300, 150));
    lineCatcher_->SetCursor (*cursor);
    lineCatcher_->SetSize (yap::Vector2 (242, 12));
  }

  ChatWidget::~ChatWidget ()
  {
    delete (chat_);
    chat_ = nullptr;
    delete (lineCatcher_);
    lineCatcher_ = nullptr;
    delete (tabLayout_);
    tabLayout_ = nullptr;
    delete (dialog_);
    dialog_ = nullptr;
    delete (dialLayout_);
    dialLayout_ = nullptr;
    delete (entryLayout_);
    entryLayout_ = nullptr;
    delete (bigLayout_);
    bigLayout_ = nullptr;

    for (yap::Label* l : tabTitle_)
    {
      delete (l);
      l = nullptr;
    }
  }

  void ChatWidget::InitTab ()
  {
    tabLayout_->SetSize (yap::Vector2 (242, 12));
    for (yap::UInt32 i = 0; i < chat_->GetTabCount (); i++)
    {
      yap::String name = chat_->GetTabName (i);
      yap::Label* title = new yap::Label (name);
      title->ChangeColor (sf::Color::Black);
      title->SetTextSize (12);
      title->SetBorder (*new yap::WidgetBorder ("Test/black.png"));
      tabTitle_.Add (title);
      tabLayout_->AddChild (*title);
    }
    tabLayout_->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
    bigLayout_->AddChild (*tabLayout_);
  }

  void ChatWidget::InitDial ()
  {
    dialLayout_->SetSize (yap::Vector2 (242, 96));
    dialog_->SetSize (yap::Vector2 (242, 96));

    dialLayout_->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
    dialLayout_->AddChild (*dialog_);
    bigLayout_->AddChild (*dialLayout_);
  }

  void ChatWidget::InitEntry ()
  {
    entryLayout_->SetSize (yap::Vector2 (242, 20));

    entryLayout_->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
    lineCatcher_->ChangeColor (sf::Color::Black);
    entryLayout_->AddChild (*lineCatcher_);
    bigLayout_->AddChild (*entryLayout_);
  }

  void ChatWidget::Init ()
  {
    yap::WidgetBackground* chatBground =
      new yap::WidgetBackground (
      "WindowSkins/BasicSkin/Global/WindowBackgroundTexture.png",
      true);
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

    yap::WidgetBorder* chatBorder =
      new yap::WidgetBorder (*t, *tr, *r, *br, *b, *bl, *l, *tl, true);

    InitTab ();
    InitDial ();
    InitEntry ();

    AddChild (*bigLayout_);
    bigLayout_->SetBorder (*chatBorder);
    bigLayout_->SetPosition (
      yap::Vector2 (
      20,
      Game::SCREEN_SIZE.y - GetSize ().y - 20));
    bigLayout_->SetBackground (*chatBground);

    TabAndChanHandler (true, true, 1);
  }

  bool ChatWidget::IsFocusable () const
  {
    return true;
  }

  yap::Vector2 ChatWidget::HandleGetSize () const
  {
    return bigLayout_->GetSize ();
  }

  void ChatWidget::AddMessage (const yap::GameMessage& message)
  {
    yap::String fullMessage = 
      message.GetSenderName () + ": " + message.GetContent ();

    dialog_->AddText (fullMessage, 12, sf::Color (127, 127, 127));
  }

  void ChatWidget::DisplayResponse (yap::ResponseType res)
  {
    bool toclear = res.Clean;
    yap::collection::Array<yap::UInt32> responseChan = res.Channb;
    yap::collection::Array<yap::String> responseString = res.Message;

    if (toclear)
      dialog_->Clear ();

    for (size_t i = 0; i < responseString.Count (); i++)
    {
      sf::Color color = sf::Color::Black;
      switch (responseChan[i])
      {
      case 1:
        color = sf::Color::Black;
        break;
      case 2:
        color = sf::Color::Green;
        break;
      case 3:
        color = sf::Color::Blue;
        break;
      case 4:
        color = sf::Color (128, 128, 0);
        break;
      case 5:
        color = sf::Color::Magenta;
        break;
      default:
        color = sf::Color::Red;
        break;
      }

      yap::String message = responseString[i];

      if (res.Command)
      {
        dialog_->AddText (
          message,
          12,
          color);
        continue;
      }

      yap::GameMessage gameMessage;
      gameMessage.SetSenderName (userLogin_);
      gameMessage.SetContent (message);
      OnMessageSent (*this, gameMessage);
    }
  }

  bool ChatWidget::TabAndChanHandler (bool chan, bool add, int i)
  {
    yap::ResponseType response;
    if (chan)
      chat_->SetBuf ((add ? "/addchan " : "/switchchan ") +
      yap::StringHelper::ToString (i));
    else
      chat_->SetBuf ("/switchtab " + yap::StringHelper::ToString (i));
    chat_->Parse ();
    response = chat_->Exec ();

    if (!chan && response.Message.IsEmpty ())
      response.Clean = true;
    response.Command = true;
    DisplayResponse (response);

    return true;
  }

  bool ChatWidget::TestAddChan (const yap::GuiEvent& guiEvent)
  {
    if (guiEvent.key.alt
      && guiEvent.key.code == sf::Keyboard::Num0)
      return TabAndChanHandler (true, true, 0);
    if (guiEvent.key.alt
      && guiEvent.key.code == sf::Keyboard::Num1)
      return TabAndChanHandler (true, true, 1);
    if (guiEvent.key.alt
      && guiEvent.key.code == sf::Keyboard::Num2)
      return TabAndChanHandler (true, true, 2);
    if (guiEvent.key.alt
      && guiEvent.key.code == sf::Keyboard::Num3)
      return TabAndChanHandler (true, true, 3);
    if (guiEvent.key.alt
      && guiEvent.key.code == sf::Keyboard::Num4)
      return TabAndChanHandler (true, true, 4);
    if (guiEvent.key.alt
      && guiEvent.key.code == sf::Keyboard::Num5)
      return TabAndChanHandler (true, true, 5);
    if (guiEvent.key.alt
      && guiEvent.key.code == sf::Keyboard::Num6)
      return TabAndChanHandler (true, true, 6);
    if (guiEvent.key.alt
      && guiEvent.key.code == sf::Keyboard::Num7)
      return TabAndChanHandler (true, true, 7);
    if (guiEvent.key.alt
      && guiEvent.key.code == sf::Keyboard::Num8)
      return TabAndChanHandler (true, true, 8);
    if (guiEvent.key.alt
      && guiEvent.key.code == sf::Keyboard::Num9)
      return TabAndChanHandler (true, true, 9);
    return false;
  }

  bool ChatWidget::TestSwitchTab (const yap::GuiEvent& guiEvent)
  {
    if (guiEvent.key.control
      && guiEvent.key.code == sf::Keyboard::Num0)
      return TabAndChanHandler (false, false, 0);
    if (guiEvent.key.control
      && guiEvent.key.code == sf::Keyboard::Num1)
      return TabAndChanHandler (false, false, 1);
    if (guiEvent.key.control
      && guiEvent.key.code == sf::Keyboard::Num2)
      return TabAndChanHandler (false, false, 2);
    if (guiEvent.key.control
      && guiEvent.key.code == sf::Keyboard::Num3)
      return TabAndChanHandler (false, false, 3);
    if (guiEvent.key.control
      && guiEvent.key.code == sf::Keyboard::Num4)
      return TabAndChanHandler (false, false, 4);
    if (guiEvent.key.control
      && guiEvent.key.code == sf::Keyboard::Num5)
      return TabAndChanHandler (false, false, 5);
    if (guiEvent.key.control
      && guiEvent.key.code == sf::Keyboard::Num6)
      return TabAndChanHandler (false, false, 6);
    if (guiEvent.key.control
      && guiEvent.key.code == sf::Keyboard::Num7)
      return TabAndChanHandler (false, false, 7);
    if (guiEvent.key.control
      && guiEvent.key.code == sf::Keyboard::Num8)
      return TabAndChanHandler (false, false, 8);
    if (guiEvent.key.control
      && guiEvent.key.code == sf::Keyboard::Num9)
      return TabAndChanHandler (false, false, 9);
    return false;
  }

  bool ChatWidget::HandleOnPriorityEvent (const yap::GuiEvent& guiEvent)
  {
    if (guiEvent.type == sf::Event::KeyPressed)
    {
      if (guiEvent.key.code == sf::Keyboard::Escape)
      {
        this->Close ();
        return true;
      }

      if (TestAddChan (guiEvent) || TestSwitchTab (guiEvent))
        return true;
    }

    return false;
  }

  bool ChatWidget::HandleOnEvent (const yap::GuiEvent& guiEvent)
  {
    if (guiEvent.type == sf::Event::KeyPressed)
    {
      if (guiEvent.key.code == sf::Keyboard::Return)
      {
        yap::ResponseType response;
        yap::String todisplay = lineCatcher_->GetContent ();

        chat_->SetBuf (todisplay);
        chat_->Parse ();
        response = chat_->Exec ();
        response.Command = chat_->GetIsCommand ();
        if (!response.Message.IsEmpty ())
          DisplayResponse (response);
        lineCatcher_->Clear ();
      }

      if (guiEvent.key.code == sf::Keyboard::Up)
      {
        chat_->SetBuf ("/up");
        yap::String todisplay = chat_->Parse ();
        lineCatcher_->Clear ();
        if (!todisplay.empty ())
          lineCatcher_->SetText (todisplay);
      }

      if (guiEvent.key.code == sf::Keyboard::Down)
      {
        chat_->SetBuf ("/down");
        yap::String todisplay = chat_->Parse ();
        lineCatcher_->Clear ();
        if (!todisplay.empty ())
          lineCatcher_->SetText (todisplay);
      }

      return true;
    }
    return false;
  }

  void ChatWidget::HandleMove (const yap::Vector2& offset)
  {

  }
  void ChatWidget::HandleScale (const yap::Vector2& factor)
  {

  }
  void ChatWidget::HandleDraw (yap::IDrawingContext& context)
  {

  }
  void ChatWidget::HandleShow (bool isVisible)
  {

  }
  void ChatWidget::HandleChangeColor (const sf::Color& color)
  {

  }
  void ChatWidget::HandleUpdate (const yap::Time& dt)
  {

  }
} // namespace ycl
