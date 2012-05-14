#ifndef YAPOG_CLIENT_LOGINSCREEN_HPP
# define YAPOG_CLIENT_LOGINSCREEN_HPP

# include "YAPOG/Macros.hpp"

# include "GameScreen/BaseScreen.hpp"

namespace ycl
{
  class LoginScreen : public BaseScreen
  {
      DISALLOW_COPY(LoginScreen);

    public:

      LoginScreen ();
      virtual ~LoginScreen ();
  };
} // namespace ycl

#endif // YAPOG_CLIENT_LOGINSCREEN_HPP
