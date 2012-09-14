#include "Battle/BattleParameters.hpp"
#include "Battle/IDrawableBattleEntity.hpp"

namespace ycl
{
  BattleParameters::BattleParameters ()
    : yap::BattleParameters ()
    , opponent_ (nullptr)
  {
  }

  BattleParameters::~BattleParameters ()
  {
  }

  // Getters
  IDrawableBattleEntity& BattleParameters::GetOpponent () const
  { return *opponent_; };

  // Setters
  void BattleParameters::SetOpponent (IDrawableBattleEntity* value)
  {
    // We set the opponent of the base class
    yap::BattleParameters::SetOpponent (value);

    opponent_ = value;
  }

} // namespace yap
