#ifndef YAPOG_MULTILABELWIDGET_HPP
# define YAPOG_MULTILABELWIDGET_HPP

# include "YAPOG/Graphics/Texture.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/Graphics/Gui/Label.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/System/Time/UpdateableTimer.hpp"
# include "YAPOG/Graphics/Gui/LayoutBox.hpp"

namespace yap
{
  class PartialLayoutManager;
  class VerticalLayout;
  class YAPOG_LIB MultiLabelWidget : public BaseWidget
  {
    DISALLOW_COPY(MultiLabelWidget);

  public:

    MultiLabelWidget (Padding ext, Padding in, bool Extendable);    
    virtual ~MultiLabelWidget ();

    virtual String GetContent () const;   
    virtual void AddText (const String& contentArg, uint charSize, sf::Color color = sf::Color::Black, LayoutBox::Align align = LayoutBox::Align::LEFT);
    virtual bool IsFocusable () const;
    void SetShowText (bool state);
    void Clear ();
  protected:
    void Refresh ();
    virtual bool HandleOnEvent (const GuiEvent& guiEvent);
    virtual Vector2 HandleGetSize () const;
    virtual void HandleMove (const Vector2& offset);
    virtual void HandleScale (const Vector2& factor);

    virtual void HandleDraw (IDrawingContext& context);

    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    virtual void HandleUpdate (const Time& dt);

  private:
    String content_;
    collection::Array<Label*> labels_;
    uint currentText_;
    VerticalLayout* layout_;
    PartialLayoutManager* layoutManager_;
    bool showText_;
    uint currentSelec_;

  };
} // namespace yap

#endif /* YAPOG_MULTILABELWIDGET_HPP! */