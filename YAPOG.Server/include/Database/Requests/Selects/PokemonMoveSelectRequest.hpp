#ifndef YAPOG_SERVER_POKEMONMOVESELECTREQUEST_HPP
# define YAPOG_SERVER_POKEMONMOVESELECTREQUEST_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Collection/List.hpp"
# include "YAPOG/Database/DatabaseManager.hpp"
# include "Database/Requests/Selects/ISelectRequest.hpp"
# include "Database/Tables/PokemonMoveTable.hpp"

namespace yse
{
  class PokemonTeam;

  class PokemonMoveSelectRequest : public ISelectRequest
  {
    DISALLOW_COPY(PokemonMoveSelectRequest);

  public:
    PokemonMoveSelectRequest (yap::DatabaseManager& dm);

    bool Select (PokemonMoveTable& pokemonTable);

  private:
    yap::DatabaseManager& databaseManager_;

  };
} // namespace yse

#endif // YAPOG_SERVER_POKEMONMOVESELECTREQUEST_HPP