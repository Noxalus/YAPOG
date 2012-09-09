#include "YAPOG/System/MathHelper.hpp"
#include "YAPOG/System/Time/Time.hpp"

#include "Client/PlayerData.hpp"

namespace ycl
{
  PlayerData::PlayerData ()
    : money_ (0)
    , playerTime_ ()
  {
  }

  PlayerData::~PlayerData ()
  {
  }

  void PlayerData::ChangeMoney (int value)
  {
    money_ = yap::MathHelper::Clamp (
      money_ + value, 
      static_cast<yap::UInt32>(0), 
      money_);
  }

  void PlayerData::UpdatePlayTime (const yap::Time& dt)
  {
    playerTime_.UpdateTime (dt);
  }

  // Getters
  const yap::UInt32& PlayerData::GetMoney () const
  {
    return money_;
  }

  const yap::Time& PlayerData::GetPlayTime () const
  {
    return playerTime_.GetPlayTime ();
  }

  // Setters
  void PlayerData::RawSetMoney (const yap::UInt32& value)
  {
    money_ = value;
  }

  void PlayerData::RawSetPlayTime (const yap::Time& value)
  {
    playerTime_.RawSetPlayTime (value);
  }

} // namespace ycl
