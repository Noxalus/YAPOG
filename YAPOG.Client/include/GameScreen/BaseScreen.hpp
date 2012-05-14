#ifndef YAPOG_CLIENT_BASESCREEN_HPP
# define YAPOG_CLIENT_BASESCREEN_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/GameScreen.hpp"

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
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BASESCREEN_HPP
