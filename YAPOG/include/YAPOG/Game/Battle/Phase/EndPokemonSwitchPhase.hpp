#ifndef YAPOG_ENDPOKEMONSWITCHPHASE_HPP
# define YAPOG_ENDPOKEMONSWITCHPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/Phase/BattlePhase.hpp"

namespace yap
{
  class PhaseArgs;

  class YAPOG_LIB EndPokemonSwitchPhase : public BattlePhase
  {
  public:
    EndPokemonSwitchPhase (Battle& battle);

    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart (const PhaseArgs& args);
    virtual void HandleUpdate (const Time& dt);
    virtual void HandleEnd ();
    /// @}
  };
} // namespace yap

#endif // YAPOG_ENDPOKEMONSWITCHPHASE_HPP
