#ifndef YAPOG_WIDGETBASE_HPP
# define YAPOG_WIDGETBASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/IWidget.hpp"
# include "YAPOG/Graphics/SpatialInfo.hpp"

namespace yap
{
  class YAPOG_LIB WidgetBase : public IWidget
  {
      DISALLOW_COPY(WidgetBase);

    public:

      WidgetBase ();
      virtual ~WidgetBase ();

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
      /// @}

      /// @name IUpdateable members.
      /// @{
      virtual void Update (const Time& dt);
      /// @}

    private:

      virtual void HandleMove (const Vector2& offset) = 0;
      virtual void HandleScale (const Vector2& factor) = 0;

      virtual void HandleDraw (IDrawingContext& context) = 0;

      virtual void HandleShow (bool isVisible) = 0;
      virtual void HandleChangeColor (const sf::Color& color) = 0;

      virtual bool HandleOnEvent (const GuiEvent& guiEvent) = 0;

      virtual void HandleUpdate (const Time& dt) = 0;

      static const bool DEFAULT_VISIBLE_STATE;
      static const sf::Color DEFAULT_COLOR;

      SpatialInfo spatialInfo_;
      bool isVisible_;
      sf::Color color_;
  };
} // namespace yap

#endif // YAPOG_WIDGETBASE_HPP
