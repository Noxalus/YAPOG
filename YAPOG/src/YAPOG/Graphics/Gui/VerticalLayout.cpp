#include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Collection/List.hpp"
#include "YAPOG/System/MathHelper.hpp"

namespace yap
{

  VerticalLayout::VerticalLayout ()
    : LayoutBox ()
  {
  }

  VerticalLayout::VerticalLayout (Padding ext, Padding in, bool isExt)
    : LayoutBox (ext, in, isExt)
  {
  }

  float VerticalLayout::GetWidthItem ()
  {
    for (auto itMap = items_.begin (); itMap != items_.end (); itMap++)
      return (*itMap).first->GetSize ().y;
    return 0;
  }

  VerticalLayout::~VerticalLayout ()
  {
  }

  void VerticalLayout::GeneratePosition ()
  {
    float totalPad = 0;


    if (globalAlign_ == Align::BOTTOM)
      totalPad = GetSize ().y - externPad_.bottom;
    else if (globalAlign_ == Align::CENTER)
      totalPad = (GetSize ().y - externPad_.bottom - externPad_.top) / 2
      + externPad_.top;
    else
      totalPad = externPad_.top;


    float leftAlign = externPad_.left;
    float rightAlign = GetSize ().x - externPad_.right;
    float midAlign = (GetSize ().x - externPad_.right - externPad_.left) / 2
      + externPad_.left;

    for (IWidget* child : childen_)
    {
      child->SetPosition (GetPosition ());

      float posX = 0;
      if (items_[child] == Align::LEFT)
        posX = leftAlign;
      else if (items_[child] == Align::RIGHT)
        posX = rightAlign - child->GetSize ().x;
      else
        posX = midAlign - (child->GetSize ().x / 2);

      Vector2 currentPos (posX, totalPad);
      child->Move (currentPos);

      totalPad += child->GetSize ().y + innerPad_.bottom;
    }
    realSize_.y = MathHelper::Max (totalPad - innerPad_.bottom
      + externPad_.bottom
      , spatialInfo_.GetSize ().y);
    realSize_.x = MaxSize ('x');
    BaseWidget::Refresh ();
  }

  void VerticalLayout::HandleDraw (IDrawingContext& context)
  {
  }

  void VerticalLayout::HandleShow (bool isVisible)
  {
  }

  void VerticalLayout::HandleMove (const Vector2& offset)
  {
  }

  void VerticalLayout::HandleScale (const Vector2& factor)
  {
  }

  void VerticalLayout::HandleUpdate (const Time& dt)
  {
  }

  void VerticalLayout::HandleChangeColor (const sf::Color& color)
  {
  }
} //namespace yap
