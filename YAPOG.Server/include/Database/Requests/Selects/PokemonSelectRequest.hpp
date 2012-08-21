#ifndef YAPOG_POKEMONSELECTREQUEST_HPP
# define YAPOG_POKEMONSELECTREQUEST_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Database/DatabaseManager.hpp"
# include "Database/Requests/Selects/ISelectRequest.hpp"
# include "Database/Tables/PokemonTable.hpp"

namespace yse
{
  class PokemonSelectRequest : public ISelectRequest
  {
    DISALLOW_COPY(PokemonSelectRequest);

  public:
    PokemonSelectRequest (
      yap::DatabaseManager& dm, 
      PokemonTable& pokemonTable);
  };
} // namespace yse

#endif // YAPOG_POKEMONSELECTREQUEST_HPP