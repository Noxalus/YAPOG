#include <SFML/Graphics/Text.hpp>
#include "YAPOG/Graphics/Gui/Label.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/Gui/GuiEvent.hpp"
#include "YAPOG/Graphics/Gui/DialogBoxWidget.hpp"
#include "YAPOG/Content/ContentManager.hpp"

namespace yap
{
  DialogBoxWidget::DialogBoxWidget ()
    : labels_ ()
    , currentText_ (0)
    , textSpeed_ ()
  {
  }

  DialogBoxWidget::DialogBoxWidget (const String& content)
    : labels_ ()
    , currentText_ (0)
  {
    AddText (content);
  }

  DialogBoxWidget::~DialogBoxWidget ()
  {
  }

  void DialogBoxWidget::SetShowText (bool state)
  {
    showText_ = state;
  }

  bool DialogBoxWidget::IsFocusable () const
  {
    return true;
  }

  void DialogBoxWidget::Refresh ()
  {
    for (Label* text : labels_)
    {
      text->SetPosition (Vector2 (GetPosition ().x + padding_.left,
        GetPosition ().y + padding_.top/*+ label_->GetCharHeight () / 2*/));
    }

    BaseWidget::Refresh ();
  }

  Vector2 DialogBoxWidget::HandleGetSize () const
  {
    return GetUserSize ()
      + ((border_ != nullptr) ? border_->GetSize () : Vector2 ());
  }

  void DialogBoxWidget::HandleDraw (IDrawingContext& context)
  {      
    if (showText_)
      labels_[currentText_]->Draw (context);

  }

  void DialogBoxWidget::HandleShow (bool isVisible)
  {
    for (Label* text : labels_)
      text->Show (isVisible);
  }

  void DialogBoxWidget::HandleMove (const Vector2& offset)
  {
    for (Label* text : labels_)
      text->Move (offset);
  }

  void DialogBoxWidget::HandleScale (const Vector2& factor)
  {
    for (Label* text : labels_)
      text->Scale (factor);
  }

  void DialogBoxWidget::HandleUpdate (const Time& dt)
  {
    for (Label* text : labels_)
      text->Update (dt);
  }

  void DialogBoxWidget::HandleChangeColor (const sf::Color& color)
  {
    for (Label* text : labels_)
      text->ChangeColor (color);
  }

  String DialogBoxWidget::GetContent () const
  {
    return content_;
  }

  bool DialogBoxWidget::HandleOnEvent (const GuiEvent& guiEvent)
  {
    if (!isVisible_ || !showText_)
      return false;
    if (guiEvent.type == sf::Event::KeyPressed)
    {
      if (guiEvent.key.code == sf::Keyboard::Return)
      {
        SkipText ();
        return true;
      }
    }
    return false;
  }

  void DialogBoxWidget::AddText (const String& contentArg)
  {
    if (contentArg.empty())
      return;

    String txt = contentArg;
    Label* lb = new Label ();

    uint LabelMaxSize = GetUserSize ().x - padding_.left - padding_.right;
    uint charNumb = (LabelMaxSize / lb->GetCharWidth ());

    uint previousPos = 0;
    uint subPos = charNumb;
    sf::Text width (
      txt.substr (0, subPos), 
      ContentManager::Instance ().LoadFont (Label::DEFAULT_FONT),
      Label::DEFAULT_SIZE);

    while (true)
    {
      while (width.getLocalBounds ().width < LabelMaxSize)
      {
        if (previousPos + subPos + 1 >= txt.length ())
          break;
        width.setString (txt.substr (previousPos, ++subPos));
      }

      if (previousPos + subPos + 1 >= txt.length ())
        break;
      
      txt.insert (previousPos + subPos - 1, "\n");
      previousPos += subPos;
      subPos = 1;
      width.setString (txt.substr (previousPos, subPos));
    }

    lb->SetDefaultColor (userColor_);
    lb->SetText (txt);
    labels_.Add (lb);
    Refresh ();
  }

  void DialogBoxWidget::SkipText ()
  {
    currentText_++;
    OnTextChanged (*this, EmptyEventArgs ());

    isVisible_ = !IsEmpty ();
  }

  bool DialogBoxWidget::IsEmpty () const
  {
    return (currentText_ < labels_.Count ()) ? false : true;
  }

} // namespace yap
