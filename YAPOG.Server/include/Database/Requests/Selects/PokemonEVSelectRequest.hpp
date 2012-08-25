#ifndef YAPOG_SERVER_POKEMONEVSELECTREQUEST_HPP
# define YAPOG_SERVER_POKEMONEVSELECTREQUEST_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Collection/List.hpp"
# include "YAPOG/Database/DatabaseManager.hpp"
# include "Database/Requests/Selects/ISelectRequest.hpp"
# include "Database/Tables/PokemonEVTable.hpp"

namespace yse
{
  class PokemonTeam;

  class PokemonEVSelectRequest : public ISelectRequest
  {
    DISALLOW_COPY(PokemonEVSelectRequest);

  public:
    PokemonEVSelectRequest (yap::DatabaseManager& dm);

    bool Select (PokemonEVTable& pokemonTable);

  private:
    yap::DatabaseManager& databaseManager_;

  };
} // namespace yse

#endif // YAPOG_SERVER_POKEMONEVSELECTREQUEST_HPP