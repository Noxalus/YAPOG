#include "YAPOG/Game/Battle/BattleParameters.hpp"
#include "YAPOG/Game/Battle/BattleParameters.hpp"

namespace yap
{
  const ID BattleParameters::DEFAULT_GROUND_TYPE (1);
  const ID BattleParameters::DEFAULT_WEATHER (1);
  const BattleType BattleParameters::
    DEFAULT_BATTLE_TYPE = BattleType::SingleWild;

  BattleParameters::BattleParameters ()
    : battleType_ (DEFAULT_BATTLE_TYPE)
    , groundType_ (DEFAULT_GROUND_TYPE)
    , weather_ (DEFAULT_WEATHER)
    , opponent_ (nullptr)
  {
  }

  // Getters
  const BattleType& BattleParameters::GetBattleType () const
  { return battleType_; }
  const ID& BattleParameters::GetGroundType () const
  { return groundType_; }
  const ID& BattleParameters::GetWeather () const
  { return weather_; }
  IBattleEntity& BattleParameters::GetOpponent () const
  { return *opponent_; }

  // Setters
  void BattleParameters::SetBattleType (const BattleType& value)
  { battleType_ = value; }
  void BattleParameters::SetGroundType (const ID& value)
  { groundType_ = value; }
  void BattleParameters::SetWeather (const ID& value)
  { weather_ = value; }
  void BattleParameters::SetOpponent (IBattleEntity* value)
  { opponent_ = value; }

} // namespace yap