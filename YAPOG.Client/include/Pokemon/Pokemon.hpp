#ifndef YAPOG_CLIENT_POKEMON_HPP
# define YAPOG_CLIENT_POKEMON_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/Pokemon.hpp"

namespace ycl
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
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMON_HPP

