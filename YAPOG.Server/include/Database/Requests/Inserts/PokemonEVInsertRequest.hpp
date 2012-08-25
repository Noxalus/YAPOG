#ifndef YAPOG_SERVER_POKEMONEVINSERTREQUEST_HPP
# define YAPOG_SERVER_POKEMONEVINSERTREQUEST_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "Database/Requests/Inserts/IInsertRequest.hpp"

namespace yse
{
  class PokemonEVTable;

  class PokemonEVInsertRequest : public IInsertRequest
  {
    DISALLOW_COPY(PokemonEVInsertRequest);

  public:
    PokemonEVInsertRequest (const PokemonEVTable& pokemonEVTable);
    virtual ~PokemonEVInsertRequest();

    /// @name IInsertRequest members.
    /// @{
    virtual bool Insert (yap::DatabaseManager& databaseManager);
    /// @}

  private:
    const PokemonEVTable& pokemonEVTable_;
  };

} // namespace yse

#endif // YAPOG_SERVER_POKEMONEVINSERTREQUEST_HPP