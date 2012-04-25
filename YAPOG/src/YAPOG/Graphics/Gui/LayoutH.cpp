#include "YAPOG/Graphics/Gui/LayoutH.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Collection/List.hpp"

namespace yap
{

  LayoutH::LayoutH ()
    : LayoutBox ()
  {
  }

  LayoutH::LayoutH (Padding ext, Padding in)
    : LayoutBox (ext, in)
  {
  }

  LayoutH::~LayoutH ()
  {
  }

  void LayoutH::GeneratePosition ()
  {
    collection::List<Vector2> sizeList;

    float totalPad = externPad_.left;

    float topAlign = externPad_.top;
    float botAlign = GetSize ().y - externPad_.bottom;
    float midAlign = (GetSize ().y - externPad_.bottom - externPad_.top) / 2
      + externPad_.top;

    for (IWidget* child : childen_)
    {
      Vector2 toto = GetPosition ();
      child->SetPosition (Vector2(0,0));

      sizeList.Add (child->GetSize ());
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