#ifndef YAPOG_WIDGETBASE_HPP
# define YAPOG_WIDGETBASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/IWidget.hpp"
# include "YAPOG/Graphics/SpatialInfo.hpp"
# include "YAPOG/Collection/List.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/System/Event/Event.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Graphics/Gui/Padding.hpp"

namespace yap
{
  class WidgetBackground;
  class WidgetBorder;

  class YAPOG_LIB BaseWidget : public IWidget
  {
    DISALLOW_COPY(BaseWidget);

  public:

    struct EventArgs
    {
      EventArgs (const Vector2& content)
      {
        newContent = content;
      }
      Vector2 newContent;
    };

    struct EventArgsDraw
    {
      EventArgsDraw (IDrawingContext& content)
        : newContent (content)
      {
      }
      IDrawingContext& newContent;
    };

    struct EventArgsColor
    {
      EventArgsColor (const sf::Color& content)
        : newContent (content)
      {
      }
      const sf::Color& newContent;
    };

    struct EventArgsIWidget
    {
      IWidget& newContent;

      EventArgsIWidget (IWidget& content)
        : newContent (content)
      {
      }
    };

    Event<const BaseWidget&, const EventArgs&> OnMoved;
    Event<const BaseWidget&, const EventArgs&> OnScaled;
    Event<const BaseWidget&, const EventArgs&> OnSizeSet;
    Event<const BaseWidget&, const EventArgsDraw&> OnDraw;
    Event<const BaseWidget&, const EventArgsColor&> OnColorChanged;
    Event<const BaseWidget&, const EventArgsIWidget&> OnChildAdded;

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
    virtual WidgetBorder* GetBorder () const;

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
    virtual void FrontAddChild (IWidget& child);
    virtual void RemoveChild (IWidget& child);
    virtual IWidget& GetRoot () const;
    virtual void SetDefaultColor (const sf::Color& color);
    virtual void SetParent (IWidget& parent);
    virtual void SetPadding (const Padding& padding);
    virtual void SetBackground (WidgetBackground& background);
    virtual void SetBorder  (WidgetBorder& border, uint width);
    virtual void SetBorder  (WidgetBorder& border);
    virtual void UnsetBackground ();
    virtual void UnsetBorder ();
    virtual bool IsFocusable () const = 0;
    Vector2 GetUserSize () const;

    virtual void SetToTop();

    virtual void SetEnable (bool enable);
    virtual void Open ();
    virtual void Close ();
  protected:

    void RefreshBorder ();
    virtual void SetFocused (bool state);
    virtual void Refresh ();
    virtual Vector2 HandleGetSize () const;

    virtual void HandleMove (const Vector2& offset);
    virtual void HandleScale (const Vector2& factor);
    virtual void HandleDraw (IDrawingContext& context);
    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);
    virtual void HandleUpdate (const Time& dt);

    virtual void HandleOpen ();
    virtual void HandleClose ();

    virtual bool HandleOnEvent (const GuiEvent& guiEvent);
    virtual bool HandleOnPriorityEvent (const GuiEvent& guiEvent);

    static const bool DEFAULT_VISIBLE_STATE;
    static const bool DEFAULT_ENABLED_STATE;

    static const sf::Color DEFAULT_COLOR;

    mutable SpatialInfo spatialInfo_;
    bool isVisible_;
    bool isEnabled_;
    sf::Color color_;
    collection::List<IDrawable*> drawables_;
    collection::List<IEventHandler*> eventHandlers_;
    collection::List<IWidget*> childen_;
    collection::List<IUpdateable*> updatables_;
    IWidget* root_;
    IWidget* parent_;
    Padding padding_;
    WidgetBackground* background_;
    WidgetBorder* border_;
    Vector2 userSize_;
    bool isExtensible_;
    bool isFocused_;
    sf::Color userColor_;
    bool isChangeColorCall_;
  private:
    void SetPosAfterBorder (uint width, uint height, bool refreshing);
  };
} // namespace yap

#endif // YAPOG_WIDGETBASE_HPP
