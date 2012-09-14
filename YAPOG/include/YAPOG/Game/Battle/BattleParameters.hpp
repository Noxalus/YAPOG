#ifndef YAPOG_BATTLEPARAMETERS_HPP
# define YAPOG_BATTLEPARAMETERS_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/Game/Battle/BattleType.hpp"
# include "YAPOG/Game/Battle/IBattleEntity.hpp"

namespace yap
{
  class YAPOG_LIB BattleParameters
  {
    DISALLOW_COPY(BattleParameters);

  public:
    BattleParameters ();

    /// @name Getters.
    /// {
    const BattleType& GetBattleType () const;
    const ID& GetGroundType () const;
    const ID& GetWeather () const;
    IBattleEntity& GetOpponent () const;
    /// }

    /// @name Setters.
    /// {
    void SetBattleType (const BattleType& value);
    void SetGroundType (const ID& value);
    void SetWeather (const ID& value);
    void SetOpponent (IBattleEntity* value);
    /// }

    static const BattleType DEFAULT_BATTLE_TYPE;
    static const ID DEFAULT_GROUND_TYPE;
    static const ID DEFAULT_WEATHER;

  protected:
    BattleType battleType_;
    ID groundType_;
    ID weather_;
    IBattleEntity* opponent_;
  };
} // namespace yap

#endif // YAPOG_BATTLEPARAMETERS_HPP
