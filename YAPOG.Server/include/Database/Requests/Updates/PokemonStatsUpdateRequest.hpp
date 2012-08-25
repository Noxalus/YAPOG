#ifndef YAPOG_SERVER_POKEMONSTATSUPDATEREQUEST_HPP
# define YAPOG_SERVER_POKEMONSTATSUPDATEREQUEST_HPP

# include "YAPOG/Macros.hpp"
# include "Database/Requests/Updates/IUpdateRequest.hpp"
# include "Database/Tables/PokemonStatsTable.hpp"

namespace yse
{
  class PokemonStatsUpdateRequest : public IUpdateRequest
  {
    DISALLOW_COPY(PokemonStatsUpdateRequest);
  public:
    PokemonStatsUpdateRequest (const PokemonStatsTable& pokemonTable);

    /// @name IUpdateRequest members.
    /// @{
    virtual bool Update (yap::DatabaseManager& databaseManager);
    /// @}

  private:
    const PokemonStatsTable& pokemonTable_;
  };
} // namespace yse

#endif // YAPOG_SERVER_POKEMONSTATSUPDATEREQUEST_HPP