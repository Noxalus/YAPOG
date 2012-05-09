#include "Account/PlayerData.hpp"
#include "YAPOG/System/StringHelper.hpp"

const yap::Vector2 PlayerData::DEFAULT_POSITION (42.69f, 1337.56f);

PlayerData::PlayerData (const yap::ID accountID)
  : accountID_ (accountID)
  , position_ (DEFAULT_POSITION)
{
}

/// Getters
const yap::ID& PlayerData::GetAccountID () const 
{ return accountID_; }
const yap::Vector2& PlayerData::GetPosition () const 
{ return position_; }

/// Setters
void PlayerData::SetAccountID (const yap::ID& value)
{ accountID_ = value; }
void PlayerData::SetPosition (const yap::Vector2& value)
{ position_ = value; }

void PlayerData::DisplayData ()
{
  yap::String position 
    ("(" + yap::StringHelper::ToString (position_.x) + ", " + 
    yap::StringHelper::ToString (position_.y) + ")");

  std::cout << "/** Player Data Information **/" << std::endl
    << "ID: " << accountID_.GetValue () << std::endl
    << "Position: " << position << std::endl
    << "/****/" << std::endl;
}