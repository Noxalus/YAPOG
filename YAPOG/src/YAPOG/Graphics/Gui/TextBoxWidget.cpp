#include "YAPOG/Graphics/Gui/Label.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/Gui/GuiEvent.hpp"
#include "YAPOG/Graphics/Gui/TextBoxWidget.hpp"

namespace yap
{
  TextBoxWidget::TextBoxWidget ()
    : label_ (nullptr)
    , curser_ (nullptr)
    , curserPos_ (0)
    , curserRelPos_ (0)
  {
    label_ = new Label ();
    label_->SetPosition (Vector2 (GetPosition ().x,
      GetPosition ().y + label_->GetCharHeight () / 2));
  }

  TextBoxWidget::TextBoxWidget (String content, uint size)
    : label_ (nullptr)
    , curser_ (nullptr)
    , curserPos_ (0)
    , curserRelPos_ (0)
  {
    label_ = new Label ();
    if (size != 30)
      SetTextSize (size);
    label_->SetPosition (
      Vector2 (
      GetPosition ().x,
      GetPosition ().y + label_->GetCharHeight () / 2));
    SetText (content);
  }

  TextBoxWidget::~TextBoxWidget ()
  {
  }

  bool TextBoxWidget::IsFocusable () const
  {
    return true;
  }

  void TextBoxWidget::Clear ()
  {
    label_->SetText ("");
    curserRelPos_ = 0;
    curserPos_ = 0;
    content_ = "";
  }
  void TextBoxWidget::SetCursor (Texture& cursor)
  {
    cursor.SetSize (Vector2 (cursor.GetSize ().x, label_->GetCharHeight ()));
    cursor.SetPosition (GetPosition ());
    curser_ = &cursor;
  }

  void TextBoxWidget::Refresh ()
  {
    label_->SetPosition (Vector2 (GetPosition ().x,
      GetPosition ().y));

    uint labelMaxWidth = GetUserSize ().x - padding_.left - padding_.right;
    while (label_->GetSize ().x > labelMaxWidth)
    {
      label_->SetText (label_->GetText ().substr (1));
    }

    BaseWidget::Refresh ();
  }

  Vector2 TextBoxWidget::HandleGetSize () const
  {
    return GetUserSize ()
      + ((border_ != nullptr) ? border_->GetSize () : Vector2 ());
  }

  void TextBoxWidget::HandleDraw (IDrawingContext& context)
  {
    label_->Draw (context);

    if (curser_ != nullptr)
    {
      curser_->SetPosition (label_->CharPos (
        label_->Length () - curserRelPos_) - Vector2 (2, -2));
      curser_->Draw (context);
    }
  }

  void TextBoxWidget::HandleShow (bool isVisible)
  {
  }

  void TextBoxWidget::HandleMove (const Vector2& offset)
  {
    label_->Move (offset);
    if (curser_ != nullptr)
      curser_->Move (offset);
    //drawableText_.setPosition (GetPosition() + offset);
  }

  void TextBoxWidget::HandleScale (const Vector2& factor)
  {
    label_->Scale (factor);
    if (curser_ != nullptr)
      curser_->Scale (factor);
  }

  void TextBoxWidget::HandleUpdate (const Time& dt)
  {
  }

  void TextBoxWidget::HandleChangeColor (const sf::Color& color)
  {
    label_->ChangeColor (color);
  }

  String TextBoxWidget::GetContent () const
  {
    return label_->GetText ();
  }

  void TextBoxWidget::SetTextSize (uint size)
  {
    label_->SetTextSize (size);
    if (curser_ != nullptr)
      curser_->SetSize (Vector2 (curser_->GetSize ().x, label_->GetSize ().y));
    Refresh ();
  }
  bool TextBoxWidget::HandleOnEvent (const GuiEvent& guiEvent)
  {
    if ((guiEvent.type == sf::Event::KeyPressed)
      && !guiEvent.key.alt 
      && !guiEvent.key.control
      && !(guiEvent.key.code == sf::Keyboard::Escape)
      && !(guiEvent.key.code >= sf::Keyboard::F1
      && guiEvent.key.code <= sf::Keyboard::F12))
    {
      if (guiEvent.key.code == sf::Keyboard::Back)
      {
        if (label_->Length () - curserRelPos_ == 0)
          return true;
        uint contentLength = content_.length ();
        if (content_.length () > 0)
        {
          if (curserPos_ == 0)
            content_ = content_.substr (0, content_.length () - 1);
          else
          {
            String firstPart =
              content_.substr (0, content_.length () - curserPos_ - 1);
            String lastPart =
              content_.substr (content_.length () - curserPos_);

            content_ = firstPart + lastPart;
          }
        }

        if (label_->Length () < contentLength)
        {
          if (curserRelPos_ == 0)
          {
            String temp;
            if (content_.length () == label_->Length ())
              temp = content_.substr (0, 1);
            else
              temp = content_.substr
              (content_.length () - label_->Length () - 1, 1);
            String temp2 = label_->GetText ();
            label_->SetText (temp + temp2.substr (0, temp2.length () - 1));

            uint labelMaxWidth =
              GetUserSize ().x - padding_.left - padding_.right;

            Vector2 labelWidth (
              label_->CharPos (label_->Length () - curserRelPos_)
              - label_->GetPosition ());

            while (labelWidth.x > labelMaxWidth)
            {
              label_->SetText (label_->GetText ().substr (1));
              labelWidth =
                label_->CharPos (label_->Length () - curserRelPos_)
                - label_->GetPosition ();
            }
          }
          else
          {
            String temp = label_->GetText ();
            String firstPart =
              temp.substr (0, temp.length () - curserRelPos_ - 1);
            String lastPart = temp.substr (temp.length () - curserRelPos_);

            int charleft = label_->Length () - curserRelPos_;
            char first =
              content_.at (content_.length () - curserPos_ - charleft);

            label_->SetText (first + firstPart + lastPart);
          }
        }
        else
          label_->SetText (content_);

        return true;
      }
      if (guiEvent.key.code == sf::Keyboard::Left)
      {
        if (curserPos_ >= content_.length ())
          return true;

        curserPos_++;
        if (curserRelPos_ < label_->Length ())
          curserRelPos_++;
        else
        {
          int charleft = label_->Length () - curserRelPos_;
          char first =
            content_.at (content_.length () - curserPos_ - charleft);

          String temp = label_->GetText ().substr (0, label_->Length () - 1);

          label_->SetText (first + temp);
        }

        return true;
      }

      if (guiEvent.key.code == sf::Keyboard::Right)
      {
        if (curserPos_ == 0)
          return true;

        if (curserRelPos_ > 0)
          curserRelPos_--;
        else
        {
          char end = content_.at (content_.length () - curserPos_);
          label_->SetText (label_->GetText ().substr (1) + end);
        }

        curserPos_--;

        return true;
      }
      return false;
    }

    if (guiEvent.type == sf::Event::TextEntered)
    {
      char txt = static_cast<char> (guiEvent.text.unicode);
      if (txt == '\b')
        return true;
      if (txt == '\t')
        return false;
      if (txt == '\r')
        return false;
      if (curserPos_ > 0)
      {
        String firstPart =
          content_.substr (0, content_.length () - curserPos_);
        String lastPart = content_.substr (content_.length () - curserPos_);

        content_ = firstPart + txt + lastPart;
      }
      else
        content_ += txt;

      if (curserRelPos_ > 0)
      {
        String temp = label_->GetText ();

        if (temp.length () < curserRelPos_)
          return true;

        String firstPart = temp.substr (0, temp.length () - curserRelPos_);
        String lastPart = temp.substr (temp.length () - curserRelPos_);

        label_->SetText (firstPart + txt + lastPart);
      }
      else
        label_->SetText (label_->GetText () + txt);

      uint labelMaxWidth = GetUserSize ().x - padding_.left - padding_.right;
      Vector2 labelWidth (label_->CharPos (label_->Length ())
        - label_->GetPosition ());
      while (labelWidth.x > labelMaxWidth - 10)
      {
        label_->SetText (label_->GetText ().substr (1));
        labelWidth = label_->CharPos (label_->Length ())
          - label_->GetPosition ();
      }
      while (label_->GetSize ().x > labelMaxWidth - 10)
      {
        label_->SetText (label_->GetText ().substr (1));
      }
      return true;
    }
    return false;
  }

  void TextBoxWidget::SetText (const String& contentArg)
  {
    if (contentArg.empty())
      return;
    else if (contentArg == content_)
      return;

    content_ = contentArg;
    label_->SetText (content_);

    String contentTemp = content_;
    uint labelMaxWidth = GetUserSize ().x - padding_.left - padding_.right;

    if (label_->GetSize ().x > labelMaxWidth)
    {
      uint endStrWidth = label_->GetSize ().x - labelMaxWidth;
      uint posChar =
        (label_->GetSize ().x - endStrWidth) * label_->GetCharWidth ();

      contentTemp = contentTemp.substr (posChar);
      label_->SetText (contentTemp);

      uint size = content_.length () - 1;
      while (label_->GetSize ().x < labelMaxWidth)
      {
        label_->SetText (content_.substr (0, size--) + contentTemp);
      }

      while (label_->GetSize ().x > labelMaxWidth && labelMaxWidth != 0)
      {
        contentTemp = contentTemp.substr (1);
        label_->SetText (contentTemp);
      }
    }
  }
} // namespace yap
