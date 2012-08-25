#include "YAPOG/Game/Pokemon/Pokemon.hpp"

#include "Pokemon/Pokemon.hpp"

namespace yse
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

  Pokemon::Pokemon (
    const yap::ID& uniqueID,
    const yap::ID& staticID,
    const yap::String& nickname,
    const yap::PokemonStat& stats,
    const yap::Gender& gender,
    const yap::PokemonStatus& status,
    const bool shiny,
    const yap::Int16& loyalty,
    const yap::PokemonMoveSet& moveSet,
    const yap::ID& natureID,
    const yap::uint& exp,
    const yap::UInt8& boxNumber,
    const yap::ID& boxIndex,
    const yap::String& catchDate)
    : yap::Pokemon (
    uniqueID,
    staticID,
    nickname,
    stats,
    gender,
    status,
    shiny,
    loyalty,
    moveSet,
    natureID,
    exp,
    boxNumber,
    boxIndex,
    catchDate)
  {
  }

  Pokemon::~Pokemon ()
  {
  }

} // namespace yse