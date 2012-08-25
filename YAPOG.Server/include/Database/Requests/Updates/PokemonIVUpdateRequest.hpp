#ifndef YAPOG_SERVER_POKEMONIVUPDATEREQUEST_HPP
# define YAPOG_SERVER_POKEMONIVUPDATEREQUEST_HPP

# include "YAPOG/Macros.hpp"
# include "Database/Requests/Updates/IUpdateRequest.hpp"
# include "Database/Tables/PokemonIVTable.hpp"

namespace yse
{
  class PokemonIVUpdateRequest : public IUpdateRequest
  {
    DISALLOW_COPY(PokemonIVUpdateRequest);
  public:
    PokemonIVUpdateRequest (const PokemonIVTable& pokemonIVTable);

    /// @name IUpdateRequest members.
    /// @{
    virtual bool Update (yap::DatabaseManager& databaseManager);
    /// @}

  private:
    const PokemonIVTable& pokemonIVTable_;
  };
} // namespace yse

#endif // YAPOG_SERVER_POKEMONIVUPDATEREQUEST_HPP