#ifndef YAPOG_GAME_HPP
# define YAPOG_GAME_HPP

# include <SFML/Graphics/RenderWindow.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/IGame.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/Time/Timer.hpp"

namespace yap
{
  struct IGameScreenManager;
  struct IDrawingContext;
  class Time;
  class GuiEvent;

  class Game : public IGame
  {
    public:

      DISALLOW_COPY(Game);

      /// @brief Initializes a Game with the name @a name.
      Game (const String& name);
      virtual ~Game ();

      /// @name IGame members.
      /// @{
      virtual void Init ();
      virtual void Launch ();
      /// @}

    protected:

      IGameScreenManager* screenManager_;

      IDrawingContext* drawingContext_;
      /// Handle of the RenderWindow.
      /// MUST NOT be deleted from here.
      sf::RenderWindow* window_;

      const String name_;

    private:

      virtual void HandleInit () = 0;
      virtual void HandleRun (const Time& dt, IDrawingContext& context);
      virtual bool HandleOnEvent (const GuiEvent& guiEvent) = 0;

      bool isRunning_;
      Timer timer_;
  };
} // namespace yap

#endif // YAPOG_GAME_HPP
