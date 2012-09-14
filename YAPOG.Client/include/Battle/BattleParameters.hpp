#ifndef YAPOG_CLIENT_BATTLEPARAMETERS_HPP
# define YAPOG_CLIENT_BATTLEPARAMETERS_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/BattleParameters.hpp"

namespace ycl
{
  struct IDrawableBattleEntity;

  class BattleParameters : public yap::BattleParameters
  {
    DISALLOW_COPY (BattleParameters);

  public:
    BattleParameters ();
    virtual ~BattleParameters ();

    /// @name Getters.
    /// {
    IDrawableBattleEntity& GetOpponent () const;
    /// }

    /// @name Setters.
    /// {
    void SetOpponent (IDrawableBattleEntity* value);
    /// }

  private:
    IDrawableBattleEntity* opponent_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BATTLEPARAMETERS_HPP
