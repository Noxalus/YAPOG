#include "YAPOG/Game/Pokemon/PokemonSkill.hpp"

namespace yap
{
  PokemonSkill::PokemonSkill ()
  {
  }

  void PokemonSkill::Refill ()
  {
    currentPP_ = maxPP_;
  }

  void PokemonSkill::Use ()
  {
    if (currentPP_ > 0)
      currentPP_--;
  }
  
  void PokemonSkill::AddPP (int value)
  {
    maxPP_ += value;

    if (maxPP_ > limitPPMax_)
      maxPP_ = limitPPMax_;
  }

  void PokemonSkill::RaiseToMaxPP ()
  {
    maxPP_ = limitPPMax_;
  }
}