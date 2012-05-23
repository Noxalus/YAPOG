#include "YAPOG/Game/Pokemon/Pokemon.hpp"

#include "Pokemon/Pokemon.hpp"

namespace ycl
{
  Pokemon::Pokemon (const yap::ID& staticID)
    : yap::Pokemon (staticID)
  {
  }

  Pokemon::Pokemon (
    const yap::ID& staticID, 
    const yap::UInt16& level, 
    const bool& shiny)
    : yap::Pokemon (staticID, level, shiny)
  {
  }

  Pokemon::~Pokemon ()
  {
  }
} // namespace ycl