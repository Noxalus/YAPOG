#include "YAPOG/Graphics/Gui/LayoutH.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Collection/List.hpp"
#include "YAPOG/System/MathHelper.hpp "

namespace yap
{

  LayoutH::LayoutH ()
    : LayoutBox ()
  {
  }

  LayoutH::LayoutH (Padding ext, Padding in, bool isExt)
    : LayoutBox (ext, in, isExt)
  {
  }

  LayoutH::~LayoutH ()
  {
  }

  void LayoutH::GeneratePosition ()
  {
    float totalPad = 0;

    if (globalAlign_ == Align::LEFT)
      totalPad = externPad_.left;
    else if (globalAlign_ == Align::CENTER)
      totalPad = (GetSize ().x - externPad_.left- externPad_.right) / 2
      + externPad_.left;
    else if (globalAlign_ == Align::RIGHT)
      totalPad = GetSize ().x - externPad_.right;

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
      , spatialInfo_.GetSize ().x);
    realSize_.y = MaxSize ('y');
  }

  void LayoutH::HandleDraw (IDrawingContext& context)
  {
  }

  void LayoutH::HandleShow (bool isVisible)
  {
  }

  void LayoutH::HandleMove (const Vector2& offset)
  {
  }

  void LayoutH::HandleScale (const Vector2& factor)
  {
  }

  void LayoutH::HandleUpdate (const Time& dt)
  {
  }

  void LayoutH::HandleChangeColor (const sf::Color& color)
  {
  }
} //namespace yap