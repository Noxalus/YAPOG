#ifndef YAPOG_PLAYERDATATABLE_HPP
# define YAPOG_PLAYERDATATABLE_HPP

# include "YAPOG/Macros.hpp"
# include "Database/Tables/ITable.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yse
{
  class PlayerDataTable : public ITable
  {
    DISALLOW_COPY(PlayerDataTable);
  public:
    explicit PlayerDataTable (const yap::ID& accountID);

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
} // namespace yse

#endif // YAPOG_PLAYERDATATABLE_HPP