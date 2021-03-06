#ifndef YAPOG_IGAMESCREEN_HPP
# define YAPOG_IGAMESCREEN_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Graphics/Gui/IEventHandler.hpp"
# include "YAPOG/System/Event/Event.hpp"

namespace yap
{
  typedef String ScreenType;

  class Time;
  struct IDrawingContext;
  class GuiManager;

  /// @brief Represents a phase of the game client.
  struct YAPOG_LIB IGameScreen : public IEventHandler
  {
      virtual ~IGameScreen () {}

      /// @brief Called once after the add into a IGameScreenManager.
      virtual void Init () = 0;
      /// @brief Called each time this IGameScreen is slected to be run.
      virtual void Activate () = 0;
      /// @brief Called each time this IGameScreen is not running anymore.
      virtual void Deactivate () = 0;

      virtual void NextFrame () = 0;

      /// @brief Performs one frame of the screen life.
      /// @param dt Delta time elapsed since last frame.
      /// @param context Drawing context where are drawn graphical elements.
      /// @return Next screen type that must be executed.
      /// By default, the returned type is the type of this Screen.
      virtual const ScreenType& Run (
        const Time& dt,
        IDrawingContext& context) = 0;

      /// @brief Gets the root widget of this Screen.
      /// @return A constant reference to the root widget of this Screen.
      virtual const GuiManager& GetGuiManager () const = 0;
      /// @brief Gets the root widget of this Screen.
      /// @return A non-constant reference to the root widget of this Screen.
      virtual GuiManager& GetGuiManager () = 0;

      /// @brief Gets the unique type name of this Screen.
      virtual const ScreenType& GetType () const = 0;

      virtual Event<IGameScreen&>& OnGameExitedEvent () = 0;
  };
} // namespace yap

#endif // YAPOG_IGAMESCREEN_HPP
