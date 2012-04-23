#ifndef YAPOG_WIDGETBASE_HPP
# define YAPOG_WIDGETBASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/IWidget.hpp"
# include "YAPOG/Graphics/SpatialInfo.hpp"
# include "YAPOG\Collection\List.hpp"

namespace yap
{
  class Padding;
  class WidgetBackground;
  class WidgetBorder;

  class YAPOG_LIB BaseWidget : public IWidget
  {
    DISALLOW_COPY(BaseWidget);

  public:

    BaseWidget ();
    virtual ~BaseWidget ();

    /// @name ISpatial members.
    /// @{
    virtual const Vector2& GetPosition () const;
    virtual const Vector2& GetSize () const;

    virtual const Vector2& GetTopLeft () const;
    virtual const Vector2& GetBottomRight () const;
    virtual const Vector2& GetCenter () const;

    virtual const sf::FloatRect& GetRectangle () const;

    virtual void Move (const Vector2& offset);
    virtual void Scale (const Vector2& factor);

    virtual void SetPosition (const Vector2& position);
    virtual void SetSize (const Vector2& size);
    /// @}

    /// @name IDrawable members.
    /// @{
    virtual void Draw (IDrawingContext& context);

    virtual bool IsVisible () const;
    virtual void Show (bool isVisible);

    virtual void ChangeColor (const sf::Color& color);
    /// @}

    /// @name IEventHandler members.
    /// @{
    virtual bool OnEvent (const GuiEvent& guiEvent);
    virtual bool OnPriorityEvent (const GuiEvent& guiEvent);
    /// @}

    /// @name IUpdateable members.
    /// @{
    virtual void Update (const Time& dt);
    /// @}

    virtual void AddDrawable (IDrawable& drawable);
    virtual void AddChild (IWidget& child);
    virtual IWidget& GetRoot () const;
    virtual void SetParent (IWidget& parent);
    virtual void SetPadding (Padding* padding);
    virtual void SetBackground (WidgetBackground& background);
    virtual void SetBorder  (WidgetBorder& border);


  protected:

    virtual Vector2 HandleGetSize () const;

    virtual void HandleMove (const Vector2& offset) = 0;
    virtual void HandleScale (const Vector2& factor) = 0;
    virtual void HandleDraw (IDrawingContext& context) = 0;
    virtual void HandleShow (bool isVisible) = 0;
    virtual void HandleChangeColor (const sf::Color& color) = 0;
    virtual void HandleUpdate (const Time& dt) = 0;

    virtual bool HandleOnEvent (const GuiEvent& guiEvent);
    virtual bool HandleOnPriorityEvent (const GuiEvent& guiEvent);

    static const bool DEFAULT_VISIBLE_STATE;
    static const sf::Color DEFAULT_COLOR;

    mutable SpatialInfo spatialInfo_;
    bool isVisible_;
    bool isEnable;
    sf::Color color_;
    collection::List<IDrawable*> drawables_;
    collection::List<IEventHandler*> eventHandlers_;
    collection::List<IWidget*> childen_;
    collection::List<IWidget*> updatables_;
    IWidget* root_;
    IWidget* parent_;
    IWidget* focusedChildren_;
    Padding* padding_;
    WidgetBackground* background_;
    WidgetBorder* border_;

  };
} // namespace yap

#endif // YAPOG_WIDGETBASE_HPP
