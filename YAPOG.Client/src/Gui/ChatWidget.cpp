#include "YAPOG/Game/Chat/ChatHeader.hpp"
#include "YAPOG/Game/Chat/Chat.hpp"
#include "YAPOG/Game/Chat/ChatDisplayer.hpp"

#include "Gui/ChatWidget.hpp"

namespace ycl
{

  ChatWidget::ChatWidget ()
    : chat_ (new yap::Chat ())
    , line_ ("")
    , lineCatcher_ (new yap::TextBoxWidget ())
    , tabTitle_ ()
    , tabLayout_ (new yap::HorizontalLayout (yap::Padding (5, 5, 0, 0),
    yap::Padding (0, 5, 0, 0), false))
    , dialog_ (new yap::Label (yap::String ("COUCOU")))
    , dialLayout_ (new yap::HorizontalLayout (yap::Padding (5, 5, 0, 0),
    yap::Padding (0, 0, 0, 0), false))
    , entryLayout_ (new yap::HorizontalLayout (yap::Padding (5, 5, 0, 0),
    yap::Padding (0, 0, 0, 0), false))
    , bigLayout_ (new yap::VerticalLayout (yap::Padding (5, 5, 5, 5),
    yap::Padding (5, 5, 5, 5), false))
  {
    yap::Texture* cursor = new yap::Texture ();
    cursor->LoadFromFile ("chatSet/Cursor.png");
    bigLayout_->SetSize (yap::Vector2 (300, 150));
    lineCatcher_->ChangeColor (sf::Color::Black);
    lineCatcher_->SetCursor (*cursor);
    lineCatcher_->SetSize (yap::Vector2 (242, 12));
    lineCatcher_->Scale (yap::Vector2 (0.5, 0.5));
    dialog_->Scale (yap::Vector2 (0.5, 0.5));
    dialog_->ChangeColor (sf::Color::Black);
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
      //title->SetSize (yap::Vector2 (name.length () * 8, 12));
      title->Scale (yap::Vector2 (0.5, 0.5));
      tabTitle_.Add (title);
      tabLayout_->AddChild (*title);
    }
    tabLayout_->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
    bigLayout_->AddChild (*tabLayout_);
  }

  void ChatWidget::InitDial ()
  {
    dialLayout_->SetSize (yap::Vector2 (242, 96));

    dialLayout_->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
    dialLayout_->AddChild (*dialog_);
    bigLayout_->AddChild (*dialLayout_);
  }

  void ChatWidget::InitEntry ()
  {
    entryLayout_->SetSize (yap::Vector2 (242, 12));

    entryLayout_->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
    entryLayout_->AddChild (*lineCatcher_);
    bigLayout_->AddChild (*entryLayout_);
  }

  void ChatWidget::Init ()
  {
    yap::WidgetBackground* background = new yap::WidgetBackground ("chatSet/Background.png", true);
    SetBackground (*background);

    InitTab ();
    InitDial ();
    InitEntry ();

    AddChild (*bigLayout_);
    bigLayout_->SetBackground (*background);
    bigLayout_->SetPosition (yap::Vector2 (42, 242));
    int toto = bigLayout_->GetPosition ().x;
  }

  bool ChatWidget::IsFocusable () const
  {
    return true;
  }

  yap::Vector2 ChatWidget::HandleGetSize () const
  {
    return yap::Vector2 (300, 150);
  }

  bool         ChatWidget::HandleOnEvent (const yap::GuiEvent& guiEvent)
  {
    if (guiEvent.type == sf::Event::KeyPressed)
    {
      if (guiEvent.key.code == sf::Keyboard::Return)
      {
        yap::String todisplay = lineCatcher_->GetContent ();
        if (todisplay.compare ("exit") == 0)
          exit (EXIT_SUCCESS);
        chat_->SetBuf (todisplay);
        chat_->Parse ();
        chat_->Exec ();
        dialog_->SetText (todisplay);
        dialog_->SetSize (yap::Vector2 (todisplay.length () * 8, 12));
      }
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
