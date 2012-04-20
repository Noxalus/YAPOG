#ifndef YAPOG_PICTURE_BOX_HPP
# define YAPOG_PICTURE_BOX_HPP

# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/Graphics/Texture.hpp"
# include "YAPOG\Graphics\Gui\"

namespace yap
{
  class YAPOG_LIB PictureBox : public BaseWidget
  {
    DISALLOW_COPY(PictureBox);

  public:
    PictureBox ();
    virtual ~PictureBox ();

  private:
    virtual void HandleMove (const Vector2& offset);
    virtual void HandleScale (const Vector2& factor);

    virtual void HandleDraw (IDrawingContext& context);

    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    virtual bool HandleOnEvent (const GuiEvent& guiEvent);
    virtual bool HandleOnPriorityEvent (const GuiEvent& guiEvent);

    virtual void HandleUpdate (const Time& dt);

    Texture picture_;
    WidgetBorder border_;
  };
} // namespace yap

#endif /* YAPOG_PICTURE_BOX_HPP! */