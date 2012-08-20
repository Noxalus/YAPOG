#ifndef YAPOG_PLAYERDATATABLE_HPP
# define YAPOG_PLAYERDATATABLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "Database/Tables/ITable.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yse
{
  class PlayerData;

  class PlayerDataTable : public ITable
  {
    DISALLOW_COPY(PlayerDataTable);
  public:
    explicit PlayerDataTable (const yap::ID& accountID);

    void LoadFromPlayerData (const PlayerData& playerData);

    void DisplayData ();

    /// Getters
    const yap::ID& GetAccountID () const;
    const yap::Vector2& GetPosition () const;
    const yap::ID& GetMapID () const;
    int GetPlayTime () const;
    int GetStepCount () const;
    const yap::Vector2& GetRespawnSpot () const;
    int GetFleeCount () const;
    int GetBoxNumber () const;
    int GetBattleCount () const;
    int GetMoney () const;

    /// Setters
    void SetAccountID (const yap::ID& value);
    void SetPosition (const yap::Vector2& value);
    void SetMapID (const yap::ID& value);
    void SetPlayTime (int value);
    void SetStepCount (int value);
    void SetRespawnSpot (const yap::Vector2& value);
    void SetFleeCount (int value);
    void SetBoxNumber (int value);
    void SetBattleCount (int value);
    void SetMoney (int value);

  private:
    yap::ID accountID_;
    yap::Vector2 position_;
    yap::ID mapID_;
    int playTime_;
    int stepCount_;
    yap::Vector2 respawnSpot_;
    int fleeCount_;
    int boxNumber_;
    int battleCount_;
    int money_;
  };
} // namespace yse

#endif // YAPOG_PLAYERDATATABLE_HPP