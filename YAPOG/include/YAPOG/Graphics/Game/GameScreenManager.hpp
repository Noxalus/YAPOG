#ifndef YAPOG_GAMESCREENMANAGER_HPP
# define YAPOG_GAMESCREENMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/IGameScreenManager.hpp"
# include "YAPOG/Collection/Map.hpp"

namespace yap
{
  class YAPOG_LIB GameScreenManager : public IGameScreenManager
  {
    public:

      DISALLOW_COPY(GameScreenManager);

      GameScreenManager ();
      virtual ~GameScreenManager ();

      /// @name IEventHandler members.
      /// @{
      virtual bool OnEvent (const GuiEvent& guiEvent);
      /// @}

      /// @name IGameScreenManager members.
      /// @{
      virtual void Init (const ScreenType& screenType);

      virtual void AddGameScreen (IGameScreen* gameScreen);
      virtual void RemoveGameScreen (const ScreenType& screenType);
      virtual void SetCurrentScreen (const ScreenType& screenType);

      virtual void Run (const Time& dt, IDrawingContext& context);
      /// @}

    private:

      ScreenType currentScreenType_;
      /// The IGameScreen currently run.
      /// MUST NOT be deleted from here.
      IGameScreen* currentScreen_;
      collection::Map<ScreenType, IGameScreen*> screens_;
  };
} // namespace yap

#endif // YAPOG_GAMESCREENMANAGER_HPP
