#ifndef YAPOG_MENU_ITEM_HPP
# define YAPOG_MENU_ITEM_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"

namespace yap
{
  class YAPOG_LIB MenuItem : public BaseWidget
  {
    DISALLOW_COPY(MenuItem);

  public:
    MenuItem ();
    virtual ~MenuItem ();
    virtual void Do ();
    virtual bool IsFocusable () const;

  private:
    virtual Vector2 HandleGetSize () const;
    virtual void HandleMove (const Vector2& offset);
    virtual void HandleScale (const Vector2& factor);

    virtual void HandleDraw (IDrawingContext& context);

    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    virtual void HandleUpdate (const Time& dt);

  };
} // namespace yap

#endif /* YAPOG_MENU_ITEM_HPP! */