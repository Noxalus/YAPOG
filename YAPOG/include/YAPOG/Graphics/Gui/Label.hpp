#ifndef YAPOG_LABEL_HPP
# define YAPOG_LABEL_HPP

# include <SFML\Graphics\Text.hpp>

# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG\System\String.hpp"
# include "YAPOG/System/Event/Event.hpp"

namespace yap
{
  class sf::Text;
  class YAPOG_LIB Label : public BaseWidget
  {
    DISALLOW_COPY(Label);

  public:

    struct EventArgs
    {
      EventArgs (String content)
      {
        newContent = content;
      }

      String newContent;
    };

    Label ();
    virtual ~Label ();

    void SetText (String& content);
    String GetText () const;
    Event<const Label&, const EventArgs&> OnTextChanged;

  private:
    virtual void HandleMove (const Vector2& offset);
    virtual void HandleScale (const Vector2& factor);

    virtual void HandleDraw (IDrawingContext& context);

    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    virtual bool HandleOnEvent (const GuiEvent& guiEvent);
    virtual bool HandleOnPriorityEvent (const GuiEvent& guiEvent);

    virtual void HandleUpdate (const Time& dt);


    String textContent_;
    sf::Text drawableText_;
  };
} // namespace yap

#endif /* YAPOG_LABEL_HPP! */