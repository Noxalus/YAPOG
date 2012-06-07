#ifndef YAPOG_GRIDMENU_HPP
# define YAPOG_GRIDMENU_HPP

# include "YAPOG/Collection/Matrix.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/Graphics/Gui/MenuItem.hpp"
# include "YAPOG/Graphics/Gui/LayoutBox.hpp"
# include "YAPOG/Graphics/Gui/Padding.hpp"
# include "YAPOG/Graphics/Gui/PartialLayoutManager.hpp"

namespace yap
{
  class VerticalLayout;
  class HorizontalLayout;

  class YAPOG_LIB GridMenu : public BaseWidget
  {
    DISALLOW_COPY(GridMenu);

  public:
    GridMenu (const Vector2& size, Padding ext, Padding in, bool extend);
    void AddChild (MenuItem& child, LayoutBox::Align align
      = LayoutBox::Align::CENTER);
    virtual ~GridMenu ();

    void SetSelectedBackground (WidgetBackground& background);
    void SetSelectedBorder (WidgetBorder& border);
    virtual bool IsFocusable () const;
    Vector2 GetCurrentSelect () const;

  protected:
    virtual Vector2 HandleGetSize () const;
    virtual void HandleMove (const Vector2& offset);
    virtual void HandleScale (const Vector2& factor);

    virtual void HandleDraw (IDrawingContext& context);

    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    virtual void HandleUpdate (const Time& dt);
    bool HandleOnEvent (const GuiEvent& guiEvent);

  private:
    void SetFormItem ();
    void SetUnformItem ();

    collection::Matrix<MenuItem*> itemz_;
    Vector2 currentSelec_;
    VerticalLayout* layoutV_;
    collection::Array<HorizontalLayout*> layoutHs_;

    WidgetBackground* selecBckgrd_;
    WidgetBorder* selecBrdr_;
    uint selecBrdSize_;
    Vector2 size_;
    bool isFixed_;
    uint currentLine_;
    collection::Array<uint> itemCount_;

  };
} // namespace yap

#endif /* YAPOG_GRIDMENU_HPP! */
