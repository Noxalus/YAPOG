#ifndef YAPOG_SERVER_POKEMONSTATSSELECTREQUEST_HPP
# define YAPOG_SERVER_POKEMONSTATSSELECTREQUEST_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Collection/List.hpp"
# include "YAPOG/Database/DatabaseManager.hpp"
# include "Database/Requests/Selects/ISelectRequest.hpp"
# include "Database/Tables/PokemonStatsTable.hpp"

namespace yse
{
  class PokemonTeam;

  class PokemonStatsSelectRequest : public ISelectRequest
  {
    DISALLOW_COPY(PokemonStatsSelectRequest);

  public:
    PokemonStatsSelectRequest (yap::DatabaseManager& dm);

    bool Select (PokemonStatsTable& pokemonTable);

  private:
    yap::DatabaseManager& databaseManager_;

  };
} // namespace yse

#endif // YAPOG_SERVER_POKEMONSTATSSELECTREQUEST_HPP