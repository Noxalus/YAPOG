#ifndef YAPOG_INSERTPLAYERDATA_HPP
# define YAPOG_INSERTPLAYERDATA_HPP

# include "YAPOG/Macros.hpp"
# include "Database/IInsertTable.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

class PlayerData;

class InsertPlayerData : public IInsertTable
{
	DISALLOW_COPY(InsertPlayerData);

public:
	InsertPlayerData (const PlayerData& playerData);
	virtual ~InsertPlayerData();

  const yap::ID& GetID ();

	/// @name ISpatial members.
	/// @{
	virtual bool Add (yap::DatabaseManager& databaseManager);
	/// @}

private:
	const PlayerData& playerData_;
};

#endif // YAPOG_INSERTPLAYERDATA_HPP