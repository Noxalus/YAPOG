#ifndef YAPOG_WIDGET_BACKGROUND_HPP
# define YAPOG_WIDGET_BACKGROUND_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/Graphics/Texture.hpp"

namespace yap
{
  class YAPOG_LIB WidgetBackground : public BaseWidget
  {
    DISALLOW_COPY(WidgetBackground);

  public:

    struct EventArgsTexture
    {
      Texture& newContent;
      EventArgsTexture (Texture& content)
        : newContent (content)
      {
      }
    };

    WidgetBackground ();
    virtual ~WidgetBackground ();

    void SetBackground (String file);
    const Texture& GetBackground () const;
    Event<const WidgetBackground&, const EventArgsTexture&> OnBackgroundSet;

  private:
    virtual void HandleMove (const Vector2& offset);
    virtual void HandleScale (const Vector2& factor);

    virtual void HandleDraw (IDrawingContext& context);

    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    virtual void HandleUpdate (const Time& dt);

    Texture background_;

  };
} // namespace yap

#endif /* YAPOG_WIDGET_BACKGROUND_HPP! */