#include "YAPOG/Graphics/Gui/Menu.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/System/MathHelper.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/Gui/LayoutH.hpp"
#include "YAPOG/Graphics/Gui/LayoutV.hpp"

namespace yap
{

  Menu::Menu (Type type, Padding ext, Padding in, bool extend)
    : itemz_ ()
    , layout_ (nullptr)
  {
    if (type == Type::HORIZONTAL)
      layout_ = new LayoutH (ext, in, extend);
    else if (type == Type::VERTICAL)
      layout_ = new LayoutV (ext, in, extend);
  }

  Menu::~Menu ()
  {
  }

  Vector2 Menu::HandleGetSize () const
  {
    return layout_->GetSize () + ((border_ != nullptr) ? Vector2 (border_->GetWidth ()
      * 2, border_->GetWidth () * 2) : Vector2 ());
  }

  void Menu::AddChild (MenuItem& child, LayoutBox::Align align)
  {
    BaseWidget::AddChild (child);
    itemz_.Add (&child);
    layout_->AddChild (child, align);
  }

  void Menu::HandleDraw (IDrawingContext& context)
  {
    layout_->Draw (context);
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