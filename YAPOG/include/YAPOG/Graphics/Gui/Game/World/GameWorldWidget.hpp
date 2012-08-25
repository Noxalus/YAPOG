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

      virtual void AddGameWorldWidget (GameWorldWidget* gameWorldWidget);
      virtual void RemoveGameWorldWidget (GameWorldWidget* gameWorldWidget);

      virtual bool IsFocusable () const;

    protected:

      GameWorldWidget ();

      virtual const GameWorldGuiManager& GetGameWorldRoot () const;

      virtual void HandleSetGameWorldParent (
        const GameWorldWidget& gameWorldParent);

    private:

      void SetGameWorldParent (const GameWorldWidget& gameWorldParent);

      const GameWorldWidget* gameWorldParent_;

      collection::List<GameWorldWidget*> gameWorldWidgets_;
  };
} // namespace yap

#endif // YAPOG_GAMEWORLDWIDGET_HPP
