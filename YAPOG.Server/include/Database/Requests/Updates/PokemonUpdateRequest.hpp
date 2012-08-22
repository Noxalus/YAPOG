#ifndef YAPOG_PLAYERDATAUPDATEREQUEST_HPP
# define YAPOG_PLAYERDATAUPDATEREQUEST_HPP

# include "YAPOG/Macros.hpp"
# include "Database/Requests/Updates/IUpdateRequest.hpp"
# include "Database/Tables/PokemonTable.hpp"

namespace yse
{
  class PokemonUpdateRequest : public IUpdateRequest
  {
    DISALLOW_COPY(PokemonUpdateRequest);
  public:
    PokemonUpdateRequest (const PokemonTable& pokemonTable);

    /// @name IUpdateRequest members.
    /// @{
    virtual bool Update (yap::DatabaseManager& databaseManager);
    /// @}

  private:
    const PokemonTable& pokemonTable_;
  };
} // namespace yse

#endif // YAPOG_PLAYERDATAUPDATEREQUEST_HPP