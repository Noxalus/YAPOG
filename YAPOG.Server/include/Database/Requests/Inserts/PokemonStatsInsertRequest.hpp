#ifndef YAPOG_SERVER_POKEMONSTATSINSERTREQUEST_HPP
# define YAPOG_SERVER_POKEMONSTATSINSERTREQUEST_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "Database/Requests/Inserts/IInsertRequest.hpp"

namespace yse
{
  class PokemonStatsTable;

  class PokemonStatsInsertRequest : public IInsertRequest
  {
    DISALLOW_COPY(PokemonStatsInsertRequest);

  public:
    PokemonStatsInsertRequest (const PokemonStatsTable& pokemonStatsTable);
    virtual ~PokemonStatsInsertRequest();

    /// @name IInsertRequest members.
    /// @{
    virtual bool Insert (yap::DatabaseManager& databaseManager);
    /// @}

  private:
    const PokemonStatsTable& pokemonStatsTable_;
  };

} // namespace yse

#endif // YAPOG_SERVER_POKEMONSTATSINSERTREQUEST_HPP