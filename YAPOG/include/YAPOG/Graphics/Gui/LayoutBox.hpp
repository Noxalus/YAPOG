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
    LayoutBox (Padding ext, Padding in);
    virtual ~LayoutBox ();

    virtual void AddChild (IWidget& child, Align align = Align::CENTER);
    virtual void GeneratePosition () = 0;

  protected:

    virtual void HandleMove (const Vector2& offset);
    virtual void HandleScale (const Vector2& factor);

    virtual void HandleDraw (IDrawingContext& context);

    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    virtual void HandleUpdate (const Time& dt);

    collection::Map<IWidget*, Align> items_;
    Padding externPad_;
    Padding innerPad_;

  };
} // namespace yap

#endif /* YAPOG_LAYOUT_BOX_HPP! */