#include "YAPOG/Game/Pokemon/Skill.hpp"

namespace yap
{
  Skill::Skill ()
  {
  }

  void Skill::Refill ()
  {
    currentPP_ = maxPP_;
  }

  void Skill::Use ()
  {
    if (currentPP_ > 0)
      currentPP_--;
  }
  
  void Skill::AddPP (int value)
  {
    maxPP_ += value;

    if (maxPP_ > limitPPMax_)
      maxPP_ = limitPPMax_;
  }

  void Skill::RaiseToMaxPP ()
  {
    maxPP_ = limitPPMax_;
  }
}