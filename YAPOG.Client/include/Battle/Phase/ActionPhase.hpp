#ifndef YAPOG_CLIENT_ACTIONPHASE_HPP
# define YAPOG_CLIENT_ACTIONPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"
# include "YAPOG/Game/Battle/Phase/ActionPhase.hpp"
# include "YAPOG/Game/Battle/BattleCore.hpp"
# include "YAPOG/System/IntTypes.hpp"

namespace yap
{
  class PhaseArgs;
} // namespace yap

namespace ycl
{
  class Battle;
  class BattleInterface;
  class PhaseArgs;

  class ActionPhase
    : public yap::ActionPhase
    , public yap::IDrawable
  {
  public:
    explicit ActionPhase (Battle& battle, BattleInterface& battleInterface);
    virtual ~ActionPhase ();

    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart (const yap::PhaseArgs& args);
    virtual void HandleUpdate (const yap::Time& dt);
    virtual void HandleEnd ();
    /// @}

    /// @name IDrawable members.
    /// @{
    virtual void Draw (yap::IDrawingContext& context);

    virtual bool IsVisible () const;
    virtual void Show (bool isVisible);

    virtual void ChangeColor (const sf::Color& color);
    /// @}

  protected:
    virtual void HandleDraw (yap::IDrawingContext& context);
    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    static const bool DEFAULT_VISIBLE_STATE;
    static const sf::Color DEFAULT_COLOR;

    bool isVisible_;
    sf::Color color_;

  private:
    Battle& battle_;
    BattleInterface& battleInterface_;
    yap::BattleCore battleCore_;
    yap::uchar opponentMoveIndex_;
    yap::uint textSkippedNumber_;
    bool playerAttack_;
    bool opponentAttack_;
    bool nextPhase_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_ACTIONPHASE_HPP
