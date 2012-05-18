#ifndef YAPOG_POKEMONSKILL_HPP
# define YAPOG_POKEMONSKILL_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Game/Pokemon/SkillInfo.hpp"
# include "YAPOG/Game/Pokemon/TypeInfo.hpp"
# include "YAPOG/System/IntTypes.hpp"

namespace yap
{
  class YAPOG_LIB PokemonSkill
  {
  public:
    PokemonSkill ();
    PokemonSkill (const ID& skillID);

    void SetSkillInfo (const ID& skillID);

    /// Getters
    const String& GetName () const;
    const UInt16& GetPower () const;
    const UInt16& GetCurrentPP () const;
    const UInt16& GetMaxPP () const;
    const TypeInfo& GetType () const;
    const UInt16& GetCategory () const;

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
    const UInt16& GetLimitPPMax () const;

    UInt16 currentPP_;
    UInt16 maxPP_;
    SkillInfo* skillInfo_;

    static const UInt16 DEFAULT_PP_VALUE;
    static const UInt16 DEFAULT_MAX_PP_VALUE;
  };

} // namespace yap

#endif // YAPOG_POKEMONSKILL_HPP
