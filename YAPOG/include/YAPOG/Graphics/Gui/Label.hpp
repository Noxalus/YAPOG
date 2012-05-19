#ifndef YAPOG_LABEL_HPP
# define YAPOG_LABEL_HPP

# include <SFML/Graphics/Color.hpp>
# include <SFML/Graphics/Text.hpp>

# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/Event/Event.hpp"

namespace yap
{
  class YAPOG_LIB Label : public BaseWidget
  {
    DISALLOW_COPY(Label);

  public:

    struct EventArgsString
    {
      EventArgsString (String content)
      {
        newContent = content;
      }

      String newContent;
    };

    Label ();
    Label (String content);

    virtual ~Label ();
    virtual bool IsFocusable () const;

    void SetText (const String& content);
    String GetText () const;
    Event<const Label&, const EventArgsString&> OnTextChanged;
    float GetCharWidth () const;
    uint GetCharHeight () const;
    Vector2 CharPos (uint pos) const;
    uint Length () const;
    virtual void SetBackground (WidgetBackground& background);

  private:

    virtual Vector2 HandleGetSize () const;

    virtual void HandleMove (const Vector2& offset);
    virtual void HandleScale (const Vector2& factor);

    virtual void HandleDraw (IDrawingContext& context);

    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    virtual void HandleUpdate (const Time& dt);


    String textContent_;
    sf::Text drawableText_;
    bool isPosSet_;
  };
} // namespace yap

#endif /* YAPOG_LABEL_HPP! */
