#ifndef YAPOG_BATTLEPHASE_HPP
# define YAPOG_BATTLEPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/IUpdateable.hpp"

namespace yap
{
  class Battle;

  class YAPOG_LIB BattlePhase : public IUpdateable
  {
  public:
    BattlePhase ();

    void Start ();
    void End ();
    void SetBattle (Battle* battle);

    /// @name IUpdateable members.
    /// @{
    virtual void Update (const Time& dt);
    /// @}

  protected:
    virtual void HandleStart ();
    virtual void HandleEnd ();
    virtual void HandleUpdate (const Time& dt);
    Battle& GetBattle ();

  private:
    Battle* battle_;
  };
} // namespace yap

#endif // YAPOG_BATTLEPHASE_HPP
