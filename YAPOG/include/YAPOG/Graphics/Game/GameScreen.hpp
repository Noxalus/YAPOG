#ifndef YAPOG_GAMESCREEN_HPP
# define YAPOG_GAMESCREEN_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/IGameScreen.hpp"

namespace yap
{
  /// @brief A basic implementation of IGameScreen, a game phase.
  class YAPOG_LIB GameScreen : public IGameScreen
  {
      DISALLOW_COPY(GameScreen);

    public:

      /// @brief Initializes a GameScreen with the ScreenType @a type.
      /// @param type ScreenType of this GameScreen.
      explicit GameScreen (const ScreenType& type);
      virtual ~GameScreen ();

      /// @name IGameScreen members.
      /// @{
      virtual void Init ();
      virtual void Activate ();
      virtual void Deactivate ();

      virtual void NextFrame ();
      virtual const ScreenType& Run (const Time& dt, IDrawingContext& context);

      virtual const GuiManager& GetGuiManager () const;
      virtual GuiManager& GetGuiManager ();

      virtual const ScreenType& GetType () const;
      /// @}

      /// @name IEventHandler members.
      /// @{
      virtual bool OnEvent (const GuiEvent& guiEvent);
      virtual bool OnPriorityEvent (const GuiEvent& guiEvent);
      /// @}

    protected:

      virtual void CreateGuiManager ();

      /// @brief Behavior of Run.
      virtual void HandleRun (
        const Time& dt,
        IDrawingContext& context);
      /// @brief Behavior of Init.
      virtual void HandleInit ();
      /// @brief Behavior of Activate.
      virtual void HandleActivate ();
      /// @brief Behavior of Deactivate.
      virtual void HandleDeactivate ();
      /// @brief Behavior of OnEvent.
      virtual bool HandleOnEvent (const GuiEvent& guiEvent);
      /// @brief Behavior of OnPriorityEvent.
      virtual bool HandleOnPriorityEvent (const GuiEvent& guiEvent);

      /// Type of the Screen to be executed on next frame.
      ScreenType nextScreen_;
      /// Root widget if this GameScreen.
      GuiManager* guiManager_;

    private:

      /// Type of this GameScreen.
      ScreenType type_;
  };
} // namespace yap

#endif // YAPOG_GAMESCREEN_HPP
