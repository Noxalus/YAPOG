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

  protected:

    virtual void HandleInit ();

    virtual const yap::ScreenType& HandleRun (
      const yap::Time& dt,
      yap::IDrawingContext& context);

  private:
    void Login ();

    static const yap::ScreenType DEFAULT_NAME;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_LOGINSCREEN_HPP
