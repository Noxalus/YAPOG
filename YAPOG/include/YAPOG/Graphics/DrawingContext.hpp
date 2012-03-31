#ifndef YAPOG_DRAWINGCONTEXT_HPP
# define YAPOG_DRAWINGCONTEXT_HPP

# include <SFML/Graphics/RenderWindow.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/Graphics/IDrawingContext.hpp"
# include "YAPOG/Graphics/ICamera.hpp"

namespace yap
{
  /// @brief A common implementation of an IDrawingContext.
  class YAPOG_LIB DrawingContext : public IDrawingContext
  {
    public:

      DISALLOW_COPY(DrawingContext);

      DrawingContext (const Vector2& size, const String& name);
      virtual ~DrawingContext ();

      /// @name IDrawingContext members.
      /// @{
      virtual void AddCamera (const CameraMode& mode, ICamera* camera);
      virtual void RemoveCamera (const CameraMode& mode);

      virtual const ICamera& GetCamera () const;
      virtual ICamera& GetCamera ();
      virtual const ICamera& GetCamera (const CameraMode& mode) const;
      virtual ICamera& GetCamera (const CameraMode& mode);

      virtual void SetMode (const CameraMode& mode);
      virtual void SetDefaultMode (const CameraMode& mode);
      virtual void SetDefaultCamera ();

      virtual const sf::RenderTarget& GetRenderTarget () const;
      virtual sf::RenderTarget& GetRenderTarget ();

      virtual void Draw (const sf::Drawable& drawable);
      /// @}

      sf::RenderWindow& GetWindow ();

    private:

      void SetCurrentMode (const CameraMode& mode);

      sf::RenderWindow window_;
      CameraMode currentMode_;
      CameraMode defaultMode_;
      collection::Map<CameraMode, ICamera*> cameras_;
  };
} // namespace yap

#endif // YAPOG_DRAWINGCONTEXT_HPP
