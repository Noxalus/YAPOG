#include "YAPOG/Graphics/Gui/Menu.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/System/MathHelper.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/LayoutH.hpp"
#include "YAPOG/Graphics/Gui/LayoutV.hpp"


namespace yap
{

  Menu::Menu (Type type, Padding ext, Padding in, bool extend)
    : itemz_ ()
    , currentSelec_ (0)
    , layout_ (nullptr)
    , selecBrdr_ (nullptr)
    , selecBckgrd_ (new WidgetBackground ("bckgrd.png", true))
    , selecBrdSize_ (16)
  {
    Texture* t = new Texture ();
    t->LoadFromFile ("T.png");
    Texture* tr = new Texture ();
    tr->LoadFromFile ("TR.png");
    Texture* r = new Texture (); 
    r->LoadFromFile ("R.png");
    Texture* br = new Texture ();
    br->LoadFromFile  ("BR.png");
    Texture* b = new Texture (); 
    b->LoadFromFile ("B.png");
    Texture* bl = new Texture (); 
    bl->LoadFromFile ("BL.png");
    Texture* l = new Texture ();
    l->LoadFromFile ("L.png");
    Texture* tl = new Texture (); 
    tl->LoadFromFile ("TL.png");

    selecBrdr_ = new WidgetBorder (*t, *tr, *r, *br, *b, *bl, *l, *tl, true);
    if (type == Type::HORIZONTAL)
      layout_ = new LayoutH (ext, in, extend);
    else if (type == Type::VERTICAL)
      layout_ = new LayoutV (ext, in, extend);

    BaseWidget::AddChild (*layout_);
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
    return layout_->GetSize () + ((border_ != nullptr) ? Vector2 (border_->GetWidth ()
      * 2, border_->GetWidth () * 2) : Vector2 ());
  }

  void Menu::SetFormItem ()
  {
    MenuItem* curItem = itemz_[currentSelec_];

    curItem->SetBackground (*selecBckgrd_);
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
    itemz_.Add (&child);
    layout_->AddChild (child, align);

    if (itemz_.Count () == 1)
      SetFormItem ();
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
        SetFormItem ();
        return true;
      }
      if (guiEvent.key.code == sf::Keyboard::Down)
      {
        if (currentSelec_ >= itemz_.Count () - 1)
          return true;

        SetUnformItem ();
        currentSelec_++;
        SetFormItem ();
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