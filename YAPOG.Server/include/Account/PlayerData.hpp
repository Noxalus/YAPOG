#ifndef YAPOG_PLAYERDATA_HPP
# define YAPOG_PLAYERDATA_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "Database/Tables/InsertPlayerData.hpp"
# include "Database/Tables/SelectPlayerData.hpp"

class PlayerData
{
	DISALLOW_COPY(PlayerData);
public:
	PlayerData (const yap::ID accountID);

  void DisplayData ();

  /// Getters
  const yap::ID& GetAccountID () const;
  const yap::Vector2& GetPosition () const;

  /// Setters
  void SetAccountID (const yap::ID& value);
  void SetPosition (const yap::Vector2& value);

private:
  yap::ID accountID_;
  yap::Vector2 position_;

  static const yap::Vector2 DEFAULT_POSITION;
};

#endif // YAPOG_PLAYERDATA_HPP