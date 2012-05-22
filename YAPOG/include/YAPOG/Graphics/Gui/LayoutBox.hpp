#ifndef YAPOG_LAYOUT_BOX_HPP
# define YAPOG_LAYOUT_BOX_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/Graphics/Gui/Padding.hpp"

namespace yap
{

  class YAPOG_LIB LayoutBox : public BaseWidget
  {
    DISALLOW_COPY(LayoutBox);

  public:

    enum class Align
    {
      LEFT,
      CENTER,
      RIGHT,
      TOP,
      BOTTOM
    };

    LayoutBox ();
    LayoutBox (Padding ext, Padding in, bool isExt);
    virtual ~LayoutBox ();
    virtual bool IsFocusable () const;

    virtual void AddChild (IWidget& child, Align align = Align::CENTER);
    void RemoveChild (IWidget& child);
    virtual uint GetWidthItem () = 0;
    void SetExtensible (bool isExt);
    bool GetExtensible ();
    void SetAlign (Align global);
    Align GetAlign ();
    void Clear ();


  protected:
    virtual void GeneratePosition () = 0;
    virtual void Refresh ();
    virtual Vector2 HandleGetSize () const;
    virtual void HandleMove (const Vector2& offset);
    virtual void HandleScale (const Vector2& factor);

    virtual void HandleDraw (IDrawingContext& context);

    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    virtual void HandleUpdate (const Time& dt);

    float MaxSize (char coord);

    virtual bool HandleOnPriorityEvent (const GuiEvent& guiEvent);
   //virtual bool HandleOnEvent (const GuiEvent& guiEvent);

    collection::Map<IWidget*, Align> items_;
    collection::Array<IWidget*> focusables_;
    Padding innerPad_;
    Padding externPad_;
    Align globalAlign_;

    Vector2 realSize_;
    uint focusedChild_;

  };
} // namespace yap

#endif /* YAPOG_LAYOUT_BOX_HPP! */
