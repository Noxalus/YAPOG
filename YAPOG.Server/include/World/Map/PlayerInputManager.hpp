#ifndef YAPOG_SERVER_PLAYERINPUTMANAGER_HPP
# define YAPOG_SERVER_PLAYERINPUTMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/GameInput/GameInputType.hpp"
# include "YAPOG/Collection/Map.hpp"

namespace yse
{
  class PlayerInputManager
  {
      DISALLOW_COPY(PlayerInputManager);

    public:

      PlayerInputManager ();
      ~PlayerInputManager ();

      bool InputIsActivated (yap::GameInputType gameInputType) const;
      bool InputIsDeactivated (yap::GameInputType gameInputType) const;

      bool InputIsActive (yap::GameInputType gameInputType) const;

      void SetInputState (yap::GameInputType gameInputType, bool isActive);

      void Refresh ();

    private:

      class Entry
      {
        public:

          enum class State
          {
              Activated,
              Deactivated,
              Active,
              Inactive
          };

          Entry ();

          State GetState () const;

          void Activate (bool isActive);

          void Refresh ();

        private:

          static const State DEFAULT_STATE;

          State currentState_;

          State newState_;

          bool isRefreshed_;
      };

      typedef yap::collection::Map<yap::GameInputType, Entry> GameInputMap;

      void AddInput (yap::GameInputType gameInputType);

      Entry::State GetInputState (yap::GameInputType gameInputType) const;

      GameInputMap gameInputs_;
  };
} // namespace yse

#endif // YAPOG_SERVER_PLAYERINPUTMANAGER_HPP
