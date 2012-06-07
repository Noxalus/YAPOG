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
    , size_ (size)
    , isFixed_ (!extend)
    , currentLine_ (0)
    , itemCount_ (size.y, 0)
  {
    for (int i = 0; i < size.y; ++i)
    {
      layoutHs_[i] = new HorizontalLayout (ext, in, extend);
      layoutV_->AddChild (*layoutHs_[i]);
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
    if (currentLine_ >= size_.y)
      return;
    if (itemCount_[currentLine_] >= size_.x)
      currentLine_++;
    if (currentLine_ >= size_.y)
      return;

    layoutHs_[currentLine_]->AddChild (child, align);
    itemz_(itemCount_[currentLine_], currentLine_) = &child;
    itemCount_[currentLine_]++;

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
    if (guiEvent.type == sf::Event::KeyPressed)
    {
      if (guiEvent.key.code == sf::Keyboard::Up)
      {

        if (currentSelec_.y <= 0)
        {
          uint line = size_.y - 1;
          while (line != 0)
          {
            if (itemCount_[line] != 0)
              break;
            line--;
          }
          SetUnformItem ();
          currentSelec_.y = line;
        }
        else
        {
          SetUnformItem ();
          currentSelec_.y--;
        }
        SetFormItem ();
        itemz_(currentSelec_.x, currentSelec_.y)
          ->OnSelected (itemz_(currentSelec_.x, currentSelec_.y),
          EmptyEventArgs ());
        return true;
      }
      if (guiEvent.key.code == sf::Keyboard::Down)
      {
        //replace itemcount
        if (currentSelec_.y >= itemCount_.Count () - 1)
        {
          SetUnformItem ();
          currentSelec_.y = 0;
        }
        else
        {
          SetUnformItem ();
          currentSelec_.y++;
        }
        SetFormItem ();
        itemz_(currentSelec_.x, currentSelec_.y)
          ->OnSelected (itemz_(currentSelec_.x, currentSelec_.y),
          EmptyEventArgs ());
        return true;
      }
      if (guiEvent.key.code == sf::Keyboard::Left)
      {
        if (currentSelec_.x == 0 && currentSelec_.y == 0)
        { 
          uint line = size_.y - 1;
          while (line != 0)
          {
            if (itemCount_[line] != 0)
              break;
            line--;
          }
          SetUnformItem ();
          currentSelec_.y = line;
          currentSelec_.x = itemCount_[line] - 1;          
        }
        else if (currentSelec_.x == 0)
        {
          SetUnformItem ();
          currentSelec_.y--;
          currentSelec_.x = itemCount_[currentSelec_.y] - 1;
        }
        else
        {
          SetUnformItem ();
          currentSelec_.x--;
        }
        SetFormItem ();
        itemz_(currentSelec_.x, currentSelec_.y)
          ->OnSelected (itemz_(currentSelec_.x, currentSelec_.y),
          EmptyEventArgs ());
        return true;
      }
      if (guiEvent.key.code == sf::Keyboard::Right)
      {
        if (currentSelec_.x == itemCount_[currentSelec_.y] - 1
          && currentSelec_.y == itemCount_.Count () - 1)
        {
          SetUnformItem ();
          currentSelec_.x = 0;
          currentSelec_.y = 0;
        }
        else if (currentSelec_.x == itemCount_[currentSelec_.y] - 1)
        {
          SetUnformItem ();
          currentSelec_.y++;
          currentSelec_.x = 0;
        }
        else
        {
          SetUnformItem ();
          currentSelec_.x++;
        }
        SetFormItem ();
        itemz_(currentSelec_.x, currentSelec_.y)
          ->OnSelected (itemz_(currentSelec_.x, currentSelec_.y),
          EmptyEventArgs ());
        return true;
      }
      if (guiEvent.key.code == sf::Keyboard::Return)
      {        
        itemz_(currentSelec_.x, currentSelec_.y)
          ->OnSelected (itemz_(currentSelec_.x, currentSelec_.y),
          EmptyEventArgs ());
        return true;
      }
    }
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
