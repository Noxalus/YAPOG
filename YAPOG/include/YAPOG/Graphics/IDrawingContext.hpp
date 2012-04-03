#ifndef YAPOG_IDRAWINGCONTEXT_HPP
# define YAPOG_IDRAWINGCONTEXT_HPP

# include <SFML/Graphics/RenderTarget.hpp>
# include <SFML/Graphics/Drawable.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  /// Mode name associated to a Camera.
  typedef String CameraMode;

  struct ICamera;
  struct IDrawable;

  /// @brief A context to render graphical objects.
  /// Possesses a set of Camera associated to each CameraMode.
  struct YAPOG_LIB IDrawingContext
  {
      virtual ~IDrawingContext () {}

      /// @brief Adds an ICamera associated to a CameraMode.
      /// @param mode CameraMode associated to the ICamera.
      /// @param camera ICamera associated to the CameraMode.
      virtual void AddCamera (const CameraMode& mode, ICamera* camera) = 0;
      /// @brief Remove an ICamera associated to a CameraMode.
      /// @param mode CameraMode associated to the ICamera to remove.
      virtual void RemoveCamera (const CameraMode& mode) = 0;

      /// @brief Gets the Camera associated to the CameraMode currently used.
      /// @return A constant reference to the current Camera.
      virtual const ICamera& GetCamera () const = 0;
      /// @brief Gets the Camera associated to the CameraMode currently used.
      /// @return A non-constant reference to the current Camera.
      virtual ICamera& GetCamera () = 0;
      /// @brief Gets the Camera associated to a CameraMode.
      /// @param mode CameraMode to get the Camera associated with.
      /// @return A constant reference to the Camera.
      virtual const ICamera& GetCamera (const CameraMode& mode) const = 0;
      /// @brief Gets the Camera associated to a CameraMode.
      /// @param mode CameraMode to get the Camera associated with.
      /// @return A non-constant reference to the Camera.
      virtual ICamera& GetCamera (const CameraMode& mode) = 0;

      /// @brief Sets the CameraMode currently used by the IDrawingContext.
      /// @param mode CameraMode to use.
      virtual void SetMode (const CameraMode& mode) = 0;
      /// @brief Sets the CameraMode used by default i-e the CameraMode
      /// when IDrawingContext::SetDefaultCamera () is called.
      /// @param mode CameraMode to set by default.
      virtual void SetDefaultMode (const CameraMode& mode) = 0;
      /// @brief Sets the default CameraMode as the current one used.
      virtual void SetDefaultCamera () = 0;

      /// @brief Gets the RenderTarget of this IDrawingContext.
      /// @return A constant reference to the RenderTarget.
      virtual const sf::RenderTarget& GetRenderTarget () const = 0;
      /// @brief Gets the RenderTarget of this IDrawingContext.
      /// @return A non-constant reference to the RenderTarget.
      virtual sf::RenderTarget& GetRenderTarget () = 0;

      /// @brief Renders the Drawable into the RenderTarget
      /// of this DrawingContext with the current settings.
      /// @param drawable Drawable to render into this IDrawingContext.
      virtual void Draw (const sf::Drawable& drawable) = 0;
  };
} // namespace yap

#endif // YAPOG_IDRAWINGCONTEXT_HPP
