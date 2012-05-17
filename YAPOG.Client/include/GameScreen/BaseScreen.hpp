#ifndef YAPOG_CLIENT_BASESCREEN_HPP
# define YAPOG_CLIENT_BASESCREEN_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/GameScreen.hpp"

namespace yap
{
  class ContentManager;
  class ObjectFactory;
  class WorldObjectStateFactory;
  class GameInputManager;
  class Logger;
} // namespace yap

namespace ycl
{
  class Session;

  class BaseScreen : public yap::GameScreen
  {
      DISALLOW_COPY(BaseScreen);

    public:

      virtual ~BaseScreen ();

    protected:

      explicit BaseScreen (const yap::ScreenType& type);

      Session& session_;

      yap::ContentManager& contentManager_;

      yap::ObjectFactory& objectFactory_;
      yap::WorldObjectStateFactory& worldObjectStateFactory_;

      yap::GameInputManager& gameInputManager_;

      yap::Logger& logger_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BASESCREEN_HPP
