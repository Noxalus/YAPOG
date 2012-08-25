#ifndef YAPOG_POKEMONSELECTREQUEST_HPP
# define YAPOG_POKEMONSELECTREQUEST_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Collection/List.hpp"
# include "YAPOG/Database/DatabaseManager.hpp"
# include "Database/Requests/Selects/ISelectRequest.hpp"
# include "Database/Tables/PokemonTable.hpp"

namespace yse
{
  class PokemonTeam;

  class PokemonSelectRequest : public ISelectRequest
  {
    DISALLOW_COPY(PokemonSelectRequest);

  public:
    PokemonSelectRequest (yap::DatabaseManager& dm);

    bool Select (PokemonTable& pokemonTable);
    PokemonTable* SelectPokemon (const yap::ID& pokemonID);
    PokemonTeam* SelectPokemonTeam (const yap::ID& accountID);

  private:
    yap::DatabaseManager& databaseManager_;

  };
} // namespace yse

#endif // YAPOG_POKEMONSELECTREQUEST_HPP