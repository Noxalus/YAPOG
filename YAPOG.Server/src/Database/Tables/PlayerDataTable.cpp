#include "Database/Tables/PlayerDataTable.hpp"
#include "Account/PlayerData.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace yse
{
  PlayerDataTable::PlayerDataTable (const yap::ID& accountID)
    : accountID_ (accountID)
    , position_ (PlayerData::DEFAULT_POSITION)
    , mapID_ (PlayerData::DEFAULT_MAP_ID)
    , playTime_ (0)
    , stepCount_ (0)
    , respawnSpot_ (PlayerData::DEFAULT_RESPAWN_SPOT)
    , fleeCount_ (0)
    , boxNumber_ (PlayerData::DEFAULT_BOX_NUMBER)
    , battleCount_ (0)
    , money_ (PlayerData::DEFAULT_MONEY)
  {
  }

  void PlayerDataTable::LoadFromPlayerData (const PlayerData& playerData)
  {
    SetAccountID (playerData.GetAccountID ());
    SetPosition (playerData.GetPosition ());
    SetMapID (playerData.GetMapID ());
    SetPlayTime (playerData.GetPlayTime ().GetValue ());
    SetStepCount (playerData.GetStepCount ());
    SetRespawnSpot (playerData.GetRespawnSpot ());
    SetFleeCount (playerData.GetFleeCount ());
    SetBoxNumber (playerData.GetBoxNumber ());
    SetBattleCount (playerData.GetBattleCount ());
    SetMoney (playerData.GetMoney ());
  }

  /// Getters
  const yap::ID& PlayerDataTable::GetAccountID () const 
  { return accountID_; }
  const yap::Vector2& PlayerDataTable::GetPosition () const 
  { return position_; }
  const yap::ID& PlayerDataTable::GetMapID () const
  { return mapID_; }
  int PlayerDataTable::GetPlayTime () const
  { return playTime_; }
  int PlayerDataTable::GetStepCount () const
  { return stepCount_; }
  const yap::Vector2& PlayerDataTable::GetRespawnSpot () const
  { return respawnSpot_; }
  int PlayerDataTable::GetFleeCount () const
  { return fleeCount_; }
  int PlayerDataTable::GetBoxNumber () const
  { return boxNumber_; }
  int PlayerDataTable::GetBattleCount () const
  { return battleCount_; }
  int PlayerDataTable::GetMoney () const
  { return money_; }

  /// Setters
  void PlayerDataTable::SetAccountID (const yap::ID& value)
  { accountID_ = value; }
  void PlayerDataTable::SetPosition (const yap::Vector2& value)
  { position_ = value; }
  void PlayerDataTable::SetMapID (const yap::ID& value)
  { mapID_ = value; }
  void PlayerDataTable::SetPlayTime (int value)
  { playTime_ = value; }
  void PlayerDataTable::SetStepCount (int value)
  { stepCount_ = value; }
  void PlayerDataTable::SetRespawnSpot (const yap::Vector2& value)
  { respawnSpot_ = value; }
  void PlayerDataTable::SetFleeCount (int value)
  { fleeCount_ = value; }
  void PlayerDataTable::SetBoxNumber (int value)
  { boxNumber_ = value; }
  void PlayerDataTable::SetBattleCount (int value)
  { battleCount_ = value; }
  void PlayerDataTable::SetMoney (int value)
  { money_ = value; }

  void PlayerDataTable::DisplayData ()
  {
    yap::String position 
      ("(" + yap::StringHelper::ToString (position_.x) + ", " + 
      yap::StringHelper::ToString (position_.y) + ")");

    std::cout << "/** Player Data Information **/" << std::endl
      << "ID: " << accountID_.GetValue () << std::endl
      << "Position: " << position << std::endl
      << "/****/" << std::endl;
  }
} // namespace yse