#ifndef YAPOG_BATTLEPHASE_HPP
# define YAPOG_BATTLEPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/Game/Battle/Phase/BattlePhaseState.hpp"

namespace yap
{
  class Battle;

  class YAPOG_LIB BattlePhase : public IUpdateable
  {
  public:
    BattlePhase (Battle& battle, const BattlePhaseState& battlePhaseState);

    /// Getters
    const BattlePhaseState& GetNext () const;

    void Start ();
    void End ();
    
    /// @name Setters.
    /// @{
    void SetPreviousPhase (const BattlePhaseState& value);
    /// @}

    /// @name IUpdateable members.
    /// @{
    virtual void Update (const Time& dt);
    /// @}

  protected:
    virtual void HandleStart ();
    virtual void HandleEnd ();
    virtual void HandleUpdate (const Time& dt);

    Battle& GetBattle ();

    BattlePhaseState state_;
    BattlePhaseState nextPhase_;
    BattlePhaseState previousPhase_;

  private:
    Battle& battle_;
  };
} // namespace yap

#endif // YAPOG_BATTLEPHASE_HPP
