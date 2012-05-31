#ifndef YAPOG_PICTURE_BOX_HPP
# define YAPOG_PICTURE_BOX_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/Graphics/Texture.hpp"
# include "YAPOG/Graphics/Gui/BorderWidget.hpp"
# include "YAPOG/System/Event/Event.hpp"

namespace yap
{
  class YAPOG_LIB PictureBox : public BaseWidget
  {
    DISALLOW_COPY(PictureBox);

  public:

    struct EventArgsTexture
    {
      Texture& newContent;
      EventArgsTexture (Texture& content)
        : newContent (content)
      {
      }
    };

    PictureBox ();
    virtual ~PictureBox ();

    virtual bool IsFocusable () const;

    void SetPicture (String file);
    const Texture& GetPicture () const;
    Event<const PictureBox&, const EventArgsTexture&> OnPictureSet;

  private:
    virtual Vector2 HandleGetSize () const;

    virtual void HandleMove (const Vector2& offset);
    virtual void HandleScale (const Vector2& factor);

    virtual void HandleDraw (IDrawingContext& context);

    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    virtual void HandleUpdate (const Time& dt);

    Texture picture_;
  };
} // namespace yap

#endif /* YAPOG_PICTURE_BOX_HPP! */