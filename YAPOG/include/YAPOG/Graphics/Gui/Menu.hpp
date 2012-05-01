#ifndef YAPOG_MENU_HPP
# define YAPOG_MENU_HPP

# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/Graphics/Gui/MenuItem.hpp"
# include "YAPOG/Graphics/Gui/LayoutBox.hpp"
# include "YAPOG/Graphics/Gui/Padding.hpp"

namespace yap
{
  class YAPOG_LIB Menu : public BaseWidget
  {
    DISALLOW_COPY(Menu);

  public:

    enum class Type
    {
      VERTICAL,
      HORIZONTAL
    };

    Menu (Type type, Padding ext, Padding in, bool extend);
    void AddChild (MenuItem& child, LayoutBox::Align align
      = LayoutBox::Align::CENTER);
    virtual ~Menu ();

  private:
    virtual Vector2 HandleGetSize () const;
    virtual void HandleMove (const Vector2& offset);
    virtual void HandleScale (const Vector2& factor);

    virtual void HandleDraw (IDrawingContext& context);

    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    virtual void HandleUpdate (const Time& dt);
    bool HandleOnEvent (const GuiEvent& guiEvent);
    void SetFormItem ();

    collection::Array<MenuItem*> itemz_;
    int currentSelec_;
    LayoutBox* layout_;
  };
} // namespace yap

#endif /* YAPOG_MENU_HPP! */