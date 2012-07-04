#ifndef YAPOG_IGAMESCREENMANAGER_HPP
# define YAPOG_IGAMESCREENMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/IGameScreen.hpp"
# include "YAPOG/System/Event/Event.hpp"

namespace yap
{
  /// @brief Interface for manipulate several IGameScreen.
  struct YAPOG_LIB IGameScreenManager : public IEventHandler
  {
      virtual ~IGameScreenManager () {}

      /// @brief Initializes each IGameScreen added to this IGameScreenManager.
      /// @param screenType ScreenType associated to the IGameScreen
      /// to run first.
      virtual void Init (const ScreenType& screenType) = 0;
      /// @brief Adds an IGameScreen to the set.
      /// @param gameScreen IGameScreen to add to the set.
      virtual void AddGameScreen (IGameScreen* gameScreen) = 0;
      /// @brief Removes an IGameScreen from the set.
      /// @param gameScreen IGameScreen to remove from the set.
      virtual void RemoveGameScreen (const ScreenType& screenType) = 0;
      /// @brief Activate the IGameScreen associated to the ScreenType.
      /// @param screenType ScreenType of the IGameScreen to activate.
      virtual void SetCurrentScreen (const ScreenType& screenType) = 0;

      virtual void NextFrame () = 0;

      /// @brief Runs the current IGameScreen.
      /// @param dt Delta time since last frame.
      /// @param context IDrawingContext where to draw graphical elements.
      virtual void Run (const Time& dt, IDrawingContext& context) = 0;

      virtual Event<IGameScreenManager&>& OnGameExitedEvent () = 0;
  };
} // namespace yap

#endif // YAPOG_IGAMESCREENMANAGER_HPP
