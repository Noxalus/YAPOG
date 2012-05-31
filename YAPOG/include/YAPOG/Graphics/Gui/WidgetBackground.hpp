#ifndef YAPOG_WIDGET_BACKGROUND_HPP
# define YAPOG_WIDGET_BACKGROUND_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/Graphics/Texture.hpp"
# include "YAPOG/Graphics/Gui/TextureManager.hpp"
# include "YAPOG/System/IntTypes.hpp"

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
    WidgetBackground (String file, bool resize);
    virtual ~WidgetBackground ();

    virtual bool IsFocusable () const;
          void SetBackground (String file, uint width, uint height, bool resize);
    void SetBackground (Vector2 size);
    const Texture& GetBackground () const;
    Event<const WidgetBackground&, const EventArgsTexture&> OnBackgroundSet;
    void SetFixed (bool state);
    bool GetFixed () const;

  private:
    virtual Vector2 HandleGetSize () const;

    virtual void HandleMove (const Vector2& offset);
    virtual void HandleScale (const Vector2& factor);

    virtual void HandleDraw (IDrawingContext& context);

    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    virtual void HandleUpdate (const Time& dt);

    Texture background_;
    TextureManager* tm_;
    bool resize_;
    bool isInit;
    bool fixed_;

  };
} // namespace yap

#endif /* YAPOG_WIDGET_BACKGROUND_HPP! */