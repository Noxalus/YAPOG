#ifndef YAPOG_POKEMONINSERTREQUEST_HPP
# define YAPOG_POKEMONINSERTREQUEST_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "Database/Requests/Inserts/IInsertRequest.hpp"

namespace yse
{
  class PokemonTable;

  class PokemonInsertRequest : public IInsertRequest
  {
    DISALLOW_COPY(PokemonInsertRequest);

  public:
    PokemonInsertRequest (const PokemonTable& playerDataTable);
    virtual ~PokemonInsertRequest();

    const yap::ID& GetID ();

    /// @name IInsertRequest members.
    /// @{
    virtual bool Insert (yap::DatabaseManager& databaseManager);
    /// @}

  private:
    yap::ID id_;
    const PokemonTable& pokemonTable_;
  };

} // namespace yse

#endif // YAPOG_POKEMONINSERTREQUEST_HPP