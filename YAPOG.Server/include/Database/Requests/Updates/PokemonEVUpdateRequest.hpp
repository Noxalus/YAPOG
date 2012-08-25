#ifndef YAPOG_POKEMONEVUPDATEREQUEST_HPP
# define YAPOG_POKEMONEVUPDATEREQUEST_HPP

# include "YAPOG/Macros.hpp"
# include "Database/Requests/Updates/IUpdateRequest.hpp"
# include "Database/Tables/PokemonEVTable.hpp"

namespace yse
{
  class PokemonEVUpdateRequest : public IUpdateRequest
  {
    DISALLOW_COPY(PokemonEVUpdateRequest);
  public:
    PokemonEVUpdateRequest (const PokemonEVTable& pokemonTable);

    /// @name IUpdateRequest members.
    /// @{
    virtual bool Update (yap::DatabaseManager& databaseManager);
    /// @}

  private:
    const PokemonEVTable& pokemonTable_;
  };
} // namespace yse

#endif // YAPOG_POKEMONEVUPDATEREQUEST_HPP