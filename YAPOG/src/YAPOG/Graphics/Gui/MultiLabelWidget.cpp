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
    , currentSelec_ (0)
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
    if (guiEvent.type == sf::Event::KeyPressed)
    {
      if (guiEvent.key.code == sf::Keyboard::PageUp)
      {
        if (currentSelec_ <= 0)
          return true;

        currentSelec_--;
        layoutManager_->SetCurrentSel (currentSelec_);        
        return true;
      }
      if (guiEvent.key.code == sf::Keyboard::PageDown)
      {
        if (labels_.Count () == 0 || currentSelec_ >= labels_.Count () - 1)
          return true;

        currentSelec_++;
        layoutManager_->SetCurrentSel (currentSelec_);
        return true;
      }     
    }
    return false;
  }
  
  void MultiLabelWidget::AddText (const String& contentArg, uint charSize, sf::Color color, LayoutBox::Align align)
  {
    if (contentArg.empty())
      return;

    String txt = contentArg;
    Label charWidth ("Test");
    charWidth.SetTextSize (charSize);

    uint LabelMaxSize = GetUserSize ().x - padding_.left - padding_.right;
    uint charNumb = (LabelMaxSize / charWidth.GetCharWidth ());

    uint previousPos = 0;
    uint subPos = charNumb;
    sf::Text width (txt.substr (0, subPos));

    collection::Array<uint> pos;
    pos.Add (0);
    while (1)
    {
      while (width.getLocalBounds ().width < LabelMaxSize)
      {
        if (previousPos + subPos + 1 >= txt.length ())
          break;
        width.setString (txt.substr (previousPos, ++subPos));
      }
      if (previousPos + subPos + 1 >= txt.length ())
        break;
      pos.Add (previousPos + subPos - 1);
      txt.insert (previousPos + subPos - 1, "\n");
      previousPos += subPos;
      subPos = 1;
      width.setString (txt.substr (previousPos, subPos));
    }

    for (int i = 0; i < pos.Count (); ++i)
    {
      Label* lb = new Label ();
      lb->ChangeColor (color);
      

      if (i + 1 < pos.Count ())
        lb->SetText (contentArg.substr (pos[i], pos[i + 1] - pos[i]));
      else
        lb->SetText (contentArg.substr (pos[i]));      
      labels_.Add (lb);
      layout_->AddChild (*lb, align);
      layoutManager_->AddItem (lb);
      layoutManager_->SetSize (layout_->GetSize ().y - charWidth.GetCharHeight ());
    }    
    Refresh ();
  }

  void MultiLabelWidget::Clear ()
  {
    content_ = "";
    labels_.Clear ();
    currentSelec_ = 0;
    layout_->Clear ();
    currentText_ = 0;
  }
} // namespace yap
