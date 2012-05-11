#ifndef YAPOG_SELECTPLAYERDATA_HPP
# define YAPOG_SELECTPLAYERDATA_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Database/DatabaseManager.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"

class PlayerData;

class SelectPlayerData
{
  DISALLOW_COPY(SelectPlayerData);

public:
  SelectPlayerData (
    yap::DatabaseManager& dm, 
    PlayerData& playerData);
};

#endif // YAPOG_SELECTACCOUNT_HPP