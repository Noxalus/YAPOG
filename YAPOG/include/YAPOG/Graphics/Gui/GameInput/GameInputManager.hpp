#ifndef YAPOG_GAMEINPUTMANAGER_HPP
# define YAPOG_GAMEINPUTMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/GameInput/GameInput.hpp"
# include "YAPOG/Collection/Map.hpp"

namespace yap
{
  class YAPOG_LIB GameInputManager
  {
    public:

      DISALLOW_COPY(GameInputManager);

      static GameInputManager& Instance ();

      void BeginUpdate ();
      void Update (const GuiEvent& guiEvent);
      void EndUpdate ();

      void AddGameInput (GameInput* gameInput);
      void RemoveGameInput (GameInput* gameInput);

      bool GameInputIsActive (GameInputType gameInputType) const;
      bool GameInputIsActivated (GameInputType gameInputType) const;
      bool GameInputIsDeactivated (GameInputType gameInputType) const;

    private:

      GameInputManager ();
      ~GameInputManager ();

      collection::Map<GameInputType, GameInput*> gameInputs_;
  };
} // namespace yap

#endif // YAPOG_GAMEINPUTMANAGER_HPP
