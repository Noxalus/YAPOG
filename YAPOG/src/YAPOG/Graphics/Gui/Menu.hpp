#ifndef YAPOG_MENU_HPP
# define YAPOG_MENU_HPP

# include "YAPOG/Graphics/Gui/BaseWidget.hpp"

namespace yap
{
  class YAPOG_LIB Menu : public BaseWidget
  {
    DISALLOW_COPY(Menu);

  public:
    Menu ();
    virtual ~Menu ();

  private:
    virtual void HandleMove (const Vector2& offset);
    virtual void HandleScale (const Vector2& factor);

    virtual void HandleDraw (IDrawingContext& context);

    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    virtual bool HandleOnEvent (const GuiEvent& guiEvent);
    virtual bool HandleOnPriorityEvent (const GuiEvent& guiEvent);

    virtual void HandleUpdate (const Time& dt);
  private:

  };
} // namespace yap

#endif /* YAPOG_MENU_HPP! */