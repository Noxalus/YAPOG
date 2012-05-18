#include <SFML/Graphics/Text.hpp>
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
    //if (isVisible_)
    Label* current = labels_[currentText_];
    current->ChangeColor (sf::Color (128, 32, 64));
    current->Draw (context);

    if (IsVisible ())
      labels_[currentText_]->Draw (context);

  }

  void WidgetDialogBox::HandleShow (bool isVisible)
  {
    for (Label* text : labels_)
      text->Show (isVisible);
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
    for (Label* text : labels_)
      text->Update (dt);
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
    if (!isVisible_)
      return false;
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

  void WidgetDialogBox::AddText (const String& contentArg)
  {
    if (contentArg.empty())
      return;

    String txt = contentArg;
    Label* lb = new Label ();

    uint LabelMaxSize = GetUserSize ().x - padding_->left - padding_->right;
    uint charNumb = (LabelMaxSize / lb->GetCharWidth ());
    charNumb += (charNumb / 2);

    for (int i = 1; i < contentArg.length (); i++)
    {
      sf::Text widh
      int tess = i % charNumb;
      if (i % charNumb == 0)
        txt.insert (i, "\n");
    }
    lb->SetText (txt);
    labels_.Add (lb);
    Refresh ();
  }
} // namespace yap
