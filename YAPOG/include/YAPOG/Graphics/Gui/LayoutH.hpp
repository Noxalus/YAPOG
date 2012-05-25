#ifndef YAPOG_LAYOUT_H_HPP
# define YAPOG_LAYOUT_H_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/LayoutBox.hpp"

namespace yap
{
  class YAPOG_LIB LayoutH : public LayoutBox
  {
    DISALLOW_COPY(LayoutH);

  public:

    LayoutH ();
    LayoutH (Padding ext, Padding in, bool isExt);
    virtual ~LayoutH ();
    virtual void GeneratePosition ();
    virtual uint GetWidthItem ();
    

  private:

    virtual void HandleMove (const Vector2& offset);
    virtual void HandleScale (const Vector2& factor);

    virtual void HandleDraw (IDrawingContext& context);

    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    virtual void HandleUpdate (const Time& dt);
  };
} // namespace yap

#endif /* YAPOG_LAYOUT_H! */