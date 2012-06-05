#include <SFML/Graphics/Text.hpp>
#include "YAPOG/Graphics/Gui/Label.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/Gui/GuiEvent.hpp"
#include "YAPOG/Graphics/Gui/MultiLabelWidget.hpp"
#include "YAPOG/Graphics/Gui/PartialLayoutManager.hpp"
#include "YAPOG/Graphics/Gui/VerticalLayout.hpp"

namespace yap
{
  MultiLabelWidget::MultiLabelWidget (Padding ext, Padding in, bool Extendable)
    : labels_ ()
    , currentText_ (0)
    , layout_ (nullptr)
    , layoutManager_ (nullptr)
    , showText_ (true)
  {
    layout_ = new VerticalLayout (ext, in, Extendable);
    layoutManager_ = new PartialLayoutManager (*layout_);
    BaseWidget::AddChild (*layout_);
  }

  MultiLabelWidget::~MultiLabelWidget ()
  {
  }

  void MultiLabelWidget::SetShowText (bool state)
  {
    showText_ = state;
  }

  bool MultiLabelWidget::IsFocusable () const
  {
    return true;
  }

  void MultiLabelWidget::Refresh ()
  {
    layout_->Refresh ();
    BaseWidget::Refresh ();
  }

  Vector2 MultiLabelWidget::HandleGetSize () const
  {
    return GetUserSize ()
      + ((border_ != nullptr) ? border_->GetSize () : Vector2 ());
  }

  void MultiLabelWidget::HandleDraw (IDrawingContext& context)
  {
  }

  void MultiLabelWidget::HandleShow (bool isVisible)
  {    
  }

  void MultiLabelWidget::HandleMove (const Vector2& offset)
  {
  }

  void MultiLabelWidget::HandleScale (const Vector2& factor)
  {
  }

  void MultiLabelWidget::HandleUpdate (const Time& dt)
  {
  }

  void MultiLabelWidget::HandleChangeColor (const sf::Color& color)
  {
  }

  String MultiLabelWidget::GetContent () const
  {
    return content_;
  }

  bool MultiLabelWidget::HandleOnEvent (const GuiEvent& guiEvent)
  {
    if (!isVisible_ || !showText_)
      return false;
    if (guiEvent.type == sf::Event::KeyPressed)
    {
      if (guiEvent.key.code == sf::Keyboard::Return)
      {       
        return true;
      }
    }
    return false;
  }

  void MultiLabelWidget::AddText (const String& contentArg)
  {
    if (contentArg.empty())
      return;

    String txt = contentArg;
    Label* lb = new Label ();

    uint LabelMaxSize = GetUserSize ().x - padding_.left - padding_.right;
    uint charNumb = (LabelMaxSize / lb->GetCharWidth ());

    uint previousPos = 0;
    uint subPos = charNumb;
    sf::Text width (txt.substr (0, subPos));

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

    lb->SetText (txt);
    labels_.Add (lb);
    Refresh ();
  }
} // namespace yap
