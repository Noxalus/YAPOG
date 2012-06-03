#include "YAPOG/Graphics/Gui/Menu.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/System/MathHelper.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
#include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
#include "YAPOG/System/Event/Event.hpp"

namespace yap
{

  Menu::Menu (Type type, Padding ext, Padding in, bool fixed)
    : itemz_ ()
    , currentSelec_ (0)
    , layout_ (nullptr)
    , selecBckgrd_ (nullptr)
    , selecBrdr_ (nullptr)
    , selecBrdSize_ (16)
    , isFixed_ (fixed)
    , type_ (type)
    , layoutManager_ (nullptr)
  {
    if (type == Type::HORIZONTAL)
      layout_ = new HorizontalLayout (ext, in, !fixed);
    else if (type == Type::VERTICAL)
      layout_ = new VerticalLayout (ext, in, !fixed);

    layoutManager_ = new PartialLayoutManager (*layout_);
    layoutManager_->SetEnable (fixed);
    BaseWidget::AddChild (*layout_);
  }

  void Menu::SetFixed (bool state)
  {
    isFixed_ = state;
  }

  bool Menu::IsFocusable () const
  {
    return true;
  }

  Menu::~Menu ()
  {
  }

  void Menu::SetSelectedBackground (WidgetBackground& background)
  {
    selecBckgrd_ = &background;
  }

  void Menu::SetSelectedBorder (WidgetBorder& border)
  {
    selecBrdr_ = &border;
  }

  Vector2 Menu::HandleGetSize () const
  {
    if (isFixed_)
      return GetUserSize ();
    return layout_->GetSize () + ((border_ != nullptr) ? border_->GetSize () : Vector2 ());
  }

  void Menu::SetFormItem ()
  {
    MenuItem* curItem = itemz_[currentSelec_];

    if (selecBckgrd_ != nullptr)
      curItem->SetBackground (*selecBckgrd_);
    if (selecBrdr_ != nullptr)
      curItem->SetBorder (*selecBrdr_);
  }

  void Menu::SetUnformItem ()
  {
    MenuItem* curItem = itemz_[currentSelec_];
    curItem->UnsetBackground ();
    curItem->UnsetBorder ();
  }

  void Menu::AddChild (MenuItem& child, LayoutBox::Align align)
  {
    if (selecBrdr_ != nullptr)
      child.SetBorder (*selecBrdr_);
    itemz_.Add (&child);
    layout_->AddChild (child, align);
    layoutManager_->AddItem (&child);

    /*
    if (isFixed_ && type_ == Type::VERTICAL)
    {
    if (GetUserSize () != Vector2 (0, 0) && layout_->GetSize ().y > GetUserSize ().y)
    layout_->RemoveChild (child);
    }
    else if (isFixed_ && type_ == Type::HORIZONTAL)
    if (GetUserSize () != Vector2 (0, 0) && layout_->GetSize ().x > GetUserSize ().x)
    layout_->RemoveChild (child);
    */

    child.UnsetBorder ();

    SetFormItem ();

    if (type_ == Menu::Type::HORIZONTAL)
      layoutManager_->SetSize (layout_->GetSize ().x);
    if (type_== Menu::Type::VERTICAL)
      layoutManager_->SetSize (layout_->GetSize ().y);

  }

  uint Menu::GetCurrentSelect () const
  {
    return currentSelec_;
  }

  void Menu::HandleDraw (IDrawingContext& context)
  {
    layout_->Draw (context);
  }

  bool Menu::HandleOnEvent (const GuiEvent& guiEvent)
  {
    if (guiEvent.type == sf::Event::KeyPressed)
    {
      if (guiEvent.key.code == sf::Keyboard::Up)
      {

        if (currentSelec_ <= 0)
          return true;

        SetUnformItem ();
        currentSelec_--;
        layoutManager_->SetCurrentSel (currentSelec_);
        SetFormItem ();
        itemz_[currentSelec_]->OnSelected (itemz_[currentSelec_], EmptyEventArgs ());
        return true;
      }
      if (guiEvent.key.code == sf::Keyboard::Down)
      {
        if (itemz_.Count () == 0 || currentSelec_ >= itemz_.Count () - 1)
          return true;

        SetUnformItem ();
        currentSelec_++;
        layoutManager_->SetCurrentSel (currentSelec_);
        SetFormItem ();
        itemz_[currentSelec_]->OnSelected (itemz_[currentSelec_], EmptyEventArgs ());
        return true;
      }
      if (guiEvent.key.code == sf::Keyboard::Return)
      {
        itemz_[currentSelec_]->Do ();
        itemz_[currentSelec_]->OnActivated (itemz_[currentSelec_], EmptyEventArgs ());
        return true;
      }
    }
    return false;
  }

  void Menu::HandleShow (bool isVisible)
  {
  }

  void Menu::HandleMove (const Vector2& offset)
  {
  }

  void Menu::HandleScale (const Vector2& factor)
  {
  }

  void Menu::HandleUpdate (const Time& dt)
  {
  }

  void Menu::HandleChangeColor (const sf::Color& color)
  {
  }
} //namespace yap
