#ifndef YAPOG_CLIENT_BATTLEINTERFACE_HPP
# define YAPOG_CLIENT_BATTLEINTERFACE_HPP

# include "YAPOG/Macros.hpp"

# include "Battle/BaseBattleWidget.hpp"

namespace yap
{
  class ISprite;
  class WidgetDialogBox;
  class WidgetBackground;
  class IDrawingContext;
  class Time;
} // namespace yap

namespace ycl
{
  class BattleBackgroundWidget;

  class BattleInterface 
    : public yap::BaseWidget
    , public BaseBattleWidget
  {
  public:
    BattleInterface ();

  private:
    yap::ISprite* background_;
    yap::ISprite* opponentGround_;
    yap::ISprite* playerGround_;
    yap::WidgetDialogBox* battleTextDialogBox_;

    static const yap::Vector2 DEFAULT_OPPONENT_GROUND_SPRITES_SCALE;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BATTLEINTERFACE_HPP
