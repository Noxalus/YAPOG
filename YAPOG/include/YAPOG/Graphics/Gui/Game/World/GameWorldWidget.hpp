#ifndef YAPOG_GAMEWORLDWIDGET_HPP
# define YAPOG_GAMEWORLDWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/Game/GameWidget.hpp"

namespace yap
{
  class GameWorldGuiManager;

  class GameWorldWidget : public GameWidget
  {
      DISALLOW_COPY(GameWorldWidget);

    public:

      virtual ~GameWorldWidget ();

      void SetGameWorldRoot (const GameWorldGuiManager& gameWorldRoot);

    protected:

      GameWorldWidget ();

      const GameWorldGuiManager* gameWorldRoot_;
  };
} // namespace yap

#endif // YAPOG_GAMEWORLDWIDGET_HPP
