#ifndef YAPOG_SERVER_POKEMON_HPP
# define YAPOG_SERVER_POKEMON_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/Pokemon.hpp"

namespace yse
{
  class Pokemon : public yap::Pokemon
  {
    DISALLOW_COPY (Pokemon);

  public:
    Pokemon (const yap::ID& staticID);
    Pokemon (
      const yap::ID& staticID, 
      const yap::UInt16& level, 
      const bool& shiny);
    virtual ~Pokemon ();

  };
} // namespace yse

#endif // YAPOG_SERVER_POKEMON_HPP

