#ifndef YAPOG_SERVER_POKEMONIVINSERTREQUEST_HPP
# define YAPOG_SERVER_POKEMONIVINSERTREQUEST_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "Database/Requests/Inserts/IInsertRequest.hpp"

namespace yse
{
  class PokemonIVTable;

  class PokemonIVInsertRequest : public IInsertRequest
  {
    DISALLOW_COPY(PokemonIVInsertRequest);

  public:
    PokemonIVInsertRequest (const PokemonIVTable& pokemonIVTable);
    virtual ~PokemonIVInsertRequest();

    /// @name IInsertRequest members.
    /// @{
    virtual bool Insert (yap::DatabaseManager& databaseManager);
    /// @}

  private:
    const PokemonIVTable& pokemonIVTable_;
  };

} // namespace yse

#endif // YAPOG_SERVER_POKEMONIVINSERTREQUEST_HPP