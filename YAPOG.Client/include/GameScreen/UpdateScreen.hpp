#ifndef YAPOG_CLIENT_UPDATESCREEN_HPP
# define YAPOG_CLIENT_UPDATESCREEN_HPP

# include "YAPOG/Macros.hpp"

# include "GameScreen/BaseScreen.hpp"

namespace ycl
{
  class UpdateScreen : public BaseScreen
  {
      DISALLOW_COPY(UpdateScreen);

    public:

      UpdateScreen ();
      virtual ~UpdateScreen ();
  };
} // namespace ycl

#endif // YAPOG_CLIENT_UPDATESCREEN_HPP
