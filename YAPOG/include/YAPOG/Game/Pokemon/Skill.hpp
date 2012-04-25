#ifndef YAPOG_SKILL_HPP
# define YAPOG_SKILL_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Game/Pokemon/Type.hpp"

namespace yap
{
  class YAPOG_LIB Skill
  {
  public:
    Skill ();
  private:
    ID id_;
    String name_;
    String description_;
    int power_;
    int accuracy_;
    Type type_;
    int maxPP_;
    int currentPP_;
  };

} // namespace yap

#endif // YAPOG_SKILL_HPP
