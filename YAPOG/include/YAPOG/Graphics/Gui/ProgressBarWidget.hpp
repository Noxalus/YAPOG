#ifndef YAPOG_PROGRESSBARWIDGET_HPP
# define YAPOG_PROGRESSBARWIDGET_HPP

# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/Graphics/Texture.hpp"
# include "YAPOG/Graphics/Gui/TextureManager.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Collection/Array.hpp"

namespace yap
{
  class YAPOG_LIB ProgressBarWidget : public BaseWidget
  {
    DISALLOW_COPY(ProgressBarWidget);

  public:

    ProgressBarWidget ();

    virtual ~ProgressBarWidget ();

    void SetScalable (bool state);
    uint GetWidth () const;

  private:
    virtual Vector2 HandleGetSize () const;
    virtual void HandleMove (const Vector2& offset);
    virtual void HandleScale (const Vector2& factor);

    virtual void HandleDraw (IDrawingContext& context);

    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    virtual void HandleUpdate (const Time& dt);

    uint width_;

    bool isScalable_;

  };
} // namespace yap

#endif /* YAPOG_PROGRESSBARWIDGET_HPP! */