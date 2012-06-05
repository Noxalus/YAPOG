#include "YAPOG/Graphics/Gui/GridMenu.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/System/MathHelper.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
#include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
#include "YAPOG/System/Event/Event.hpp"

namespace yap
{

  GridMenu::GridMenu (Vector2& size, Padding ext, Padding in, bool extend)
    : itemz_ (size.x, size.y, nullptr)
    , currentSelec_ ()
    , layoutV_ (new VerticalLayout (ext, in, extend))
    , layoutHs_ (size.y, nullptr)
    , selecBckgrd_ (nullptr)
    , selecBrdr_ (nullptr)
    , selecBrdSize_ (16)
    , isFixed_ (!extend)
    , currentLine_ (0)
  {
    for (HorizontalLayout* layout : layoutHs_)
    {
      layout = new HorizontalLayout (ext, in, extend);
      layoutV_->AddChild (*layout);
    }

    BaseWidget::AddChild (*layoutV_);
  }  

  bool GridMenu::IsFocusable () const
  {
    return true;
  }

  GridMenu::~GridMenu ()
  {
  }

  void GridMenu::SetSelectedBackground (WidgetBackground& background)
  {
    selecBckgrd_ = &background;
  }

  void GridMenu::SetSelectedBorder (WidgetBorder& border)
  {
    selecBrdr_ = &border;
  }

  Vector2 GridMenu::HandleGetSize () const
  {
    if (isFixed_)
      return GetUserSize ();
    return layoutV_->GetSize () + ((border_ != nullptr) ? border_->GetSize () : Vector2 ());
  }

  void GridMenu::SetFormItem ()
  {
    MenuItem* curItem = itemz_(currentSelec_.x, currentSelec_.y);

    if (selecBckgrd_ != nullptr)
      curItem->SetBackground (*selecBckgrd_);
    if (selecBrdr_ != nullptr)
      curItem->SetBorder (*selecBrdr_);
  }

  void GridMenu::SetUnformItem ()
  {
    MenuItem* curItem = itemz_(currentSelec_.x, currentSelec_.y);

    curItem->UnsetBackground ();
    curItem->UnsetBorder ();
  }

  void GridMenu::AddChild (MenuItem& child, LayoutBox::Align align)
  {
    if (selecBrdr_ != nullptr)
      child.SetBorder (*selecBrdr_);
    if (currentLine_ >= layoutHs_.Count ())
      return;
    if (layoutHs_[currentLine_]->Count () >= size_.x)
      currentLine_++;
    if (currentLine_ >= layoutHs_.Count ())
      return;
    layoutHs_[currentLine_]->AddChild (child, align);
    itemz_(layoutHs_[currentLine_]->Count () -1, currentLine_) = &child;
    currentLine_++;

    child.UnsetBorder ();

    SetFormItem ();
  }

  Vector2 GridMenu::GetCurrentSelect () const
  {
    return currentSelec_;
  }

  void GridMenu::HandleDraw (IDrawingContext& context)
  {
    //layout_->Draw (context);
  }

  bool GridMenu::HandleOnEvent (const GuiEvent& guiEvent)
  {
    /*if (guiEvent.type == sf::Event::KeyPressed)
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
    return false;*/
    return false;
  }

  void GridMenu::HandleShow (bool isVisible)
  {
  }

  void GridMenu::HandleMove (const Vector2& offset)
  {
  }

  void GridMenu::HandleScale (const Vector2& factor)
  {
  }

  void GridMenu::HandleUpdate (const Time& dt)
  {
  }

  void GridMenu::HandleChangeColor (const sf::Color& color)
  {
  }
} //namespace yap
