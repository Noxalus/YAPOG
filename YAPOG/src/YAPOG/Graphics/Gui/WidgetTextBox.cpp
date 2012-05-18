#include "YAPOG/Graphics/Gui/Label.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/Gui/GuiEvent.hpp"
#include "YAPOG/Graphics/Gui/WidgetTextBox.hpp"

namespace yap
{
  WidgetTextBox::WidgetTextBox ()
    : label_ (nullptr)
    , curser_ (nullptr)
    , curserPos_ (0)
    , curserRelPos_ (0)
  {
    label_ = new Label ();
    label_->SetPosition (Vector2 (GetPosition ().x,
                                  GetPosition ().y + label_->GetCharHeight () / 2));
  }

  WidgetTextBox::WidgetTextBox (String content)
    : label_ (nullptr)
    , curser_ (nullptr)
    , curserPos_ (0)
    , curserRelPos_ (0)
  {
    label_ = new Label ();
    label_->SetPosition (
      Vector2 (
        GetPosition ().x,
        GetPosition ().y + label_->GetCharHeight () / 2));
    SetText (content);
  }

  WidgetTextBox::~WidgetTextBox ()
  {
  }

  bool WidgetTextBox::IsFocusable () const
  {
    return true;
  }

  void WidgetTextBox::SetCursor (Texture& cursor)
  {
    cursor.SetSize (Vector2 (cursor.GetSize ().x, label_->GetCharHeight ()));
    cursor.SetPosition (GetPosition ());
    curser_ = &cursor;
  }

  void WidgetTextBox::Refresh ()
  {
    label_->SetPosition (Vector2 (GetPosition ().x,
                                  GetPosition ().y /*+ label_->GetCharHeight () / 2*/));

    uint labelMaxWidth = GetUserSize ().x - padding_->left - padding_->right;
    while (label_->GetSize ().x > labelMaxWidth)
    {
      label_->SetText (label_->GetText ().substr (1));
    }

    BaseWidget::Refresh ();
  }

  Vector2 WidgetTextBox::HandleGetSize () const
  {
    return GetUserSize ()
      + ((border_ != nullptr) ? Vector2 (border_->GetWidth ()
                                         * 2, border_->GetWidth () * 2) : Vector2 ());
  }

  void WidgetTextBox::HandleDraw (IDrawingContext& context)
  {
    label_->Draw (context);

    if (curser_ != nullptr)
    {
      curser_->SetPosition (label_->CharPos (
                              label_->Length () - curserRelPos_) - Vector2 (3, -5));
      curser_->Draw (context);
    }
  }

  void WidgetTextBox::HandleShow (bool isVisible)
  {
  }

  void WidgetTextBox::HandleMove (const Vector2& offset)
  {
    label_->Move (offset);
    if (curser_ != nullptr)
      curser_->Move (offset);
    //drawableText_.setPosition (GetPosition() + offset);
  }

  void WidgetTextBox::HandleScale (const Vector2& factor)
  {
    label_->Scale (factor);
    if (curser_ != nullptr)
      curser_->Scale (factor);
  }

  void WidgetTextBox::HandleUpdate (const Time& dt)
  {
  }

  void WidgetTextBox::HandleChangeColor (const sf::Color& color)
  {
    label_->ChangeColor (color);
  }

  String WidgetTextBox::GetContent () const
  {
    return label_->GetText ();
  }

  bool WidgetTextBox::HandleOnEvent (const GuiEvent& guiEvent)
  {
    if (guiEvent.type == sf::Event::KeyPressed)
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
              GetUserSize ().x - padding_->left - padding_->right;

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

      uint labelMaxWidth = GetUserSize ().x - padding_->left - padding_->right;
      Vector2 labelWidth (label_->CharPos (label_->Length ())
                          - label_->GetPosition ());
      while (labelWidth.x > labelMaxWidth)
      {
        label_->SetText (label_->GetText ().substr (1));
        labelWidth = label_->CharPos (label_->Length ())
          - label_->GetPosition ();
      }
      while (label_->GetSize ().x > labelMaxWidth)
      {
        label_->SetText (label_->GetText ().substr (1));
      }
      return true;
    }
    return false;
  }

  void WidgetTextBox::SetText (const String& contentArg)
  {
    if (contentArg.empty())
      return;
    else if (contentArg == content_)
      return;

    content_ = contentArg;
    label_->SetText (content_);

    String contentTemp = content_;
    uint labelMaxWidth = GetUserSize ().x - padding_->left - padding_->right;

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
