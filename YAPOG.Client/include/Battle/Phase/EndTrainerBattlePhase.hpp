#ifndef YAPOG_CLIENT_ENDTRAINERBATTLEPHASE_HPP
# define YAPOG_CLIENT_ENDTRAINERBATTLEPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"
# include "YAPOG/Game/Battle/Phase/EndTrainerBattlePhase.hpp"

namespace yap
{
  class PhaseArgs;
} // namespace yap

namespace ycl
{
  class Battle;

  class EndTrainerBattlePhase
    : public yap::EndTrainerBattlePhase
    , public yap::IDrawable
  {
  public:
    EndTrainerBattlePhase (Battle& battle);
    virtual ~EndTrainerBattlePhase ();

    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart (yap::PhaseArgs* args);
    virtual void HandleUpdate (const yap::Time& dt);
    virtual void HandleEnd ();
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
  };
} // namespace ycl

#endif // YAPOG_CLIENT_ENDTRAINERBATTLEPHASE_HPP