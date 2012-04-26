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

    /// @brief Reset the PP to the maxPP value.
    void Refill ();
    /// @brief Decrease the currentPP value of 1.
    void Use ();
    /// @brief Increase the maxPP with @a value.
    /// @param value The value that will increase the maxPP field.
    void AddPP (int value);
    /// @brief Jump the maxPP value directly to the limiPPMax value.
    void RaiseToMaxPP ();
  private:
    ID id_;
    String name_;
    String description_;
    int power_;
    int accuracy_;
    Type type_;
    int maxPP_;
    int currentPP_;
    int limitPPMax_;
  };

} // namespace yap

#endif // YAPOG_SKILL_HPP
