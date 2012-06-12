#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Collection/List.hpp"
#include "YAPOG/System/MathHelper.hpp"

namespace yap
{

  HorizontalLayout::HorizontalLayout ()
    : LayoutBox ()
  {
  }

  HorizontalLayout::HorizontalLayout (Padding ext, Padding in, bool isExt)
    : LayoutBox (ext, in, isExt)
  {
  }

  HorizontalLayout::~HorizontalLayout ()
  {
  }

  float HorizontalLayout::GetWidthItem ()
  {
    for (auto itMap = items_.begin (); itMap != items_.end (); itMap++)
      return (*itMap).first->GetSize ().x;
    return 0;
  }

  void HorizontalLayout::GeneratePosition ()
  {
    float totalPad = 0;


    if (globalAlign_ == Align::RIGHT)
      totalPad = GetSize ().x - externPad_.right;
    else if (globalAlign_ == Align::CENTER)
      totalPad = (GetSize ().x - externPad_.left- externPad_.right) / 2
      + externPad_.left;
    else
      totalPad = externPad_.left;


    float topAlign = externPad_.top;
    float botAlign = GetSize ().y - externPad_.bottom;
    float midAlign = (GetSize ().y - externPad_.bottom - externPad_.top) / 2
      + externPad_.top;

    for (IWidget* child : childen_)
    {
      child->SetPosition (GetPosition ());

      float posY = 0;
      if (items_[child] == Align::TOP)
        posY = topAlign;
      else if (items_[child] == Align::BOTTOM)
        posY = botAlign - child->GetSize ().y;
      else
        posY = midAlign - (child->GetSize ().y / 2);

      Vector2 currentPos (totalPad, posY);
      child->Move (currentPos);

      totalPad += child->GetSize ().x + innerPad_.right;
    }
    realSize_.x = MathHelper::Max (totalPad - innerPad_.right
      + externPad_.right
      , GetUserSize ().x /*spatialInfo_.GetSize ().x*/);
    realSize_.y = MaxSize ('y');
    BaseWidget::Refresh ();
  }

  void HorizontalLayout::HandleDraw (IDrawingContext& context)
  {
  }

  void HorizontalLayout::HandleShow (bool isVisible)
  {
  }

  void HorizontalLayout::HandleMove (const Vector2& offset)
  {
  }

  void HorizontalLayout::HandleScale (const Vector2& factor)
  {
  }

  void HorizontalLayout::HandleUpdate (const Time& dt)
  {
  }

  void HorizontalLayout::HandleChangeColor (const sf::Color& color)
  {
  }
} //namespace yap
