#include "YAPOG/Graphics/Gui/LayoutV.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Collection/List.hpp"
#include "YAPOG/System/MathHelper.hpp "

namespace yap
{

  LayoutV::LayoutV ()
    : LayoutBox ()
  {
  }

  LayoutV::LayoutV (Padding ext, Padding in, bool isExt)
    : LayoutBox (ext, in, isExt)
  {
  }

  LayoutV::~LayoutV ()
  {
  }

  void LayoutV::GeneratePosition ()
  {
    float totalPad = 0;

    if (globalAlign_ == Align::TOP)
      totalPad = externPad_.top;
    else if (globalAlign_ == Align::CENTER)
      totalPad = (GetSize ().y - externPad_.bottom - externPad_.top) / 2
      + externPad_.top;
    else if (globalAlign_ == Align::BOTTOM)
      totalPad = GetSize ().y - externPad_.bottom;

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
  }

  void LayoutV::HandleDraw (IDrawingContext& context)
  {
  }

  void LayoutV::HandleShow (bool isVisible)
  {
  }

  void LayoutV::HandleMove (const Vector2& offset)
  {
  }

  void LayoutV::HandleScale (const Vector2& factor)
  {
  }

  void LayoutV::HandleUpdate (const Time& dt)
  {
  }

  void LayoutV::HandleChangeColor (const sf::Color& color)
  {
  }
} //namespace yap