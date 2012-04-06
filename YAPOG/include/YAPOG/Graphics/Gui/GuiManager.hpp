#ifndef YAPOG_GUIMANAGER_HPP
# define YAPOG_GUIMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/WidgetBase.hpp"

namespace yap
{
  /// @brief Common implementation of root widget manager.
  /// @todo Implementation of the list of IWidgets
  /// and methods that maintain it.
  class YAPOG_LIB GuiManager : public WidgetBase
  {
      DISALLOW_COPY(GuiManager);

    public:

      GuiManager ();
      virtual ~GuiManager ();

    private:

      virtual void HandleMove (const Vector2& offset);
      virtual void HandleScale (const Vector2& factor);

      virtual void HandleDraw (IDrawingContext& context);

      virtual void HandleShow (bool isVisible);
      virtual void HandleChangeColor (const sf::Color& color);

      virtual bool HandleOnEvent (const GuiEvent& guiEvent);

      virtual void HandleUpdate (const Time& dt);
  };
} // namespace yap

#endif // YAPOG_GUIMANAGER_HPP
