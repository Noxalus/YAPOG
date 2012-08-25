#ifndef YAPOG_GAMEWIDGET_HPP
# define YAPOG_GAMEWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"

namespace yap
{
  class GameWidget : public BaseWidget
  {
      DISALLOW_COPY(GameWidget);

    public:

      virtual ~GameWidget ();

    protected:

      GameWidget ();
  };
} // namespace yap

#endif // YAPOG_GAMEWIDGET_HPP
