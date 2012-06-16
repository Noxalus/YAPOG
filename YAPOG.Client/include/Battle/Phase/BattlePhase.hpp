#ifndef YAPOG_CLIENT_BATTLEPHASE_HPP
# define YAPOG_CLIENT_BATTLEPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"
# include "YAPOG/Game/Battle/Phase/BattlePhase.hpp"

namespace yap
{
  class PhaseArgs;
} // namespace yap

namespace ycl
{
  class Battle;

  class BattlePhase
    : public yap::BattlePhase
    , public yap::IDrawable
  {
  public:
    BattlePhase (Battle& battle);
    BattlePhase (Battle& battle, const yap::BattlePhaseState& battlePhaseState);
    virtual ~BattlePhase ();

    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart (yap::PhaseArgs* args);
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

    static const yap::BattlePhaseState DEFAULT_BATTLE_PHASE_STATE;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BATTLEPHASE_HPP