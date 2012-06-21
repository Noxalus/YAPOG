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

      bool InputIsActive (yap::GameInputType gameInputType) const;
      void SetInputState (yap::GameInputType gameInputType, bool isActive);

    private:

      yap::collection::Map<yap::GameInputType, bool> gameInputs_;
  };
} // namespace yse

#endif // YAPOG_SERVER_PLAYERINPUTMANAGER_HPP
