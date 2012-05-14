#ifndef YAPOG_CLIENT_BATTLESCREEN_HPP
# define YAPOG_CLIENT_BATTLESCREEN_HPP

# include "YAPOG/Macros.hpp"

# include "GameScreen/BaseScreen.hpp"

namespace ycl
{
  class BattleScreen : public BaseScreen
  {
      DISALLOW_COPY(BattleScreen);

    public:

      BattleScreen ();
      virtual ~BattleScreen ();
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BATTLESCREEN_HPP
