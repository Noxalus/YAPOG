#ifndef YAPOG_SERVER_POKEMONMOVEINSERTREQUEST_HPP
# define YAPOG_SERVER_POKEMONMOVEINSERTREQUEST_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "Database/Requests/Inserts/IInsertRequest.hpp"

namespace yse
{
  class PokemonMoveTable;

  class PokemonMoveInsertRequest : public IInsertRequest
  {
    DISALLOW_COPY(PokemonMoveInsertRequest);

  public:
    PokemonMoveInsertRequest (const PokemonMoveTable& pokemonMoveTable);
    virtual ~PokemonMoveInsertRequest();

    /// @name IInsertRequest members.
    /// @{
    virtual bool Insert (yap::DatabaseManager& databaseManager);
    /// @}

  private:
    const PokemonMoveTable& pokemonMoveTable_;
  };

} // namespace yse

#endif // YAPOG_SERVER_POKEMONMOVEINSERTREQUEST_HPP