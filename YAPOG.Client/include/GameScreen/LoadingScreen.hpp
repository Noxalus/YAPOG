#ifndef YAPOG_CLIENT_LOADINGSCREEN_HPP
# define YAPOG_CLIENT_LOADINGSCREEN_HPP

# include "YAPOG/Macros.hpp"

# include "GameScreen/BaseScreen.hpp"

namespace ycl
{
  class LoadingScreen : public BaseScreen
  {
      DISALLOW_COPY(LoadingScreen);

    public:

      LoadingScreen ();
      virtual ~LoadingScreen ();
  };
} // namespace ycl

#endif // YAPOG_CLIENT_LOADINGSCREEN_HPP
