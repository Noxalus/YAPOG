#include "YAPOG/Graphics/Gui/Label.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/Gui/GuiEvent.hpp"
#include "YAPOG/Graphics/Gui/WidgetDialogBox.hpp"

namespace yap
{
  WidgetDialogBox::WidgetDialogBox ()
    : labels_ ()
    , currentText_ (0)
    , textSpeed_ ()
  {
  }

  WidgetDialogBox::WidgetDialogBox (String content)
    : labels_ ()
    , currentText_ (0)
  {
    AddText (content);
  }

  WidgetDialogBox::~WidgetDialogBox ()
  {
  }

  bool WidgetDialogBox::IsFocusable () const
  {
    return true;
  }

  void WidgetDialogBox::Refresh ()
  {
    for (Label* text : labels_)
    {
      text->SetPosition (Vector2 (GetPosition ().x,
        GetPosition ().y /*+ label_->GetCharHeight () / 2*/));
    }

    BaseWidget::Refresh ();
  }

  Vector2 WidgetDialogBox::HandleGetSize () const
  {
    return GetUserSize ()
      + ((border_ != nullptr) ? Vector2 (border_->GetWidth ()
      * 2, border_->GetWidth () * 2) : Vector2 ());
  }

  void WidgetDialogBox::HandleDraw (IDrawingContext& context)
  {
    if (IsVisible ())
      labels_[currentText_]->Draw (context);
  }

  void WidgetDialogBox::HandleShow (bool isVisible)
  {
  }

  void WidgetDialogBox::HandleMove (const Vector2& offset)
  {
    for (Label* text : labels_)
      text->Move (offset);
  }

  void WidgetDialogBox::HandleScale (const Vector2& factor)
  {
    for (Label* text : labels_)
      text->Scale (factor);
  }

  void WidgetDialogBox::HandleUpdate (const Time& dt)
  {
  }

  void WidgetDialogBox::HandleChangeColor (const sf::Color& color)
  {
    for (Label* text : labels_)
      text->ChangeColor (color);
  }

  String WidgetDialogBox::GetContent () const
  {
    return content_;
  }

  bool WidgetDialogBox::HandleOnEvent (const GuiEvent& guiEvent)
  {
    if (guiEvent.type == sf::Event::KeyPressed)
    {
      if (guiEvent.key.code == sf::Keyboard::Return)
      {
        currentText_++;
        if (currentText_ == labels_.Count ())
        {
          isVisible_ = false;
        }
        else
        {
          isVisible_ = true;
        }
        return true;
      }
    }
    return false;
  }

  void WidgetDialogBox::AddText (String& contentArg)
  {
    if (contentArg.empty())
      return;

    String txt = contentArg;
    Label* lb = new Label ();
    lb->SetSize (GetUserSize ());

    uint LabelMaxSize = GetUserSize ().x - padding_->left - padding_->right;
    uint charNumb = LabelMaxSize / lb->GetCharWidth ();

    for (uint i = 0; i < contentArg.length (); i++)
    {
      if (i % charNumb == 0)
        txt.insert (charNumb, "\n");
    }
    lb->SetText (txt);
    labels_.Add (lb);
    Refresh ();
  }
} // namespace yap
