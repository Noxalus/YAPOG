#ifndef YAPOG_SERVER_POKEMONMOVEUPDATEREQUEST_HPP
# define YAPOG_SERVER_POKEMONMOVEUPDATEREQUEST_HPP

# include "YAPOG/Macros.hpp"
# include "Database/Requests/Updates/IUpdateRequest.hpp"
# include "Database/Tables/PokemonMoveTable.hpp"

namespace yse
{
  class PokemonMoveUpdateRequest : public IUpdateRequest
  {
    DISALLOW_COPY(PokemonMoveUpdateRequest);
  public:
    PokemonMoveUpdateRequest (const PokemonMoveTable& pokemonTable);

    /// @name IUpdateRequest members.
    /// @{
    virtual bool Update (yap::DatabaseManager& databaseManager);
    /// @}

  private:
    const PokemonMoveTable& pokemonTable_;
  };
} // namespace yse

#endif // YAPOG_SERVER_POKEMONMOVEUPDATEREQUEST_HPP