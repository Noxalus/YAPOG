#include "Database/Tables/PlayerDataTable.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace yse
{
  const yap::Vector2 PlayerDataTable::DEFAULT_POSITION (42.69f, 1337.56f);

  PlayerDataTable::PlayerDataTable (const yap::ID accountID)
    : accountID_ (accountID)
    , position_ (DEFAULT_POSITION)
  {
  }

  /// Getters
  const yap::ID& PlayerDataTable::GetAccountID () const 
  { return accountID_; }
  const yap::Vector2& PlayerDataTable::GetPosition () const 
  { return position_; }

  /// Setters
  void PlayerDataTable::SetAccountID (const yap::ID& value)
  { accountID_ = value; }
  void PlayerDataTable::SetPosition (const yap::Vector2& value)
  { position_ = value; }

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